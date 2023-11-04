#include "QLTP.h"
QLTP::QLTP(){
	this->p = NULL;
	this->size = 0;
}
QLTP::QLTP(int n){
	this->p = new PhieuTraPhong [n];
	this->size = n;
}
QLTP::~QLTP(){
	delete[] this->p;
}
PhieuTraPhong& QLTP::operator[](const int& index){
	static PhieuTraPhong NGU;
	return (index >= 0 && index < this->size)
	? this->p[index] : NGU;
}
ostream& operator<<(ostream& o, const QLTP& ds){
	if(ds.p == NULL){
		o << "Nothing!" << endl;
		return o;
	}
	o << "\n";
	for(int i = 0; i < ds.size; ++i){
		o << ds.p[i];
	}
	return o;
}
void QLTP::doc_file(ifstream& fileTraPhong){
	int n = 0;
	//đếm số dòng trong file
	while(fileTraPhong.eof() == false){
		string x;
		getline(fileTraPhong, x);
		n++;
	}
	fileTraPhong.seekg(0, ios::beg);
	
	this->p = new PhieuTraPhong [n];
	this->size = n;
	for(int i = 0; i < n; ++i){
		//đọc từng phiếu trả phòng
		this->p[i].doc_1_dong(fileTraPhong);
	}
}