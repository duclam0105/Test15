#include "department.h"

extern set<string> listID;

//DEPARTMENT FUNCTION ==========================================================//
void Department::setDepartmentName(const string& name)          { this->departmentName = name; }

string Department::getDepartmentName()                          { return this->departmentName; }

int Department::getNumberRegular()                              { return this->numberRegular; }

int Department::getNumberInservice()                            { return this->numberInservice; }

void Department::addStudentData() {
    int a;
    cout << "1-Regular student - 2-In-service student - 0-Back: ";
    cin >> a;
    switch (a) {
    case exit_t:
        return;
    case regular_t: {
        shared_ptr<regularStudent> p(new regularStudent);
        p->insertData();
        p->showInfo();
        v.push_back(p);
        numberRegular++;
        break;
    }
    case inservice_t: {
        shared_ptr<inserviceStudent> p(new inserviceStudent);
        p->insertData();
        p->showInfo();
        v.push_back(p);
        numberInservice++;
        break;
    }
    default:
        cout << "Nhap sai! Nhap so trong khoang 0 - 2\n";
        break;
    }
    /*sort(v.begin(), v.end()); */                              //Sap xep theo thu tu giam dan ho ten
    //selectionSort();
    int q;
    cout << "Ban co muon tiep tuc? 1-Yes - 0-No: ";
    cin >> q;
    if (q == yes) {
        Department::addStudentData();
    }
}

void Department::delStudentData(const string& id) {
    int count = 0;
    if (v.empty()) {
        cout << "No data in list!" << endl;
        return;
    }
    for (int i = 0; i < v.size(); i++) {
        if (v[i]->getID() == id) {
            count++;
            if (v[i]->getType() == regular_s) {
                numberRegular--;
            }
            else if (v[i]->getType() == inservice_s) {
                numberInservice--;
            }
            v.erase(v.begin() + i);
            i--;
        }
    }
    if (count == 0) {
        cout << "Can not find student has ID: " << id << " in list!" << endl;
        return;
    }
    cout << "Delete done!" << endl;
}

void Department::findStudentData(const string& id) {
    int count = 0;
    //if (v.empty()) {
    //    cout << "No data in list!" << endl;
    //    return;
    //}
    for (int i = 0; i < v.size(); i++) {
        if (v[i]->getID() == id) {
            count++;
            cout << i + 1 << ". ";
            showMemberData(i);
        }
    }
    if (count == 0) {
        cout << "Can not find student has ID: " << id << " in list!" << endl;
        return;
    }
}

void Department::findStudentDataByType() {
    if (v.empty()) {
        cout << "No data in list!" << endl;
        return;
    }
    int temp;
    cout << "1-Tim theo ID - 2-Tim theo ten khu vuc tai chuc - 3-Tim sinh vien theo nam vao hoc: ";
    cin >> temp;
    switch (temp)
    {
    case 1: {
        string tmp_id;
        do {
            cout << "Nhap so ID cua sinh vien can tim kiem: ";
            cin >> tmp_id;
            if (tmp_id == "0") break;
        } while (!checkValidID(tmp_id));
        findStudentData(tmp_id);
        break;
    }
    case 2: {
        string tmp_location;
        int count = 0;
        cout << "Nhap ten khu vuc tai chuc: ";
        cin.ignore();
        getline(cin, tmp_location);
        chuanhoaTen(tmp_location);
        for (int i = 0; i < v.size(); i++) {
            if (v[i]->getType() == inservice_s) {
                shared_ptr<inserviceStudent> p = dynamic_pointer_cast<inserviceStudent>(v[i]);
                if (p->getLocation() == tmp_location) {
                    count++;
                    cout << i + 1 << ". ";
                    p->showInfo();
                }
            }
        }
        if (count == 0) {
            cout << "Khong co sinh vien tai chuc nao duoc dao tao tai " << tmp_location << endl;
        }
        break;
    }
    case 3: {
        int tmp_entryYear;
        int count = 0;
        cout << "Nhap nam vao hoc (Entry Year): ";
        cin >> tmp_entryYear;
        for (int i = 0; i < v.size(); i++) {
            if (v[i]->getEntryYear() == tmp_entryYear) {
                count++;
                showMemberData(i);
            }
        }
        if (count == 0) {
            cout << "Khong co sinh vien nao nhap hoc nam " << tmp_entryYear << endl;
        }
    }
    default:
        break;
    }
    
}

void Department::showStudentList() {
    if (v.empty()) {
        cout << "No data in list!" << endl;
        return;
    }
    cout << "Danh sach sinh vien Khoa " << hienthichuinhoa(getDepartmentName()) << endl;
    cout << "Sinh vien chinh quy: " << numberRegular << " | Sinh vien tai chuc: " << numberInservice << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << i + 1 << ". ";
        showMemberData(i);
    }
}

void Department::showMemberData(const unsigned int& index) {
    if (v.empty()) {
        // cout << "No data in list!"<<endl;
        return;
    }
    if (index < v.size()) {
        if (v[index]->getType() == regular_s) {
            shared_ptr<regularStudent> p(dynamic_pointer_cast<regularStudent>(v[index]));
            p->showInfo();
        }
        else if (v[index]->getType() == inservice_s) {
            shared_ptr<inserviceStudent> p(dynamic_pointer_cast<inserviceStudent>(v[index]));
            p->showInfo();
        }
    }
}

void Department::changeStudentData(const int& index) {
    if (!v.empty()) {
        if (index < v.size()) {
            v[index]->insertData();
        }
    }
}

