#include <stdio.h>
#include <string.h>
#include "course.h"
#include "student.h"

int login(void);

int main(void)
{
    int manger_menu_ret, stu_menu_ret, type, login_ret;
    student *head_stu = NULL, *p_student = NULL;
    course *head_cour = NULL;
    head_stu = create_link_stu();
    head_cour = create_link_cour();
    while (1)
    {
		type = login();
        if (type == 0)
		{
			printf("\n您已退出选课系统!\n欢迎下次使用!\n\n");
            return 0;
		}
        else if (type == 1)
        {
            login_ret = manger_login();
			if (login_ret == 0)
				return 0;
            while (1)
            {
            	manger_menu_ret = manger_menu();
				if (manger_menu_ret == 0)
					break;
                switch (manger_menu_ret)
                {
                    case 1:
                        course_add(head_cour);break;
                    case 2:
                        course_delete(head_cour, head_stu);break;
                    case 3:
                        course_look(head_cour, head_stu);break;
                    case 4:
                        course_modify(head_cour, head_stu);break;
                    case 5:
                        student_add(head_stu);break;
                    case 6:
                        student_delete(head_stu, head_cour);break;
                    case 7:
                        student_look(head_stu);break;
                    case 8:
                        student_modify(head_stu);break;
                    case 9:
                        student_showall(head_stu);break;
                    case 10:
                        course_showall(head_cour);break;
                    default:
                        printf("########输入错误########\n");break;
                }
            }
        }
        else if (type == 2)
        {
            p_student=student_login(head_stu);
			if (p_student == NULL)
				continue;
            while (1)
            {
                stu_menu_ret = student_menu();
				if (stu_menu_ret == 0)
					break;
                switch(stu_menu_ret)
                {
                    case 1:
                        student_showone(p_student);
                        printf("输入回车键继续\n");
                        getchar();
                        getchar();
                        break;
                    case 2:
                        choose_course(p_student, head_cour);
                        student_update(head_stu);
                        break;
                    default:
                        printf("########输入错误########\n");break;
                }
            }
        }
    }
    return 0;
}

int login(void)
{
    int type = -1;
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~欢迎使用选课管理系统~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    while (type != 0 && type != 1 && type != 2)
    {
		printf("\n\t\t\t---------请选择登录类型---------\n");
		printf("\t\t\t\t[0]退出\n");
		printf("\t\t\t\t[1]管理员\n");
		printf("\t\t\t\t[2]学生\n");
		printf("\t\t\t--------------------------------\n\n");
        scanf("%d", &type);
        if (type != 0 && type != 1 && type != 2)
        {
            printf("输入错误!\n\n");
        }
    }
    return type;
}
