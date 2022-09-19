#ifndef __REGULAR_H
#define __REGULAR_H

#include "Lib.h"
#include "student.h"

class regularStudent : public student {
public:
	regularStudent(){}
	~regularStudent(){
		student::~student();
	}
	void insertData();
	void showInfo();
};

#endif // !__REGULAR_H
