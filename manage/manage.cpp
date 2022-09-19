#include "manage.h"

extern set<string> listID;

//MANAGEMENT FUNCTION
void Manage::addDepartmentData() {
	string tmp_name;
	Department* p(new Department);
	cout << "Nhap ten khoa can them du lieu: ";
    cin.ignore();
	getline(cin, tmp_name);
	chuanhoaTen(tmp_name);
	p->setDepartmentName(tmp_name);
	m.push_back(p);
}

int Manage::showDepartmentData(const string& departmentName) {
    int count = 0;
	if (m.empty()) {
		cout << "No data to show!\n";
		return -1;
	}
	for (int i = 0; i < m.size(); i++) {
		if (m[i]->getDepartmentName() == departmentName) {
            count++;
			return i;
		}
	}
    if (count == 0) {
        cout << "Khong co du lieu nao ve khoa " << departmentName << "!\n";
        return -1;
    }
}

void Manage::showListDepartment() {
    for (int i = 0; i < m.size(); i++) {
        cout << i + 1 << ". ";
        cout << m[i]->getDepartmentName() << endl;
    }
}

void Manage::DepartmentDisplay(const int& index) {
    if (index == -1) {
        return;
    }
    int temp;
    int state = 0;
    while (true)
    {
        cout << "==================== "<< hienthichuinhoa(m[index]->getDepartmentName()) << " ==============================\n";
        cout << "1-Them moi sinh vien\n2-Xoa sinh vien\n3-Tim kiem\n4-Hien thi danh sach\n5-Them ket qua hoc tap\n6-Hien thi ket qua hoc tap\n7-Show Best GPA"
            << "\n0-Thoat\nMoi ban nhap: ";
        cin >> temp;
        cout << "=================================\n";
        switch (temp) {
        case cmd_exit: {
            state = 1;
            break;
        }
        case cmd_add:
            m[index]->addStudentData();
            break;
        case cmd_remove: {
            string tmp_id;
            do {
                cout << "Nhap so ID cua sinh vien can xoa: ";
                cin >> tmp_id;
                if (tmp_id == "0") break;
            } while (!checkValidID(tmp_id));
            m[index]->delStudentData(tmp_id);
            break;
        }
        case cmd_find: {
            //string tmp_id;
            //do {
            //    cout << "Nhap so ID cua sinh vien can tim kiem: ";
            //    cin >> tmp_id;
            //    if (tmp_id == "0") break;
            //} while (!checkValidID(tmp_id));
            //m[index]->findStudentData(tmp_id);
            m[index]->findStudentDataByType();
            break;
        }
        case cmd_showlist: {
            m[index]->showStudentList();
            int tmp;
            cout << "Sap xep danh sach tang dan theo loai (regular -> in-service) va giam dan theo nam hoc\n1-Yes - 0-No: ";
            cin >> tmp;
            if (tmp == yes) {
                m[index]->selectionSort();
                cout << "Danh sach sau khi sap xep:\n";
                m[index]->showStudentList();
            }
            break;
        }
        case cmd_addResult: {
            m[index]->showStudentList();
            string tmp_id;
            do {
                cout << "Nhap so ID cua sinh vien can them ket qua hoc tap: ";
                cin >> tmp_id;
                if (tmp_id == "0") break;
            } while (!checkValidID(tmp_id));
            m[index]->addStudentResult(tmp_id);
            break;
        }
        case cmd_showResult: {
            m[index]->showStudentList();
            string tmp_id;
            do {
                cout << "Nhap so ID cua sinh vien can hien thi ket qua hoc tap: ";
                cin >> tmp_id;
                if (tmp_id == "0") break;
            } while (!checkValidID(tmp_id));
            m[index]->showStudentResult(tmp_id);
            break;
        }
        case cmd_findBestStudent: {
            int tmp;
            cout << "1-Sinh vien co GPA cao nhat ki gan nhat - 2-Sinh vien co GPA cao nhat lich su: ";
            cin >> tmp;
            switch (tmp)
            {
            case 1:
                m[index]->getBestGPASemester();
                break;
            case 2:
                m[index]->getBestGPAEver();
                break;
            default:
                break;
            }
        }
        default:
            break;
        }
        if (state) {
            break;
        }
    }
}

