#include "globalusermanager.h"

// 定义静态成员变量
GlobalDataManager* GlobalDataManager::instance = nullptr;

// 私有构造函数
GlobalDataManager::GlobalDataManager() {
    // 初始化代码（如果有的话）
}

// 析构函数
GlobalDataManager::~GlobalDataManager() {
    // 清理资源（如果有的话）
}

// 获取单例对象的方法
GlobalDataManager* GlobalDataManager::getInstance() {
    if (instance == nullptr) {
        instance = new GlobalDataManager();
    }
    return instance;
}

// 设置用户数据的方法
void GlobalDataManager::setUserDataBase(const QString& data,const QString& p) {
    userData = data;
    password = p;
}

// 获取用户数据的方法
QString GlobalDataManager::getUserDataBase() const {
    return userData;
}
QString GlobalDataManager::getUserDataBase1() const {
    return password;
}
