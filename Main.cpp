#include"Adressbooks.h"

int main()
{
	Adressbooks abs;
	while (true)
	{
		abs.show_Menu();
		int select;
		
		//选择
		cout << "请输入您的选择：";
	FLAG_Reselect_for_Menu:
		cin >> select;

		switch (select)
		{
		case 0://退出通讯录
			cout << "欢迎您下次使用！  :-)" << endl;
			system("pause");
			exit(0);
			break;

		case 1://添加联系人
			abs.Add_Person();
			break;
		
		case 2://显示联系人
			abs.Show_Persons();
			break;
		
		case 3://删除联系人
			abs.Del_Person();
			break;
		
		case 4://查找联系人
			abs.LookUp_Person();
			break;
		
		case 5://修改联系人
			abs.Modify_Person();
			break;

		case 6://清空通讯录
			abs.Clear();
			break;
		
		default:
			goto FLAG_Reselect_for_Menu;
			break;
		}
	}
	return 0;
}