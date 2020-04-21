/*
 * Degrees.cpp
 *
 *  Created on: 19-Apr-2020
 *      Author: sunbeam
 */

#include "Degrees.h"

Degrees::Degrees(string degree) {
	this->name = degree;
}

string Degrees::get_name(){
	return this->name;
}
void Degrees::set_name(string degree){
	this->name = degree;
}

Degrees::~Degrees() {
	// TODO Auto-generated destructor stub
}

