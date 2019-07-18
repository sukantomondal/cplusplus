#include<iostream>
#include<queue>
#include<string>
using namespace std;



struct Person{
	string name;
	int age;	
};

struct LessThanCompareAge{

	bool operator()(const Person &p1, const Person &p2) const{
		return p1.age < p2.age;
	}
};


int main(){


	Person p1;
	p1.name = "Sukanto";
	p1.age = 10;

	Person p2;
	p2.name = "Mondal";
	p2.age = 20;


	priority_queue<Person, vector<Person>, LessThanCompareAge> pq;

	pq.push(p1);
	pq.push(p2);


	Person p = pq.top();

	cout << p.name << " " << p.age;

	return 0;
}
