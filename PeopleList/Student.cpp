#include "Student.h"

unsigned int Student::m_StudentCounter = 0;
const int Student::m_Rank = 3;
int Student::Getm_Rank() {
	return m_Rank;
}
unsigned int Student::Getm_StudentCounter() {
	return m_StudentCounter;
}
int Student::Getm_Grade() {
	return m_Grade;
}
void Student::Setm_Grade(int m_NewGrade) {
	m_Grade = m_NewGrade;
}
int Student::Getm_NumberOfProject() {
	return m_NumberOfProject;
}
void Student::Setm_NumberOfProject(int m_NewNumberOfProject) {
	m_NumberOfProject = m_NewNumberOfProject;
}
float * Student::Getm_Score() {
	return m_Score;
}
void Student::Setm_Score(float * m_NewScore, int m_NumberOfProject) {
	//std::cout<<sizeof(m_NewScore)/sizeof(m_NewScore[0]);
	m_Score = new float[m_NumberOfProject];
	for (int i = 0; i<m_NumberOfProject; i++) {
		m_Score[i] = m_NewScore[i];
	}
}
float Student::m_AverageScore() {
	float AverageScore = 0.0000;
	for (int i = 0; i<m_NumberOfProject; i++) {
		AverageScore = AverageScore + m_Score[i];
	}
	AverageScore = AverageScore / m_NumberOfProject;
	return AverageScore;
}
float Student::Getm_AverageScore() {
	return m_AverageScore();
}

void Student::PrintInfo() {
	std::cout << "\n\nName : " << People::Getm_Name();
	std::cout << "\nID : " << People::Getm_ID();
	std::cout << "\nBirthday : " << (int)People::Getm_Birthday().dd << "/" << (int)People::Getm_Birthday().mm << "/" << People::Getm_Birthday().yy;
	std::cout << "\nGrade : " << m_Grade;
	std::cout << "\nNumber of Project : " << m_NumberOfProject;
	std::cout << "\nScore : ";
	for (int i = 0; i<m_NumberOfProject; i++) {
		std::cout << m_Score[i] << " ";

	}
	std::cout << "\nAverage Score : " << Getm_AverageScore();
}
Student::Student()
{
	m_StudentCounter++;
	//ctor
}

Student::~Student()
{
	m_StudentCounter--;
	//dtor
}

Student::Student(Student * other)
{
	m_StudentCounter++;
	People::Setm_Birthday(other->m_Birthday);
	People::Setm_ID(other->m_ID);
	People::Setm_Name(other->m_Name);
	Setm_Grade(other->m_Grade);
	Setm_NumberOfProject(other->m_NumberOfProject);
	Setm_Score(other->m_Score, other->m_NumberOfProject);

	//copy ctor
}

Student::Student(int m_NewID, Date m_NewBirthday, char * m_NewName, int m_NewGrade, int m_NewNumberOfProject, float * m_NewScore) {
	People::Setm_ID(m_NewID);
	People::Setm_Birthday(m_NewBirthday);
	People::Setm_Name(m_NewName);
	Setm_Grade(m_NewGrade);
	Setm_NumberOfProject(m_NewNumberOfProject);
	Setm_Score(m_NewScore, m_NewNumberOfProject);
}
