#include<iostream>
#include"library.h"
#include<vector>
#include<iomanip>

using namespace std;

library::library(int r, int c) : ad("admin", "admin") {
	desk_num = r * c;
	row = r, column = c;
	remain_desk = desk_num;
	vector<int> temp(column, 0);
	for(int i = 0; i < r; i++)
		all_desk.push_back(temp);
}

int library::get_number_id(Person &p){
	int i = 0;
	vector<Person>::iterator ppp; // ������
    for(ppp = pp.begin(); ppp != pp.end(); ppp++)
    {
    	//����ҵ���id�򷵻� 
        if((*ppp).User::get_id() == p.User::get_id() && (*ppp).User::get_name() == p.User::get_name())
        	return i;
        //���������ѧ��ֻ������һ��,˵���������� 
        else if(((*ppp).User::get_id() == p.User::get_id() && (*ppp).User::get_name() != p.User::get_name())  || ((*ppp).User::get_id() != p.User::get_id() && (*ppp).User::get_name() == p.User::get_name()))
        	return -2;
		i++;
    }
    //û���ҵ� 
    return -1;
}

void library::get_loc(int id){
	if(!pp[id].get_ifadvance()){
		cout<<"�Բ���,����û��ԤԼ��λ��."<<endl;
		return;
	}
	cout<<"��ѡ���λ���ڵ�"<<pp[id].get_row()<<"�е�"<<pp[id].get_column()<<"��"<<endl;
	cout<<"�뼰ʱǰ������"<<endl;
}
void library::add_stu(Person &p){
	pp.push_back(p);
}

string library::get_un(){
	return ad.get_name();
}

string library::get_pw(){
	return ad.get_id();
}

void library::show_desk(){
	int i, j;
	cout<<"������ͼ�����λ��ԤԼ���:"<<endl;
	cout<<"1Ϊ�Ѿ���ԤԼ��0Ϊδ��ԤԼ"<<endl;
	cout<<" ========================================"<<endl;
	for(i = 0; i < row; i++){
		for(j = 0; j < column; j++)
			cout<<"| "<<all_desk[i][j]<<" ";
		cout<<"|"<<endl;
		cout<<" ---------------------------------------- "<<endl;
	}
}

void library::advance_desk(int id){
	if(remain_desk == 0){
		cout<<"�Բ���ͼ���λ���ѱ�ԤԼ��..."<<endl;
		cout<<"ԤԼʧ��"<<endl;
		return;
	}
	int r, c;
	char temp;
	if(pp[id].get_ifadvance()){
		cout<<"�Բ���,���Ѿ�ԤԼ��λ��."<<endl;
		cout<<"��ԤԼ����λΪ��"<<pp[id].get_row()<<"�е�"<<pp[id].get_column()<<"��."<<endl;
		cout<<"ԤԼʧ��"<<endl;
		return;
	}
	show_desk();
	cout<<"��ѡ����ԤԼ����λ(��ʼΪ��һ�е�һ��)"<<endl;
	cout<<"(��:�ڶ��е�����������:2 3)"<<endl;
	cin>>r>>c;
	if(r <= 0 || r > row || c <= 0 || c >= column){
		cout<<"�Բ���,��������λ�ó�����ͼ��ݵ�λ�÷�Χ,��������ȷ������."<<endl;
		cout<<"ԤԼʧ��"<<endl;
		return;
	}
	if(all_desk[r-1][c-1]){
		cout<<"�Բ���,��"<<r<<"�е�"<<c<<"�е�λ���ѱ�Ԥ��"<<endl;
		cout<<"�Ƿ�����ѡ��(y/n):";
		cin>>temp;
		if(temp == 'y'){
			cout<<"��ѡ����ԤԼ����λ(��ʼΪ��һ�е�һ��)"<<endl;
			cout<<"(��:�ڶ��е�����������:2 3)"<<endl;
			cin>>r>>c;
			if(all_desk[r-1][c-1]){
				cout<<"�Բ���,��"<<r<<"�е�"<<c<<"�е�λ��Ҳ�ѱ�Ԥ��"<<endl;
				cout<<"ԤԼʧ��"<<endl;
				return;
			}
		}
		else{
			cout<<"ԤԼʧ��"<<endl;
			return;
		}
	}
	cout<<"ԤԼ�ɹ�!"<<endl;
	cout<<"��ԤԼ���ǵ�"<<r<<"�е�"<<c<<"�е�λ��,��׼ʱ����"<<endl;
	// ������ݵ����ӽ��в��� 
	remain_desk--;
	all_desk[r-1][c-1] = 1;
	pp[id].choose_loc(r, c);
	pp[id].advance();
	
	// ��ѧԺ��ԤԼ�������в���
	int id1 = ad.get_coll_id(pp[id].get_college());
	ad.add_to_coll(id1, pp[id].get_college());
}

void library::disadvance_desk(int id){
	int r = pp[id].get_row(), c = pp[id].get_column();
	char temp;
	if(!pp[id].get_ifadvance()){
		cout<<"�Բ���,����û��ԤԼ��λ��."<<endl;
		cout<<"ȡ��ʧ��"<<endl;
		return;
	}
	cout<<"��ԤԼ���ǵ�"<<r<<"�е�"<<c<<"�е�λ��,�Ƿ�ȷ��ȡ��:(y/n)";
	cin>>temp;
	if(temp == 'n'){
		cout<<"ȡ��ʧ��"<<endl;
		return;
	}
	all_desk[r-1][c-1] = 0;
	pp[id].disadvance();
	remain_desk++;
	cout<<"ȡ���ɹ�"<<endl;
	
	// ��ѧԺ��ԤԼ�������в���
	int id1 = ad.get_coll_id(pp[id].get_college());
	ad.min_to_coll(id1);
}

void library::print_detail(){
	cout<<"������ԤԼ��Ա����ϸ���:"<<endl;
	cout<<"���ڹ���"<<desk_num - remain_desk<<"����ԤԼ"<<endl;
	vector<Person>::const_iterator ppp; 	// ����������
	cout<<setiosflags(ios_base::left); 		// ��������� 
    for(ppp = pp.begin(); ppp != pp.end(); ppp++)
    {
        if((*ppp).get_ifadvance())
        	cout<<"����  "<<setw(20)<<(*ppp).get_college()<<"��  "<<setw(6)<<(*ppp).User::get_name()<<"ͬѧ"<<endl;
    }
    cout<<resetiosflags(ios_base::left); 	// ȡ������� 
}

void library::print_college(){
	cout<<"�����Ǹ���ѧԺ��ԤԼ�������"<<endl;
	ad.print_college();
}

void library::show_an(){
	ad.show_an();
}

void library::change_an(){
	ad.change_an();
}

void library::output_all(){
	ad.output(pp);
}
