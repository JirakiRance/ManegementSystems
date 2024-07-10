#include"teacher.h"

//默认构造
Teacher::Teacher()
{
	this->m_Id = 0;
}
//有参构造(职工号、姓名、密码)
Teacher::Teacher(int empId, std::string name, std::string pwd)
{
	this->m_Id = empId;
	this->m_Name = name;
	this->m_Password = pwd;
}

//菜单
void Teacher::openMenu()
{
	system("cls");
	std::cout << "欢迎老师 " << this->m_Name << " 登录！\n\n";

    std::cout << "请选择您的操作" << std::endl;
    std::cout << "             ----------------------------" << std::endl;
    std::cout << "            |                            |" << std::endl;
    std::cout << "            |       1.查看所有预约       |" << std::endl;
    std::cout << "            |                            |" << std::endl;
    std::cout << "            |       2.审 核 预 约        |" << std::endl;
    std::cout << "            |                            |" << std::endl;
    std::cout << "            |       0.注 销 登 录        |" << std::endl;
    std::cout << "            |                            |" << std::endl;
    std::cout << "             ----------------------------" << std::endl;
    std::cout << "输入您的选择：";
}

//字符串处理
std::string Teacher::getTimeStr(int week, int day)
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

std::string Teacher::getInfoStr(int info)
{
    std::string str;
    switch (info)
    {
    case RAW:
        str = "草稿";
        break;
    case EXAMINE:
        str = "待审核";
        break;
    case CANCEL:
        str = "学生取消";
        break;
    case FAIL:
        str = "未通过";
        break;
    case SUCCEED:
        str = "通过";
        break;
    default:
        break;
    }
    return str;
}

//获取预约信息
std::vector<Order> Teacher::loadOrderFile()
{
    std::vector<Order> vOrder;
    std::ifstream ifs(ORDER_FILE, std::ios::in);

    int orderId = 0;    //草泥马
    int stuId = 0;
    int teaId = 0;
    int oInfo = 0;        //raw
    int comId = 0;
    int wTime = 0;        //sun 
    int dTime = 0;          //am
    while (ifs >> orderId && ifs >> stuId && ifs >> teaId && ifs >> oInfo && ifs >> comId && ifs >> wTime && ifs >> dTime)
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

//写回预约
void Teacher::writeBackOrder(std::vector <Order>& vOrder)
{
    std::fstream ofs(ORDER_FILE, std::ios::out | std::ios::trunc);
    for (std::vector<Order>::iterator it = vOrder.begin(); it != vOrder.end(); it++)
    {
        ofs << it->orderId << " " << it->stuId << " " << it->teaId << " " << it->oInfo << " " << it->copmId << " "
            << it->oTime.weekTime << " " << it->oTime.dayTime << std::endl;
    }
}

//查看所有预约
void Teacher::showAllOrder()
{
    std::vector<Order> vOrder = this->loadOrderFile();
    
    std::cout << "----------------------------------------------------------------------------------\n";
    std::cout << "\t预约号\t机房号\t学生学号\t审核职工号\t预约时段\t预约状态\n\n";
    for (std::vector<Order>::iterator it = vOrder.begin(); it != vOrder.end(); it++)
    {
        std::string timeStr = getTimeStr(it->oTime.weekTime, it->oTime.dayTime);
        std::string infoStr = getInfoStr(it->oInfo);
        std::cout << "\t" << it->orderId <<"\t"<<it->copmId << "\t" << it->stuId << "\t\t" << it->teaId << "\t\t"
                  << timeStr << "\t" << infoStr << "\n";
    }
}

//审核预约
void Teacher::validOrder()
{
    std::vector<Order> vOrder = this->loadOrderFile();
    //筛选
    std::vector<Order> vSubOrder;
    for (std::vector<Order>::iterator it = vOrder.begin(); it != vOrder.end(); it++)
    {
        if (it->oInfo == EXAMINE)//只有待审核的记录可以取消
            vSubOrder.push_back(*it);
    }
    if (vSubOrder.size() == 0)//没记录
    {
        std::cout << "当前无记录！\n";
        return;
    }
    else
    {
        std::cout << "-------------------\n";
        std::cout << "\t预约号\t学生学号\t预约时段\t预约状态\n";
        int examineOrderSelect = 0;//选择订单号
        int passSelect = 0;//判断通不通过，排除杂项
        for (std::vector<Order>::iterator it = vSubOrder.begin(); it != vSubOrder.end(); it++)
        {
            std::string timeStr = getTimeStr(it->oTime.weekTime, it->oTime.dayTime);
            std::string infoStr = getInfoStr(it->oInfo);
            std::cout << "\t" << it->orderId << "\t" << it->stuId << "\t\t" << timeStr << "\t" << infoStr << "\n";
        }
        std::cout << "-------------------\n";
        std::cout << "请选择一条记录：\n";
        std::cin >> examineOrderSelect;
        //判断记录合法性
        bool selectOrderOk = false;//判断Order订单号合不合法
        for (auto& od : vSubOrder)
        {
            if (od.orderId== examineOrderSelect)
            {
                selectOrderOk = true;
            }
        }
        if (!selectOrderOk)
        {
            std::cout << "不正确的记录号！\n";
            return;
        }
        std::cout << "是否通过？\n1.通过\n2.不通过\n";
        while (1)
        {
            std::cin >> passSelect;
            if (passSelect != 1 && passSelect != 2)
                continue;
            break;
        }
        //选好了，改状态
        for (std::vector<Order>::iterator it = vOrder.begin(); it != vOrder.end(); it++)
        {
            if (it->orderId == examineOrderSelect)
            {
                if (passSelect == 1)
                {
                    it->teaId = this->m_Id;
                    it->oInfo = SUCCEED;
                }
                else
                {
                    it->teaId = this->m_Id;
                    it->oInfo = FAIL;
                }
                std::cout << "操作成功！\n";
                this->writeBackOrder(vOrder);
                return;
            }
        }
        std::cout << "订单号有误！\n";
        return;
    }
}