#include"MainMenu.h"

//����������費��Ҫ��д�ļ��������ȿ�ʵ�ֹ��������
MainMenu::MainMenu()
{
    this->mainMenu_UsrId =0;
};
MainMenu::~MainMenu() {};

//������˵�
void MainMenu::showMainMenu()//�������ݣ���������¼�ӿ�
{
    std::cout << "===============��ӭʹ�û���ԤԼϵͳ===============" << std::endl<< std::endl;

    std::cout << "��ѡ���������" << std::endl;
    std::cout << "             ------------------------" << std::endl;
    std::cout << "            |                         |" << std::endl;
    std::cout << "            |       1.ѧ������        |" << std::endl;
    std::cout << "            |                         |" << std::endl;
    std::cout << "            |       2.��    ʦ        |" << std::endl;
    std::cout << "            |                         |" << std::endl;
    std::cout << "            |       3.�� �� Ա        |" << std::endl;
    std::cout << "            |                         |" << std::endl;
    std::cout << "            |       0.��    ��        |" << std::endl;
    std::cout << "            |                         |" << std::endl;
    std::cout << "             ------------------------" << std::endl;
}
void MainMenu::exitSystem()
{
    std::cout << "��ӭ���´�ʹ��Ciallo��(�ϡ���< ) �� ��\n"; system("pause");
    exit(0);
}

std::vector<Identity*> MainMenu::loadFile(std::string fileName, int personType)
{
    //����׼��(ID,�û���������)
    std::vector<Identity*> vIdentityData;
    int id = 0;
    std::string usrName;
    std::string pwd;

    std::fstream ifs(fileName, std::ios::in);
    //�ļ�������
    if (!ifs.is_open())
    {
        //std::cout << "(����)�ļ������ڣ�\n";
        ifs.close();
        return vIdentityData;
    }
    //�ļ�Ϊ��
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        //std::cout << "(����)�ļ�Ϊ�գ�\n";
        ifs.putback(ch);
        ifs.close();
        return vIdentityData;
    }
    ifs.putback(ch);

   
    while (ifs >> id && ifs >> usrName && ifs >> pwd)
    {
        Identity* person = NULL;
        switch (personType)
        {
        case ADMIN:
            person = new Admin(id, usrName, pwd);
            break;
        case TEACHER:
            person = new Teacher(id, usrName, pwd);
            break;
        case STUDENT:
            person = new Student(id, usrName, pwd);
            break;
        default:
            break;
        }
        vIdentityData.push_back(person);
    }
    //����
    //std::cout << (*vIdentityData.begin())->m_Name << std::endl;
    ifs.close();
    return vIdentityData;
}
void MainMenu::writeBackFile(std::string fileName, std::vector<Identity*> &vIdentityData)
{
    std::fstream ofs(fileName, std::ios::trunc);
    for (std::vector<Identity*>::iterator it = vIdentityData.begin(); it != vIdentityData.end(); it++)
    {
        ofs << (*it)->m_Id << " " << (*it)->m_Name << " " << (*it)->m_Password << std::endl;
    }
}

int MainMenu::getUsrId(std::string str)
{
    std::vector<int> v;
    bool isSafe = false;
    for (std::string::iterator it = str.begin(); it != str.end(); it++)
    {
        if ((*it - '0') < 0 || (*it - '0') > 9)//�ַ����ڷ�����
        {
            isSafe = false;
            return -1;
        }
        else//�ַ�����
        {
            v.push_back(*it - '0');
        }
    }
    int sum = 0;//�ַ���ת���ɴ�����
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        sum = sum * 10 + *it;
    }
    return sum;
}


//�����¼
//void MainMenu::loginIn(std::string fileName, int personType)
//{
//    //�Ȱ������õ���
//    std::vector<Identity*> vIdentityData = this->loadFile(fileName, personType);
//    Identity* person = NULL;
//
//    //Ȼ�������֤
//    //�û�����
//    std::cout << "�������ţ�"; std::cin >> this->mainMenu_UsrId;
//    std::cout << "�������û�����"; std::cin >> this->mainMenu_UsrName;
//    std::cout << "���������룺"; std::cin >> this->mainMenu_Password;
//    //��ʼ����
//    bool isSignIn = false;
//    for (std::vector<Identity*>::iterator it = vIdentityData.begin(); it != vIdentityData.end(); it++)
//    {
//        if ((*it)->m_Id==mainMenu_UsrId && 
//            (*it)->m_Name == mainMenu_UsrName && 
//            (*it)->m_Password == mainMenu_Password)
//        {
//            std::cout << "��֤�ɹ�,"; system("pause");
//            person = *it;
//            isSignIn = true;
//            break;
//        }
//    }
//    //��¼�ɹ�
//    if (isSignIn)
//    {
//        vIdentityData.clear();
//        switch (personType)
//        {
//        case ADMIN:
//            this->adminMenu(person);
//            break;
//        case TEACHER:
//            this->teacherMenu(person);
//            break;
//        case STUDENT:
//            this->studentMenu(person);
//            break;
//        default:
//            break;
//        }
//        //���ڷ������ˣ���һЩ����
//    }
//    else//��¼ʧ��
//    {     
//        std::cout << "��֤ʧ��!";
//        system("pause");    
//        this->writeBackFile(fileName, vIdentityData);
//        vIdentityData.clear();
//    }   
//    return;
//}

