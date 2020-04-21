/*
 * AdmissionSystem.cpp
 *
 *  Created on: 19-Apr-2020
 *      Author: sunbeam
 */

#include "AdmissionSystem.h"

AdmissionSystem* AdmissionSystem::get_instance()
{
	if(ptr == NULL)
	{
		ptr = new AdmissionSystem;
	}
	return ptr;
}

bool comp_rank_a(const Student& r1, const Student& r2) {
	return r1.rank_a < r2.rank_a;
}

bool comp_rank_b(const Student& r1, const Student& r2) {
	return r1.rank_b < r2.rank_b;
}

bool comp_rank_c(const Student& r1, const Student& r2) {
	return r1.rank_c < r2.rank_c;
}

bool comp_form_no(const Student& r1, const Student& r2) {
	return r1.form_no < r2.form_no;
}

AdmissionSystem::AdmissionSystem() {
	// TODO Auto-generated constructor stub

}

Student* AdmissionSystem::find_student(vector<Student>& students_v,int form_no){
	for(unsigned i = 0 ; i < students_v.size() ; i++ )
		if(students_v[i].form_no == form_no)
			return &students_v[i];
	return NULL;
}

Courses* AdmissionSystem::find_course(vector<Courses>& courses_v,string course_name){
	for(unsigned i = 0 ; i < courses_v.size() ; i++ )
		if(courses_v[i].name == course_name)
			return &courses_v[i];
	return NULL;
}

Centers* AdmissionSystem::find_center(vector<Centers>& centers_v,string center_id){
	for(unsigned i = 0 ; i < centers_v.size() ; i++ )
		if(centers_v[i].id == center_id)
			return &centers_v[i];
	return NULL;
}

void AdmissionSystem::load_students_csv(vector<Student>& students_v){
	ifstream fin("students.csv");
	if(!fin) {
		cout << "failed to open students file" << endl;
		return;
	}
	string line;
	while(getline(fin, line)) {
		string tokens[13];
		stringstream str(line);
		for(int i=0; i<13; i++)
			getline(str, tokens[i], ',');
		Student obj(stoi(tokens[0]), tokens[1], stoi(tokens[2]), stoi(tokens[3]), stoi(tokens[4]), tokens[5] , stod(tokens[6]), stoi(tokens[7]), tokens[8], tokens[9],stod(tokens[10]), stoi(tokens[11]), tokens[12]);
		students_v.push_back(obj);
	}
}

void AdmissionSystem::load_preferences_csv(vector<Student>& students_v){
	ifstream fin("preferences.csv");
	if(!fin) {
		cout << "failed to open preferences file" << endl;
		return;
	}
	string line;
	while(getline(fin, line)) {
		string tokens[4];
		stringstream str(line);
		for(int i=0; i<4; i++)
			getline(str, tokens[i], ',');
		Preferences obj(stoi(tokens[0]), stoi(tokens[1]), tokens[2], tokens[3]);
		Student *temp = find_student(students_v,obj.student_form_no);
		temp->preferences_v.push_back(obj);
	}
}

void AdmissionSystem::load_courses_csv(vector<Courses>& courses_v){
	ifstream fin("courses.csv");
	if(!fin) {
		cout << "failed to open courses file" << endl;
		return;
	}
	string line;
	while(getline(fin, line)) {
		string tokens[4];
		stringstream str(line);
		for(int i=0; i<4; i++)
			getline(str, tokens[i], ',');
		Courses obj(stoi(tokens[0]), tokens[1], tokens[2], tokens[3]);
		courses_v.push_back(obj);
	}
}

void AdmissionSystem::load_centers_csv(vector<Centers>& centers_v){
	ifstream fin("centers.csv");
	if(!fin) {
		cout << "failed to open centers file" << endl;
		return;
	}
	string line;
	while(getline(fin, line)) {
		string tokens[5];
		stringstream str(line);
		for(int i=0; i<5; i++)
			getline(str, tokens[i], ',');
		Centers obj(tokens[0], tokens[1], tokens[2], tokens[3],tokens[4]);
		centers_v.push_back(obj);
	}
}

void AdmissionSystem::load_capacities_csv(vector<Capacities>& capacities_v , vector<Courses>& courses_v , vector<Centers>& centers_v){
	ifstream fin("capacities.csv");
	if(!fin) {
		cout << "failed to open capacities file" << endl;
		return;
	}
	string line;
	while(getline(fin, line)) {
		string tokens[4];
		stringstream str(line);
		for(int i=0; i<4; i++)
			getline(str, tokens[i], ',');
		Capacities obj(tokens[0], tokens[1], stoi(tokens[2]), stoi(tokens[3]));
		capacities_v.push_back(obj);

		Courses* cour = find_course(courses_v,obj.course_name);
		cour->course_cap[obj.center_id] = capacities_v.size() - 1 ;
		Centers* cent = find_center(centers_v,obj.center_id);
		cent->course_cap[obj.course_name] = capacities_v.size() - 1 ;
	}
}

