#include "Date.h"

Date::Date(){
    //do nothing
}
Date::Date(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}
Date::Date(string s){
    char c = s[0]; int i = 0, count = 0;
    while(c == ' '){
    	count++;
		i++;
    	c = s[i];
	}
	string day1 = s.substr(count, 2);
	string month1 = s.substr(count+3, 2);
	string year1 = s.substr(count+3+3, 4);

	int d = atoi(day1.c_str());
	int m = atoi(month1.c_str());
	int y = atoi(year1.c_str());
    //int num = atoi(s.c_str()); // Nếu là string, convert về char array sử dụng .c_str()
    this->day = d;
    this->month = m;
    this->year = y;
}
Date::~Date()
{
}
int Date::getDay(){
    return this->day;
}
int Date::getMonth(){
    return this->month;
}
int Date::getYear(){
    return this->year;
}
void Date::setDay(int d){
    this->day = d;
}
void Date::setMonth(int m){
    this->month = m;
}
void Date::setYear(int y){
    this->year = y;
}

bool isLeapYear(int y){
    if( (y % 400 == 0) || (y % 100 != 0 && y % 4 == 0)){
        return true;
    }
    return false;
}

// void Date::nextDay(){
//     int d = this->monthDays();
//     if(this->day == d && this->year == 12){
//         this->day = 1;
//         this->month = 1;
//         this->year += 1;
//     }
//     if(this->day == d){
//         this->day = 1;
//         this->month += 1;
//     }
//     else this->day += 1;
// }
ostream& operator<<(ostream& o, const Date& s){
    if(s.day < 10 && s.month < 10){
        o << "0" << s.day << "/" << "0" << s.month << "/" << s.year ;
    }
    else if(s.day < 10 && s.month >= 10){
        o << "0" << s.day << "/" << s.month << "/" << s.year ;
    }
    else if(s.day >= 10 && s.month < 10){
        o << s.day << "/" << "0" << s.month << "/" << s.year ;
    }
    else o << s.day << "/" << s.month << "/" << s.year ;
    // o << s.day << "/" << s.month << "/" << s.year ;
    return o;
}
int monthDays(int month, int year)
{
    switch(month){
        case 1:{
            return 31;
            break;
        }
        case 3:{
            return 31;
            break;
        }
        case 5:{
            return 31;
            break;
        }
        case 7:{
            return 31;
            break;
        }
        case 8:{
            return 31;
            break;
        }
        case 10:{
            return 31;
            break;
        }
        case 12:{
            return 31;
            break;
        }
        case 4:{
            return 30;
            break;
        }
        case 6:{
            return 30;
            break;
        }
        case 9:{
            return 30; 
            break;
        }
        case 11:{
            return 30;
            break;
        }
        case 2:{
            if(isLeapYear(year) == true){
                return 29;
            }
            else return 28;
            break;
        }
        default:{
            return -1;
            break;
        }
    }
}
int tinhSoNgay(int d, int m, int y){
    int kc = 0;
    if(y < 2020){
        cout << "ERROR!!\n";
        exit(0);
    }
    for(int i = 2020; i < y; ++i){
        if(isLeapYear(i) == true){
            kc += 366;
        }
        else kc += 365;
    }
    int songay = d;
    for(int i = 1; i < m; ++i){
        songay += monthDays(i, y);
    }
    int result = kc + songay;
    return result;
}
int operator-(const Date& date1, const Date& date2){
    int d1 = date1.day, m1 = date1.month, y1 = date1.year;
    int d2 = date2.day, m2 = date2.month, y2 = date2.year;
    int kc1 = tinhSoNgay(d1, m1, y1);
    int kc2 = tinhSoNgay(d2, m2, y2);
    int soNgay = abs(kc1 - kc2);
    return soNgay;
}
