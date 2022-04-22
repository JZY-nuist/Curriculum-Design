#include<iostream>
#include"library.h"
#include<windows.h>
#include<conio.h>

using namespace std;

void Main_menu(library &li);
void login(library &li, int id);
void Administer(library &li);

int main(){
	// ��ʼ������ 
	library li(10, 10);
	
	// ��ҳ�� 
	Main_menu(li);
	return 0;
}

void Main_menu(library &li){
	while(1){
		string temp; 
		cout<<"================================"<<endl;
		cout<<"||   ��ӭ����ͼ���ԤԼϵͳ   ||"<<endl;
		cout<<"||         1����½            ||"<<endl;
		cout<<"||         2��ע��            ||"<<endl;
		cout<<"||               ����Ա���밴3||"<<endl;
		cout<<"================================"<<endl;
		cout<<"��ѡ��������Ҫ�ķ���:";
		cin>>temp;
		if(temp == "1"){
			system("cls");
			string n, i;
			cout<<"����������������ѧ��"<<endl;
			cout<<"����:";
			cin>>n;
			cout<<"ѧ��:";
			cin>>i;
			Person ptemp(n, i); 
			if(li.get_number_id(ptemp) == -1){
				cout<<"\nû�д��˺ţ���ע��...\n��½ʧ��..."<<endl;
				cout<<"�����Զ��˳�"<<endl;
				Sleep(1000);
				system("cls");
				continue;
			}
			else if(li.get_number_id(ptemp) == -2){
				cout<<"\n����/�������\n��½ʧ��..."<<endl;
				cout<<"�����Զ��˳�"<<endl;
				Sleep(1000);
				system("cls");
				continue;
			}
			cout<<"\n��½�ɹ�..."<<endl;
			int id = li.get_number_id(ptemp);
			Sleep(1000);
			system("cls");
			login(li, id);
		}
		else if(temp == "2"){
			system("cls");
			string n, i, co;
			cout<<"����������������ѧ�ź�����ѧԺ"<<endl;
			cout<<"����:";
			cin>>n;
			cout<<"ѧ��:";
			cin>>i;
			cout<<"����ѧԺ:";
			cin>>co;
			Person ptemp(n, i, co); 
			if(li.get_number_id(ptemp) != -1 || li.get_number_id(ptemp) == -2){
				cout<<"\n�����˺ţ���ǰȥ��½!!!\nע��ʧ��..."<<endl;
				cout<<"�����Զ��˳�"<<endl;
				Sleep(1000);
				system("cls");
				continue;
			}
			li.add_stu(ptemp);
			cout<<"\nע��ɹ�������ȥ��½��!"<<endl;
			cout<<"�����Զ��˳�"<<endl;
			Sleep(1000);
			system("cls");
		}
		else if(temp == "3"){
			system("cls");
			string n, i;
			cout<<"���������Ա�˺ź�����"<<endl;
			cout<<"�˺�:";
			cin>>n;
			cout<<"����:";
			cin>>i;
			if(li.get_un() == n && li.get_pw() == i){
				cout<<"\n����Ա��½�ɹ�!"<<endl;
				cout<<"���ڽ����̨..."<<endl;
				Sleep(1000);
				system("cls");
				Administer(li);
			}
			else{
				cout<<"\n�˺�/�������?"<<endl;
				cout<<"�����Զ��˳�..."<<endl;
				Sleep(1000);
				system("cls");
			}
		}
		else{
			cout<<"\n��������ȷ�ķ������..."<<endl;
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
		cout<<" || ͼ���ԤԼϵͳ���ṩ�ķ��� ||"<<endl;
		cout<<" ||    1��Ԥ��ͼ���λ��       ||"<<endl;
		cout<<" ||    2��ȡ��ͼ���Ԥ��λ��   ||"<<endl;
		cout<<" ||    3���鿴��ǰ��ѡλ��     ||"<<endl;
		cout<<" ||    4���˳�                 ||"<<endl;
		cout<<" ================================"<<endl;
		cout<<"��ѡ������Ҫ�ķ���:";
		cin>>temp;
		if(temp == "1"){
			cout<<"\n���ڽ���ԤԼϵͳ,���Ժ�..."<<endl;
			Sleep(1000);
			system("cls");
			li.show_an();
			li.advance_desk(id);
			cout<<"\n�����Զ��˳�..."<<endl;
			Sleep(2000);
			system("cls");
		}
		else if(temp == "2"){
			cout<<"\n���ڽ���ԤԼϵͳ,���Ժ�..."<<endl;
			Sleep(1000);
			system("cls");
			li.show_an();
			li.disadvance_desk(id);
			cout<<"\n�����Զ��˳�..."<<endl;
			Sleep(2000);
			system("cls");
		}
		else if(temp == "3"){
			li.get_loc(id);
			cout<<"\n�����Զ��˳�..."<<endl;
			Sleep(2000);
			system("cls");
		}
		else if(temp == "4"){
			cout<<"\n�����Զ��˳�..."<<endl;
			Sleep(1000);
			system("cls");
			return;
		}
		else{
			cout<<"\n��������ȷ�ķ������..."<<endl;
			Sleep(1000);
			system("cls");
		}
	}
}

void Administer(library &li){
	while(1){
		int temp;
		cout<<"\n\n =================================="<<endl;
		cout<<" || ͼ��ݺ�̨����ϵͳ���ṩ�ķ��� ||"<<endl;
		cout<<" ||     1���鿴��ǰԤԼλ�����    ||"<<endl;
		cout<<" ||     2���鿴ͼ���ԤԼ��Ա���  ||"<<endl;
		cout<<" ||     3���鿴ÿ��ѧԺԤԼ������  ||"<<endl;
		cout<<" ||     4���Ķ���������            ||"<<endl;
		cout<<" ||     5������ͼ��ݺ�̨����      ||"<<endl;
		cout<<" ||     6���˳�                    ||"<<endl;
		cout<<" ================================"<<endl;
		cout<<"��ѡ������Ҫ�ķ���:";
		cin>>temp;
		if(temp == 1){
			system("cls");
			li.show_desk();
			cout<<"����Escֹͣ�鿴"<<endl;
			while(1){
				if(_kbhit() && _getch()==0x1b){
					cout<<"�鿴����..."<<endl;
					Sleep(1000);
					system("cls");
					break;
				}
			}	
		}
		else if(temp == 2){
			system("cls");
			li.print_detail();
			cout<<"\n����Escֹͣ�鿴"<<endl;
			while(1){
				if(_kbhit() && _getch()==0x1b){
					cout<<"�鿴����..."<<endl;
					Sleep(1000);
					system("cls");
					break;
				}
			}
		}
		else if(temp == 3){
			system("cls");
			li.print_college();
			cout<<"\n����Escֹͣ�鿴"<<endl;
			while(1){
				if(_kbhit() && _getch()==0x1b){
					cout<<"�鿴����..."<<endl;
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
			cout<<"���ڵ�����̨���ݣ����Ժ�..."<<endl;
			Sleep(2000);
			cout<<"�����ɹ���"<<endl;
			Sleep(2000);
			system("cls");
		}
		else if(temp == 6){
			cout<<"\n�����˳�,���Ժ�..."<<endl;
			Sleep(1000);
			system("cls");
			return;
		}
		else{
			cout<<"\n��������ȷ�ķ������..."<<endl;
			Sleep(1000);
			system("cls");
		}
	}
}
