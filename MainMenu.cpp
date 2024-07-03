#include"MainMenu.h"

//待会儿看看需不需要读写文件，这里先空实现构造和析构
MainMenu::MainMenu()
{
    this->mainMenu_UsrId =0;
};
MainMenu::~MainMenu() {};

//主界面菜单
void MainMenu::showMainMenu()//保存数据，接三个登录接口
{
    std::cout << "===============欢迎使用机房预约系统===============" << std::endl<< std::endl;

    std::cout << "请选择您的身份" << std::endl;
    std::cout << "             ------------------------" << std::endl;
    std::cout << "            |                         |" << std::endl;
    std::cout << "            |       1.学生代表        |" << std::endl;
    std::cout << "            |                         |" << std::endl;
    std::cout << "            |       2.老    师        |" << std::endl;
    std::cout << "            |                         |" << std::endl;
    std::cout << "            |       3.管 理 员        |" << std::endl;
    std::cout << "            |                         |" << std::endl;
    std::cout << "            |       0.退    出        |" << std::endl;
    std::cout << "            |                         |" << std::endl;
    std::cout << "             ------------------------" << std::endl;
}
void MainMenu::exitSystem()
{
    std::cout << "欢迎您下次使用Ciallo～(∠·ω< ) ⌒ ★\n"; system("pause");
    exit(0);
}

std::vector<Identity*> MainMenu::loadFile(std::string fileName, int personType)
{
    //数据准备(ID,用户名，密码)
    std::vector<Identity*> vIdentityData;
    int id = 0;
    std::string usrName;
    std::string pwd;

    std::fstream ifs(fileName, std::ios::in);
    //文件不存在
    if (!ifs.is_open())
    {
        //std::cout << "(测试)文件不存在！\n";
        ifs.close();
        return vIdentityData;
    }
    //文件为空
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        //std::cout << "(测试)文件为空！\n";
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
    //测试
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
        if ((*it - '0') < 0 || (*it - '0') > 9)//字符存在非数字
        {
            isSafe = false;
            return -1;
        }
        else//字符合理
        {
            v.push_back(*it - '0');
        }
    }
    int sum = 0;//字符串转换成纯数字
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        sum = sum * 10 + *it;
    }
    return sum;
}


//初版登录
//void MainMenu::loginIn(std::string fileName, int personType)
//{
//    //先把数据拿到手
//    std::vector<Identity*> vIdentityData = this->loadFile(fileName, personType);
//    Identity* person = NULL;
//
//    //然后进行验证
//    //用户输入
//    std::cout << "请输入编号："; std::cin >> this->mainMenu_UsrId;
//    std::cout << "请输入用户名："; std::cin >> this->mainMenu_UsrName;
//    std::cout << "请输入密码："; std::cin >> this->mainMenu_Password;
//    //开始检索
//    bool isSignIn = false;
//    for (std::vector<Identity*>::iterator it = vIdentityData.begin(); it != vIdentityData.end(); it++)
//    {
//        if ((*it)->m_Id==mainMenu_UsrId && 
//            (*it)->m_Name == mainMenu_UsrName && 
//            (*it)->m_Password == mainMenu_Password)
//        {
//            std::cout << "验证成功,"; system("pause");
//            person = *it;
//            isSignIn = true;
//            break;
//        }
//    }
//    //登录成功
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
//        //现在返回来了，做一些清理
//    }
//    else//登录失败
//    {     
//        std::cout << "验证失败!";
//        system("pause");    
//        this->writeBackFile(fileName, vIdentityData);
//        vIdentityData.clear();
//    }   
//    return;
//}

