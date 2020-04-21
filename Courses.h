/*
 * Courses.h
 *
 *  Created on: 18-Apr-2020
 *      Author: sunbeam
 */
#include "Eligibility.h"
#include "Centers.h"
#include<string>
#include <vector>
#include<iostream>
using namespace std;
#ifndef COURSES_H_
#define COURSES_H_

class Courses {
public:
	int id;
	string name , fees , section;
	map<string,int> course_cap;
	vector<Eligibility> course_eligibility;
public:
	Courses(int id,string name,string fees,string section);
	int get_id();
	void set_id(int id);
	string get_name();
	void set_name(string name);
	string get_fees();
	void set_fees(string fees);
	string get_section();
	void set_section(string section);
	void display();
	void display_with_elig();
	void display_centers(vector<Capacities> capicities_v,vector<Centers> center_v);
	virtual ~Courses();
};

#endif /* COURSES_H_ */
