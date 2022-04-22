#include<iostream>
#include"College.h"

using namespace std;

College::College(string c_na) : col_name(c_na){
	col_number = 1;
}

string College::get_col_name() const{
	return col_name;
}

int College::get_col_number() const{
	return col_number;
}

void College::add_col_number(){
	col_number++;
}

void College::min_col_number(){
	col_number--;
}
