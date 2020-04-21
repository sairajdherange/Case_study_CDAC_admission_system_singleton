/*
 * Eligibility.cpp
 *
 *  Created on: 18-Apr-2020
 *      Author: sunbeam
 */

#include "Eligibility.h"

Eligibility::Eligibility(string course_name , string degree , double min_percentage) {
	this->course_name = course_name;
	this->degree = degree;
	this->min_percentage = min_percentage;
}

void Eligibility::setCourse_name(string course_name){
	this->course_name = course_name;
}
string Eligibility::getCourse_name(){
	return this->course_name;
}
void Eligibility::setDegree(string degree){
	this->degree = degree;
}
string Eligibility::getDegree(){
	return this->degree;
}
void Eligibility::setMin_percentage(double min_percentage) {
	this->min_percentage = min_percentage;
}
double Eligibility::getMin_percentage() {
	return this->min_percentage;
}

void Eligibility::display(){
	cout << course_name << "\t" << degree << "\t" << min_percentage << endl ;
}

Eligibility::~Eligibility() {
	// TODO Auto-generated destructor stub
}

