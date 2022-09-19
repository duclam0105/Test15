#ifndef __MANAGE_H
#define __MANAGE_H

#include "department.h"

class Manage {
private:
	vector<Department*> m;
public:
	~Manage() {
		if (m.empty()) {
			for (Department* i : m) {
				delete(i);
			}
		}
	}
	void addDepartmentData();
	int showDepartmentData(const string&);
	void DepartmentDisplay(const int&);
	void showListDepartment();
	int getSize() {
		return m.size();
	}
};

#endif // !__MANAGE_H
