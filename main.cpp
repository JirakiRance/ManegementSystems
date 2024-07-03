#include<iostream>
#include"shuffler.h"

int main()
{
	std::cout << "请键入最大随机数，输入0退出" << std::endl << std::endl;

	int usrNum = 0;	//选择最大随机数
	std::cin >> usrNum;
	if (usrNum<1)
	{
		std::cout << "进程已结束，欢迎下次使用Ciallo～(∠·ω< )⌒ ★" << std::endl;
		system("pause");
		exit(0);
	}
	std::cout << "您已选择最大随机数为" << usrNum << ","<<"键入enter以继续，输入0退出" << std::endl;
	system("pause");
	std::cout << std::endl;

	char* usrAction = new char[128];	//用户操作
	srand((unsigned)time(NULL));		//时间种子
	std::cin.getline(usrAction, 128);
	while (*usrAction != '0')
	{
		Jshuffler jr(usrNum);
		jr.doShuffle();
		jr.showOrder();

		std::cin.getline(usrAction, 128);
	}

	delete[] usrAction;
	std::cout << "进程已结束，欢迎下次使用Ciallo～(∠·ω< )⌒ ★" << std::endl;
	system("pause");

	return 0;
}
