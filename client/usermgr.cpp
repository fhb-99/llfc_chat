#include "usermgr.h"

UserMgr::~UserMgr()
{

}

void UserMgr::setName(QString name)
{
    _name = name;
}

void UserMgr::setId(int id)
{
    _id = id;
}

void UserMgr::setToken(QString token)
{
    _token = token;
}

UserMgr::UserMgr(QObject *parent)
    : QObject{parent}
{

}
