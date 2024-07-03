#include"student.h"

//Ĭ�Ϲ���
Student::Student() 
{
	this->m_Id = 0;
}
//�вΣ�������ѧ�š����룩
Student::Student(int stuId, std::string name, std::string password)
{
	this->m_Id = stuId;
	this->m_Name = name;
	this->m_Password = password;
}

//�ַ�������
std::string Student::getTimeStr(int week, int day)
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

std::string Student::getInfoStr(int info)
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
        str = "��ȡ��";
        break;
    case FAIL:
        str = "���δͨ��";
        break;
    case SUCCEED:
        str = "���ͨ����";
        break;
    default:
        break;
    }
    return str;
}

//�˵�
void Student::openMenu()
{
	system("cls");
	std::cout << "��ӭ " << this->m_Name << " ��¼��\n\n";

    std::cout << "��ѡ�����Ĳ���" << std::endl;
    std::cout << "             ----------------------------" << std::endl;
    std::cout << "            |                            |" << std::endl;
    std::cout << "            |       1.�� �� Ԥ Լ        |" << std::endl;
    std::cout << "            |                            |" << std::endl;
    std::cout << "            |       2.�鿴�ҵ�ԤԼ       |" << std::endl;
    std::cout << "            |                            |" << std::endl;
    std::cout << "            |       3.�鿴����ԤԼ       |" << std::endl;
    std::cout << "            |                            |" << std::endl;
    std::cout << "            |       4.ȡ �� Ԥ Լ        |" << std::endl;
    std::cout << "            |                            |" << std::endl;
    std::cout << "            |       0.ע �� �� ¼        |" << std::endl;
    std::cout << "            |                            |" << std::endl;
    std::cout << "             ----------------------------" << std::endl;
    std::cout << "��������ѡ��";
}

