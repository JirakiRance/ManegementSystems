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
		cout << "����������ѡ��"; cin >> choice;

		switch (choice)
		{
		case 0://�˳�ϵͳ
			wm.exitSystem();
			break;
		case 1://����ְ��
			wm.addWorker();
			break;
		case 2://��ʾְ��
			wm.showWorker();
			break;
		case 3://ɾ��ְ��
			wm.deleteWorker();
			break;
		case 4://�޸�ְ��
			wm.modefyWorker();
			break;
		case 5://����ְ��
			wm.findWorker();
			break;
		case 6://����ְ��
			wm.Sort();
			break;
		case 7://����ĵ�
			wm.Delete_All();
			break;
		default:
			system("cls");//����
			break;
		}
	}
 
	system("pause");
	return 0;
}