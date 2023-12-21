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

	o << left << setw(10) << "Ma HD" << "|"
	<< setw(10) << "Ma KH" << "|"
	<< setw(15) << "Check In" << "|"
	<< setw(10) << "So phong" << "|"
	<< setw(10) << "So nguoi" << "|"
	<< setw(15) << "Check Out" << endl;

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
void QLDK::Remove(int maKH){
	ofstream fileDK("PhieuDangKy.txt", ios::trunc);
	if(this->size == 0){
		cout << "Du lieu trong!!\n";
	}
	int index;
	for(int i = 0; i < this->size; ++i){
		if(this->p[i].getMaKH() == maKH){
			index = i; 
		}
	}
	// if(index == -1){
	// 	cout << "Ma KH khong hop le!\n";
	// 	return;
	// }
	PhieuDangKy* temp = new PhieuDangKy[this->size - 1];
	for(int i = 0; i < index; ++i){
		temp[i] = this->p[i];
	}
	for(int j = index + 1; j < this->size; ++j){
		temp[j-1] = this->p[j];
	}
	delete[] this->p;
	this->p = temp;
	--this->size;
	delete[] temp;

	for(int i = 0; i < this->size; ++i){
		if(i == this->size-1){
			fileDK << this->p[i].getMaHD() << " " << this->p[i].getMaKH()
			<< " " << this->p[i].getCheckIn() << ";" << this->p[i].getSoPhong()
			<< "; " << this->p[i].getSoNguoi() << " " << this->p[i].getCheckOut();
		}
		else{
			fileDK << this->p[i].getMaHD() << " " << this->p[i].getMaKH()
			<< " " << this->p[i].getCheckIn() << ";" << this->p[i].getSoPhong()
			<< "; " << this->p[i].getSoNguoi() << " " << this->p[i].getCheckOut() << endl;
		}
	}
	fileDK.close();
}
int QLDK::getSize(){
	return this->size;
}