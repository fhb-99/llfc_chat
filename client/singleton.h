#ifndef SINGLETON_H
#define SINGLETON_H

#include <global.h>

template<typename T>
class Singleton{
protected:
    Singleton() = default;
    Singleton(const Singleton<T>&) = delete;
    Singleton& operator = (const Singleton<T>& other) = delete;
    static std::shared_ptr<T> m_instance;

public:
    static std::shared_ptr<T> getInstance()
    {
        static std::once_flag s_flag;
        std::call_once(s_flag, [&](){
            // 之所以不使用make_shared_ptr是因为它调用的是拷贝构造
            // 而继承模板单例模式的子类的构造会设置为private，它无法访问私有的构造函数
            m_instance = std::shared_ptr<T>(new T);
        });
        return m_instance;
    }

    void PrintAddress()
    {
        std::cout << m_instance.get() << std::endl;
    }

    ~Singleton()
    {
        std::cout << "this is singleton destruct" << std::endl;
    }
};

template <typename T>
std::shared_ptr<T> Singleton<T>::m_instance = nullptr;

#endif // SINGLETON_H
