#include"admin.h"

//默认构造
Admin::Admin()
{
	this->m_Id = 0;
}

//有参构造(管理员编号、姓名、密码)
Admin::Admin(int adId, std::string name, std::string pwd)
{
	this->m_Id = adId;
	this->m_Name = name;
	this->m_Password = pwd;
}

//菜单
void Admin::openMenu()
{
	system("cls");
	std::cout << "欢迎管理员" << this->m_Name << "登录！\n\n";

    std::cout << "请选择您的操作" << std::endl;
    std::cout << "             ------------------------" << std::endl;
    std::cout << "            |                         |" << std::endl;
    std::cout << "            |       1.添加账号        |" << std::endl;
    std::cout << "            |                         |" << std::endl;
    std::cout << "            |       2.查看账号        |" << std::endl;
    std::cout << "            |                         |" << std::endl;
    std::cout << "            |       3.添加机房        |" << std::endl;
    std::cout << "            |                         |" << std::endl;
    std::cout << "            |       4.查看机房        |" << std::endl;
    std::cout << "            |                         |" << std::endl;
    std::cout << "            |       5.清空预约        |" << std::endl;
    std::cout << "            |                         |" << std::endl;
    std::cout << "            |       0.注销登录        |" << std::endl;
    std::cout << "            |                         |" << std::endl;
    std::cout << "             ------------------------" << std::endl;
    std::cout << "输入您的选择：";
}

//loadFile
std::vector<Identity*> Admin::loadIdentityFile(std::string fileName,int personType)
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
    ifs.close();
    return vIdentityData;
}

//WriteBackSub
void Admin::writeBackSubFile(std::string fileName, std::vector<Identity*>& vIdentityData)
{
    std::fstream ofs(fileName, std::ios::out|std::ios::trunc);
    for (std::vector<Identity*>::iterator it = vIdentityData.begin(); it != vIdentityData.end(); it++)
    {
        ofs << (*it)->m_Id << " " << (*it)->m_Name << " " << (*it)->m_Password << std::endl;
    }
}

//loadComp
std::vector<ComputerRoom> Admin::loadCompFile()
{
    //获取机房信息
    std::vector<ComputerRoom> vComp;
    std::ifstream ifs(COMPUTER_FILE, std::ios::in);
    int comId = 0;
    int capa = 0;
    while (ifs >> comId && ifs >> capa)
    {
        ComputerRoom cm(comId, capa);
        vComp.push_back(cm);
    }
    return vComp;
}

//writeBackComp
void Admin::writeBackCompFile(std::vector < ComputerRoom> &vComp)
{
    std::fstream ofs(COMPUTER_FILE, std::ios::out | std::ios::trunc);
    for (std::vector<ComputerRoom>::iterator it = vComp.begin(); it != vComp.end(); it++)
    {
        ofs << it->m_ComId << " " << it->m_MaxCapacity<< std::endl;
    }
}

//loadOrder
std::vector<Order> Admin::loadOrderFile()
{
    std::vector<Order> vOrder;
    std::ifstream ifs(ORDER_FILE, std::ios::in);

    int orderId = 0;
    int stuId = 0;
    int teaId = 0;
    int oInfo = 0;        //raw
    int comId = 0;
    int wTime = 0;        //sun 
    int dTime = 0;          //am
    while (ifs>> orderId&&ifs >> stuId && ifs >> teaId && ifs >> oInfo && ifs >> comId && ifs >> wTime && ifs >> dTime)
    {
        Order od;
        od.orderId = orderId;
        od.stuId = stuId;
        od.teaId = teaId;
        od.oInfo = oInfo;
        od.copmId = comId;
        OrderTime ot(wTime, dTime);
        od.oTime = ot;

        vOrder.push_back(od);
    }
    return vOrder;
}


