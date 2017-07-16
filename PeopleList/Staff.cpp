#include "Staff.h"

unsigned int Staff::m_StaffCounter = 0;
const int Staff::m_Rank = 1;
int Staff::Getm_Rank() {
	return m_Rank;
}
unsigned int Staff::Getm_StaffCounter() {
	return m_StaffCounter;
}
int Staff::Getm_Level() {
	return m_Level;
}
void Staff::Setm_Level(int m_NewLevel) {
	m_Level = m_NewLevel;
}
int Staff::Getm_DepID() {
	return m_DepID;
}
void Staff::Setm_DepID(int m_NewDepID) {
	m_DepID = m_NewDepID;
}
People::Date Staff::Getm_JoinedDate() {
	return m_JoinedDate;
}
void Staff::Setm_JoinedDate(People::Date m_NewJoinedDate) {
	m_JoinedDate.dd = m_NewJoinedDate.dd;
	m_JoinedDate.mm = m_NewJoinedDate.mm;
	m_JoinedDate.yy = m_NewJoinedDate.yy;
}
void Staff::PrintInfo() {
	std::cout << "\n\nName : " << People::Getm_Name();
	std::cout << "\nID : " << People::Getm_ID();
	std::cout << "\nBirthday : " << (int)People::Getm_Birthday().dd << "/" << (int)People::Getm_Birthday().mm << "/" << People::Getm_Birthday().yy;
	std::cout << "\nLevel : " << m_Level;
	std::cout << "\nDepartement ID : " << m_DepID;
	std::cout << "\nJoined Date : " << (int)m_JoinedDate.dd << "/" << (int)m_JoinedDate.mm << "/" << m_JoinedDate.yy;
}

Staff::Staff()
{
	m_StaffCounter++;
	//ctor
}

Staff::~Staff()
{
	m_StaffCounter--;
	//dtor
}

Staff::Staff(Staff * other)
{
	m_StaffCounter++;
	People::Setm_Birthday(other->m_Birthday);
	People::Setm_ID(other->m_ID);
	People::Setm_Name(other->m_Name);
	Setm_Level(other->m_Level);
	Setm_DepID(other->m_DepID);
	Setm_JoinedDate(other->m_JoinedDate);
	//copy ctor
}
Staff::Staff(int m_NewID, Date m_NewBirthday, char * m_NewName, int m_NewLevel, int m_NewDepID, People::Date m_NewJoinedDate) {
	People::Setm_ID(m_NewID);
	People::Setm_Birthday(m_NewBirthday);
	People::Setm_Name(m_NewName);
	Setm_Level(m_NewLevel);
	Setm_DepID(m_NewDepID);
	Setm_JoinedDate(m_NewJoinedDate);
}
