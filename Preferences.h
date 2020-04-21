/*
 * Preferences.h
 *
 *  Created on: 18-Apr-2020
 *      Author: sunbeam
 */
#include<string>
using namespace std;

#ifndef PREFERENCES_H_
#define PREFERENCES_H_

class Preferences {
public:
	int student_form_no, preference_no;
	string course_name , center_id;
public:
	Preferences(int form_no,int pref_no,string name,string id);
	void set_form_no(int form_no);
	int get_form_no();
	void set_preference_no(int pref_no);
	int get_preference_no();
	string get_course_name();
	string get_center_id();
	void set_course_name(string name);
	void set_center_id(string id);
	void display();
	virtual ~Preferences();
};

#endif /* PREFERENCES_H_ */
