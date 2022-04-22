#include<iostream>
#include<string>
#include"Person.h"

using namespace std;

Person::Person(string n, string i, string co) : User(n, i){
	college = co;
	if_advance = false;
}
string Person::get_college() const{
	return college;
}

bool Person::get_ifadvance() const{
	return if_advance;
}

int Person::get_row() const{
	return row;
}

int Person::get_column() const{
	return column;
}

void Person::choose_loc(int x, int y){
	row = x;
	column = y;
}

void Person::advance(){
	if_advance = true;
}

void Person::disadvance(){
	if_advance = false;
}
