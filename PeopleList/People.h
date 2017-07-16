#ifndef PEOPLE_H
#define PEOPLE_H
#pragma once
#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;


class People
{
public:
	typedef struct Date {
		unsigned int yy;
		unsigned char dd;
		unsigned char mm;
		bool isDateValid(unsigned char Newdd, unsigned char Newmm, unsigned int Newyy) {
			bool valid = true;
			if (Newmm>12 || Newmm<1 || Newdd<1 || Newdd>31)
				valid = false;
			else if ((Newmm == 4 || Newmm == 6 || Newmm == 9 || Newmm == 11) && Newdd == 31)//month with day count<31
				valid = false;
			else if ((Newmm == 2) && (Newyy % 4 == 0) && (Newdd>29))//leap year
				valid = false;
			else if ((Newmm == 2) && (Newyy % 4>0) && (Newdd>28))// not leap year
				valid = false;
			return valid;
		}
		Date() {
		}
		~Date() {
		}
		Date(unsigned char Newdd, unsigned char Newmm, unsigned int Newyy) {
			if (isDateValid(Newdd, Newmm, Newyy)) {
				dd = Newdd;
				mm = Newmm;
				yy = Newyy;
				//std::cout<<"\nDate valid.\n";
			}
			else {
				std::cout << "\nDate " << dd << "/" << mm << "/" << yy << " is invalid.\n";
				delete this;
			}
		}
	}Date;
	int Getm_PeopleCounter();
	int Getm_ID();
	void Setm_ID(int m_NewID);
	Date Getm_Birthday();
	void Setm_Birthday(Date m_NewBirthday);
	char * Getm_Name();
	void Setm_Name(char * m_NewName);
	virtual void PrintInfo();
	People();
	virtual ~People();
	People(People * other);
	People(int m_NewID, Date m_NewBirthday, char * m_NewName);
	virtual int Getm_Rank();
protected:
	static unsigned int m_PeopleCounter;
	int m_ID;
	const static int m_Rank;
	char * m_Name;
	Date m_Birthday;
};

#endif // PEOPLE_H
