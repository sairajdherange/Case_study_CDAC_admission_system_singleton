/*
 * Student.cpp
 *
 *  Created on: 18-Apr-2020
 *      Author: sunbeam
 */

#include "Student.h"
#include <iostream>
using namespace std;

Student::Student(int form_no,string name,int rank_a,int rank_b,int rank_c,string degree,double percentage,int allocated_preference,string allocated_course_name,string allocated_center_id,double payment,int reported,string prn) {
	this->form_no = form_no;
	this->rank_a = rank_a;
	this->rank_b = rank_b;
	this->rank_c = rank_c;
	this->allocated_preference = allocated_preference;
	this->reported = reported;
	this->name = name;
	this->degree = degree ;
	this->allocated_course_name = allocated_course_name;
	this->allocated_center_id = allocated_center_id;
	this->prn = prn;
	this->percentage = percentage;
	this->payment = payment;
}

int Student::get_form_no(){
	return this->form_no;
}
int Student::get_rank_a(){
	return this->rank_a;
}
int Student::get_rank_b(){
	return this->rank_b;
}
int Student::get_rank_c(){
	return this->rank_c;
}
int Student::get_allocated_preference(){
	return this->allocated_preference;
}
int Student::get_reported(){
	return this->reported;
}
void Student::set_form_no(int form_no){
	this->form_no = form_no;
}
void Student::set_rank_a(int rank_a){
	this->rank_a = rank_a;
}
void Student::set_rank_b(int rank_b){
	this->rank_b = rank_b;
}
void Student::set_rank_c(int rank_c){
	this->rank_c = rank_c;
}
void Student::set_allocated_preference(int allocated_preference){
	this->allocated_preference = allocated_preference;
}
void Student::set_reported(int reported){
	this->reported = reported;
}
string Student::get_name(){
	return this->name;
}
string Student::get_degree(){
	return this->degree;
}
string Student::get_allocated_course_name(){
	return this->allocated_course_name;
}
string Student::get_allocated_center_id(){
	return this->allocated_center_id;
}
string Student::get_prn(){
	return this->prn;
}
void Student::set_name(string name){
	this->name = name;
}
void Student::set_degree(string degree){
	this->degree = degree ;
}
void Student::set_allocated_course_name(string allocated_course_name){
	this->allocated_course_name = allocated_course_name;
}
void Student::set_allocated_center_id(string allocated_center_id){
	this->allocated_center_id = allocated_center_id;
}
void Student::set_prn( string prn){
	this->prn = prn;
}
double Student::get_payment(){
	return this->payment;
}
double Student::get_percentage(){
	return this->percentage;
}
void Student::set_percentage(double percentage){
	this->percentage = percentage;
}
void Student::set_payment(double payment){
	this->payment = payment;
}

void Student::display(){
	cout << form_no << "\t" << name << "\t" << rank_a << "\t" << rank_b << "\t" << rank_c << "\t" << degree << "\t" << percentage << "\t" << allocated_preference << "\t" << allocated_course_name << "\t" << allocated_center_id << "\t" << payment << "\t" << reported << "\t" << prn << endl ;
}

void Student::display_with_pref(){
	cout << form_no << "\t" << name << "\t" << rank_a << "\t" << rank_b << "\t" << rank_c << "\t" << degree << "\t" << percentage << "\t" << allocated_preference << "\t" << allocated_course_name << "\t" << allocated_center_id << "\t" << payment << "\t" << reported << "\t" << prn << endl ;
	if(preferences_v.size() != 0)
	{
		cout << "Preferences" << endl ;
		for(unsigned i = 0 ; i < preferences_v.size() ; i++ )
			preferences_v[i].display();
		cout << endl ;
	}
}

Student::~Student() {
	// TODO Auto-generated destructor stub
}