//��ȡԤԼ��Ϣ
std::vector<Order> Student::loadOrderFile()
{
    std::vector<Order> vOrder;
    std::ifstream ifs(ORDER_FILE, std::ios::in);

    int orderId = 0;    //������
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

//д��ԤԼ
void Student::writeBackOrder(std::vector <Order>& vOrder)
{
    std::fstream ofs(ORDER_FILE, std::ios::out | std::ios::trunc);
    for (std::vector<Order>::iterator it = vOrder.begin(); it != vOrder.end(); it++)
    {
        ofs << it->orderId<<" "<< it->stuId << " " << it->teaId << " " << it->oInfo << " " << it->copmId << " "
            << it->oTime.weekTime << " " << it->oTime.dayTime << std::endl;
    }
}

//��һ�»���
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

//����ظ�ԤԼ
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

//����ԤԼ
void Student::applyDetail(int week, int day, int comp)
{
    //��ȡԤԼ��(ֱ�Ӵ�admin���ﳭ����)
    std::vector<Order> vOrder = this->loadOrderFile();
    std::vector<ComputerRoom> vComp = this->loadCompRoom();
    //ɸѡ
    int currentSize = 0;
    for (std::vector<Order>::iterator it = vOrder.begin(); it != vOrder.end(); it++)
    {
        if (it->oTime.weekTime == week && it->oTime.dayTime == day && it->copmId == comp && it->oInfo == SUCCEED)
        {
            currentSize++;
        }
    }
    //����һ�»���
    ComputerRoom* cr = NULL;
    for (std::vector<ComputerRoom>::iterator it = vComp.begin(); it != vComp.end(); it++)
    {
        if (comp== it->m_ComId)
        {
            cr = &(*it);
            break;
        }
    }
    if (cr == NULL)//û�ҵ�����
    {
        std::cout << "���������ڣ�\n";
        return;
    }
    //�ж��Ƿ��������ظ�
    if (currentSize >= cr->m_MaxCapacity)//����
    {
        std::cout << "��ǰʱ�ε�ǰ������ԤԼ���ˣ������ʱ�λ����,";
        return;
    }
    //û��,����Ƿ��ظ�,�ȴ���һ���ݸ�״̬�Ķ���
    Order newOrder;
    newOrder.orderId = (int)(vOrder.size()) + 1;
    newOrder.copmId = comp;
    newOrder.stuId = this->m_Id;
    //��ʦ����,Ĭ��Ϊ0
    newOrder.teaId = 0;
    newOrder.oTime.weekTime = week;
    newOrder.oTime.dayTime = day;
    newOrder.oInfo = RAW;
    
    if (orderIsExist(vOrder, newOrder))
    {
        std::cout << "�����ظ�ԤԼ��\n";
        return;
    }
    //���ظ������Լ�
    newOrder.oInfo = EXAMINE;
    vOrder.push_back(newOrder);
    std::cout << "ԤԼ��¼��ӳɹ���";
    //д������
    this->writeBackOrder(vOrder);
    return;
    
}

//����ԤԼ
void Student::applyOrder()
{
    //�Ȼ�ȡ����ԤԼ(�����󵽣�������),˳�㿴һ�»���
    std::vector<Order> vOrder= this->loadOrderFile();
    std::vector<ComputerRoom>vComp = this->loadCompRoom();

    //���������Ϣ(Ϊ�˷��㣬����չʾ�ˣ�ֱ�ӽ�ԤԼ)
    std::cout << "��ѡ���ܼ���(0-sun,1-mon...)\n";
    int weekSelect = 0;
    while (1)
    {
        std::cin >> weekSelect;
        if (weekSelect != 0 && weekSelect != 1 && weekSelect != 2 && weekSelect != 3 && weekSelect != 4 && weekSelect != 5 && weekSelect != 6)
            continue;
        break;
    }
    std::cout << "��ѡ��ʱ�Σ�(0-am,1-pm)\n";
    int daySelect = 0;
    while (1)
    {
        std::cin >> daySelect;
        if (daySelect != 0 && daySelect != 1)
            continue;
        break;
    }
    std::cout << "��ѡ�������:\n";
    //��ӡһ�»�����
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

//�鿴�ҵ�ԤԼ
void Student::showMyOrder()
{
    std::vector<Order> vOrder= this->loadOrderFile();
    //ɸѡ
    std::vector<Order> vSubOrder;
    int currentSize = 0;
    for (std::vector<Order>::iterator it = vOrder.begin(); it != vOrder.end(); it++)
    {
        if (it->stuId == this->m_Id&&it->oInfo==SUCCEED)
            vSubOrder.push_back(*it);
    }
    //չʾ
    if (vSubOrder.size() == 0)
    {
        std::cout << "��ǰ��ͨ����ԤԼ��\n";
        return;
    }
    else
    {            
        std::cout << "\tԤԼ��\t������\tԤԼʱ��\tԤԼ״̬\n";
        for (std::vector<Order>::iterator it = vSubOrder.begin(); it != vSubOrder.end(); it++)
        {
            std::string timeStr = getTimeStr(it->oTime.weekTime,it->oTime.dayTime);
            std::string infoStr = getInfoStr(it->oInfo);
            std::cout <<"\t"<<it->orderId <<"\t"<<it->copmId << "\t" << timeStr << "\t" << infoStr << "\n";
        }
    }
}

//�鿴����ԤԼ
void Student::showAllOrder()
{
    std::vector<Order> vOrder = this->loadOrderFile();
    //ɸѡ
    std::vector<Order> vSubOrder;
    int currentSize = 0;
    for (std::vector<Order>::iterator it = vOrder.begin(); it != vOrder.end(); it++)
    {
        if (it->stuId == this->m_Id)
            vSubOrder.push_back(*it);
    }
    if (vSubOrder.size()==0)//�޼�¼
    {
        std::cout << "��ǰû���κμ�¼��\n";
    }
    else
    {
        std::cout << "\tԤԼ��\t������\tԤԼʱ��\tԤԼ״̬\n";
        for (std::vector<Order>::iterator it = vSubOrder.begin(); it != vSubOrder.end(); it++)
        {
            std::string timeStr = getTimeStr(it->oTime.weekTime, it->oTime.dayTime);
            std::string infoStr = getInfoStr(it->oInfo);
            std::cout << "\t" << it->orderId << "\t" << it->copmId << "\t" << timeStr << "\t" << infoStr << "\n";
        }
    }
}

//ȡ��ԤԼ
void Student::cancelOrder()
{
    std::vector<Order> vOrder = this->loadOrderFile();
    //ɸѡ
    std::vector<Order> vSubOrder;
    int currentSize = 0;
    for (std::vector<Order>::iterator it = vOrder.begin(); it != vOrder.end(); it++)
    {
        if (it->stuId == this->m_Id && it->oInfo == EXAMINE)//ֻ������еļ�¼����ȡ��
            vSubOrder.push_back(*it);
    }
    if (vSubOrder.size() == 0)//�޼�¼
    {
        std::cout << "��ǰ��������˵�ԤԼ��¼��\n";
    }
    else//�м�¼
    {
        std::cout << "-------------------\n";
        std::cout << "\tԤԼ��\tԤԼʱ��\tԤԼ״̬\n";
        int examineSelect = 0;
        for (std::vector<Order>::iterator it = vSubOrder.begin(); it != vSubOrder.end(); it++)
        {
            std::string timeStr = getTimeStr(it->oTime.weekTime, it->oTime.dayTime);
            std::string infoStr = getInfoStr(it->oInfo);
            std::cout << "\t" << it->orderId << "\t" << timeStr << "\t" << infoStr << "\n";
        }
        std::cout << "-------------------\n";
        std::cout << "��ѡ��һ����¼��\n";
        std::cin >> examineSelect;
        //ѡ���ˣ���״̬
        for (std::vector<Order>::iterator it = vOrder.begin(); it != vOrder.end(); it++)
        {
            if (it->orderId == examineSelect)
            {
                it->oInfo = CANCEL;
                std::cout << "��ȡ����\n";
                this->writeBackOrder(vOrder);
                return;
            }
        }
        std::cout << "����������\n";
        return;
    }
}
