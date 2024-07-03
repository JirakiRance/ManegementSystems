#include"student.h"

//默认构造
Student::Student() 
{
	this->m_Id = 0;
}
//有参（姓名、学号、密码）
Student::Student(int stuId, std::string name, std::string password)
{
	this->m_Id = stuId;
	this->m_Name = name;
	this->m_Password = password;
}

//字符串处理
std::string Student::getTimeStr(int week, int day)
{
    std::string str;
    switch (week)
    {
    case SUN:
        str = "周日";
        break;
    case MON:
        str = "周一";
        break;
    case TUE:
        str = "周二";
        break;
    case WED:
        str = "周三";
        break;
    case THR:
        str = "周四";
        break;
    case FRI:
        str = "周五";
        break;
    case SAT:
        str = "周六";
        break;
    default:
        break;
    }
    if (day == AM)
    {
        str += "上午";
    }
    else
    {
        str += "下午";
    }
    return str;
}

std::string Student::getInfoStr(int info)
{
    std::string str;
    switch (info)
    {
    case RAW:
        str = "草稿";
        break;
    case EXAMINE:
        str = "审核中";
        break;
    case CANCEL:
        str = "已取消";
        break;
    case FAIL:
        str = "审核未通过";
        break;
    case SUCCEED:
        str = "审核通过！";
        break;
    default:
        break;
    }
    return str;
}

//菜单
void Student::openMenu()
{
	system("cls");
	std::cout << "欢迎 " << this->m_Name << " 登录！\n\n";

    std::cout << "请选择您的操作" << std::endl;
    std::cout << "             ----------------------------" << std::endl;
    std::cout << "            |                            |" << std::endl;
    std::cout << "            |       1.申 请 预 约        |" << std::endl;
    std::cout << "            |                            |" << std::endl;
    std::cout << "            |       2.查看我的预约       |" << std::endl;
    std::cout << "            |                            |" << std::endl;
    std::cout << "            |       3.查看所有预约       |" << std::endl;
    std::cout << "            |                            |" << std::endl;
    std::cout << "            |       4.取 消 预 约        |" << std::endl;
    std::cout << "            |                            |" << std::endl;
    std::cout << "            |       0.注 销 登 录        |" << std::endl;
    std::cout << "            |                            |" << std::endl;
    std::cout << "             ----------------------------" << std::endl;
    std::cout << "输入您的选择：";
}

//获取预约信息
std::vector<Order> Student::loadOrderFile()
{
    std::vector<Order> vOrder;
    std::ifstream ifs(ORDER_FILE, std::ios::in);

    int orderId = 0;    //草泥马
    int stuId=0;
    int teaId = 0;
    int oInfo=0;        //raw
    int comId = 0;
    int wTime=0;        //sun 
    int dTime=0;          //am
    while(ifs>>orderId&&ifs >> stuId && ifs >> teaId && ifs >> oInfo && ifs >> comId && ifs >> wTime && ifs >> dTime)
    {
        Order od;
        od.orderId = orderId;
        od.stuId = stuId;
        od.teaId = teaId;
        od.oInfo = oInfo;
        od.copmId = comId;
        OrderTime ot(wTime,dTime);
        od.oTime = ot;

        vOrder.push_back(od);
    }
    return vOrder;
}

//写回预约
void Student::writeBackOrder(std::vector <Order>& vOrder)
{
    std::fstream ofs(ORDER_FILE, std::ios::out | std::ios::trunc);
    for (std::vector<Order>::iterator it = vOrder.begin(); it != vOrder.end(); it++)
    {
        ofs << it->orderId<<" "<< it->stuId << " " << it->teaId << " " << it->oInfo << " " << it->copmId << " "
            << it->oTime.weekTime << " " << it->oTime.dayTime << std::endl;
    }
}

//看一下机房
std::vector<ComputerRoom> Student::loadCompRoom()
{
    std::vector<ComputerRoom> vComp;
    std::ifstream ifs(COMPUTER_FILE, std::ios::in);
    int comId = 0;
    int capa = 0;
    int size = 0;
    while (ifs >> comId && ifs >> capa)
    {
        ComputerRoom cm(comId, capa);
        vComp.push_back(cm);
    }
    return vComp;
}

//检查重复预约
bool Student::orderIsExist(std::vector<Order> &vOrder,Order &od)
{
    for (std::vector<Order>::iterator it = vOrder.begin(); it != vOrder.end(); it++)
    {
        if ((it->oInfo == SUCCEED||it->oInfo==EXAMINE) && it->stuId == od.stuId && it->copmId == od.copmId && it->oTime == od.oTime)
        {
            return true;
        }
    }
    return false;
}

//具体预约
void Student::applyDetail(int week, int day, int comp)
{
    //获取预约单(直接从admin那里抄过来)
    std::vector<Order> vOrder = this->loadOrderFile();
    std::vector<ComputerRoom> vComp = this->loadCompRoom();
    //筛选
    int currentSize = 0;
    for (std::vector<Order>::iterator it = vOrder.begin(); it != vOrder.end(); it++)
    {
        if (it->oTime.weekTime == week && it->oTime.dayTime == day && it->copmId == comp && it->oInfo == SUCCEED)
        {
            currentSize++;
        }
    }
    //先找一下机房
    ComputerRoom* cr = NULL;
    for (std::vector<ComputerRoom>::iterator it = vComp.begin(); it != vComp.end(); it++)
    {
        if (comp== it->m_ComId)
        {
            cr = &(*it);
            break;
        }
    }
    if (cr == NULL)//没找到机房
    {
        std::cout << "机房不存在！\n";
        return;
    }
    //判断是否已满、重复
    if (currentSize >= cr->m_MaxCapacity)//满了
    {
        std::cout << "当前时段当前机房已预约满了，请更换时段或机房,";
        return;
    }
    //没满,检测是否重复,先创建一个草稿状态的订单
    Order newOrder;
    newOrder.orderId = (int)(vOrder.size()) + 1;
    newOrder.copmId = comp;
    newOrder.stuId = this->m_Id;
    //老师不加,默认为0
    newOrder.teaId = 0;
    newOrder.oTime.weekTime = week;
    newOrder.oTime.dayTime = day;
    newOrder.oInfo = RAW;
    
    if (orderIsExist(vOrder, newOrder))
    {
        std::cout << "请勿重复预约！\n";
        return;
    }
    //不重复，可以加
    newOrder.oInfo = EXAMINE;
    vOrder.push_back(newOrder);
    std::cout << "预约记录添加成功！";
    //写回数据
    this->writeBackOrder(vOrder);
    return;
    
}

