/*
 * Centers.cpp
 *
 *  Created on: 18-Apr-2020
 *      Author: sunbeam
 */

#include "Centers.h"

Centers::Centers(string id, string name, string address, string coordinator, string password) {
	this->id = id;
	this->name = name;
	this->address = address;
	this->coordinator = coordinator;
	this->password = password;
}

void Centers::setId(string id) {
	this->id = id;
}
string Centers::getId() {
	return this->id;
}
void Centers::setName(string name) {
	this->name = name;
}
string Centers::getName() {
	return this->name;
}
void Centers::setAddress(string address) {
	this->address = address;
}
string Centers::getAddress() {
	return this->address;
}
void Centers::setCoordinator(string coordinator) {
	this->coordinator = coordinator;
}
string Centers::getCoordinator() {
	return this->coordinator;
}
void Centers::setPassword(string password) {
	this->password = password;
}
string Centers::getPassword() {
	return this->password;
}

void Centers::display_with_capa(vector<Capacities>& capacities_v){
	cout << id << "\t" << name << "\t" << address << "\t" << coordinator << "\t" << password << endl;
	map<string,int>::iterator itr = course_cap.begin();
	while(itr != course_cap.end())
	{
		capacities_v[itr->second].display();
		itr++;
	}
}

void Centers::display(){
	cout << id << "\t" << name << "\t" << address << "\t" << coordinator << "\t" << password << endl;
}

void Centers::display_courses(vector<Capacities>& capacities_v){
	int n = 1;
	for(unsigned i = 0 ; i < capacities_v.size() ; i++ )
	{
		if(capacities_v[i].center_id == this->id)
		{
			cout << n << ". " << capacities_v[i].course_name << endl;
			n++;
		}
	}
}

Centers::~Centers() {
	// TODO Auto-generated destructor stub
}

