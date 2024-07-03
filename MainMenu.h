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

//���˵���Ҫʵ�ּ����ӿڣ�������ͬidentity��¼�ӿڣ��Լ�һ���˳�ϵͳ�Ľӿڣ�
//���о�����Ҫ��ʾ�˵�������Ҫ����,������ҪһЩ��������
class MainMenu
{
public:
    //���������
    MainMenu();
    ~MainMenu();

    //��Ҫ�ӿ�(����д������,����д��д�˾��ð�)
    void loginIn(std::string fileName,int personType);//�������ļ��������
    std::vector<Identity*> loadFile(std::string fileName, int personType);
    void writeBackFile(std::string fileName, std::vector<Identity*> &vIdentityData);
    void adminMenu( Identity*& admin);
    void teacherMenu( Identity*& teacher);
    void studentMenu(Identity*& student);
    void showMainMenu();
    void exitSystem();
    //���id��ȫ��
    int getUsrId(std::string str);

public:
    //�洢�û���Ϣ
    int mainMenu_UsrId;
    std::string mainMenu_UsrName;  
    std::string mainMenu_Password;
};