//�Ľ���ĵ�¼
void MainMenu::loginIn(std::string fileName, int personType)
{
    //�Ȱ������õ���
    std::vector<Identity*> vIdentityData = this->loadFile(fileName, personType);
    Identity* person = NULL;

    //Ȼ�������֤
    //�û�����
    //����Ϊ�˰�ȫ����һ����ż��
    std::string idIsSafe;
    std::cout << "�������ţ�"; std::cin >> idIsSafe;
    this->mainMenu_UsrId = getUsrId(idIsSafe);
    std::cout << "�������û�����"; std::cin >> this->mainMenu_UsrName;
    std::cout << "���������룺"; std::cin >> this->mainMenu_Password;
    //��ʼ����
    bool isSignIn = false;
    for (std::vector<Identity*>::iterator it = vIdentityData.begin(); it != vIdentityData.end(); it++)
    {
        if ((*it)->m_Id == mainMenu_UsrId &&
            (*it)->m_Name == mainMenu_UsrName &&
            (*it)->m_Password == mainMenu_Password)
        {
            std::cout << "��֤�ɹ�,"; system("pause");
            person = *it;
            isSignIn = true;
            break;
        }
    }
    //��¼�ɹ�
    if (isSignIn)
    {
        vIdentityData.clear();
        switch (personType)
        {
        case ADMIN:
            this->adminMenu(person);
            break;
        case TEACHER:
            this->teacherMenu(person);
            break;
        case STUDENT:
            this->studentMenu(person);
            break;
        default:
            break;
        }
        //���ڷ������ˣ���һЩ����
    }
    else//��¼ʧ��
    {
        std::cout << "��֤ʧ��!";
        system("pause");
        system("cls");
        this->showMainMenu();
    }

}

//�����¼���ʵ��-Admin
void MainMenu::adminMenu(Identity* &admin)
{
    while (1)
    {
        admin->openMenu();
        Admin *ad = (Admin*)admin;//����ָ��ת������
        int adminSelect = -1;//adminѡ��
        std::cin >> adminSelect;

        switch (adminSelect)
        {
        case 0://ע����¼��������һ��
            std::cout << "ȷ��ע����(����0ע�����������������ַ�ȡ��ע��)\n";
            int ConfirmNumber;
            std::cin >> ConfirmNumber;
            if (ConfirmNumber == 0)
            {
                return;
            }
            else
            {
                std::cout << "��ȡ��!  ";
                break;
            }
            break;
        case 1://����˺�
            ad->addAccount();
            break;
        case 2://�鿴�˺�
            ad->showAccount();
            break;
        case 3://��ӻ���
            ad->addComputerRoom();
            break;
        case 4://�鿴����
            ad->showCompuRoomInfo();
            break;
        case 5://���ԤԼ
            ad->clearReservation();
            break;
        default:
            break;
        }
        system("pause");
    }
}
//�����¼���ʵ��-Student
void MainMenu::studentMenu(Identity* &student)
{
    while (1)
    {
        student->openMenu();
        Student* st = (Student*)student;//����ָ��ת������
        int studentSelect = -1;//adminѡ��
        std::cin >> studentSelect;

        switch (studentSelect)
        {
        case 0://ע����¼��������һ��
            std::cout << "ȷ��ע����(����0ע�����������������ַ�ȡ��ע��)\n";
            int ConfirmNumber;
            std::cin >> ConfirmNumber;
            if (ConfirmNumber == 0)
            {
                return;
            }
            else
            {
                std::cout << "��ȡ��!  ";
                break;
            }
            break;
        case 1://����ԤԼ
            st->applyOrder();
            break;
        case 2://�鿴�ҵ�ԤԼ
            st->showMyOrder();
            break;
        case 3://�鿴����ԤԼ
            st->showAllOrder();
            break;
        case 4://ȡ��ԤԼ
            st->cancelOrder();
            break;
        default:
            break;
        }
        system("pause");
    }
}
//�����¼���ʵ��-Teacher
void MainMenu::teacherMenu(Identity*& teacher)
{
    while (1)
    {
        teacher->openMenu();
        Teacher* te = (Teacher*)teacher;//����ָ��ת������
        int teacherSelect = -1;//adminѡ��
        std::cin >> teacherSelect;

        switch (teacherSelect)
        {
        case 0://ע����¼��������һ��
            std::cout << "ȷ��ע����(����0ע�����������������ַ�ȡ��ע��)\n";
            int ConfirmNumber;
            std::cin >> ConfirmNumber;
            if (ConfirmNumber == 0)
            {
                return;
            }
            else
            {
                std::cout << "��ȡ��!  ";
                break;
            }
            break;
        case 1://�鿴����ԤԼ
            te->showAllOrder();
            break;
        case 2://���ԤԼ
            te->validOrder();
            break;
        default:
            break;
        }
        system("pause");
    }
}
