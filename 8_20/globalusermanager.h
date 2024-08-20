#ifndef GLOBALDATAMANAGER_H
#define GLOBALDATAMANAGER_H

#include <QHash>
#include <QString>

class GlobalDataManager {
public:
    // 获取单例对象的静态方法
    static GlobalDataManager* getInstance();

    // 设置和获取用户数据的方法
    void setUserDataBase(const QString& ph,const QString& n,const QString& p);
    QString getUserDataBase() const;
    QString getUserDataBase1() const;
    QString getUserDataBase2() const;
private:
    // 私有构造函数和析构函数，防止外部创建和删除实例
    GlobalDataManager();
    ~GlobalDataManager();

    // 禁止拷贝构造函数和赋值操作符
    GlobalDataManager(const GlobalDataManager&) = delete;
    GlobalDataManager& operator=(const GlobalDataManager&) = delete;

    // 静态私有指针，用于持有单例对象
    static GlobalDataManager* instance;

    // 用于存储用户数据的字符串变量
    QString user_phone;
    QString password;
    QString user_name;
};

#endif // GLOBALDATAMANAGER_H
