#include"Adressbooks.h"

int main()
{
	Adressbooks abs;
	while (true)
	{
		abs.show_Menu();
		int select;
		
		//ѡ��
		cout << "����������ѡ��";
	FLAG_Reselect_for_Menu:
		cin >> select;

		switch (select)
		{
		case 0://�˳�ͨѶ¼
			cout << "��ӭ���´�ʹ�ã�  :-)" << endl;
			system("pause");
			exit(0);
			break;

		case 1://�����ϵ��
			abs.Add_Person();
			break;
		
		case 2://��ʾ��ϵ��
			abs.Show_Persons();
			break;
		
		case 3://ɾ����ϵ��
			abs.Del_Person();
			break;
		
		case 4://������ϵ��
			abs.LookUp_Person();
			break;
		
		case 5://�޸���ϵ��
			abs.Modify_Person();
			break;

		case 6://���ͨѶ¼
			abs.Clear();
			break;
		
		default:
			goto FLAG_Reselect_for_Menu;
			break;
		}
	}
	return 0;
}