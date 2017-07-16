#include "People.h"
#include <string.h>
#include <iostream>

unsigned int People::m_PeopleCounter = 0;
const int People::m_Rank = 0;
int People::Getm_Rank() {
	return m_Rank;
}
int People::Getm_PeopleCounter() {
	return m_PeopleCounter;
}
int People::Getm_ID() {
	return m_ID;
}
void People::Setm_ID(int m_NewID) {
	m_ID = m_NewID;
}
People::Date People::Getm_Birthday() {
	return m_Birthday;
}
void People::Setm_Birthday(People::Date m_NewBirthday) {
	m_Birthday.dd = m_NewBirthday.dd;
	m_Birthday.mm = m_NewBirthday.mm;
	m_Birthday.yy = m_NewBirthday.yy;
}
char * People::Getm_Name() {
	return m_Name;
}
void People::Setm_Name(char * m_NewName) {
	int i = 0;
	m_Name = new char[strlen(m_NewName) + 1];
	for (i = 0; i<(int)strlen(m_NewName) + 1; i++)
		m_Name[i] = m_NewName[i];
	m_Name[i] = '\0';
}

void People::PrintInfo() {
	std::cout << "\n\nName : " << m_Name;
	std::cout << "\nID : " << m_ID;
	std::cout << "\nBirthday : " << (int)m_Birthday.dd << "/" << (int)m_Birthday.mm << "/" << m_Birthday.yy;
}

People::People()
{
	m_PeopleCounter++;//ctor
}

People::~People()
{
	m_PeopleCounter--;
	//delete this;
	//dtor
}

People::People(People * other)
{
	m_PeopleCounter++;
	Setm_ID(other->m_ID);
	Setm_Birthday(other->m_Birthday);
	Setm_Name(other->m_Name);
	//copy ctor
}
People::People(int m_NewID, Date m_NewBirthday, char * m_NewName) {
	Setm_ID(m_NewID);
	Setm_Birthday(m_NewBirthday);
	Setm_Name(m_NewName);
}
