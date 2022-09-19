#ifndef __STUDENT_H
#define __STUDENT_H

#include "Lib.h"
#include "ketquahoctap.h"

class student {
	friend class Department;
private:
	string id;
	string name;
	string date;
	int entryYear;
	float gradeEntry;
	vector<Ketquahoctap*> vs;
	typestudent type;
public:
	//student():id(""), name(""), date(""), entryYear(0), gradeEntry(0.0) {}
	//student(string id, string name, string date, int year, float grade) :
	//	id(id), name(name), date(date), entryYear(year), gradeEntry(grade) {}
	virtual ~student() {
		if (!vs.empty()) {
			for (Ketquahoctap* i : vs) {
				delete(i);
			}
		}
	}
	void setID(const string&);
	void setName(const string&);
	void setDate(const string&);
	void setEntryYear(const int&);
	void setGradeEntry(const float&);
	void setType(const typestudent&);
	string getID();
	string getName();
	string getData();
	int getEntryYear();
	float getGradeEntry();
	typestudent getType();
	void addResult();
	void showResult();
	void showResultBySemester();
	int getListResultSize() {
		return vs.size();
	}

	virtual void insertData();
	virtual void showInfo();
};

#endif // ! __STUDENT_H
