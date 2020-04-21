/*
 * Capacities.h
 *
 *  Created on: 18-Apr-2020
 *      Author: sunbeam
 */
#include<string>
#include<iostream>
using namespace std;
#ifndef CAPACITIES_H_
#define CAPACITIES_H_

class Capacities {
public:
	string center_id,course_name;
	int capacity,filled;
public:
	Capacities(string center_id,string course_name,int capacity,int filled);
	void setCenter_id(string center_id);
	string getCenter_id();
	void setCourse_name(string course_name);
	string getCourse_name();
	void setCapacity(int capacity);
	int getCapacity();
	void setFilled(int filled);
	int getFilled();
	void display();
	virtual ~Capacities();
};

#endif /* CAPACITIES_H_ */
