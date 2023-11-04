#include "QLDK.h"


QLDK::QLDK(){
	this->p = NULL;
	this->size = 0;
}

QLDK::QLDK(int n){
	this->p = new PhieuDangKy [n];
	this->size = n;
}

QLDK::~QLDK(){
	delete[] this->p;
}
PhieuDangKy& QLDK::operator[](const int& index){
	static PhieuDangKy NGU;
	return (index >= 0 && index < this->size)
	? this->p[index] : NGU;
}
ostream& operator<<(ostream& o, const QLDK& ds){
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
void QLDK::doc_file(ifstream& fileDK, QLP& dsP){
	int n = 0;
	//đếm số dòng trong file
	while(fileDK.eof() == false){
		string x;
		getline(fileDK, x);
		n++;
	}
	fileDK.seekg(0, ios::beg);
	
	this->p = new PhieuDangKy [n];
	this->size = n;
	for(int i = 0; i < n; ++i){
		this->p[i].doc_1_dong(fileDK);
		for(int j = 0; j < dsP.getSize()-1; ++j){
			if( this->p[i].getSoPhong().compare(dsP[j].getSoPhong()) == 0 ){
				dsP[j].setTinhTrang(false);
			}
		}
	}
}