//申请预约
void Student::applyOrder()
{
    //先获取所有预约(先来后到，不排序),顺便看一下机房
    std::vector<Order> vOrder= this->loadOrderFile();
    std::vector<ComputerRoom>vComp = this->loadCompRoom();

    //输出机房信息(为了方便，不做展示了，直接进预约)
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
    std::cout << "请选择机房号:\n";
    //打印一下机房号
    for (std::vector<ComputerRoom>::iterator it = vComp.begin(); it != vComp.end(); it++)
    {
        std::cout << it->m_ComId << "  ";
    }
    std::cout << "\n";
    int comSelect = 0;
    bool comOK = false;
    while (1)
    {
        std::cin >> comSelect;
        for (std::vector<ComputerRoom>::iterator it = vComp.begin(); it != vComp.end(); it++)
        {
            if (comSelect != it->m_ComId)
            {
                continue;
            }
            comOK = true;
            break;
        }
        break;
    }
    this->applyDetail(weekSelect, daySelect, comSelect);
}

//查看我的预约
void Student::showMyOrder()
{
    std::vector<Order> vOrder= this->loadOrderFile();
    //筛选
    std::vector<Order> vSubOrder;
    int currentSize = 0;
    for (std::vector<Order>::iterator it = vOrder.begin(); it != vOrder.end(); it++)
    {
        if (it->stuId == this->m_Id&&it->oInfo==SUCCEED)
            vSubOrder.push_back(*it);
    }
    //展示
    if (vSubOrder.size() == 0)
    {
        std::cout << "当前无通过的预约！\n";
        return;
    }
    else
    {            
        std::cout << "\t预约号\t机房号\t预约时段\t预约状态\n";
        for (std::vector<Order>::iterator it = vSubOrder.begin(); it != vSubOrder.end(); it++)
        {
            std::string timeStr = getTimeStr(it->oTime.weekTime,it->oTime.dayTime);
            std::string infoStr = getInfoStr(it->oInfo);
            std::cout <<"\t"<<it->orderId <<"\t"<<it->copmId << "\t" << timeStr << "\t" << infoStr << "\n";
        }
    }
}

//查看所有预约
void Student::showAllOrder()
{
    std::vector<Order> vOrder = this->loadOrderFile();
    //筛选
    std::vector<Order> vSubOrder;
    int currentSize = 0;
    for (std::vector<Order>::iterator it = vOrder.begin(); it != vOrder.end(); it++)
    {
        if (it->stuId == this->m_Id)
            vSubOrder.push_back(*it);
    }
    if (vSubOrder.size()==0)//无记录
    {
        std::cout << "当前没有任何记录！\n";
    }
    else
    {
        std::cout << "\t预约号\t机房号\t预约时段\t预约状态\n";
        for (std::vector<Order>::iterator it = vSubOrder.begin(); it != vSubOrder.end(); it++)
        {
            std::string timeStr = getTimeStr(it->oTime.weekTime, it->oTime.dayTime);
            std::string infoStr = getInfoStr(it->oInfo);
            std::cout << "\t" << it->orderId << "\t" << it->copmId << "\t" << timeStr << "\t" << infoStr << "\n";
        }
    }
}

//取消预约
void Student::cancelOrder()
{
    std::vector<Order> vOrder = this->loadOrderFile();
    //筛选
    std::vector<Order> vSubOrder;
    int currentSize = 0;
    for (std::vector<Order>::iterator it = vOrder.begin(); it != vOrder.end(); it++)
    {
        if (it->stuId == this->m_Id && it->oInfo == EXAMINE)//只有审核中的记录可以取消
            vSubOrder.push_back(*it);
    }
    if (vSubOrder.size() == 0)//无记录
    {
        std::cout << "当前无正在审核的预约记录！\n";
    }
    else//有记录
    {
        std::cout << "-------------------\n";
        std::cout << "\t预约号\t预约时段\t预约状态\n";
        int examineSelect = 0;
        for (std::vector<Order>::iterator it = vSubOrder.begin(); it != vSubOrder.end(); it++)
        {
            std::string timeStr = getTimeStr(it->oTime.weekTime, it->oTime.dayTime);
            std::string infoStr = getInfoStr(it->oInfo);
            std::cout << "\t" << it->orderId << "\t" << timeStr << "\t" << infoStr << "\n";
        }
        std::cout << "-------------------\n";
        std::cout << "请选择一条记录：\n";
        std::cin >> examineSelect;
        //选好了，改状态
        for (std::vector<Order>::iterator it = vOrder.begin(); it != vOrder.end(); it++)
        {
            if (it->orderId == examineSelect)
            {
                it->oInfo = CANCEL;
                std::cout << "已取消！\n";
                this->writeBackOrder(vOrder);
                return;
            }
        }
        std::cout << "订单号有误！\n";
        return;
    }
}
