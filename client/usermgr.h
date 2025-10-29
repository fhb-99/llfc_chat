#ifndef USERMGR_H
#define USERMGR_H

#include <QObject>

#include "singleton.h"


class UserMgr : public QObject, public Singleton<UserMgr>,
                public std::enable_shared_from_this<UserMgr>
{
    Q_OBJECT
public:
    friend class Singleton<UserMgr>;

    ~UserMgr();

    void setName(QString name);
    void setId(int id);
    void setToken(QString token);

private:
    explicit UserMgr(QObject *parent = nullptr);
    QString _name;
    int _id;
    QString _token;

signals:
};

#endif // USERMGR_H
