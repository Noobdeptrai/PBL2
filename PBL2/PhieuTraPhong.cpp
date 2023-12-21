#include "PhieuTraPhong.h"

PhieuTraPhong::PhieuTraPhong(){
	
}
// PhieuTraPhong::PhieuTraPhong(int maHD, int maKH, string checkIn, string checkOut, string thoiHan){
// 	this->maHD = maHD;
// 	this->maKH = maKH;
// 	this->checkIn = checkIn;
// 	this->checkOut = checkOut;
// 	this->thoiHan = thoiHan;	
// }
PhieuTraPhong::~PhieuTraPhong(){
		
}
void PhieuTraPhong::doc_1_dong(ifstream& fileTraPhong){
	string checkIn1; string checkOut1; string thoiHan1;
	fileTraPhong >> this->maHD;
	fileTraPhong >> this->maKH;
	getline(fileTraPhong, checkIn1, ';');
	getline(fileTraPhong, checkOut1, ';');
	getline(fileTraPhong, thoiHan1);
	this->checkIn = Date(checkIn1);
	this->checkOut = Date(checkOut1);
	this->thoiHan = Date(thoiHan1);

	// fileTraPhong >> this->maHD;
	// fileTraPhong >> this->maKH;
	// getline(fileTraPhong, this->checkIn, ';');
	// getline(fileTraPhong, this->checkOut, ';');
	// getline(fileTraPhong, this->thoiHan);
}
ostream& operator<<(ostream& o, const PhieuTraPhong& s){
	o << left << setw(10) << s.maHD << "|"
	<< setw(10) << s.maKH << "|"
	<< s.checkIn << "          " << "|"
	<< s.checkOut << "          " << "|"
	<< s.thoiHan << "          " << endl;
	return o;
}
int PhieuTraPhong::getMaHD(){
	return this->maHD;
}
int PhieuTraPhong::getMaKH(){
	return this->maKH;
}
Date PhieuTraPhong::getCheckIn(){
	return this->checkIn;
}
Date PhieuTraPhong::getCheckOut(){
	return this->checkOut;
}
Date PhieuTraPhong::getThoiHan(){
	return this->thoiHan;
}
