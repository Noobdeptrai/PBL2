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
	o << setw(8) << s.soPhong << "|" << setw(15);
	if(s.tinhTrang) cout << "O";
	else cout << "X";
	// o << s.soPhong << " - ";
	// if(s.tinhTrang) cout << "O";
	// else cout << "X";
	return o;
}
void Phong::setTinhTrang(bool x){
	this->tinhTrang = x;
}
char Phong::getLoaiPhong(){
	string s = this->soPhong;
	char c = s[0]; int i = 0;
    while(c == ' '){
		i++;
    	c = s[i];
	}
	return c;
}