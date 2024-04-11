//#define DEBUG

#include"speechManeger.h"
#include"speaker.h"



int main()
{
	//创建流程管理类
	speechManeger spchmager;
	//创建系统时间随机数种子
	srand((unsigned int)time(NULL));
	
	while (1)
	{
		int user_Select = -1;//用户选择

		#ifdef DEBUG
		cout << user_Select << endl;
		#endif // DEBUG

		//展示菜单
		spchmager.show_Menu();
		
		//提示用户输入选择
		cout << "请输入您的选择：" << endl;
		cin >> user_Select;

		switch (user_Select)
		{
		case 0://退出系统
			spchmager.exit_speechManeger();
			break;
		case 1://开始比赛
			{
				spchmager.start_Speech();
				//更新属性
				spchmager.initSpeechContainers();
				spchmager.init_Speaker();
				spchmager.load_Record();
			}
			break;
		case 2://查看往届记录
			spchmager.see_Record();
			break;
		case 3://清空文档
			spchmager.clear_List();
			break;

		default://清屏
			system("cls");
			continue;
		}


		//一次功能结束，提示按任意键继续并清屏
		system("pause");
		system("cls");
	}

	system("pause");
	return 0;
}