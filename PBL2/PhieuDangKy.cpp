#include "PhieuDangKy.h"

PhieuDangKy::PhieuDangKy(){
	
}
PhieuDangKy::PhieuDangKy(int maHD, int maKH, string checkIn, string soPhong, int soNguoi, string checkOut){
	this->maHD = maHD;
	this->maKH = maKH;
	this->checkIn = checkIn;
	this->soPhong = soPhong;
	this->soNguoi = soNguoi;
	this->checkOut = checkOut;
}
PhieuDangKy::~PhieuDangKy(){
	
}
void PhieuDangKy::doc_1_dong(ifstream& fileDK){
	fileDK >> this->maHD;
	fileDK >> this->maKH; //fileDK.seekg(1, ios::cur);
	getline(fileDK, this->checkIn, ';');
	getline(fileDK, this->soPhong, ';');
	fileDK >> this->soNguoi; //fileDK.seekg(1, ios::cur);
	getline(fileDK, this->checkOut);
}
ostream& operator<<(ostream& o, const PhieuDangKy& s){
	o << s.maHD << "; " << s.maKH << ";" << s.checkIn;
	o << "; " << s.soPhong << "; " << s.soNguoi << ";" << s.checkOut << endl;
//	o << s.checkIn;
	return o;
}
string PhieuDangKy::getSoPhong(){
	return this->soPhong;
}
void PhieuDangKy::setSoPhong(string s){
	this->soPhong = s;
}
