


/*
预约信息格式：

订单号		预约人		审核人		预约状态		预约机房	预约天		预约时段
1			zhang		li			edxamine		1			mon			am
(草拟吗)	(学号)		(职工号)	(状态名)		(机房号)	(名)		(时段名)

info类型：
{raw,examine,cancel,fail,succeed};//初始状态，审核中，学生取消，审核不过，审核通过
weekTime类型：
{sun,mon,tue,wed,thr,fri,sat};
dayTime类型：
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
	int weekTime;//周几
	int dayTime;//上下午
};


class Order
{
	//几个属性：预约时间，预约机房，预约人，审核人，预约状态,还有草拟吗的订单号！！
public:
	bool operator==(Order &od)
	{
		return this->orderId == od.orderId;
	}
public:	
	int orderId;		//草泥马
	int copmId;			//机房号
	int stuId;			//学生学号
	int teaId;			//老师职工号
	int oInfo;			//预约状态
	OrderTime oTime;	//预约时间
};