//#define DEBUG

#include"speechManeger.h"
#include"speaker.h"



int main()
{
	//�������̹�����
	speechManeger spchmager;
	//����ϵͳʱ�����������
	srand((unsigned int)time(NULL));
	
	while (1)
	{
		int user_Select = -1;//�û�ѡ��

		#ifdef DEBUG
		cout << user_Select << endl;
		#endif // DEBUG

		//չʾ�˵�
		spchmager.show_Menu();
		
		//��ʾ�û�����ѡ��
		cout << "����������ѡ��" << endl;
		cin >> user_Select;

		switch (user_Select)
		{
		case 0://�˳�ϵͳ
			spchmager.exit_speechManeger();
			break;
		case 1://��ʼ����
			{
				spchmager.start_Speech();
				//��������
				spchmager.initSpeechContainers();
				spchmager.init_Speaker();
				spchmager.load_Record();
			}
			break;
		case 2://�鿴�����¼
			spchmager.see_Record();
			break;
		case 3://����ĵ�
			spchmager.clear_List();
			break;

		default://����
			system("cls");
			continue;
		}


		//һ�ι��ܽ�������ʾ�����������������
		system("pause");
		system("cls");
	}

	system("pause");
	return 0;
}