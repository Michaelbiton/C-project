#pragma once
#include <string>
#include <iostream>
using namespace std;
#include "School.h"
#include "Class.h"
#include "Layer.h"
#include "Manager.h"
#include "Secretary.h"

School::School()
{
	layer = new Layer*[layerNum];
	for (int i = 0,j=97; i < layerNum; ++i,++j)
	{
		layer[i]=new Layer(j);
	}
	person = new Person*[personNum];
	manager = false;
}
void School::manu()
{
	int choise=0;

	while (choise!=10)
	{
		cout << endl << endl << endl;
		cout << "Enter number between 1-10:" << endl;
		cout << "[1] Add pupil:" << endl;
		cout << "[2] Add teacher:" << endl;
		cout << "[3] Add tutor:" << endl;
		cout << "[4] Add manager:" << endl;
		cout << "[5] Add secretary:" << endl;
		cout << "[6] Print worker and pupil detail:" << endl;
		cout << "[7] Print outstanding people" << endl;
		cout << "[8] Print tutor`s class" << endl;
		cout << "[9] Print worker details with smallest salary:" << endl;
		cout << "[10] Exit!" << endl;
		cin >> choise;

		while (choise > 10 || choise < 1)
		{
			cout << "You entered invaild number, please enter again" << endl;
			cout << "Enter number between 1-10:" << endl;
			cout << "[1] Add pupil:" << endl;
			cout << "[2] Add teacher:" << endl;
			cout << "[3] Add tutor:" << endl;
			cout << "[4] Add manager:" << endl;
			cout << "[5] Add secretary:" << endl;
			cout << "[6] Print worker and pupil detail:" << endl;
			cout << "[7] Print outstanding people" << endl;
			cout << "[8] Print tutor`s class" << endl;
			cout << "[9] Print worker details with smallest salary:" << endl;
			cout << "[10] Exit!" << endl;
			cin >> choise;
		}
		switch (choise)
		{
			case 1:
			{
				string first_name, last_name;
				char layer_name;
				int class_num, id, grades_num=0,pupil_num=0,flag=0;
				pupil_num++;
				cout << "For adding pupil please follow the instruction`s:" << endl;
				cout << "Enter First name:";
				cin >> first_name;
				cout << "Enter Last name:";
				cin >> last_name;
				cout << "Enter pupil ID:";
				cin >> id;
				for (int i = 0; i < personNum; ++i)
				{
					if (id == person[i]->getID())
					{
						cout << "the person is already in the system!" << endl << endl;
						flag=1;
					}
				}
				if (flag == 1)
				{
					break;
				}
				cout << "Enter class number[1-3]:";
				cin >> class_num;
				cout << "Enter layer name[a-f]:";
				cin >> layer_name;
				cout << "Enter the number of courses he take:";
				cin >> grades_num;
				while(grades_num > (layer_name - 92))
				{
					cout << "The number of courses are not available in this layer " << endl << "please enter the correct number" << endl;
					cout << "Enter the number of courses he take:";
					cin >> grades_num;
				}
				int* grades = new int[grades_num];
				cout << "Enter the pupil grades[0-100]:" << endl;
				for (int i = 0; i < grades_num; ++i)
					{
					cout << "Enter grade number" << i + 1 << endl;;
						cin >> grades[i];
					}
				Person** temp = new Person*[personNum];
				for (int i = 0; i < personNum; ++i)
				{
					temp[i] = person[i];
				}
				personNum++;
				person = new Person*[personNum];
				for (int i = 0; i < personNum; ++i)
				{
					person[i] = temp[i];
				}
				person[personNum - 1] = new Pupil(first_name, last_name, id, grades, grades_num, class_num, layer_name);
				delete[]temp;


				Pupil *p = new Pupil(first_name, last_name, id, grades, grades_num, class_num, layer_name);
				layer[layer_name - 97]->addPupil(class_num-1,p);
				break;
			}
			case 2:
			{
				string first_name, last_name;
				string* nameofcourses=	NULL;
				int id,exp,flag=0,courses_num=0;

				cout << "For adding Teacher please follow the instruction`s:" << endl;
				cout << "Enter First name:";
				cin >> first_name;
				cout << "Enter Last name:";
				cin >> last_name;
				cout << "Enter Teacher ID:";
				cin >> id;
				for (int i = 0; i < personNum; ++i)
				{
					if (id == person[i]->getID())
					{
						cout << "the person is already in the system!" << endl << endl;
						flag = 1;
					}
				}
				if (flag == 1)
				{
					break;
				}
				cout << "Enter years of expirience:";
				cin >> exp;
				cout << "Enter the number of courses that the teacher teach:";
				cin >> courses_num;
				nameofcourses = new string[courses_num];
				cout << "Enter the name`s of the courses the teacher teach:" << endl;
				for (int i = 0; i < courses_num; ++i)
				{
					cin >> nameofcourses[i];
				}


				Person** temp = new Person*[personNum];
				for (int i = 0; i < personNum; ++i)
				{
					temp[i] = person[i];
				}
				personNum++;
				person = new Person*[personNum];
				for (int i = 0; i < personNum; ++i)
				{
					person[i] = temp[i];
				}
				person[personNum - 1] = new Teacher(first_name, last_name, id, exp, nameofcourses, courses_num);
				delete[]temp;

				break;

			}
			case 3:
			{
				string first_name, last_name;
				string* nameofcourses = NULL;
				int id, exp, flag = 0, courses_num = 0,clas_num=0;
				char layer_name;

				cout << "For adding Tutor please follow the instruction`s:" << endl;
				cout << "Enter First name:";
				cin >> first_name;
				cout << "Enter Last name:";
				cin >> last_name;
				cout << "Enter Tutor ID:";
				cin >> id;
				for (int i = 0; i < personNum; ++i)
				{
					if (id == person[i]->getID())
					{
						cout << "the person is already in the system!" << endl << endl;
						flag = 1;
					}
				}
				if (flag == 1)
				{
					break;
				}
				cout << "Enter the name of the layer that the tutor belongs to[a-f]";
				cin >> layer_name;
				cout << "Enter the number of the class[1-3]";
				cin >> clas_num;
				if (layer[layer_name - 97]->Tutor_chack(clas_num) == true)
				{
					cout << "There is already Tutor for this class!" << endl;
					break;
				}
				cout << "Enter years of expirience:";
				cin >> exp;
				cout << "Enter the number of courses that the tutor teach:";
				cin >> courses_num;
				nameofcourses = new string[courses_num];
				cout << "Enter the name`s of the courses the tutor teach:" << endl;
				for (int i = 0; i < courses_num; ++i)
				{
					cin >> nameofcourses[i];
				}
				

				Person** temp = new Person*[personNum];
				for (int i = 0; i < personNum; ++i)
				{
					temp[i] = person[i];
				}
				personNum++;
				person = new Person*[personNum];
				for (int i = 0; i < personNum; ++i)
				{
					person[i] = temp[i];
				}

				Class* C = layer[layer_name - 97]->getClass(clas_num);
				Tutor* T= new Tutor(first_name,last_name, id, exp, nameofcourses, courses_num, C);
				person[personNum - 1] = T;
				delete[]temp;
				
				layer[layer_name - 97]->addTutor(clas_num, T);
				break;

			}
			case 4:
			{
				if (manager == true)
				{
					cout << "There is already manager to the school";
					break;
				}
				string first_name, last_name;
				char layer_name;
				int id, pupil_num = 0, flag = 0,exp=0;
				pupil_num++;
				cout << "For adding Manager please follow the instruction`s:" << endl;
				cout << "Enter First name:";
				cin >> first_name;
				cout << "Enter Last name:";
				cin >> last_name;
				cout << "Enter Manager ID:";
				cin >> id;
				for (int i = 0; i < personNum; ++i)
				{
					if (id == person[i]->getID())
					{
						cout << "the person is already in the system!" << endl << endl;
						flag = 1;
					}
				}
				if (flag == 1)
				{
					break;
				}
				cout << "Enter years of expirience:";
				cin >> exp;
			
				Person** temp = new Person*[personNum];
				for (int i = 0; i < personNum; ++i)
				{
					temp[i] = person[i];
				}
				personNum++;
				person = new Person*[personNum];
				for (int i = 0; i < personNum; ++i)
				{
					person[i] = temp[i];
				}
				
				person[personNum - 1] = new Manager(first_name, last_name, id, exp);
				delete[]temp;

				manager = true;
				
				break;
			}
			case 5:
			{
				string first_name, last_name;
				int id, pupil_num = 0, flag = 0, exp = 0,child=0;
				pupil_num++;
				cout << "For adding Secretary please follow the instruction`s:" << endl;
				cout << "Enter First name:";
				cin >> first_name;
				cout << "Enter Last name:";
				cin >> last_name;
				cout << "Enter Secretary ID:";
				cin >> id;
				for (int i = 0; i < personNum; ++i)
				{
					if (id == person[i]->getID())
					{
						cout << "the person is already in the system!" << endl << endl;
						flag = 1;
					}
				}
				if (flag == 1)
				{
					break;
				}
				cout << "Enter years of expirience:";
				cin >> exp;
				cout << "Enter the number of children who learn in this school:";
				cin >> child;
				Person** temp = new Person*[personNum];
				for (int i = 0; i < personNum; ++i)
				{
					temp[i] = person[i];
				}
				personNum++;
				person = new Person*[personNum];
				for (int i = 0; i < personNum; ++i)
				{
					person[i] = temp[i];
				}

				person[personNum - 1] = new Secretary(first_name, last_name, id, exp,child);
				delete[]temp;

				break;
			}
			case 6:
			{
				for (int i = 0; i < personNum; ++i)
				{
					person[i]->print();
				}
				break;
			}
			case 7:
			{
				cout << "The outstanding people in school is:" << endl;
				for (int i = 0; i < personNum; ++i)
				{
					if (person[i]->excellent() == true)
					{
						person[i]->print();
					}
				}
				break;
			}
			case 8:
			{
				int id = 0;
				cout << "Enter id:" << endl;
				cin >> id;

				for (int i = 0; i < personNum; ++i)
				{
					if (person[i]->getID() == id)
					{
						if (person[i]->getType() == 3)
						{
							person[i]->print();
						}
							
					}
				}
				break;
			}
			case 9:
			{
				float salary = 0;
				int flag1 = 0,flag2=0;
				for (int i = 0; i < personNum; ++i)
				{
					if (person[i]->getType() != 1)
					{
						salary = person[i]->get_Salary();
						flag1 = i;
					}
				}
				for (int i = flag1+1; i < personNum; ++i)
				{
					if (person[i]->getType() != 1)
					{
						if (person[i]->get_Salary() <= salary)
						{
							salary = person[i]->get_Salary();
							flag2 = i;
						}
					}
						
				}
				cout << "The worker with the smallest salary is:-" <<endl;
				person[flag2]->print();

			}
		}


	}
	cout << "Goodbye!" << endl;
}