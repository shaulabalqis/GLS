
#ifndef STAFF_H
#define STAFF_H
#pragma once
#include "People.h"


class Staff : public People
{
public:
	Staff();
	virtual ~Staff();
	Staff(Staff * other);
	Staff(int m_NewID, Date m_NewBirthday, char * m_NewName, int m_NewLevel, int m_NewDepID, People::Date m_NewJoinedDate);
	virtual void PrintInfo();
	unsigned int Getm_StaffCounter();
	int Getm_Level();
	void Setm_Level(int m_NewLevel);
	int Getm_DepID();
	void Setm_DepID(int m_NewDepID);
	Date Getm_JoinedDate();
	void Setm_JoinedDate(Date m_NewJoinedDate);
	virtual int Getm_Rank();

protected:
	static unsigned int m_StaffCounter;
	int m_Level;
	int m_DepID;
	const static int m_Rank;
	People::Date m_JoinedDate;

};

#endif // STAFF_H
