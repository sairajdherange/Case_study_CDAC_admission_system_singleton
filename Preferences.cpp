/*
 * Preferences.cpp
 *
 *  Created on: 18-Apr-2020
 *      Author: sunbeam
 */

#include "Preferences.h"
#include <iostream>
using namespace std;

Preferences::Preferences(int form_no,int pref_no,string name,string id) {
	this->student_form_no = form_no;
	this->preference_no = pref_no;
	this->course_name = name;
	this->center_id = id;
}

void Preferences::set_form_no(int form_no){
	this->student_form_no = form_no;
}
int Preferences::get_form_no(){
	return this->student_form_no;
}
void Preferences::set_preference_no(int pref_no){
	this->preference_no = pref_no;
}
int Preferences::get_preference_no(){
	return this->preference_no;
}
string Preferences::Preferences::get_course_name(){
	return this->course_name;
}
string Preferences::get_center_id(){
	return this->center_id;
}
void Preferences::set_course_name(string name){
	this->course_name = name;
}
void Preferences::set_center_id(string id){
	this->center_id = id;
}

void Preferences::display(){
	cout << preference_no << "\t" << course_name << "\t" << center_id << endl;
}

Preferences::~Preferences() {
	// TODO Auto-generated destructor stub
}

