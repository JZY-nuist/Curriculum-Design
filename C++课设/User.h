#include<iostream>

#ifndef _COMMON
#define _COMMON
using namespace std;

class User{
	public:
		User(string n, string i) : name(n), id(i) {} ;
		User(User &U) : name(U.name), id(U.id) {} ;
		string get_name() const;
		string get_id() const;
	private:
		string name;
		string id;
};

#endif 