void AdmissionSystem::load_eligibilities_csv(vector<Courses>& courses_v){
	ifstream fin("eligibilities.csv");
	if(!fin) {
		cout << "failed to open eligibilities file" << endl;
		return;
	}
	string line;
	while(getline(fin, line)) {
		string tokens[3];
		stringstream str(line);
		for(int i=0; i<3; i++)
			getline(str, tokens[i], ',');
		Eligibility obj(tokens[0], tokens[1], stod(tokens[2]));
		Courses* temp = find_course(courses_v,obj.course_name);
		temp->course_eligibility.push_back(obj);
	}
}

void AdmissionSystem::load_degrees_txt(vector<Degrees>& degrees_v){
	ifstream fin("eligibilities.csv");
	if(!fin) {
		cout << "failed to open eligibilities file" << endl;
		return;
	}
	string line;
	while(getline(fin, line)) {
		string tokens;
		stringstream str(line);
		getline(str, tokens);
		Degrees obj(tokens);
		degrees_v.push_back(obj);

	}
}

void AdmissionSystem::seat_allocation_round_1(vector<Capacities>& capacities_v , vector<Courses>& courses_v , vector<Centers>& centers_v,vector<Student>& students_v,vector<Degrees>& degrees_v){
	int n = 1;
	while(n <= 10)
	{
		sort(students_v.begin(),students_v.end(), comp_rank_a);
		for(unsigned i = 0 ; i < students_v.size() ; i++ )
		{
			for(unsigned j = 0 ; j < students_v[i].preferences_v.size() ; j++)
			{
				if(students_v[i].preferences_v[j].preference_no == n && students_v[i].allocated_course_name == "NA" && students_v[i].payment != -1)
				{
					for(unsigned k = 0 ; k < courses_v.size() ; k++ )
					{
						if(courses_v[k].get_section() == "A" && students_v[i].preferences_v[j].course_name == courses_v[k].name)
						{
							for(unsigned l = 0 ; l < courses_v[k].course_eligibility.size() ; l++ )
							{
								if(students_v[i].degree == courses_v[k].course_eligibility[l].degree && courses_v[k].course_eligibility[l].min_percentage <= students_v[i].percentage && students_v[i].preferences_v[j].course_name == courses_v[k].course_eligibility[l].course_name)
								{
									for(unsigned m = 0 ; m < capacities_v.size() ; m++ )
									{
										if(students_v[i].preferences_v[j].course_name == capacities_v[m].course_name && students_v[i].preferences_v[j].center_id == capacities_v[m].center_id && capacities_v[m].capacity > capacities_v[m].filled)
										{
											students_v[i].allocated_course_name = students_v[i].preferences_v[j].course_name;
											students_v[i].allocated_center_id = students_v[i].preferences_v[j].center_id;
											students_v[i].allocated_preference = n;
											capacities_v[m].filled = capacities_v[m].filled + 1;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		sort(students_v.begin(),students_v.end(), comp_rank_b);
		for(unsigned i = 0 ; i < students_v.size() ; i++ )
		{
			for(unsigned j = 0 ; j < students_v[i].preferences_v.size() ; j++)
			{
				if(students_v[i].preferences_v[j].preference_no == n && students_v[i].allocated_course_name == "NA" && students_v[i].payment != -1)
				{
					for(unsigned k = 0 ; k < courses_v.size() ; k++ )
					{
						if(courses_v[k].get_section() == "B" && students_v[i].preferences_v[j].course_name == courses_v[k].name)
						{
							for(unsigned l = 0 ; l < courses_v[k].course_eligibility.size() ; l++ )
							{
								if(students_v[i].degree == courses_v[k].course_eligibility[l].degree && courses_v[k].course_eligibility[l].min_percentage <= students_v[i].percentage && students_v[i].preferences_v[j].course_name == courses_v[k].course_eligibility[l].course_name)
								{
									for(unsigned m = 0 ; m < capacities_v.size() ; m++ )
									{
										if(students_v[i].preferences_v[j].course_name == capacities_v[m].course_name && students_v[i].preferences_v[j].center_id == capacities_v[m].center_id && capacities_v[m].capacity > capacities_v[m].filled)
										{
											students_v[i].allocated_course_name = students_v[i].preferences_v[j].course_name;
											students_v[i].allocated_center_id = students_v[i].preferences_v[j].center_id;
											students_v[i].allocated_preference = n;
											capacities_v[m].filled = capacities_v[m].filled + 1;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		sort(students_v.begin(),students_v.end(), comp_rank_c);
		for(unsigned i = 0 ; i < students_v.size() ; i++ )
		{
			for(unsigned j = 0 ; j < students_v[i].preferences_v.size() ; j++)
			{
				if(students_v[i].preferences_v[j].preference_no == n && students_v[i].allocated_course_name == "NA" && students_v[i].payment != -1)
				{
					for(unsigned k = 0 ; k < courses_v.size() ; k++ )
					{
						if(courses_v[k].get_section() == "C" && students_v[i].preferences_v[j].course_name == courses_v[k].name)
						{
							for(unsigned l = 0 ; l < courses_v[k].course_eligibility.size() ; l++ )
							{
								if(students_v[i].degree == courses_v[k].course_eligibility[l].degree && courses_v[k].course_eligibility[l].min_percentage <= students_v[i].percentage && students_v[i].preferences_v[j].course_name == courses_v[k].course_eligibility[l].course_name)
								{
									for(unsigned m = 0 ; m < capacities_v.size() ; m++ )
									{
										if(students_v[i].preferences_v[j].course_name == capacities_v[m].course_name && students_v[i].preferences_v[j].center_id == capacities_v[m].center_id && capacities_v[m].capacity > capacities_v[m].filled)
										{
											students_v[i].allocated_course_name = students_v[i].preferences_v[j].course_name;
											students_v[i].allocated_center_id = students_v[i].preferences_v[j].center_id;
											students_v[i].allocated_preference = n;
											capacities_v[m].filled = capacities_v[m].filled + 1;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		n++;
	}
	sort(students_v.begin(),students_v.end(), comp_form_no);
	ofstream my_file;
	my_file.open("studentsnew.csv",ios::out);

	for(unsigned p = 0 ; p < students_v.size() ; p++)
	{
		my_file << students_v[p].form_no << "," << students_v[p].name << "," << students_v[p].rank_a << "," << students_v[p].rank_b << "," << students_v[p].rank_c << "," << students_v[p].degree << "," << students_v[p].percentage << "," << students_v[p].allocated_preference << "," << students_v[p].allocated_course_name << "," << students_v[p].allocated_center_id << "," << students_v[p].payment << "," << students_v[p].reported << "," << students_v[p].prn << endl;
	}
	my_file.close();
	remove("students.csv");
	rename("studentsnew.csv", "students.csv");


	my_file.open("capacitiesnew.csv",ios::out);

	for(unsigned p = 0 ; p < capacities_v.size() ; p++)
	{
		my_file << capacities_v[p].center_id << "," << capacities_v[p].course_name << "," << capacities_v[p].capacity << "," << capacities_v[p].filled << endl;
	}
	my_file.close();
	remove("capacities.csv");
	rename("capacitiesnew.csv", "capacities.csv");
	cout << "Centers has been allocated " << endl;

}

void AdmissionSystem::seat_allocation_round_2(vector<Capacities>& capacities_v , vector<Courses>& courses_v , vector<Centers>& centers_v,vector<Student>& students_v,vector<Degrees>& degrees_v){
	students_v.clear();
	load_students_csv(students_v);
	load_preferences_csv(students_v);

	for(unsigned i = 0 ; i < students_v.size() ; i++ )
		if(students_v[i].allocated_center_id != "NA" && students_v[i].payment != 11800 && students_v[i].allocated_preference == 1)
			students_v[i].payment = -1;

	for(unsigned i = 0 ; i < students_v.size() ; i++ )
	{
		students_v[i].allocated_preference = 0 ;
		students_v[i].allocated_center_id = "NA";
		students_v[i].allocated_course_name = "NA";
	}

	for(unsigned j = 0 ; j < capacities_v.size() ; j++ )
		capacities_v[j].filled = 0 ;

	seat_allocation_round_1(capacities_v , courses_v , centers_v,students_v,degrees_v);
}

int AdmissionSystem::main_menu(){
	int choice;
	cout << "Select the role : " << endl << "0.Exit\n1.Student\n2.Admin\n3.Center Coordinator" << endl;
	cin >> choice;
	return choice;
}

int AdmissionSystem::coordinator_menu(){
	int choice;
	cout << "0.Exit\n1.List courses\n2.List Students\n3.Update reported status\n4.List admitted students\nEnter your choice : ";
	cin >> choice;
	return choice;
}

int AdmissionSystem::admin_menu1(){
	int choice;
	cout << "0.Exit\n1.List courses and eligibilities\n2.List centers & capacities\n3.List students\n4.Update student ranks\n5.Allocate centers (Round 1)\n6.Allocate centers (Round 2)\n7.List allocated students\n8.List paid students\n9.List reported (at center) students\n10.Generate PRN\n11.List admitted students (with PRN) for given center\nEnter your choice : ";
	cin >> choice;
	return choice;
}

int AdmissionSystem::student_menu1(){
	int choice;
	cout << "0.Exit\n1.Register\n2.Sign in\nEnter your choice : ";
	cin >> choice;
	return choice;
}

int AdmissionSystem::student_menu2(){
	int choice;
	cout << "0.Exit\n1.List courses\n2.List Centers\n3.Give Preferences\n4.Show Allocated Center and Course\n5.Update Payment Details\nEnter your choice : ";
	cin >> choice;
	return choice;
}

AdmissionSystem::~AdmissionSystem() {
	// TODO Auto-generated destructor stub
}

