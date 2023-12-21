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
	o << left << setw(10) << "Ma HD" << "|"
	<< setw(10) << "Ma KH" << "|"
	<< setw(20) << "Check In" << "|"
	<< setw(20) << "Check Out" << "|"
	<< setw(20) << "Thoi han" << endl;
	                            
	for(int i = 0; i < ds.size; ++i){
		o << ds.p[i];
	}
	return o;
}
void QLTP::doc_file(ifstream& fileTraPhong, QLP& dsP, QLDK& dsDK){
	int n = 0; int maHD; string soPhong;
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
		this->p[i].doc_1_dong(fileTraPhong);
		maHD = this->p[i].getMaHD();
		for(int k = 0; k < dsDK.getSize(); ++k){
			if(maHD == dsDK[k].getMaHD()){
				soPhong = dsDK[k].getSoPhong();
			}
		}
		for(int j = 0; j < dsP.getSize()-1; ++j){
			if( soPhong.compare(dsP[j].getSoPhong()) == 0 ){
				dsP[j].setTinhTrang(true);
			}
		}
	}
}
void QLTP::Remove(int maKH){
	ofstream fileTP("PhieuTraPhong.txt", ios::trunc);
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
	PhieuTraPhong* temp = new PhieuTraPhong[this->size - 1];
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
			fileTP << this->p[i].getMaHD() << " " << this->p[i].getMaKH()
			<< " " << this->p[i].getCheckIn() << ";" << this->p[i].getCheckOut()
			<< ";" << this->p[i].getThoiHan();
		}
		else{
			fileTP << this->p[i].getMaHD() << " " << this->p[i].getMaKH()
			<< " " << this->p[i].getCheckIn() << ";" << this->p[i].getCheckOut()
			<< ";" << this->p[i].getThoiHan() << endl;
		}
	}
	fileTP.close();
}
int QLTP::getSize(){
	return this->size;
}