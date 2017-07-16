#ifndef TEACHER_H
#define TEACHER_H
#pragma once
#include "Staff.h"


class Teacher : public Staff
{
public:
	enum Subject {
		MATHS = 0,
		PHYS = 1,
		ENGLISH = 2
	};
	Teacher();
	virtual ~Teacher();
	Teacher(Teacher * other);
	Teacher(int m_NewID, Date m_NewBirthday, char * m_NewName, int m_NewLevel, int m_NewDepID, People::Date m_NewJoinedDate, int m_NewClass, Subject m_NewFirstSubject, Subject m_NewSecondSubject);
	void PrintInfo();
	unsigned int Getm_TeacherCounter();
	void Setm_Class(int m_NewClass);
	int Getm_Class();
	void Setm_FirstSubject(Subject m_NewFirstSubject);
	Subject Getm_FirstSubject();
	void Setm_SecondSubject(Subject m_SecondSubject);
	Subject Getm_SecondSubject();
	int Getm_Rank();
protected:
	static unsigned int m_TeacherCounter;
	int m_Class;
	const static int m_Rank;
	Subject m_FirstSubject;
	Subject m_SecondSubject;
};

#endif // TEACHER_HF:\Workspace\CodeBlocks\Problem solving\PeopleList\src\Student.cpp