void Department::selectionSort() {              //  < : GIAM DAN, > : TANG DAN
    //sort type
    for (int i_start = 0; i_start < v.size(); i_start++)
    {
        int minIndex = i_start;
        for (int i_current = i_start + 1; i_current < v.size(); i_current++)
        {
            if (v[minIndex]->getType() > v[i_current]->getType())
            {
                minIndex = i_current;
            }
        }
        swap(v[i_start], v[minIndex]);
    }
    //sort entry year
    for (int i_start = 0; i_start < v.size() - 1; i_start++)
    {
        int minIndex = i_start;
        for (int i_current = i_start + 1; i_current < v.size(); i_current++)
        {
            if (v[minIndex]->getType() == v[i_current]->getType()) {
                if (v[minIndex]->getEntryYear() < v[i_current]->getEntryYear()) {
                    minIndex = i_current;
                }
            }
        }
        swap(v[i_start], v[minIndex]);
    }
}

void Department::addStudentResult(const string& id) {
    if (v.empty()) {
        cout << "No data in list!" << endl;
        return;
    }
    for (int i = 0; i < v.size(); i++) {
        if (v[i]->getID() == id) {
            cout << "Nhap ket qua hoc tap cua sinh vien " << id << " :\n";
            v[i]->addResult();
        }
    }
}

void Department::showStudentResult(const string& id) {
    int count = 0;              //Gia su khong co sinh vien nao co ID trung nhau
    if (v.empty()) {
        cout << "No data in list!" << endl;
        return;
    }
    for (int i = 0; i < v.size(); i++) {
        if (v[i]->getID() == id) {
            count++;
            cout << "Ket qua hoc tap cua sinh vien " << id << " :\n";
            v[i]->showResult();
        }
        if (count) {
            int tmp;
            cout << "Tim kiem theo hoc ki? 1-Yes - 0-No: ";
            cin >> tmp;
            switch (tmp)
            {
            case no: {
                break;
            }
            case yes: {
                v[i]->showResultBySemester();
                break;
            }
            default:
                break;
            }
            return;
        }
    }
    if (!count) {
        cout << "Khong tim thay sinh vien co ID: " << id << endl;
        return;
    }
}

void Department::getBestGPASemester() {
    if (v.empty()) {
        cout << "No data in list!" << endl;
        return;
    }
    int count = 0;
    /*vector<pair<int, float>> vec;*/
    vector<float> tmp_vec;
    for (int i = 0; i < v.size(); i++) {
        if (!v[i]->vs.empty()) {
            count++;
            int tmp = v[i]->vs.size() - 1;
            tmp_vec.push_back(v[i]->vs[tmp]->getGPA());
        }
    }
    if (count > 0) {
        cout << "Sinh vien co diem GPA ki gan nhat cao nhat khoa:\n";
        sort(tmp_vec.begin(), tmp_vec.end());        //sap xep tu nho den lon
        float max_gpa = tmp_vec[tmp_vec.size() - 1];
        for (int i = 0; i < v.size(); i++) {
            if (!v[i]->vs.empty()) {
                int tmp = v[i]->vs.size() - 1;
                if (v[i]->vs[tmp]->getGPA() == max_gpa) {
                    cout << i + 1 << ". ";
                    cout << v[i]->getID() << " - " << v[i]->getName() << " : ";
                    v[i]->vs[tmp]->showResult();
                }
            }
        }
        return;
    }
    else if (count == 0) {
        cout << "No student has result data in list!\n";
        return;
    }
}

void Department::getBestGPAEver() {
    if (v.empty()) {
        cout << "No data in list!" << endl;
        return;
    }
    int count = 0;
    /*vector<pair<int, float>> vec;*/
    vector<float> tmp_vec;
    vector<float> vec1;         //luu tam gia tri ket qua hoc tap cua student
    vector<float> vec2;         //luu gia tri GPA lon nhat cua tung student
    for (int i = 0; i < v.size(); i++) {
        if (!v[i]->vs.empty()) {
            count++;
            for (int j = 0; j < v[i]->vs.size(); j++) {     //Luu gia tri GPA cua student vao 1 vector1
                vec1.push_back(v[i]->vs[j]->getGPA());
            }
            sort(vec1.begin(), vec1.end());                 //Sap xep lai thu tu cua vector 1 (sx tang dan)
            float tmp_gpa = vec1[vec1.size() - 1];          //lay gia tri GPA cao nhat cua student (dung cuoi cung cua vector)
            vec2.push_back(tmp_gpa);                        //luu gia tri GPA lon nhat cua tung student
            vec1.clear();                                   //reset vector1
        }
    }
    if (count > 0) {
        cout << "Sinh vien co diem GPA cao nhat lich su cua khoa:\n";
        sort(vec2.begin(), vec2.end());                     //sap xep tu nho den lon
        float max_gpa = vec2[vec2.size() - 1];              //lay gia tri GPA cao nhat trong khoa
        for (int i = 0; i < v.size(); i++) {
            if (!v[i]->vs.empty()) {
                for (int j = 0; j < v[i]->vs.size(); j++) {     //Luu gia tri GPA cua student vao 1 vector1
                    if (v[i]->vs[j]->getGPA() == max_gpa) {
                        cout << i + 1 << ". ";
                        cout << v[i]->getID() << " - " << v[i]->getName() << " : ";
                        v[i]->vs[j]->showResult();
                    }
                }

            }
        }
        return;
    }
    else if (count == 0) {
        cout << "No student has result data in list!\n";
        return;
    }
}
