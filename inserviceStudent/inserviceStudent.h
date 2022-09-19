#ifndef __INSERVICE_H
#define __INSERVICE_H

#include "Lib.h"
#include "student.h"

class inserviceStudent : public student {
private:
	string location;
public:
	//inserviceStudent(){}
	//inserviceStudent(string local) :location(local) {}
	~inserviceStudent() {
		student::~student();
	}
	void setLocation(const string&);
	string getLocation();
	void insertData();
	void showInfo();
};

#endif // !__INSERVICE_H