//改进后的登录
void MainMenu::loginIn(std::string fileName, int personType)
{
    //先把数据拿到手
    std::vector<Identity*> vIdentityData = this->loadFile(fileName, personType);
    Identity* person = NULL;

    //然后进行验证
    //用户输入
    //这里为了安全性做一个编号检查
    std::string idIsSafe;
    std::cout << "请输入编号："; std::cin >> idIsSafe;
    this->mainMenu_UsrId = getUsrId(idIsSafe);
    std::cout << "请输入用户名："; std::cin >> this->mainMenu_UsrName;
    std::cout << "请输入密码："; std::cin >> this->mainMenu_Password;
    //开始检索
    bool isSignIn = false;
    for (std::vector<Identity*>::iterator it = vIdentityData.begin(); it != vIdentityData.end(); it++)
    {
        if ((*it)->m_Id == mainMenu_UsrId &&
            (*it)->m_Name == mainMenu_UsrName &&
            (*it)->m_Password == mainMenu_Password)
        {
            std::cout << "验证成功,"; system("pause");
            person = *it;
            isSignIn = true;
            break;
        }
    }
    //登录成功
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
        //现在返回来了，做一些操作
    }
    else//登录失败
    {
        std::cout << "验证失败!";
        system("pause");
        system("cls");
        this->showMainMenu();
    }

}

//具体登录后的实现-Admin
void MainMenu::adminMenu(Identity* &admin)
{
    while (1)
    {
        admin->openMenu();
        Admin *ad = (Admin*)admin;//父类指针转成子类
        int adminSelect = -1;//admin选择
        std::cin >> adminSelect;

        switch (adminSelect)
        {
        case 0://注销登录，返回上一级
            std::cout << "确认注销？(输入0注销，输入任意其他字符取消注销)\n";
            int ConfirmNumber;
            std::cin >> ConfirmNumber;
            if (ConfirmNumber == 0)
            {
                return;
            }
            else
            {
                std::cout << "已取消!  ";
                break;
            }
            break;
        case 1://添加账号
            ad->addAccount();
            break;
        case 2://查看账号
            ad->showAccount();
            break;
        case 3://添加机房
            ad->addComputerRoom();
            break;
        case 4://查看机房
            ad->showCompuRoomInfo();
            break;
        case 5://清空预约
            ad->clearReservation();
            break;
        default:
            break;
        }
        system("pause");
    }
}
//具体登录后的实现-Student
void MainMenu::studentMenu(Identity* &student)
{
    while (1)
    {
        student->openMenu();
        Student* st = (Student*)student;//父类指针转成子类
        int studentSelect = -1;//admin选择
        std::cin >> studentSelect;

        switch (studentSelect)
        {
        case 0://注销登录，返回上一级
            std::cout << "确认注销？(输入0注销，输入任意其他字符取消注销)\n";
            int ConfirmNumber;
            std::cin >> ConfirmNumber;
            if (ConfirmNumber == 0)
            {
                return;
            }
            else
            {
                std::cout << "已取消!  ";
                break;
            }
            break;
        case 1://申请预约
            st->applyOrder();
            break;
        case 2://查看我的预约
            st->showMyOrder();
            break;
        case 3://查看所有预约
            st->showAllOrder();
            break;
        case 4://取消预约
            st->cancelOrder();
            break;
        default:
            break;
        }
        system("pause");
    }
}
//具体登录后的实现-Teacher
void MainMenu::teacherMenu(Identity*& teacher)
{
    while (1)
    {
        teacher->openMenu();
        Teacher* te = (Teacher*)teacher;//父类指针转成子类
        int teacherSelect = -1;//admin选择
        std::cin >> teacherSelect;

        switch (teacherSelect)
        {
        case 0://注销登录，返回上一级
            std::cout << "确认注销？(输入0注销，输入任意其他字符取消注销)\n";
            int ConfirmNumber;
            std::cin >> ConfirmNumber;
            if (ConfirmNumber == 0)
            {
                return;
            }
            else
            {
                std::cout << "已取消!  ";
                break;
            }
            break;
        case 1://查看所有预约
            te->showAllOrder();
            break;
        case 2://审核预约
            te->validOrder();
            break;
        default:
            break;
        }
        system("pause");
    }
}
