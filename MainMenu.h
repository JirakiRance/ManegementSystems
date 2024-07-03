#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include"globalFile.h"
#include"identity.h"
#include"admin.h"
#include"teacher.h"
#include"student.h"

//主菜单需要实现几个接口，三个不同identity登录接口，以及一个退出系统的接口，
//还有就是需要显示菜单，不需要属性,可能需要一些辅助函数
class MainMenu
{
public:
    //构造和析构
    MainMenu();
    ~MainMenu();

    //主要接口(不用写回数据,但是写都写了就用吧)
    void loginIn(std::string fileName,int personType);//操作的文件名，身份
    std::vector<Identity*> loadFile(std::string fileName, int personType);
    void writeBackFile(std::string fileName, std::vector<Identity*> &vIdentityData);
    void adminMenu( Identity*& admin);
    void teacherMenu( Identity*& teacher);
    void studentMenu(Identity*& student);
    void showMainMenu();
    void exitSystem();
    //检测id安全性
    int getUsrId(std::string str);

public:
    //存储用户信息
    int mainMenu_UsrId;
    std::string mainMenu_UsrName;  
    std::string mainMenu_Password;
};