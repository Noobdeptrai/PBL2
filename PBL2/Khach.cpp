#include "Khach.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

Khach::Khach(){
	
}
Khach::Khach(string ten, int maKH, int gioiTinh, string ngaySinh){
	this->ten = ten;
	this->maKH = maKH;
	this->gioiTinh = gioiTinh;
	this->ngaySinh = ngaySinh;
}
Khach::~Khach(){
	
}


ostream& operator<<(ostream& o, const Khach& s){
	o << s.ten << "; " << s.maKH << "; ";
	if(s.gioiTinh == 1) o << "Nam";
	else o << "Nu";
	o << "; " << s.ngaySinh ;
	return o;
}
void Khach::doc_1_khach(ifstream& fileKhach){
	getline(fileKhach, this->ten, ';'); 
	getline(fileKhach, this->ngaySinh, ';');
	fileKhach >> this->maKH; //fileKhach.seekg(1, ios::cur);
	fileKhach >> this->gioiTinh; 
}

