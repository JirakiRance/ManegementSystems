#include"WorkerManeger.h"
#include"Worker.h"
#include"Employee.h"

int main()
{
	WorkerManeger wm;
	int choice = 0;
	
	while (true)
	{
		wm.showMenu();
		cout << "请输入您的选择："; cin >> choice;

		switch (choice)
		{
		case 0://退出系统
			wm.exitSystem();
			break;
		case 1://增加职工
			wm.addWorker();
			break;
		case 2://显示职工
			wm.showWorker();
			break;
		case 3://删除职工
			wm.deleteWorker();
			break;
		case 4://修改职工
			wm.modefyWorker();
			break;
		case 5://查找职工
			wm.findWorker();
			break;
		case 6://排序职工
			wm.Sort();
			break;
		case 7://清空文档
			wm.Delete_All();
			break;
		default:
			system("cls");//清屏
			break;
		}
	}
 
	system("pause");
	return 0;
}