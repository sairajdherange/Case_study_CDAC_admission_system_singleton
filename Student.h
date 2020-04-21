/*
 * Student.h
 *
 *  Created on: 18-Apr-2020
 *      Author: sunbeam
 */
#include "Preferences.h"
#include<string>
#include <vector>
using namespace std;
#ifndef STUDENT_H_
#define STUDENT_H_

class Student {
public:
	int form_no,rank_a,rank_b,rank_c,allocated_preference,reported;
	string name,degree,allocated_course_name,allocated_center_id,prn;
	double percentage , payment;
	vector<Preferences> preferences_v;
public:
	Student(int form_no,string name,int rank_a,int rank_b,int rank_c,string degree,double percentage,int allocated_preference,string allocated_course_name,string allocated_center_id,double payment,int reported,string prn);
	int get_form_no();
	int get_rank_a();
	int get_rank_b();
	int get_rank_c();
	int get_allocated_preference();
	int get_reported();
	void set_form_no(int form_no);
	void set_rank_a(int rank_a);
	void set_rank_b(int rank_b);
	void set_rank_c(int rank_c);
	void set_allocated_preference(int allocated_preference);
	void set_reported(int reported);
	string get_name();
	string get_degree();
	string get_allocated_course_name();
	string get_allocated_center_id();
	string get_prn();
	void set_name(string name);
	void set_degree(string degree);
	void set_allocated_course_name(string allocated_course_name);
	void set_allocated_center_id(string allocated_center_id);
	void set_prn( string prn);
	double get_payment();
	double get_percentage();
	void set_percentage(double percentage);
	void set_payment(double payment);
	void display();
	void display_with_pref();
	virtual ~Student();
};

#endif /* STUDENT_H_ */
