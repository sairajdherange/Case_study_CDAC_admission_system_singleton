/*
 * Centers.h
 *
 *  Created on: 18-Apr-2020
 *      Author: sunbeam
 */
#include "Capacities.h"
#include <vector>
#include <map>
#include<string>
#include<iostream>
using namespace std;
#ifndef CENTERS_H_
#define CENTERS_H_

class Centers {
public:
	string id,name,address,coordinator,password;
	vector<Capacities> capt;
	map<string,int> course_cap;
public:
	Centers(string id, string name, string address, string coordinator, string password);
	void setId(string id);
	string getId();
	void setName(string name);
	string getName();
	void setAddress(string address);
	string getAddress();
	void setCoordinator(string coordinator);
	string getCoordinator();
	void setPassword(string password);
	string getPassword();
	void display();
	void display_courses(vector<Capacities>& capacities_v);
	void display_with_capa(vector<Capacities>& capacities_v);
	virtual ~Centers();
};

#endif /* CENTERS_H_ */
