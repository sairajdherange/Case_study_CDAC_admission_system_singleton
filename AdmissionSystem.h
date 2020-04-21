/*
 * AdmissionSystem.h
 *
 *  Created on: 19-Apr-2020
 *      Author: sunbeam
 */

#include "Capacities.h"
#include "Centers.h"
#include "Courses.h"
#include "Student.h"
#include "Preferences.h"
#include "Degrees.h"
#include "Eligibility.h"
#include <fstream>
#include <algorithm>
#include <sstream>
#ifndef ADMISSIONSYSTEM_H_
#define ADMISSIONSYSTEM_H_

class AdmissionSystem {
public:
	static AdmissionSystem *ptr;
	vector<Centers> a_s_centers;
	vector<Courses> a_s_courses;
	vector<Capacities> a_s_capacities;
	vector<Student> a_s_students;
	vector<Preferences> a_s_preferences;
private:
	AdmissionSystem();
	virtual ~AdmissionSystem();
public:
	void load_students_csv(vector<Student>& students_v);
	void load_preferences_csv(vector<Student>& students_v);
	Student* find_student(vector<Student>& students_v,int form_no);
	Courses* find_course(vector<Courses>& courses_v,string course_name);
	Centers* find_center(vector<Centers>& centers_v,string center_id);
	void load_courses_csv(vector<Courses>& courses_v);
	void load_eligibilities_csv(vector<Courses>& courses_v);
	void load_degrees_txt(vector<Degrees>& degrees_v);
	void load_centers_csv(vector<Centers>& centers_v);
	void load_capacities_csv(vector<Capacities>& capacities_v , vector<Courses>& courses_v , vector<Centers>& centers_v);
	void seat_allocation_round_1(vector<Capacities>& capacities_v , vector<Courses>& courses_v , vector<Centers>& centers_v,vector<Student>& students_v,vector<Degrees>& degrees_v);
	void seat_allocation_round_2(vector<Capacities>& capacities_v , vector<Courses>& courses_v , vector<Centers>& centers_v,vector<Student>& students_v,vector<Degrees>& degrees_v);
	int main_menu();
	int coordinator_menu();
	int admin_menu1();
	int student_menu1();
	int student_menu2();
	static AdmissionSystem* get_instance();
};

#endif /* ADMISSIONSYSTEM_H_ */
