#include <iostream>
#include "Teacher.h"
#include "Student.h"
#define MIN_AVERAGE_SCORE 5

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#ifdef _DEBUG
#define DEBUG_NEW new (_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif // _DEBUG



class Node {
public:
	People * people;
	Node * next;
	static void AddElement(Node *& HeadListPeople, Node *& ListPeople, People * obj);
	static void DeleteElement(Node *& HeadListPeople, Node *& ToBeDeleted);
	Node(Node * obj, Node *& head);
	Node();

};
Node::Node() {
}
Node::Node(Node * obj , Node *& head) {
	if (obj != NULL){
		static int counter = 1;
		if (dynamic_cast<Student*>(obj->people))
			people = new Student(dynamic_cast<Student*>(obj->people));
		else if (dynamic_cast<Teacher*>(obj->people))
			people = new Teacher(dynamic_cast<Teacher*>(obj->people));
		else if (dynamic_cast<Staff*>(obj->people))
			people = new Staff(dynamic_cast<Staff*>(obj->people));
		else
			people = new People(obj->people);
		if (counter == 1) {//storing head info
			head = new Node();
			head = this;
		}
		if (obj->next != NULL) {
			obj = obj->next;
			counter++;
			next = new Node(obj, head);
		}
		else {
			next = NULL;
		}
	}
}

void Node::DeleteElement(Node *& HeadListPeople, Node *& ToBeDeleted) {
	if (HeadListPeople == ToBeDeleted) {//if the one to be deleted id the first node
		if (HeadListPeople != NULL) {
			Node * temp = ToBeDeleted;
			HeadListPeople = ToBeDeleted->next;
			delete temp;
			temp = NULL;
		}
	}
	else {
		for (Node * j = HeadListPeople; j != NULL; j = j->next) { 
			if (j->next == ToBeDeleted) {
				Node * temp = ToBeDeleted;
				j->next = ToBeDeleted->next;
				ToBeDeleted = NULL;
				delete temp; 
				temp = NULL;
				break;
			}
		}
	}
}

void Node::AddElement(Node *& HeadListPeople, Node *& ListPeople, People * obj) {
	//std::cout<<ListPeople<<"\n";
	if (ListPeople == NULL) {//If list is empty
		ListPeople = new Node;
		HeadListPeople = new Node;
		if (dynamic_cast<Student*>(obj))
			ListPeople->people = new Student(dynamic_cast<Student*>(obj));
		else if (dynamic_cast<Teacher*>(obj))
			ListPeople->people = new Teacher(dynamic_cast<Teacher*>(obj));
		else if (dynamic_cast<Staff*>(obj))
			ListPeople->people = new Staff(dynamic_cast<Staff*>(obj));
		else
			ListPeople->people = new People(obj);
		ListPeople->next = NULL;
		HeadListPeople = ListPeople;
	}
	else {//If list is not empty
		for (Node * j = ListPeople; j != NULL; j = j->next) {
			if (j->next == NULL) {
				Node * NewNode = new Node;
				if (dynamic_cast<Student*>(obj))
					NewNode->people = new Student(dynamic_cast<Student*>(obj));
				else if (dynamic_cast<Teacher*>(obj))
					NewNode->people = new Teacher(dynamic_cast<Teacher*>(obj));
				else if (dynamic_cast<Staff*>(obj))
					NewNode->people = new Staff(dynamic_cast<Staff*>(obj));
				else
					NewNode->people = new People(obj);
				j->next = NewNode;
				NewNode->next = NULL;
				break;
			}
		}
	}
}

void DisplayStudentWithMinAverageScore(Node * HeadListPeople) {
	if (HeadListPeople == NULL)
		std::cout << "\nList is empty.\n";
	else {
		for (Node * j = HeadListPeople; j != NULL; j = j->next) {
			if ((dynamic_cast<Student*>(j->people)) && (dynamic_cast<Student*>(j->people)->Getm_AverageScore() >= MIN_AVERAGE_SCORE))
				j->people->PrintInfo();
		}
	}
}

void DisplayListInfo(Node * HeadListPeople) {
	if (HeadListPeople == NULL)
		std::cout << "\nList is empty.\n";
	else {
		for (Node * j = HeadListPeople; j != NULL; j = j->next) {
			j->people->PrintInfo();
			if (j->next == NULL)
				break;
		}
	}
}