//添加账号
void Admin::addAccount()
{
    std::string fileName;//准备接受在ofstream里
    int personType = 0;//准备选择
    std::ofstream ofs;
    //选择类型
    while (true)
    {
        std::cout << "请选择添加的账号类型：\n";
        std::cout << "1.添加学生\n2.添加老师\n";

       
        int select = 0;
        std::cin >> select;
        if (select == 1)//学生
        {
            fileName = STUDENT_FILE;
            personType = STUDENT;
            std::cout << "请输入学号：";
            break;
        }
        else if (select == 2)//老师
        {
            fileName = TEACHER_FILE;
            personType = TEACHER;
            std::cout << "请输入职工号：";
            break;
        }
        else
        {
            system("cls");
            this->openMenu();
            continue;
        }
    }
    //开始添加,用户输入数据
    ofs.open(fileName, std::ios::out | std::ios::app);
    int id;
    std::string name;
    std::string pwd;
    std::cin >> id;
    std::cout << "请输入用户名："; std::cin >> name;
    std::cout << "请输入密码："; std::cin >> pwd; std::cout << std::endl;

 //数据处理  1.加载数据  2.核验重复  3.处理以及提示
    std::vector<Identity*> vIdentityData=this->loadIdentityFile(fileName, personType);

    //开始核验是否重复
    bool isExist = false;
    for (std::vector<Identity*>::iterator it = vIdentityData.begin(); it != vIdentityData.end(); it++)
    {
        if ((*it)->m_Id == id)
        {
            isExist = true;
            break;
        }
    }

    //处理以及提示
    if (isExist)
    {
        std::cout << "重复的ID!\n"; 
        ofs.close();       
    }
    else//写入数据
    {
        Admin *ad =new Admin(id, name, pwd);
        vIdentityData.push_back(ad);
        this->writeBackSubFile(fileName,vIdentityData);
        ofs.close();
        vIdentityData.clear();
        std::cout << "添加成功!\n";
    }
}

//查看账号
void Admin::showAccount()
{
    //都要查看,先拿数据
    std::vector<Identity*> vStudent = this->loadIdentityFile(STUDENT_FILE, STUDENT);
    std::vector<Identity*> vTeacher = this->loadIdentityFile(TEACHER_FILE, TEACHER);

    //学生
    std::cout << "-----------------\n";
    std::cout << "当前学生账号数:" << vStudent.size() << std::endl;
    std::cout << "-----------------\n";
    if (vStudent.size())
    {
        std::cout << "\t学号\t姓名\t\t密码\n";
        for (std::vector<Identity*>::iterator it = vStudent.begin(); it != vStudent.end(); it++)
        {
            std::cout << "\t" << (*it)->m_Id << "\t" << (*it)->m_Name << "\t\t" << (*it)->m_Password << std::endl;
        }
    }
    std::cout << std::endl;
    //老师
    std::cout << "-----------------\n";
    std::cout << "当前老师账号数:" << vTeacher.size() << std::endl;
    std::cout << "-----------------\n";
    if (vTeacher.size())
    {
        std::cout << "\t职工号\t姓名\t\t密码\n";
        for (std::vector<Identity*>::iterator it = vTeacher.begin(); it != vTeacher.end(); it++)
        {
            std::cout << "\t" << (*it)->m_Id << "\t" << (*it)->m_Name << "\t\t" << (*it)->m_Password << std::endl;
        }
    }
    std::cout << std::endl;
}

//机房详情
void Admin::showRoomDetail(int week, int day)
{
    //加载机房信息
    std::vector<ComputerRoom> vComp = this->loadCompFile();
    //加载订单
    std::vector<Order> vOrder = this->loadOrderFile();

    //筛选
    std::vector<Order> vSubOrder;
    for (std::vector<Order>::iterator it = vOrder.begin(); it != vOrder.end(); it++)
    {
        if (it->oTime.weekTime == week && it->oTime.dayTime == day&&it->oInfo==SUCCEED)
            vSubOrder.push_back(*it);
    }
    //输出信息
    std::cout << "当前时段订单总数：" << vSubOrder.size() << "\n";
    std::cout << "---------------------\n";
    std::cout << "\t机房号\t最大容量\t已预约数\t余量\n";
    for (std::vector<ComputerRoom>::iterator it = vComp.begin(); it != vComp.end(); it++)
    {
        int comId = 0;//找已预约数据
        for (std::vector<Order>::iterator jt = vSubOrder.begin(); jt != vSubOrder.end(); jt++)
        {
            if (jt->copmId == it->m_ComId)
                comId++;
        }
        std::cout << "\t" << it->m_ComId << "\t" << it->m_MaxCapacity << "\t\t" << comId << "\t\t" << it->m_MaxCapacity - comId << "\n";
    }
    std::cout << std::endl;
}

