#ifndef __RESULT_H
#define __RESULT_H

#include "Lib.h"

class Ketquahoctap {
	friend class Department;
	friend class student;
private:
	string semester;
	float gpa;
	//pair<string, float > infor;
public:
	void setSemester(string);
	void setGPA(float);
	string getSemester();
	float getGPA();
	void insertResult();
	void showResult();
};

#endif // !__RESULT_H
