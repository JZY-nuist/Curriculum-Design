#include<iostream>
#include<vector>
#include<string>
#include"College.h"
#include"Person.h"
#include"User.h"

using namespace std;

class Admin : public User{
	public:
		Admin(string n, string i) : User(n, i) {
			announcement.push_back("��ԤԼ����ͬѧҪ׼ʱǰ����ϰ����,����������뼰ʱȡ��ԤԼ��");
		}
		Admin(Admin &a) : User(a.User::get_name(), a.User::get_id()), coll(a.coll), announcement(a.announcement) {} ;
		int get_coll_id(string college);
		void add_to_coll(int coll_id, string college);
		void min_to_coll(int coll_id);
		void print_college();
		void show_an();
		void change_an();
		void output(vector<Person> const &pp);
	private:
		vector<College> coll;
		vector<string> announcement;
};