//查看机房信息()
void Admin::showCompuRoomInfo()
{
    //加载机房信息
    std::vector<ComputerRoom> vComp = this->loadCompFile();

    //输出机房信息
    std::cout << "-----------------\n";
    std::cout << "机房总数:" <<vComp.size() << std::endl;
    std::cout << "-----------------\n";
    
    if (vComp.size())//有机房
    {
        std::cout << "\t机房号\t最大容量\n";
        for (std::vector<ComputerRoom>::iterator it = vComp.begin(); it != vComp.end(); it++)
        {
            std::cout << "\t" << it->m_ComId << "\t" << it->m_MaxCapacity << "\n";
        }
        std::cout << std::endl;

        //下一步操作
        std::cout << "输入0查看详情，输入其他任意字符退出查询\n";
        char nextSelect = '0';
        std::cin >> nextSelect;
        if (nextSelect == '0')
        {
            std::cout << "请选择周几：(0-sun,1-mon...)\n";
            int weekSelect = 0;
            while (1)
            {
                std::cin >> weekSelect;
                if (weekSelect != 0 && weekSelect != 1 && weekSelect != 2 && weekSelect != 3 && weekSelect != 4 && weekSelect != 5 && weekSelect != 6)
                    continue;
                break;
            }
            std::cout << "请选择时段：(0-am,1-pm)\n";
            int daySelect = 0;
            while (1)
            {
                std::cin >> daySelect;
                if (daySelect != 0 && daySelect != 1)
                    continue;
                break;
            }
            //选好了，加载数据
            if (weekSelect == 0)//周日
            {
                std::cout << "---------------------\n";
                std::cout << "您已选择：周日";
                if (daySelect == 0)
                {
                    std::cout << "上午\n";
                }
                else
                {
                    std::cout << "下午\n";
                }
            }
            else//1-6
            {
                std::cout << "---------------------\n";
                std::cout << "您已选择：周" << weekSelect << " ";
                if (daySelect == 0)
                {
                    std::cout << "上午\n";
                }
                else
                {
                    std::cout << "下午\n";
                }
            }
            this->showRoomDetail(weekSelect, daySelect);
        }
        else
        {
            return;
        }
    }
    else//没机房
    {
        return;
    }
}

//检查重复机房
bool Admin::roomIsExist(std::vector<ComputerRoom>& vComp, ComputerRoom& cr)
{
    for (std::vector<ComputerRoom>::iterator it = vComp.begin(); it != vComp.end(); it++)
    {
        if (it->m_ComId==cr.m_ComId)
        {
            return true;
        }
    }
    return false;
}

//检测机房id安全性
int Admin::getCompId(std::string str)
{
    std::vector<int> v;
    bool isSafe = false;
    for (std::string::iterator it = str.begin(); it != str.end(); it++)
    {
        if ((*it - '0') < 0 || (*it - '0') > 9)//字符存在非数字
        {
            isSafe = false;
            return -1;//输入有误
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
    //检验机房是否已存在
    //加载机房信息
    std::vector<ComputerRoom> vComp = this->loadCompFile();
    for (std::vector<ComputerRoom>::iterator it = vComp.begin(); it != vComp.end(); it++)
    {
        if (sum==it->m_ComId)
        {
            return -2;//机房已存在
        }
    }
    return sum;
}

//添加机房
void Admin::addComputerRoom()
{
    //加载机房信息
    std::vector<ComputerRoom> vComp = this->loadCompFile();

    std::string safeId;
    std::cout << "分配机房号:"; std::cin >> safeId;
    int comId = this->getCompId(safeId);
    if (comId == -1)
    {
        std::cout << "输入有误!\n";
        return;
    }
    else if (comId == -2)
    {
        std::cout << "机房已存在!\n";
        return;
    }
    //开始分配
    int maxCapa = 0;
    std::cout << "输入机房最大容量："; std::cin >> maxCapa;

    ComputerRoom cr(comId, maxCapa);
    vComp.push_back(cr);
    std::sort(vComp.begin(), vComp.end());
    std::cout << "添加成功，";
    //写回机房信息
    this->writeBackCompFile(vComp);
}

//清空预约记录
void Admin::clearReservation()
{
    //检测文件
    std::fstream ifs(ORDER_FILE, std::ios::in);
    //文件不存在
    if (!ifs.is_open())
    {
        std::cout << "文件不存在！\n";
        ifs.close();
        return;
    }
    //文件为空
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        std::cout << "文件为空！\n";
        ifs.putback(ch);
        ifs.close();
        return;
    }
    ifs.putback(ch);
    ifs.close();

    //文件存在且有数据
        std::cout << "确认清空？(输入0确认，输入任意其他字符取消)\n";
        char ConfirmNumber='0';
        std::cin >> ConfirmNumber;
        if (ConfirmNumber == '0')
        {
            std::ofstream ofs(ORDER_FILE, std::ios::trunc);
            ofs.close();
            std::cout << "已清空!  ";
            return;
        }
        else
        {
            std::cout << "已取消!  ";
            return;
        }
}