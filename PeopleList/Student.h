#ifndef STUDENT_H
#define STUDENT_H
#pragma once
#include "People.h"



class Student : public People
{
public:
	Student();
	virtual ~Student();
	Student(Student * other);
	Student(int m_NewID, Date m_NewBirthday, char * m_NewName, int m_NewGrade, int m_NewNumberOfProject, float * m_NewScore);
	void PrintInfo();
	unsigned int Getm_StudentCounter();
	int Getm_Grade();
	void Setm_Grade(int m_NewGrade);
	int Getm_NumberOfProject();
	void Setm_NumberOfProject(int m_NewNumberOfProject);
	float * Getm_Score();
	void Setm_Score(float * m_NewScore, int m_NumberOfProject);
	float Getm_AverageScore();
	int Getm_Rank();


protected:
	int m_Grade;
	int m_NumberOfProject;
	const static int m_Rank;
	static unsigned int m_StudentCounter;
	float * m_Score;
	float m_AverageScore();
	
	
};

#endif // STUDENT_H
