#include"teacher.h"

//Ĭ�Ϲ���
Teacher::Teacher()
{
	this->m_Id = 0;
}
//�вι���(ְ���š�����������)
Teacher::Teacher(int empId, std::string name, std::string pwd)
{
	this->m_Id = empId;
	this->m_Name = name;
	this->m_Password = pwd;
}

//�˵�
void Teacher::openMenu()
{
	system("cls");
	std::cout << "��ӭ��ʦ " << this->m_Name << " ��¼��\n\n";

    std::cout << "��ѡ�����Ĳ���" << std::endl;
    std::cout << "             ----------------------------" << std::endl;
    std::cout << "            |                            |" << std::endl;
    std::cout << "            |       1.�鿴����ԤԼ       |" << std::endl;
    std::cout << "            |                            |" << std::endl;
    std::cout << "            |       2.�� �� Ԥ Լ        |" << std::endl;
    std::cout << "            |                            |" << std::endl;
    std::cout << "            |       0.ע �� �� ¼        |" << std::endl;
    std::cout << "            |                            |" << std::endl;
    std::cout << "             ----------------------------" << std::endl;
    std::cout << "��������ѡ��";
}

//�ַ�������
std::string Teacher::getTimeStr(int week, int day)
{
    std::string str;
    switch (week)
    {
    case SUN:
        str = "����";
        break;
    case MON:
        str = "��һ";
        break;
    case TUE:
        str = "�ܶ�";
        break;
    case WED:
        str = "����";
        break;
    case THR:
        str = "����";
        break;
    case FRI:
        str = "����";
        break;
    case SAT:
        str = "����";
        break;
    default:
        break;
    }
    if (day == AM)
    {
        str += "����";
    }
    else
    {
        str += "����";
    }
    return str;
}

std::string Teacher::getInfoStr(int info)
{
    std::string str;
    switch (info)
    {
    case RAW:
        str = "�ݸ�";
        break;
    case EXAMINE:
        str = "�����";
        break;
    case CANCEL:
        str = "ѧ��ȡ��";
        break;
    case FAIL:
        str = "δͨ��";
        break;
    case SUCCEED:
        str = "ͨ��";
        break;
    default:
        break;
    }
    return str;
}

//��ȡԤԼ��Ϣ
std::vector<Order> Teacher::loadOrderFile()
{
    std::vector<Order> vOrder;
    std::ifstream ifs(ORDER_FILE, std::ios::in);

    int orderId = 0;    //������
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

//д��ԤԼ
void Teacher::writeBackOrder(std::vector <Order>& vOrder)
{
    std::fstream ofs(ORDER_FILE, std::ios::out | std::ios::trunc);
    for (std::vector<Order>::iterator it = vOrder.begin(); it != vOrder.end(); it++)
    {
        ofs << it->orderId << " " << it->stuId << " " << it->teaId << " " << it->oInfo << " " << it->copmId << " "
            << it->oTime.weekTime << " " << it->oTime.dayTime << std::endl;
    }
}

//�鿴����ԤԼ
void Teacher::showAllOrder()
{
    std::vector<Order> vOrder = this->loadOrderFile();
    
    std::cout << "----------------------------------------------------------------------------------\n";
    std::cout << "\tԤԼ��\t������\tѧ��ѧ��\t���ְ����\tԤԼʱ��\tԤԼ״̬\n\n";
    for (std::vector<Order>::iterator it = vOrder.begin(); it != vOrder.end(); it++)
    {
        std::string timeStr = getTimeStr(it->oTime.weekTime, it->oTime.dayTime);
        std::string infoStr = getInfoStr(it->oInfo);
        std::cout << "\t" << it->orderId <<"\t"<<it->copmId << "\t" << it->stuId << "\t\t" << it->teaId << "\t\t"
                  << timeStr << "\t" << infoStr << "\n";
    }
}

//���ԤԼ
void Teacher::validOrder()
{
    std::vector<Order> vOrder = this->loadOrderFile();
    //ɸѡ
    std::vector<Order> vSubOrder;
    for (std::vector<Order>::iterator it = vOrder.begin(); it != vOrder.end(); it++)
    {
        if (it->oInfo == EXAMINE)//ֻ�д���˵ļ�¼����ȡ��
            vSubOrder.push_back(*it);
    }
    if (vSubOrder.size() == 0)//û��¼
    {
        std::cout << "��ǰ�޼�¼��\n";
        return;
    }
    else
    {
        std::cout << "-------------------\n";
        std::cout << "\tԤԼ��\tѧ��ѧ��\tԤԼʱ��\tԤԼ״̬\n";
        int examineOrderSelect = 0;//ѡ�񶩵���
        int passSelect = 0;//�ж�ͨ��ͨ�����ų�����
        for (std::vector<Order>::iterator it = vSubOrder.begin(); it != vSubOrder.end(); it++)
        {
            std::string timeStr = getTimeStr(it->oTime.weekTime, it->oTime.dayTime);
            std::string infoStr = getInfoStr(it->oInfo);
            std::cout << "\t" << it->orderId << "\t" << it->stuId << "\t\t" << timeStr << "\t" << infoStr << "\n";
        }
        std::cout << "-------------------\n";
        std::cout << "��ѡ��һ����¼��\n";
        std::cin >> examineOrderSelect;
        //�жϼ�¼�Ϸ���
        bool selectOrderOk = false;//�ж�Order�����źϲ��Ϸ�
        for (auto& od : vSubOrder)
        {
            if (od.orderId== examineOrderSelect)
            {
                selectOrderOk = true;
            }
        }
        if (!selectOrderOk)
        {
            std::cout << "����ȷ�ļ�¼�ţ�\n";
            return;
        }
        std::cout << "�Ƿ�ͨ����\n1.ͨ��\n2.��ͨ��\n";
        while (1)
        {
            std::cin >> passSelect;
            if (passSelect != 1 && passSelect != 2)
                continue;
            break;
        }
        //ѡ���ˣ���״̬
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
                std::cout << "�����ɹ���\n";
                this->writeBackOrder(vOrder);
                return;
            }
        }
        std::cout << "����������\n";
        return;
    }
}