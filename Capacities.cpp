/*
 * Capacities.cpp
 *
 *  Created on: 18-Apr-2020
 *      Author: sunbeam
 */

#include "Capacities.h"

Capacities::Capacities(string center_id,string course_name,int capacity,int filled) {
	this->center_id = center_id;
	this->course_name = course_name;
	this->capacity = capacity;
	this->filled = filled;
}

void Capacities::setCenter_id(string center_id) {
	this->center_id = center_id;
}
string Capacities::getCenter_id() {
	return this->center_id;
}
void Capacities::setCourse_name(string course_name) {
	this->course_name = course_name;
}
string Capacities::getCourse_name() {
	return this->course_name;
}
void Capacities::setCapacity(int capacity) {
	this->capacity = capacity;
}
int Capacities::getCapacity() {
	return this->capacity;
}
void Capacities::setFilled(int filled) {
	this->filled = filled;
}
int Capacities::getFilled() {
	return this->filled;
}

void Capacities::display(){
	cout << "     -" << "\t" << course_name << "\t\t" << capacity  << endl;
}

Capacities::~Capacities() {
	// TODO Auto-generated destructor stub
}

