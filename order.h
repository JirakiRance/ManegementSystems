


/*
ԤԼ��Ϣ��ʽ��

������		ԤԼ��		�����		ԤԼ״̬		ԤԼ����	ԤԼ��		ԤԼʱ��
1			zhang		li			edxamine		1			mon			am
(������)	(ѧ��)		(ְ����)	(״̬��)		(������)	(��)		(ʱ����)

info���ͣ�
{raw,examine,cancel,fail,succeed};//��ʼ״̬������У�ѧ��ȡ������˲��������ͨ��
weekTime���ͣ�
{sun,mon,tue,wed,thr,fri,sat};
dayTime���ͣ�
{am,pm};
*/


#pragma once
#include"globalFile.h"

class OrderTime
{
public:
	OrderTime() 
	{
		weekTime = 0;
		dayTime = 0;
	}
	OrderTime(int wti,int dti)
	{
		weekTime = wti;
		dayTime = dti;
	}
	bool operator==(OrderTime &ot)
	{
		return (this->weekTime == ot.weekTime && this->dayTime == ot.dayTime);
	}
public:
	int weekTime;//�ܼ�
	int dayTime;//������
};


class Order
{
	//�������ԣ�ԤԼʱ�䣬ԤԼ������ԤԼ�ˣ�����ˣ�ԤԼ״̬,���в�����Ķ����ţ���
public:
	bool operator==(Order &od)
	{
		return this->orderId == od.orderId;
	}
public:	
	int orderId;		//������
	int copmId;			//������
	int stuId;			//ѧ��ѧ��
	int teaId;			//��ʦְ����
	int oInfo;			//ԤԼ״̬
	OrderTime oTime;	//ԤԼʱ��
};