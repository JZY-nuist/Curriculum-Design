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
	vector<Person>::iterator ppp; // 迭代器
    for(ppp = pp.begin(); ppp != pp.end(); ppp++)
    {
    	//如果找到了id则返回 
        if((*ppp).User::get_id() == p.User::get_id() && (*ppp).User::get_name() == p.User::get_name())
        	return i;
        //如果姓名和学号只满足了一个,说明输入有误 
        else if(((*ppp).User::get_id() == p.User::get_id() && (*ppp).User::get_name() != p.User::get_name())  || ((*ppp).User::get_id() != p.User::get_id() && (*ppp).User::get_name() == p.User::get_name()))
        	return -2;
		i++;
    }
    //没有找到 
    return -1;
}

void library::get_loc(int id){
	if(!pp[id].get_ifadvance()){
		cout<<"对不起,您还没有预约过位置."<<endl;
		return;
	}
	cout<<"您选择的位置在第"<<pp[id].get_row()<<"行第"<<pp[id].get_column()<<"列"<<endl;
	cout<<"请及时前来就坐"<<endl;
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
	cout<<"下面是图书馆座位被预约情况:"<<endl;
	cout<<"1为已经被预约，0为未被预约"<<endl;
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
		cout<<"对不起，图书馆位置已被预约完..."<<endl;
		cout<<"预约失败"<<endl;
		return;
	}
	int r, c;
	char temp;
	if(pp[id].get_ifadvance()){
		cout<<"对不起,您已经预约过位置."<<endl;
		cout<<"您预约的座位为第"<<pp[id].get_row()<<"行第"<<pp[id].get_column()<<"列."<<endl;
		cout<<"预约失败"<<endl;
		return;
	}
	show_desk();
	cout<<"请选择你预约的座位(起始为第一行第一列)"<<endl;
	cout<<"(例:第二行第三列则输入:2 3)"<<endl;
	cin>>r>>c;
	if(r <= 0 || r > row || c <= 0 || c >= column){
		cout<<"对不起,您的输入位置超出了图书馆的位置范围,请输入正确的坐标."<<endl;
		cout<<"预约失败"<<endl;
		return;
	}
	if(all_desk[r-1][c-1]){
		cout<<"对不起,第"<<r<<"行第"<<c<<"列的位置已被预定"<<endl;
		cout<<"是否重新选择(y/n):";
		cin>>temp;
		if(temp == 'y'){
			cout<<"请选择你预约的座位(起始为第一行第一列)"<<endl;
			cout<<"(例:第二行第三列则输入:2 3)"<<endl;
			cin>>r>>c;
			if(all_desk[r-1][c-1]){
				cout<<"对不起,第"<<r<<"行第"<<c<<"列的位置也已被预定"<<endl;
				cout<<"预约失败"<<endl;
				return;
			}
		}
		else{
			cout<<"预约失败"<<endl;
			return;
		}
	}
	cout<<"预约成功!"<<endl;
	cout<<"您预约的是第"<<r<<"行第"<<c<<"列的位置,请准时就做"<<endl;
	// 对退书馆的桌子进行操作 
	remain_desk--;
	all_desk[r-1][c-1] = 1;
	pp[id].choose_loc(r, c);
	pp[id].advance();
	
	// 对学院的预约人数进行操作
	int id1 = ad.get_coll_id(pp[id].get_college());
	ad.add_to_coll(id1, pp[id].get_college());
}

void library::disadvance_desk(int id){
	int r = pp[id].get_row(), c = pp[id].get_column();
	char temp;
	if(!pp[id].get_ifadvance()){
		cout<<"对不起,您还没有预约过位置."<<endl;
		cout<<"取消失败"<<endl;
		return;
	}
	cout<<"您预约的是第"<<r<<"行第"<<c<<"列的位置,是否确定取消:(y/n)";
	cin>>temp;
	if(temp == 'n'){
		cout<<"取消失败"<<endl;
		return;
	}
	all_desk[r-1][c-1] = 0;
	pp[id].disadvance();
	remain_desk++;
	cout<<"取消成功"<<endl;
	
	// 对学院的预约人数进行操作
	int id1 = ad.get_coll_id(pp[id].get_college());
	ad.min_to_coll(id1);
}

void library::print_detail(){
	cout<<"下面是预约人员的详细情况:"<<endl;
	cout<<"现在共有"<<desk_num - remain_desk<<"人在预约"<<endl;
	vector<Person>::const_iterator ppp; 	// 常量迭代器
	cout<<setiosflags(ios_base::left); 		// 设置左对齐 
    for(ppp = pp.begin(); ppp != pp.end(); ppp++)
    {
        if((*ppp).get_ifadvance())
        	cout<<"来自  "<<setw(20)<<(*ppp).get_college()<<"的  "<<setw(6)<<(*ppp).User::get_name()<<"同学"<<endl;
    }
    cout<<resetiosflags(ios_base::left); 	// 取消左对齐 
}

void library::print_college(){
	cout<<"下面是各个学院的预约人数情况"<<endl;
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
