/*
 * Degrees.h
 *
 *  Created on: 19-Apr-2020
 *      Author: sunbeam
 */
#include <string>

#ifndef DEGREES_H_
#define DEGREES_H_
using namespace std;

class Degrees {
public:
	string name;
public:
	Degrees(string degree);
	string get_name();
	void set_name(string degree);
	virtual ~Degrees();
};

#endif /* DEGREES_H_ */
