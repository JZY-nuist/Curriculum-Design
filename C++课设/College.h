#include<iostream>

using namespace std;

class College{
	public:
		College(string c_na);
		College(College const &c) : col_name(c.col_name), col_number(c.col_number) {} ;
		string get_col_name() const;
		int get_col_number() const;
		void add_col_number();
		void min_col_number();
	private:
		string col_name;	// ѧԺ����
		int col_number;			// ѧԺѧ��ԤԼ�� 
};
