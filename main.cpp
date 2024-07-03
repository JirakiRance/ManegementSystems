#include"MainMenu.h"

int main()
{  
    while (1)
    {
        MainMenu mainMenu;
        mainMenu.showMainMenu();
        //输入选择
        char usrSelect_MainMenu = '0';
        std::cout << "输入您的选择：";        
        while (1)
        {
            std::cin >> usrSelect_MainMenu;
            if ((usrSelect_MainMenu - '0') < 0 || (usrSelect_MainMenu - '0') > 3)
            {
                continue;
            }
            break;
        }

        if (usrSelect_MainMenu == '0')//exit
        {
            mainMenu.exitSystem();
        }
        else if (usrSelect_MainMenu == '1')//student
        {
            mainMenu.loginIn(STUDENT_FILE, STUDENT);
        }
        else if (usrSelect_MainMenu == '2')//teacher
        {
            mainMenu.loginIn(TEACHER_FILE, TEACHER);
        }
        else if (usrSelect_MainMenu == '3')//admin
        {
            mainMenu.loginIn(ADMIN_FILE, ADMIN);            
        }
        system("cls");
    }
    system("pause");
    return 0;
}