void SortUsingBubbleSort(Node *& HeadListPeople)
{
	int count = 0;
	Node * start = HeadListPeople;
	Node * curr = NULL;
	Node * trail = NULL;
	Node * temp = NULL;

	while (start != NULL) { //grab count
		count++;
		start = start->next;
	}

	for (int i = 0; i<count; ++i) { //for every element in the list
		curr = trail = HeadListPeople; //set curr and trail at the start node
		while (curr->next != NULL) { //for the rest of the elements in the list
			if (curr->people->Getm_Rank() > curr->next->people->Getm_Rank()) { //compare curr and curr->next
				temp = curr->next; //swap pointers for curr and curr->next
				curr->next = curr->next->next;
				temp->next = curr;

				//now we need to setup pointers for trail and possibly HeadListPeople
				if (curr == HeadListPeople) //this is the case of the first element swapping to preserve the HeadListPeople pointer
					HeadListPeople = trail = temp;
				else //setup trail correctly
					trail->next = temp;
				curr = temp; //update curr to be temp since the positions changed
			}

			//advance pointers
			trail = curr;
			curr = curr->next;
		}
	}
}



int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//_________Make new List__________//
	Node * HeadListPeople=NULL;
	Node * ListPeople=NULL;


	//_________Add Student_________//
	Student * objStudent;
	People::Date * birthday; float * score;

	birthday = new People::Date(21, 2, 1993);
	score = new float[2];score[0] = 8; score[1] = 9;
	objStudent = new Student(101, *birthday, "IKA", 10, 2, score);
	Node::AddElement(HeadListPeople, ListPeople, objStudent);
	delete birthday; birthday = NULL; delete[] score; score = NULL; delete objStudent; objStudent = NULL;

	birthday = new People::Date(19, 9, 1992);
	score = new float[3];score[0] = 8; score[1] = 9;score[2] = 8;
	objStudent = new Student(102, *birthday, "FAY", 10, 3, score);
	Node::AddElement(HeadListPeople, ListPeople, objStudent);
	delete birthday; birthday = NULL; delete[] score; score = NULL; delete objStudent; objStudent = NULL;

	birthday = new People::Date(22, 1, 1992);
	score = new float[2];score[0] = 7; score[1] = 6;
	objStudent = new Student(103, *birthday, "TIA", 11, 2, score);
	Node::AddElement(HeadListPeople, ListPeople, objStudent);
	delete birthday; birthday = NULL; delete[] score; score = NULL; delete objStudent; objStudent = NULL;

	birthday = new People::Date(18, 5, 1993);
	score = new float[3];score[0] = 7; score[1] = 6;  score[2] = 6;
	objStudent = new Student(104, *birthday, "JUN", 10, 3, score);
	Node::AddElement(HeadListPeople, ListPeople, objStudent);
	delete birthday; birthday = NULL; delete[] score; score = NULL; delete objStudent; objStudent = NULL;

	birthday = new People::Date(18, 5, 1993);
	score = new float[3];score[0] = 7; score[1] = 6;  score[2] = 9;
	objStudent = new Student(105, *birthday, "JON", 10, 3, score);
	Node::AddElement(HeadListPeople, ListPeople, objStudent);
	delete birthday; birthday = NULL; delete[] score; score = NULL; delete objStudent; objStudent = NULL;



	//_________Add Teacher_________//
	Teacher * objTeacher;
	People::Date * JoinedDate;

	birthday = new People::Date(2, 2, 1991);
	JoinedDate = new People::Date(31, 1, 2011);
	objTeacher = new Teacher(106, *birthday, "KAI", 1, 201, *JoinedDate, 10, Teacher::MATHS, Teacher::ENGLISH);
	Node::AddElement(HeadListPeople, ListPeople, objTeacher);
	delete birthday; birthday = NULL; delete JoinedDate; JoinedDate = NULL; delete objTeacher; objTeacher = NULL;

	birthday = new People::Date(1, 11, 1990);
	JoinedDate = new People::Date(3, 5, 2010);
	objTeacher = new Teacher(107, *birthday, "FIA", 1, 202, *JoinedDate, 11, Teacher::PHYS, Teacher::ENGLISH);
	Node::AddElement(HeadListPeople, ListPeople, objTeacher);
	delete birthday; birthday = NULL; delete JoinedDate; JoinedDate = NULL; delete objTeacher; objTeacher = NULL;

	birthday = new People::Date(13, 10, 1991);
	JoinedDate = new People::Date(9, 9, 2011);
	objTeacher = new Teacher(108, *birthday, "SAN", 2, 203, *JoinedDate, 11, Teacher::PHYS, Teacher::MATHS);
	Node::AddElement(HeadListPeople, ListPeople, objTeacher);
	delete birthday; birthday = NULL; delete JoinedDate; JoinedDate = NULL; delete objTeacher; objTeacher = NULL;

	birthday = new People::Date(15, 1, 1991);
	JoinedDate = new People::Date(9, 4, 2012);
	objTeacher = new Teacher(109, *birthday, "FIR", 1, 204, *JoinedDate, 10, Teacher::PHYS, Teacher::MATHS);
	Node::AddElement(HeadListPeople, ListPeople, objTeacher);
	delete birthday; birthday = NULL; delete JoinedDate; JoinedDate = NULL; delete objTeacher; objTeacher = NULL;

	birthday = new People::Date(30, 1, 1992);
	JoinedDate = new People::Date(9, 12, 2011);
	objTeacher = new Teacher(110, *birthday, "KUN", 1, 205, *JoinedDate, 11, Teacher::ENGLISH, Teacher::MATHS);
	Node::AddElement(HeadListPeople, ListPeople, objTeacher);
	delete birthday; birthday = NULL; delete JoinedDate; JoinedDate = NULL; delete objTeacher; objTeacher = NULL;

	//_________Add Staff_________//
	Staff * objStaff;

	birthday = new People::Date(23, 1, 1992);
	JoinedDate = new People::Date(31, 8, 2011);
	objStaff = new Staff(111, *birthday, "PIA", 1, 206, *JoinedDate);
	Node::AddElement(HeadListPeople, ListPeople, objStaff);
	delete birthday; birthday = NULL; delete JoinedDate; JoinedDate = NULL; delete objStaff; objStaff = NULL;

	birthday = new People::Date(28, 10, 1991);
	JoinedDate = new People::Date(3, 12, 2011);
	objStaff = new Staff(112, *birthday, "WIN", 2, 207, *JoinedDate);
	Node::AddElement(HeadListPeople, ListPeople, objStaff);
	delete birthday; birthday = NULL; delete JoinedDate; JoinedDate = NULL; delete objStaff; objStaff = NULL;

	birthday = new People::Date(2, 11, 1991);
	JoinedDate = new People::Date(3, 11, 2011);
	objStaff = new Staff(113, *birthday, "SHA", 2, 208, *JoinedDate);
	Node::AddElement(HeadListPeople, ListPeople, objStaff);
	delete birthday; birthday = NULL; delete JoinedDate; JoinedDate = NULL; delete objStaff; objStaff = NULL;

	birthday = new People::Date(16, 8, 1992);
	JoinedDate = new People::Date(1, 9, 2012);
	objStaff = new Staff(114, *birthday, "SIN", 2, 209, *JoinedDate);
	Node::AddElement(HeadListPeople, ListPeople, objStaff);
	delete birthday; birthday = NULL; delete JoinedDate; JoinedDate = NULL; delete objStaff; objStaff = NULL;

	birthday = new People::Date(19, 4, 1993);
	JoinedDate = new People::Date(1, 12, 2012);
	objStaff = new Staff(115, *birthday, "LIN", 1, 210, *JoinedDate);
	Node::AddElement(HeadListPeople, ListPeople, objStaff);
	delete birthday; birthday = NULL; delete JoinedDate; JoinedDate = NULL; delete objStaff; objStaff = NULL;


	std::cout << "\n_________________List of People_________________\n";
	DisplayListInfo(HeadListPeople);

	std::cout<<"\n\n\n___List of Student with Minimal Average Score = "<<MIN_AVERAGE_SCORE<<"___\n";
	DisplayStudentWithMinAverageScore(HeadListPeople);

	std::cout << "\n\n\n\n_________List of People After Sorting_________\n";
	SortUsingBubbleSort(HeadListPeople);
	DisplayListInfo(HeadListPeople);


	std::cout << "\n\n\n\n______List of People After One of the Node is Deleted______\n";
	Node::DeleteElement(HeadListPeople, ListPeople);
	DisplayListInfo(HeadListPeople);

	std::cout << "\n\n\n\n__________Copied List of People__________\n";
	Node * HeadListPeopleCopy=NULL;
	Node * ListPeopleCopy = NULL;
	ListPeopleCopy = new Node(HeadListPeople, HeadListPeopleCopy);
	DisplayListInfo(HeadListPeopleCopy);
	
	//Deleting list memory in heap//
	delete HeadListPeople;
	delete HeadListPeopleCopy;
	HeadListPeople = NULL;
	HeadListPeopleCopy = NULL;
	ListPeople = NULL;
	ListPeopleCopy = NULL;
	std::cout << std::endl;

	_CrtDumpMemoryLeaks();
	return 0;
}
