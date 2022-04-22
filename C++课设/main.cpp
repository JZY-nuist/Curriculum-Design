#include<iostream>
#include"library.h"
#include<windows.h>
#include<conio.h>

using namespace std;

void Main_menu(library &li);
void login(library &li, int id);
void Administer(library &li);

int main(){
	// 初始化操作 
	library li(10, 10);
	
	// 主页面 
	Main_menu(li);
	return 0;
}

void Main_menu(library &li){
	while(1){
		string temp; 
		cout<<"================================"<<endl;
		cout<<"||   欢迎来到图书馆预约系统   ||"<<endl;
		cout<<"||         1、登陆            ||"<<endl;
		cout<<"||         2、注册            ||"<<endl;
		cout<<"||               管理员？请按3||"<<endl;
		cout<<"================================"<<endl;
		cout<<"请选择你所需要的服务:";
		cin>>temp;
		if(temp == "1"){
			system("cls");
			string n, i;
			cout<<"请输入您的姓名和学号"<<endl;
			cout<<"姓名:";
			cin>>n;
			cout<<"学号:";
			cin>>i;
			Person ptemp(n, i); 
			if(li.get_number_id(ptemp) == -1){
				cout<<"\n没有此账号？请注册...\n登陆失败..."<<endl;
				cout<<"即将自动退出"<<endl;
				Sleep(1000);
				system("cls");
				continue;
			}
			else if(li.get_number_id(ptemp) == -2){
				cout<<"\n姓名/密码错误？\n登陆失败..."<<endl;
				cout<<"即将自动退出"<<endl;
				Sleep(1000);
				system("cls");
				continue;
			}
			cout<<"\n登陆成功..."<<endl;
			int id = li.get_number_id(ptemp);
			Sleep(1000);
			system("cls");
			login(li, id);
		}
		else if(temp == "2"){
			system("cls");
			string n, i, co;
			cout<<"请输入您的姓名、学号和所在学院"<<endl;
			cout<<"姓名:";
			cin>>n;
			cout<<"学号:";
			cin>>i;
			cout<<"所在学院:";
			cin>>co;
			Person ptemp(n, i, co); 
			if(li.get_number_id(ptemp) != -1 || li.get_number_id(ptemp) == -2){
				cout<<"\n已有账号？请前去登陆!!!\n注册失败..."<<endl;
				cout<<"即将自动退出"<<endl;
				Sleep(1000);
				system("cls");
				continue;
			}
			li.add_stu(ptemp);
			cout<<"\n注册成功！可以去登陆啦!"<<endl;
			cout<<"即将自动退出"<<endl;
			Sleep(1000);
			system("cls");
		}
		else if(temp == "3"){
			system("cls");
			string n, i;
			cout<<"请输入管理员账号和密码"<<endl;
			cout<<"账号:";
			cin>>n;
			cout<<"密码:";
			cin>>i;
			if(li.get_un() == n && li.get_pw() == i){
				cout<<"\n管理员登陆成功!"<<endl;
				cout<<"正在进入后台..."<<endl;
				Sleep(1000);
				system("cls");
				Administer(li);
			}
			else{
				cout<<"\n账号/密码错误?"<<endl;
				cout<<"即将自动退出..."<<endl;
				Sleep(1000);
				system("cls");
			}
		}
		else{
			cout<<"\n请输入正确的服务序号..."<<endl;
			Sleep(1000);
			system("cls");
		}
	}
}

void login(library &li, int id){
	while(1){
		li.show_an();
		string temp;
		cout<<"\n\n ================================"<<endl;
		cout<<" || 图书馆预约系统所提供的服务 ||"<<endl;
		cout<<" ||    1、预定图书馆位置       ||"<<endl;
		cout<<" ||    2、取消图书馆预定位置   ||"<<endl;
		cout<<" ||    3、查看当前已选位置     ||"<<endl;
		cout<<" ||    4、退出                 ||"<<endl;
		cout<<" ================================"<<endl;
		cout<<"请选择你需要的服务:";
		cin>>temp;
		if(temp == "1"){
			cout<<"\n正在进入预约系统,请稍后..."<<endl;
			Sleep(1000);
			system("cls");
			li.show_an();
			li.advance_desk(id);
			cout<<"\n即将自动退出..."<<endl;
			Sleep(2000);
			system("cls");
		}
		else if(temp == "2"){
			cout<<"\n正在进入预约系统,请稍后..."<<endl;
			Sleep(1000);
			system("cls");
			li.show_an();
			li.disadvance_desk(id);
			cout<<"\n即将自动退出..."<<endl;
			Sleep(2000);
			system("cls");
		}
		else if(temp == "3"){
			li.get_loc(id);
			cout<<"\n即将自动退出..."<<endl;
			Sleep(2000);
			system("cls");
		}
		else if(temp == "4"){
			cout<<"\n即将自动退出..."<<endl;
			Sleep(1000);
			system("cls");
			return;
		}
		else{
			cout<<"\n请输入正确的服务序号..."<<endl;
			Sleep(1000);
			system("cls");
		}
	}
}

void Administer(library &li){
	while(1){
		int temp;
		cout<<"\n\n =================================="<<endl;
		cout<<" || 图书馆后台管理系统所提供的服务 ||"<<endl;
		cout<<" ||     1、查看当前预约位置情况    ||"<<endl;
		cout<<" ||     2、查看图书馆预约人员情况  ||"<<endl;
		cout<<" ||     3、查看每个学院预约的人数  ||"<<endl;
		cout<<" ||     4、改动公告内容            ||"<<endl;
		cout<<" ||     5、导出图书馆后台数据      ||"<<endl;
		cout<<" ||     6、退出                    ||"<<endl;
		cout<<" ================================"<<endl;
		cout<<"请选择你需要的服务:";
		cin>>temp;
		if(temp == 1){
			system("cls");
			li.show_desk();
			cout<<"按下Esc停止查看"<<endl;
			while(1){
				if(_kbhit() && _getch()==0x1b){
					cout<<"查看结束..."<<endl;
					Sleep(1000);
					system("cls");
					break;
				}
			}	
		}
		else if(temp == 2){
			system("cls");
			li.print_detail();
			cout<<"\n按下Esc停止查看"<<endl;
			while(1){
				if(_kbhit() && _getch()==0x1b){
					cout<<"查看结束..."<<endl;
					Sleep(1000);
					system("cls");
					break;
				}
			}
		}
		else if(temp == 3){
			system("cls");
			li.print_college();
			cout<<"\n按下Esc停止查看"<<endl;
			while(1){
				if(_kbhit() && _getch()==0x1b){
					cout<<"查看结束..."<<endl;
					Sleep(1000);
					system("cls");
					break;
				}
			}
		}
		else if(temp == 4){
			system("cls");
			li.change_an();
		}
		else if(temp == 5){
			li.output_all();
			cout<<"正在导出后台数据，请稍后..."<<endl;
			Sleep(2000);
			cout<<"导出成功！"<<endl;
			Sleep(2000);
			system("cls");
		}
		else if(temp == 6){
			cout<<"\n正在退出,请稍后..."<<endl;
			Sleep(1000);
			system("cls");
			return;
		}
		else{
			cout<<"\n请输入正确的服务序号..."<<endl;
			Sleep(1000);
			system("cls");
		}
	}
}
