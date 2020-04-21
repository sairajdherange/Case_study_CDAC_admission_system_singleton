/*
 * Eligibility.h
 *
 *  Created on: 18-Apr-2020
 *      Author: sunbeam
 */

#include<string>
#include<iostream>
using namespace std;
#ifndef ELIGIBILITY_H_
#define ELIGIBILITY_H_

class Eligibility {
public:
	string course_name, degree;
	double min_percentage;
public:
	Eligibility(string course_name , string degree , double min_percentage);
	void setCourse_name(string course_name);
	string getCourse_name();
	void setDegree(string degree);
	string getDegree();
	void setMin_percentage(double min_percentage);
	double getMin_percentage();
	void display();
	virtual ~Eligibility();
};

#endif /* ELIGIBILITY_H_ */
