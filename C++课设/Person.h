#include<iostream>
#include<string>
#include"User.h"

#ifndef _COMMON1
#define _COMMON1

using namespace std;

class Person : public User{
	public:
		Person(string n = "", string i = "", string co = "");
		Person(const Person &p) : User(p.User::get_name(), p.User::get_id()), college(p.college), row(p.row), column(p.column), if_advance(p.if_advance) {} ;
		string get_college() const;
		bool get_ifadvance() const;
		int get_row() const;
		int get_column() const;
		void choose_loc(int x, int y);
		void advance();
		void disadvance();
	private:
		string college;	// ѧԺ
		bool if_advance;
		int row, column;
};

#endif
