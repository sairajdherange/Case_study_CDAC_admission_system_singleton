/*
 * main.cpp
 *
 *  Created on: 20-Apr-2020
 *      Author: sunbeam
 */
#include "AdmissionSystem.h"
//#include "Capacities.h"
//#include "Centers.h"
//#include "Student.h"
//#include "Degrees.h"
//#include "Courses.h"
//#include "Eligibility.h"
//#include "Preferences.h"
#include <iostream>
using namespace std;

//AdmissionSystem system1;
AdmissionSystem* AdmissionSystem::ptr=NULL;

int main(){
	static AdmissionSystem* system1=system1->get_instance();

	vector<Student> students_v;
	vector<Courses> courses_v;
	vector<Degrees> degrees_v;
	vector<Centers> centers_v;
	vector<Capacities> capacities_v;

	system1->load_students_csv(students_v);
	system1->load_preferences_csv(students_v);
	system1->load_courses_csv(courses_v);
	system1->load_eligibilities_csv(courses_v);
	system1->load_degrees_txt(degrees_v);
	system1->load_centers_csv(centers_v);
	system1->load_capacities_csv(capacities_v ,courses_v ,centers_v);

	int choice;
	while((choice = system1->main_menu()) != 0)
	{
		switch(choice)
		{
		case 1:
		{
			int choice6;
			while((choice6 = system1->student_menu1()) != 0 )
			{
				switch(choice6)
				{
				case 1:
				{
					int form_no, degree;
					string name;
					double percentage;
					cout << "Enter Form no., Name, percentage : " ;
					cin >> form_no;
					cin >> name;
					cin >> percentage;
					cout << "Select the highest qualifying degree : " << endl;
					for(unsigned i = 0 ; i < degrees_v.size() ; i++ )
					{
						cout << i + 1 << ". " << degrees_v[i].name << endl ;
					}
					cin >> degree;

					Student temp(form_no,name,-1,-1,-1,degrees_v[degree -1].name,percentage,0,"NA","NA",0,0,"NA");

					students_v.push_back(temp);
					ofstream my_file;
					my_file.open("studentsnew.csv",ios::out);

					for(unsigned p = 0 ; p < students_v.size() ; p++)
					{
						my_file << students_v[p].form_no << "," << students_v[p].name << "," << students_v[p].rank_a << "," << students_v[p].rank_b << "," << students_v[p].rank_c << "," << students_v[p].degree << "," << students_v[p].percentage << "," << students_v[p].allocated_preference << "," << students_v[p].allocated_course_name << "," << students_v[p].allocated_center_id << "," << students_v[p].payment << "," << students_v[p].reported << "," << students_v[p].prn << endl;
					}
					my_file.close();
					remove("students.csv");
					rename("studentsnew.csv", "students.csv");
					cout << "Student has been registered." << endl;
				}
				break;
				case 2:
				{
					int form_no, choice9 , flag = 0 , m;
					string pass;
					cout << "Enter form No.: ";
					cin >> form_no;
					cout << "Enter password : ";
					cin >> pass;
					for(unsigned x = 0 ; x < students_v.size() ; x++ )
					{
						if(form_no == students_v[x].get_form_no() && pass == students_v[x].get_name())
						{
							flag = 1;
							while((choice9 = system1->student_menu2()) != 0)
							{
								switch(choice9)
								{
								case 1 : m = 1;
								{
									for(unsigned j = 0 ; j < courses_v.size() ; j++)
										for(unsigned l = 0 ; l < courses_v[j].course_eligibility.size() ; l++)
										{
											if(students_v[x].degree == courses_v[j].course_eligibility[l].degree && students_v[x].percentage >= courses_v[j].course_eligibility[l].min_percentage)
												courses_v[j].display();
										}
								}
								break;
								case 2:
									//									cout << "Center Id\tCenter Name\tAddress" << endl ;
									for(unsigned j = 0 ; j < centers_v.size() ; j++)
									{
										centers_v[j].display();
									}
									break;
								case 3:{
									m = 1;
									//									Preferences temp;
									int pref_no;
									string center_id,course_name;
									cout << "Enter the preference number : ";
									cin >> pref_no;
									cout << "Enter name your desired course" << endl ;
									for(unsigned j = 0 ; j < courses_v.size() ; j++)
										for(unsigned l = 0 ; l < courses_v[j].course_eligibility.size() ; l++)
										{
											if(students_v[x].degree == courses_v[j].course_eligibility[l].degree && students_v[x].percentage >= courses_v[j].course_eligibility[l].min_percentage)
											{
												cout << m << ". " ;
												courses_v[j].display();
												m++;
											}
										}
									cin >> course_name;
									m = 1;
									cout << "Enter center id your desired center" << endl ;
									for(unsigned j = 0 ; j < courses_v.size() ; j++ )
									{
										if(course_name == courses_v[j].name)
										{
											courses_v[j].display_centers(capacities_v,centers_v);
										}
									}
									cin >> center_id;

									Preferences temp(students_v[x].form_no,pref_no,course_name,center_id);

									students_v[x].preferences_v.push_back(temp);
									ofstream my_file;
									my_file.open("preferences.csv",ios::app);
									my_file << students_v[x].form_no << "," << pref_no << "," << course_name  << "," << center_id << endl ;
									my_file.close();
								}
								break;
								case 4: {
									int flag = 0;
									for(unsigned j = 0 ; j < centers_v.size() ; j++)
										if(centers_v[j].id == students_v[x].allocated_center_id && students_v[j].allocated_preference != 0)
										{
											cout << "The allocated center is " << centers_v[j].name << ", " << centers_v[j].address << " for " << students_v[x].allocated_course_name << " course." << endl;
											flag = 1;
										}
									if(flag == 0)
										cout << "No Center Allocated" << endl;
								}
								break;
								case 5:
								{
									double payment;
									cout << "Enter the amount paid : " ;
									cin >> payment ;
									students_v[x].set_payment(payment);
									ofstream my_file;
									my_file.open("studentsnew.csv",ios::out);

									for(unsigned p = 0 ; p < students_v.size() ; p++)
									{
										my_file << students_v[p].form_no << "," << students_v[p].name << "," << students_v[p].rank_a << "," << students_v[p].rank_b << "," << students_v[p].rank_c << "," << students_v[p].degree << "," << students_v[p].percentage << "," << students_v[p].allocated_preference << "," << students_v[p].allocated_course_name << "," << students_v[p].allocated_center_id << "," << students_v[p].payment << "," << students_v[p].reported << "," << students_v[p].prn << endl;
									}
									my_file.close();
									remove("students.csv");
									rename("studentsnew.csv", "students.csv");
								}
								break;
								}
							}
							break;
						}
					}
					if(flag == 0)
						cout << "Invalid Id and Password." << endl ;
				}

				break;
				}
			}
		}
		break;
		case 2:label1:
		{
			string login_id,password;
			cout << "Enter the login id : ";
			cin >> login_id;
			cout << "Enter password : ";
			cin >> password;
			if(login_id == "admin" && password == "admin")
			{
				int choice2;
				while((choice2 = system1->admin_menu1()) != 0)
				{
					switch(choice2)
					{
					case 1:
					{
						//						cout << "  Course Name\tDegree Required\tMinimum Percentage\n";
						for(unsigned i = 0 ; i < courses_v.size() ; i++ )
							courses_v[i].display_with_elig();
					}
					break;
					case 2:
					{

						for(unsigned m = 0 ; m < centers_v.size() ; m++ )
						{
							centers_v[m].display_with_capa(capacities_v);
						}

					}
					break;
					case 3:
					{
						cout << "The list of students is as follows :\n";
						for(unsigned i = 0 ; i < students_v.size() ; i++ )
						{
							students_v[i].display_with_pref();
						}
					}
					break;
					case 4:
					{
						int form_no,rank_a ,rank_b ,rank_c , flag = 0 ;
						cout << "Enter the form number of the student whose rank is to be updated : ";
						cin >> form_no;
						cout << "Enter rank A , rank B and rank C (Enter -1 if not appeared) : ";
						cin >>rank_a;
						cin >> rank_b;
						cin >> rank_c;
						for(unsigned i = 0 ; i < students_v.size() ; i++ )
						{
							if(form_no == students_v[i].get_form_no())
							{
								students_v[i].set_rank_a(rank_a);
								students_v[i].set_rank_b(rank_b);
								students_v[i].set_rank_c(rank_c);
								flag = 1;
								ofstream my_file;
								my_file.open("studentsnew.csv",ios::out);

								for(unsigned p = 0 ; p < students_v.size() ; p++)
								{
									my_file << students_v[p].form_no << "," << students_v[p].name << "," << students_v[p].rank_a << "," << students_v[i].rank_b << "," << students_v[p].rank_c << "," << students_v[p].degree << "," << students_v[p].percentage << "," << students_v[p].allocated_preference << "," << students_v[p].allocated_course_name << "," << students_v[p].allocated_center_id << "," << students_v[p].payment << "," << students_v[p].reported << "," << students_v[p].prn << endl;
								}
								my_file.close();
								remove("students.csv");
								rename("studentsnew.csv", "students.csv");
							}
						}
						if(flag == 0)
						{
							cout << "Form Number not found!!!" << endl;
						}
					}
					break;
					case 5: system1->seat_allocation_round_1(capacities_v , courses_v , centers_v,students_v,degrees_v);
					break;
					case 6: system1->seat_allocation_round_2(capacities_v , courses_v , centers_v,students_v,degrees_v);
					break;
					case 7:
					{
						//						cout << "Form no.\tName\tCourse\tAllocated Center" << endl;
						for(unsigned i = 0 ; i < students_v.size() ; i++ )
						{
							if(students_v[i].allocated_course_name != "NA")
								students_v[i].display();
						}
					}
					break;
					case 8:
					{
						//						cout << "Form No.\tName\tAmount paid\n";
						for(unsigned i = 0 ; i < students_v.size() ; i++ )
						{
							if(students_v[i].get_payment() > 0 )
								students_v[i].display();
						}
					}
					break;
					case 9:
					{
						//						cout << "Form No.\tName\n";
						for(unsigned i = 0 ; i < students_v.size() ; i++ )
						{
							if(students_v[i].get_reported() != 0 )
								students_v[i].display();
						}
					}
					break;
					case 10:
					{
						students_v.clear();
						system1->load_students_csv(students_v);
						system1->load_preferences_csv(students_v);

						for(unsigned i = 0 ; i < students_v.size() ; i++ )
							for(unsigned j = 0 ; j < courses_v.size() ; j++ )
								if(students_v[i].reported != 0 && students_v[i].payment == stod(courses_v[j].fees)   && students_v[i].allocated_course_name == courses_v[j].name)
								{
									string prn = students_v[i].get_allocated_center_id();
									prn.append("_");
									prn.append(students_v[i].get_allocated_course_name());
									prn.append("_");
									prn.append(to_string(students_v[i].get_form_no()));

									students_v[i].prn = prn;
								}
						ofstream my_file;
						my_file.open("studentsnew.csv",ios::out);

						for(unsigned p = 0 ; p < students_v.size() ; p++)
						{
							my_file << students_v[p].form_no << "," << students_v[p].name << "," << students_v[p].rank_a << "," << students_v[p].rank_b << "," << students_v[p].rank_c << "," << students_v[p].degree << "," << students_v[p].percentage << "," << students_v[p].allocated_preference << "," << students_v[p].allocated_course_name << "," << students_v[p].allocated_center_id << "," << students_v[p].payment << "," << students_v[p].reported << "," << students_v[p].prn << endl;
						}
						my_file.close();
						remove("students.csv");
						rename("studentsnew.csv", "students.csv");

					}
					break;
					case 11:
					{
						for(unsigned i = 0 ; i < students_v.size() ; i++ )
						{
							for(unsigned m = 0 ; m < courses_v.size() ; m++ )
								if(students_v[i].get_allocated_course_name() == courses_v[m].get_name())
									if(students_v[i].get_reported() != 0 && students_v[i].get_payment() >= stod(courses_v[m].get_fees()))
									{
										students_v[i].display();
									}
						}
					}
					break;
					default : cout << "INVALID OPTION!!!" << endl;
					}
				}
			}
			else{
				cout << "INVALID ID AND PASSWORD!!!\nTRY AGAIN" << endl;
				goto label1;
			}
		}
		break;
		case 3:
			label:
			{
			int temp,z = 1;
			cout << "Select your center : \n";
			for(unsigned l = 0 ; l < centers_v.size() ; l++ )
			{
				cout << z << ". ";
				centers_v[l].display();
				z++;
			}
			cin >> temp;
			string id,password;
			cout << "Enter the login id : ";
			cin >> id;
			cout << "Enter password : ";
			cin >> password;
			if(id == centers_v[temp-1].id && password == centers_v[temp-1].password)
			{
				int choice1;
				while((choice1 = system1->coordinator_menu()) != 0)
				{
					switch(choice1)
					{
					case 1:
					{
						z = 1;
						for(unsigned i= 0 ; i < centers_v.size() ; i++ )
						{
							centers_v[i].display_courses(capacities_v);
						}
					}
					break;
					case 2:
					{
						for(unsigned i = 0 ; i < students_v.size() ; i++ )
						{
							if(students_v[i].allocated_center_id == centers_v[temp-1].id)
								students_v[i].display();
						}
					}
					break;
					case 3:
					{
						int form_no , flag = 0;
						for(unsigned i = 0 ; i < students_v.size() ; i++ )
						{
							if(students_v[i].allocated_center_id == centers_v[temp-1].id && students_v[i].reported == 0)
								students_v[i].display();
						}
						cout << "Enter the form number to update status as reported : ";
						cin >> form_no;
						for(unsigned i = 0 ; i < students_v.size() ; i++ )
						{
							if(students_v[i].form_no == form_no)
							{
								students_v[i].reported = 1;
								flag = 1;
								ofstream my_file("studentsnew.csv");

								for(unsigned p = 0 ; p < students_v.size() ; p++)
								{
									my_file << students_v[p].form_no << "," << students_v[p].name << "," << students_v[p].rank_a << "," << students_v[p].rank_b << "," << students_v[p].rank_c << "," << students_v[p].degree << "," << students_v[p].percentage << "," << students_v[p].allocated_preference << "," << students_v[p].allocated_course_name << "," << students_v[p].allocated_center_id << "," << students_v[p].payment << "," << students_v[p].reported << "," << students_v[p].prn << endl;
								}
								my_file.close();
								remove("students.csv");
								rename("studentsnew.csv", "students.csv");
							}
							cout << "Report status has been updated " << endl;
						}

						if(flag == 0)
						{
							cout << "FORM NUMBER NOT FOUND!!!" << endl;
						}
					}
					break;
					case 4:
					{
						for(unsigned i = 0 ; i < students_v.size() ; i++ )
						{
							if(students_v[i].get_prn() != "NA")
								students_v[i].display();
						}
					}
					break;
					default : cout << "INVALID OPTION !!!" << endl ;
					break;
					}
				}
			}
			else
			{
				cout << "INVALID ID AND PASSWORD!!!" << endl;
				goto label;
			}
			}
		break;
		default: cout << "INVALID OPTION!!" << endl ;
		}
	}

	return 0;
}





