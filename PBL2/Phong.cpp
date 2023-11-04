#include "Phong.h"
Phong::Phong(){
	
}
Phong::Phong(string soPhong, bool tinhTrang){
	this->soPhong = soPhong;
	this->tinhTrang = tinhTrang;
}
Phong::~Phong(){
	
}
string Phong::getSoPhong(){
	return this->soPhong;
}
bool Phong::getTinhTrang(){
	return this->tinhTrang;
}
void Phong::doc_1_dong(ifstream& filePhong){
	getline(filePhong, this->soPhong, ';');
	filePhong >> this->tinhTrang;
} 
ostream& operator<<(ostream& o, const Phong& s){
	o << s.soPhong << " - ";
	if(s.tinhTrang) cout << "not booked yet :)";
	else cout << "already booked :((";
	return o;
}
void Phong::setTinhTrang(bool x){
	this->tinhTrang = x;
}
