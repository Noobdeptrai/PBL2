#include "PhieuDangKy.h"

PhieuDangKy::PhieuDangKy(){
	
}
// PhieuDangKy::PhieuDangKy(int maHD, int maKH, string checkIn, string soPhong, int soNguoi, string checkOut){
// 	this->maHD = maHD;
// 	this->maKH = maKH;
// 	this->checkIn = checkIn;
// 	this->soPhong = soPhong;
// 	this->soNguoi = soNguoi;
// 	this->checkOut = checkOut;
// }
PhieuDangKy::~PhieuDangKy(){
	
}
void PhieuDangKy::doc_1_dong(ifstream& fileDK){
	string checkIn1; string checkOut1;
	fileDK >> this->maHD;
	fileDK >> this->maKH;
	getline(fileDK, checkIn1, ';');
	getline(fileDK, this->soPhong, ';');
	fileDK >> this->soNguoi; 
	getline(fileDK, checkOut1);
	this->checkIn = Date(checkIn1);
	this->checkOut = Date(checkOut1);

	// fileDK >> this->maHD;
	// fileDK >> this->maKH; //fileDK.seekg(1, ios::cur);
	// getline(fileDK, this->checkIn, ';');
	// getline(fileDK, this->soPhong, ';');
	// fileDK >> this->soNguoi; //fileDK.seekg(1, ios::cur);
	// getline(fileDK, this->checkOut);
}
ostream& operator<<(ostream& o, const PhieuDangKy& s){
	o << left << setw(10) << s.maHD << "|" 
	<< setw(10) << s.maKH << "|"
	<< s.checkIn << "     " << "|" 
	<< setw(10) << s.soPhong << "|" 
	<< setw(10) << s.soNguoi << "|"
	<<  s.checkOut << "     " << endl;
//	o << s.checkIn;
	return o;
}
void PhieuDangKy::setSoPhong(string s){
	this->soPhong = s;
}
int PhieuDangKy::getMaHD(){
	return this->maHD;
}
int PhieuDangKy::getMaKH(){
	return this->maKH;
}
Date PhieuDangKy::getCheckIn(){
	return this->checkIn;
}
string PhieuDangKy::getSoPhong(){
	return this->soPhong;
}
int PhieuDangKy::getSoNguoi(){
	return this->soNguoi;
}
Date PhieuDangKy::getCheckOut(){
	return this->checkOut;
}