#include<iostream>
#include<iomanip>
#include<windows.h>
#include<fstream>
#include"Admin.h"

using namespace std;

int Admin::get_coll_id(string college){
	int id = 0;
	vector<College>::iterator cc; // 迭代器
	for(cc = coll.begin(); cc != coll.end(); cc++){
		if((*cc).College::get_col_name() == college)
			return id;
		id++;
	}
	return -1;
}

void Admin::add_to_coll(int coll_id, string college){
	if(coll_id == -1){
		College Co(college);
		coll.push_back(Co);
		return;
	}
	coll[coll_id].add_col_number();
}

void Admin::min_to_coll(int coll_id){
	coll[coll_id].min_col_number();
}

void Admin::print_college(){
	vector<College>::const_iterator cc; // 常量迭代器
	cout<<setiosflags(ios_base::left); 		// 设置左对齐 
	for(cc = coll.begin(); cc != coll.end(); cc++){
		if((*cc).get_col_number())
			cout<<setw(20)<<(*cc).get_col_name()<<":\t"<<(*cc).get_col_number()<<"人"<<endl;
	}
	cout<<resetiosflags(ios_base::left); 	// 取消左对齐
}

void Admin::show_an(){
	// 颜色调整 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
	cout<<"*****************************************************************"<<endl;
	cout<<"				图书馆公告"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	if(announcement.empty()){
		cout<<"		   	         暂无公告!"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
		cout<<"*****************************************************************\n\n"<<endl;
		// 将颜色调回原来的颜色 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		return;
	}
	vector<string>::const_iterator aa; // 常量迭代器
	int i = 0;
	for(aa = announcement.begin(); aa != announcement.end(); aa++)
		cout<<++i<<"、"<<*aa<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
	cout<<"*****************************************************************\n\n"<<endl;
	// 将颜色调回原来的颜色 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void Admin::change_an(){
	while(1){
		show_an();
		string temp, input;
		int i;
		cout<<"请选择你所需要的服务:"<<endl;
		cout<<"================================"<<endl;
		cout<<"||         1、新增公告        ||"<<endl;
		cout<<"||         2、修改公告        ||"<<endl;
		cout<<"||         3、删除公告        ||"<<endl;
		cout<<"||         4、退出            ||"<<endl;
		cout<<"================================"<<endl;
		cin>>temp;
		if(temp == "1"){
			cout<<"请输入你添加的公告:(以回车结束)"<<endl;
			getchar();
			getline(cin, input);
			announcement.push_back(input);
			cout<<"\n添加成功!"<<endl;
			Sleep(2000);
			system("cls");
		}
		else if(temp == "2"){
			cout<<"选择您需要修改的公告序号:";
			cin>>i;
			if(i <= 0 || i > announcement.size()){
				cout<<"请输入正确的序号!"<<endl;
				cout<<"修改失败..."<<endl;
				Sleep(2000);
				system("cls");
				continue;
			}
			cout<<"修改的内容:(以回车结束)"<<endl;
			getline(cin, input);
			announcement[i - 1] = input;
			cout<<"修改成功!"<<endl;
			Sleep(2000);
			system("cls");
		}
		else if(temp == "3"){
			cout<<"选择您需要删除的公告序号:";
			cin>>i;
			if(i <= 0 || i > announcement.size()){ 
				cout<<"请输入正确的序号!"<<endl;
				cout<<"删除失败..."<<endl;
				Sleep(2000);
				system("cls");
				continue;
			}
			for(i = i - 1; i < announcement.size() - 1; i++)
				announcement[i] = announcement[i + 1];
			announcement.pop_back();
			cout<<"删除成功..."<<endl;
			Sleep(2000);
			system("cls");
		}
		else if(temp == "4"){
			cout<<"正在退出,请稍后..."<<endl;
			Sleep(2000);
			system("cls");
			return;
		}
		else{
			cout<<"请输入正确的序号!"<<endl;
			Sleep(2000);
			system("cls");
		}
	}
}

void Admin::output(vector<Person> const &pp){
	ofstream outfile;
	outfile.open("output.txt", ios::out | ios::trunc);
	outfile<<"下面是预约人员的详细情况:\n"<<endl;
	vector<Person>::const_iterator ppp; 	// 常量迭代器
	outfile<<setiosflags(ios_base::left); 		// 设置左对齐 
    for(ppp = pp.begin(); ppp != pp.end(); ppp++)
    {
        if((*ppp).get_ifadvance())
        	outfile<<"来自  "<<setw(20)<<(*ppp).get_college()<<"的  "<<setw(6)<<(*ppp).User::get_name()<<"同学"<<endl;
    }
    
    outfile<<"\n下面是学院人员预约的情况:\n"<<endl;
    vector<College>::const_iterator cc; // 常量迭代器
	for(cc = coll.begin(); cc != coll.end(); cc++){
		if((*cc).get_col_number())
			outfile<<setw(20)<<(*cc).get_col_name()<<":\t"<<(*cc).get_col_number()<<"人"<<endl;
	}
	outfile<<resetiosflags(ios_base::left); 	// 取消左对齐
	
	outfile.close();
}
