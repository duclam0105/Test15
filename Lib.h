#ifndef __LIBRARY_H
#define __LIBRARY_H
/// De bai: https://shareprogramming.net/tong-hop-bai-tap-lap-trinh-huong-doi-tuong-trong-java/#Bai_14
#include <iostream>
#include <sstream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <set>
//#include <utility>

using namespace std;

#define yes 1
#define no 0
typedef enum { cmd_exit, cmd_add, cmd_remove, cmd_find, cmd_showlist, cmd_addResult, cmd_showResult, cmd_findBestStudent }comand;
typedef enum {cmd_exit1, cmd_add1, cmd_show1}cmd;
typedef enum { exit_t, regular_t, inservice_t }type_t;

#define ID_SET { "2017", "2018", "2019", "2020", "2021", "2022" }
#define ID_SIZE 8
#define MIN_RECRUIT 3           //so luong sinh vien toi thieu can tuyen dung
#define MAX_RECRUIT 10          //so luong sinh vien toi da can tuyen dung

typedef enum {
    regular_s,
    inservice_s
}typestudent;

bool checkValidName(const string&);
bool checkValidDate(const string&);
bool checkValidID(const string&);
bool checkSameID(set<string>&, const string&);
void chuanhoaTen(string&);
string hienthichuinhoa(const string&);

#endif