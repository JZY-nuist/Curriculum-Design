#include<iostream>
#include<iomanip>
#include<windows.h>
#include<fstream>
#include"Admin.h"

using namespace std;

int Admin::get_coll_id(string college){
	int id = 0;
	vector<College>::iterator cc; // ������
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
	vector<College>::const_iterator cc; // ����������
	cout<<setiosflags(ios_base::left); 		// ��������� 
	for(cc = coll.begin(); cc != coll.end(); cc++){
		if((*cc).get_col_number())
			cout<<setw(20)<<(*cc).get_col_name()<<":\t"<<(*cc).get_col_number()<<"��"<<endl;
	}
	cout<<resetiosflags(ios_base::left); 	// ȡ�������
}

void Admin::show_an(){
	// ��ɫ���� 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
	cout<<"*****************************************************************"<<endl;
	cout<<"				ͼ��ݹ���"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	if(announcement.empty()){
		cout<<"		   	         ���޹���!"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
		cout<<"*****************************************************************\n\n"<<endl;
		// ����ɫ����ԭ������ɫ 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		return;
	}
	vector<string>::const_iterator aa; // ����������
	int i = 0;
	for(aa = announcement.begin(); aa != announcement.end(); aa++)
		cout<<++i<<"��"<<*aa<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
	cout<<"*****************************************************************\n\n"<<endl;
	// ����ɫ����ԭ������ɫ 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void Admin::change_an(){
	while(1){
		show_an();
		string temp, input;
		int i;
		cout<<"��ѡ��������Ҫ�ķ���:"<<endl;
		cout<<"================================"<<endl;
		cout<<"||         1����������        ||"<<endl;
		cout<<"||         2���޸Ĺ���        ||"<<endl;
		cout<<"||         3��ɾ������        ||"<<endl;
		cout<<"||         4���˳�            ||"<<endl;
		cout<<"================================"<<endl;
		cin>>temp;
		if(temp == "1"){
			cout<<"����������ӵĹ���:(�Իس�����)"<<endl;
			getchar();
			getline(cin, input);
			announcement.push_back(input);
			cout<<"\n��ӳɹ�!"<<endl;
			Sleep(2000);
			system("cls");
		}
		else if(temp == "2"){
			cout<<"ѡ������Ҫ�޸ĵĹ������:";
			cin>>i;
			if(i <= 0 || i > announcement.size()){
				cout<<"��������ȷ�����!"<<endl;
				cout<<"�޸�ʧ��..."<<endl;
				Sleep(2000);
				system("cls");
				continue;
			}
			cout<<"�޸ĵ�����:(�Իس�����)"<<endl;
			getline(cin, input);
			announcement[i - 1] = input;
			cout<<"�޸ĳɹ�!"<<endl;
			Sleep(2000);
			system("cls");
		}
		else if(temp == "3"){
			cout<<"ѡ������Ҫɾ���Ĺ������:";
			cin>>i;
			if(i <= 0 || i > announcement.size()){ 
				cout<<"��������ȷ�����!"<<endl;
				cout<<"ɾ��ʧ��..."<<endl;
				Sleep(2000);
				system("cls");
				continue;
			}
			for(i = i - 1; i < announcement.size() - 1; i++)
				announcement[i] = announcement[i + 1];
			announcement.pop_back();
			cout<<"ɾ���ɹ�..."<<endl;
			Sleep(2000);
			system("cls");
		}
		else if(temp == "4"){
			cout<<"�����˳�,���Ժ�..."<<endl;
			Sleep(2000);
			system("cls");
			return;
		}
		else{
			cout<<"��������ȷ�����!"<<endl;
			Sleep(2000);
			system("cls");
		}
	}
}

void Admin::output(vector<Person> const &pp){
	ofstream outfile;
	outfile.open("output.txt", ios::out | ios::trunc);
	outfile<<"������ԤԼ��Ա����ϸ���:\n"<<endl;
	vector<Person>::const_iterator ppp; 	// ����������
	outfile<<setiosflags(ios_base::left); 		// ��������� 
    for(ppp = pp.begin(); ppp != pp.end(); ppp++)
    {
        if((*ppp).get_ifadvance())
        	outfile<<"����  "<<setw(20)<<(*ppp).get_college()<<"��  "<<setw(6)<<(*ppp).User::get_name()<<"ͬѧ"<<endl;
    }
    
    outfile<<"\n������ѧԺ��ԱԤԼ�����:\n"<<endl;
    vector<College>::const_iterator cc; // ����������
	for(cc = coll.begin(); cc != coll.end(); cc++){
		if((*cc).get_col_number())
			outfile<<setw(20)<<(*cc).get_col_name()<<":\t"<<(*cc).get_col_number()<<"��"<<endl;
	}
	outfile<<resetiosflags(ios_base::left); 	// ȡ�������
	
	outfile.close();
}
