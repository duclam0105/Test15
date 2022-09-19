#include "Lib.h"
#include "exception.h"

extern set<string> listID;

//OTHER FUNCTION ===========================================================//
void chuanhoaTen(string& name) {
    string res = "";
    stringstream ss(name);
    string token;
    while (ss >> token) {
        res += toupper(token[0]);
        for (int i = 1; i < token.length(); i++)
        {
            res += tolower(token[i]);
        }
        res += " ";
    }
    res.erase(res.length() - 1);
    name = res;
}

string hienthichuinhoa(const string& name) {
    string res = "";
    stringstream ss(name);
    string token;
    while (ss >> token) {
        for (int i = 0; i < token.length(); i++)
        {
            res += toupper(token[i]);
        }
        res += " ";
    }
    res.erase(res.length() - 1);
   /* name = res;*/
    return res;
}

bool checkValidName(const string& name) {     //khong duoc chua chu so (tu 48 den 57 trong bang ma ascii)
    try {
        stringstream ss(name);
        string token;
        while (ss >> token)
        {
            for (int i = 0; i < token.length(); i++) {
                if ((token[i] > 47) && (token[i] < 58)) {
                    throw nameException("Invalid name!");
                }
            }
        }
    }
    catch (nameException& ex1) {
        cout << ex1.what() << endl;
        return false;
    }
    return true;
}

bool checkValidDate(const string& date) {
    try {                                    //birthday form: dd/mm/yy
        stringstream ss(date);              //               01234567
        string token;                       //  dd: 1->31; mm: 1->12; yy: thoai mai;
        while (ss >> token)
        {
            if (token.length() != 8) {
                throw dateException("Invalid date! dd/mm/yy!");
            }
            if ((token[2] != '/') || (token[5] != '/')) {
                throw dateException("Invalid date! dd/mm/yy!");
            }
            for (int i = 0; i < token.length(); i++) {
                //Khong duoc co chu cai
                if ((i != 2) && (i != 5)) {
                    if ((token[i] < 48) || (token[i] > 57)) {
                        throw dateException("Invalid date! dd/mm/yy!");
                    }
                }
            }
        }
        stringstream ss1;
        int day, month, year;// = stoi(sday);
        ss1 << date.substr(0, 2);
        ss1 >> day; ss1.clear();
        ss1 << date.substr(3, 2);
        ss1 >> month; ss1.clear();
        ss1 << date.substr(6, 2);
        ss1 >> year; ss1.clear();
        if ((day < 1) || (day > 31) || (month < 1) || (month > 12)) {
            throw dateException("Invalid date! dd/mm/yy!");
        }
    }
    catch (dateException& ex2) {
        cout << ex2.what() << endl;
        return false;
    }
    return true;
    // cout <<day<< "/"<<month<<"/"<<year;
}

bool checkValidID(const string& phone) {
//ID : phải là chuỗi số có chiều dài 8 ký tự và 
//phải bắt đầu bằng một trong các chuỗi số : "2017", "2018", "2019", "2020", "2021", "2022"
    string arr[] = ID_SET;
    int count = 0;
    try {
        stringstream ss(phone);
        string token;
        while (ss >> token)
        {
            if (token.length() != ID_SIZE) {
                throw idException("Invalid ID! (1)");
            }
            for (int i = 0; i < (sizeof(arr) / sizeof(string)); i++) {
                if (phone.substr(0, 4) == arr[i]) {
                    count++;
                }
            }
            if (count) {
                for (int i = 4; i < token.length(); i++) {
                    if ((token[i] < 48) || (token[i] > 57)) {
                        throw idException("Invalid ID! (2)");
                    }
                }
            }
            if (!count) {
                throw idException("Invalid ID! (3)");
            }
        }
    }
    catch (idException& ex3) {
        cout << ex3.what() << endl;
        cout << "ID must has 8 digits and start with: ";
        for (int i = 0; i < (sizeof(arr) / sizeof(string)); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        return false;
    }
    return true;
}

 bool checkSameID(set<string>& list, const string& id){
     if(list.size() < 1) return true;
     try{
         for(string i:list){
             if(i == id){
                 throw idException("ID has been used!");
             }
         }
     }
     catch(idException &e){
         cout << e.what() << endl;
         return false;
     }
     return true;
 }
