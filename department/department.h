#ifndef __DEPARTMENT_H
#define __DEPARTMENT_H

#include "Lib.h"
#include "student.h"
#include "regularStudent.h"
#include "inserviceStudent.h"
#include "ketquahoctap.h"

class Department {
    vector<shared_ptr<student>> v;
    string departmentName;
    int numberRegular = 0;
    int numberInservice = 0;
public:
    ~Department() {
        /*if (!v.empty()) {
            for (shared_ptr<Student> i : v) {
                delete(i);
            }
        }*/
    }
    void setDepartmentName(const string&);
    string getDepartmentName();
    int getNumberRegular();
    int getNumberInservice();
    void addStudentData();
    void delStudentData(const string&);
    void findStudentData(const string&);
    void findStudentDataByType();
    void showStudentList();
    void showMemberData(const unsigned int&);
    void changeStudentData(const int&);                 //unused
    void selectionSort();                               //Sap xep danh sach tang dan theo loai (regular -> in-service) va giam dan theo nam hoc
    void addStudentResult(const string&);
    void showStudentResult(const string&);
    void getBestGPASemester();
    void getBestGPAEver();
    int sizeList() {
        return v.size();
    }
};

#endif // !__DEPARTMENT_H