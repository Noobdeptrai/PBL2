#include "Khach.h"
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
	o << left << setw(20) << s.ten << "|" << setw(10) << s.maKH << "|" << setw(13);
	if(s.gioiTinh == 1) o << "Nam";
	else o << "Nu";
	o << "|" << setw(15) << s.ngaySinh << endl;
	return o;
}
void Khach::doc_1_khach(ifstream& fileKhach){
	getline(fileKhach, this->ten, ';'); 
	getline(fileKhach, this->ngaySinh, ';');
	fileKhach >> this->maKH; //fileKhach.seekg(1, ios::cur);
	fileKhach >> this->gioiTinh; 
	string x;
	getline(fileKhach, x);
}
string Khach::getTen(){
	return this->ten;
}
int Khach::getMaKH(){
	return this->maKH;
}
int Khach::getGioiTinh(){
	return this->gioiTinh;
}
string Khach::getNgaySinh(){
	return this->ngaySinh;
}

