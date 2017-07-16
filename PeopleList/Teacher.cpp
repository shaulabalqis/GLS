#include "Teacher.h"

unsigned int Teacher::m_TeacherCounter = 0;
const int Teacher::m_Rank = 2;
int Teacher::Getm_Rank() {
	return m_Rank;
}
unsigned int Teacher::Getm_TeacherCounter() {
	return m_TeacherCounter;
}
void Teacher::Setm_Class(int m_NewClass) {
	m_Class = m_NewClass;
}
int Teacher::Getm_Class() {
	return m_Class;
}
void Teacher::Setm_FirstSubject(Teacher::Subject m_NewFirstSubject) {
	m_FirstSubject = m_NewFirstSubject;
}
Teacher::Subject Teacher::Getm_FirstSubject() {
	return m_FirstSubject;
}
void Teacher::Setm_SecondSubject(Teacher::Subject m_NewSecondSubject) {
	m_SecondSubject = m_NewSecondSubject;
}
Teacher::Subject Teacher::Getm_SecondSubject() {
	return m_SecondSubject;
}

void Teacher::PrintInfo() {
	char * Sub[] = { "MATHS", "PHYS", "ENGLISH" };
	std::cout << "\n\nName : " << People::Getm_Name();
	std::cout << "\nID : " << People::Getm_ID();
	std::cout << "\nBirthday : " << (int)People::Getm_Birthday().dd << "/" << (int)People::Getm_Birthday().mm << "/" << People::Getm_Birthday().yy;
	std::cout << "\nLevel : " << Staff::Getm_Level();
	std::cout << "\nDepartement ID : " << Staff::Getm_DepID();
	std::cout << "\nJoined Date : " << (int)Staff::Getm_JoinedDate().dd << "/" << (int)Staff::Getm_JoinedDate().mm << "/" << Staff::Getm_JoinedDate().yy;
	std::cout << "\nClass : " << m_Class;
	std::cout << "\nFirst Subject : " << Sub[m_FirstSubject];
	std::cout << "\nSecond Subject : " << Sub[m_SecondSubject];
	//delete[] Sub;
	//Sub = NULL;
}
Teacher::Teacher()
{
	m_TeacherCounter++;//ctor
}

Teacher::~Teacher()
{
	//delete m_Name;
	//m_Name = NULL;
	m_TeacherCounter--;
	//dtor
}

Teacher::Teacher(Teacher * other)
{
	m_TeacherCounter++;
	People::Setm_Birthday(other->m_Birthday);
	People::Setm_ID(other->m_ID);
	People::Setm_Name(other->m_Name);
	Staff::Setm_Level(other->m_Level);
	Staff::Setm_DepID(other->m_DepID);
	Staff::Setm_JoinedDate(other->m_JoinedDate);
	Setm_Class(other->m_Class);
	Setm_FirstSubject(other->m_FirstSubject);
	Setm_SecondSubject(other->m_SecondSubject);
	//copy ctor
}

Teacher::Teacher(int m_NewID, Date m_NewBirthday, char * m_NewName, int m_NewLevel, int m_NewDepID, People::Date m_NewJoinedDate, int m_NewClass, Subject m_NewFirstSubject, Subject m_NewSecondSubject) {
	People::Setm_ID(m_NewID);
	People::Setm_Birthday(m_NewBirthday);
	People::Setm_Name(m_NewName);
	Staff::Setm_Level(m_NewLevel);
	Staff::Setm_DepID(m_NewDepID);
	Staff::Setm_JoinedDate(m_NewJoinedDate);
	Setm_Class(m_NewClass);
	Setm_FirstSubject(m_NewFirstSubject);
	Setm_SecondSubject(m_NewSecondSubject);
}



