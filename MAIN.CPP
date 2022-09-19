#include "Lib.h"
#include "student.h"
#include "regularStudent.h"
#include "inserviceStudent.h"
#include "department.h"
#include "exception.h"
#include "manage.h"

set<string> listID;

//MAIN FUNCTION ============================================================//
int main() {
    Manage cs;
    int tmp;
    int state = 0;
    int index;
    while (true)
    {
        cout << "============== TRUONG DAI HOC BACH KHOA HA NOI ==========================\n";
        cout << "=========================== MENU ========================================\n";
        cout << "1-Them moi du lieu khoa\n2-Hien thi khoa"
            << "\n0-Thoat\nMoi ban nhap: ";
        cin >> tmp;
        switch (tmp) {
        case cmd_exit1: {
            state = 1;
            break;
        }
        case cmd_add1:
            cs.addDepartmentData();
            break;
        case cmd_show1: {
            cs.showListDepartment();
            string tmp_department;
            cout << "Nhap ten khoa can hien thi: ";
            cin >> tmp_department;
            chuanhoaTen(tmp_department);
            index = cs.showDepartmentData(tmp_department);
            cs.DepartmentDisplay(index);
            break;
        }
        default:
            break;
        }
        if (state) {
            cout << "=========================================================================\n";
            cout << "=========================================================================\n";
            break;
        }
    }
    cout << "Close the program..." << endl;
    return 0;
}

//============================================================================//
////MAIN FUNCTION ============================================================//
//int main() {
//    int temp;
//    Department m;
//    while (true)
//    {
//        cout << "==================================================\n";
//        cout << "1-Them moi sinh vien\n2-Xoa sinh vien\n3-Tim kiem\n4-Hien thi danh sach\n5-Them ket qua hoc tap\6-Hien thi ket qua hoc tap"
//            << "\n0-Thoat\nMoi ban nhap: ";
//        cin >> temp;
//        cout << "========\n";
//        switch (temp) {
//        case cmd_exit: {
//            cout << "Close the program..." << endl;
//            system("cls");
//            return 0;
//        }
//        case cmd_add:
//            m.addStudentData();
//            break;
//        case cmd_remove: {
//            string tmp_id;
//            do {
//                cout << "Nhap so ID cua sinh vien can xoa: ";
//                cin >> tmp_id;
//                if (tmp_id == "0") break;
//            } while (!checkValidID(tmp_id));
//            m.delStudentData(tmp_id);
//            break;
//        }
//        case cmd_find: {
//            string tmp_id;
//            do {
//                cout << "Nhap so ID cua sinh vien can tim kiem: ";
//                cin >> tmp_id;
//                if (tmp_id == "0") break;
//            } while (!checkValidID(tmp_id));
//            m.findStudentData(tmp_id);
//            break;
//        }
//        case cmd_showlist: {
//            m.showStudentList();
//            break;
//        }
//        case cmd_addResult: {
//            string tmp_id;
//            do {
//                cout << "Nhap so ID cua sinh vien: ";
//                cin >> tmp_id;
//                if (tmp_id == "0") break;
//            } while (!checkValidID(tmp_id));
//            m.addStudentResult(tmp_id);
//            break;
//        }
//        case cmd_showResult: {
//            string tmp_id;
//            do {
//                cout << "Nhap so ID cua sinh vien can tim kiem: ";
//                cin >> tmp_id;
//                if (tmp_id == "0") break;
//            } while (!checkValidID(tmp_id));
//            m.showStudentResult(tmp_id);
//            break;
//        }
//        default:
//            break;
//        }
//    }
//    cout << "Close the program..." << endl;
//    return 0;
//}