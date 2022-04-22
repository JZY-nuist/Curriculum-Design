#include<iostream>
#include<string>
#include<vector>
#include"Person.h"
#include"Admin.h"

using namespace std;

class library{
	public:
		library(int r = 10, int c = 10);
		library(library &li) : desk_num(li.desk_num), row(li.row), column(li.column), remain_desk(li.remain_desk), all_desk(li.all_desk), pp(li.pp), ad(li.ad) {} ;
		void show_desk();	// ��ʾλ��
		void advance_desk(int id);// ԤԼ��λ
		void disadvance_desk(int id);// ȡ��ԤԼλ��
		void get_loc(int id);
		void add_stu(Person &p);
		int get_number_id(Person &p);// ͼ����˺�id
		string get_un();
		string get_pw();
		void print_detail();
		void print_college();
		void show_an();
		void change_an();
		void output_all();
	private:
		int desk_num;		// ���ӵ�����
		int row, column;	// ����������
		int remain_desk;	// ʣ������
		vector< vector<int> > all_desk;
		vector<Person> pp;
		Admin ad;
};
