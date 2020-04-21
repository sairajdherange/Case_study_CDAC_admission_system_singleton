/*
 * Courses.cpp
 *
 *  Created on: 18-Apr-2020
 *      Author: sunbeam
 */

#include "Courses.h"

Courses::Courses(int id,string name,string fees,string section) {
	this->id = id;
	this->name = name ;
	this->fees = fees;
	this->section = section;

}

int Courses::get_id(){
	return this->id;
}
void Courses::set_id(int id){
	this->id = id;
}
string Courses::get_name(){
	return this->name;
}
void Courses::set_name(string name){
	this->name = name ;
}
string Courses::get_fees(){
	return this->fees;
}
void Courses::set_fees(string fees){
	this->fees = fees;
}
string Courses::get_section(){
	return this->section;
}
void Courses::set_section(string section){
	this->section = section;
}

void Courses::display_with_elig(){
	cout << id << "\t" << name << "\t" << fees << "\t" << section << endl;
	cout << "Eligiility\n";
	for(unsigned i = 0 ; i < course_eligibility.size() ; i++ )
		course_eligibility[i].display();
	cout << endl;
}

void Courses::display(){
	cout << id << "\t" << name << "\t" << fees << "\t" << section << endl;
}

void Courses::display_centers(vector<Capacities> capicities_v,vector<Centers> center_v){
	map<string,int> :: iterator itr = course_cap.begin();
	while(itr != course_cap.end())
	{
		for(unsigned i = 0 ; i < center_v.size() ; i++ )
		if(capicities_v[itr->second].course_name == name && capicities_v[itr->second].center_id == center_v[i].id)
			center_v[i].display();
		itr++;
	}
}

Courses::~Courses() {
	// TODO Auto-generated destructor stub
}

