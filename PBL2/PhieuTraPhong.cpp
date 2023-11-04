#include "PhieuTraPhong.h"
PhieuTraPhong::PhieuTraPhong(){
	
}
PhieuTraPhong::PhieuTraPhong(int maHD, int maKH, string checkIn, string checkOut, string thoiHan){
	this->maHD = maHD;
	this->maKH = maKH;
	this->checkIn = checkIn;
	this->checkOut = checkOut;
	this->thoiHan = thoiHan;	
}
PhieuTraPhong::~PhieuTraPhong(){
		
}
void PhieuTraPhong::doc_1_dong(ifstream& fileTraPhong){
	fileTraPhong >> this->maHD;
	fileTraPhong >> this->maKH;
	getline(fileTraPhong, this->checkIn, ';');
	getline(fileTraPhong, this->checkOut, ';');
	getline(fileTraPhong, this->thoiHan);
}
ostream& operator<<(ostream& o, const PhieuTraPhong& s){
	o << s.maHD << "; " << s.maKH << ";" << s.checkIn << "; "
	<< s.checkOut << "; " << s.thoiHan << endl;
	return o;
}

