#include "QLKH.h"
#include <fstream>

QLKH::QLKH(){
	this->p = NULL;
	this->size = 0;
}
QLKH::QLKH(int n){
	this->p = new Khach[n];
	this->size = n;
}

QLKH::~QLKH(){
	delete[] this->p;
}

Khach& QLKH::operator[](const int& index){
	static Khach NGU;
	return (index >= 0 && index < this->size)
	? this->p[index] : NGU;
}
ostream& operator<<(ostream& o, const QLKH& ds){
	if(ds.p == NULL){
		o << "Nothing!" << endl;
		return o;
	}
	//o << "\n";
	
	o << left << setw(20) << "Ten KH" << "|" << setw(10) << "Ma KH" << "|" << setw(13) << "Gioi tinh" << "|" << setw(15) << "Ngay sinh" << endl;
	for(int i = 0; i < ds.size; ++i){
		o << ds.p[i];
	}
	return o;
}
void QLKH::doc_file(ifstream& fileKhach){
	int n = 0;
	//đếm số dòng trong file
	while(fileKhach.eof() == false){
		string x;
		getline(fileKhach, x);
		n++;
	}

	fileKhach.seekg(0, ios::beg);
	delete[] this->p;
	this->p = new Khach[n];
	this->size = n;
	for(int i = 0; i < n; ++i){
		//đọc từng khách hàng
		this->p[i].doc_1_khach(fileKhach);
	}
}
void QLKH::Add(const Khach& s){
	if(this->size == 0){
        this->p = new Khach[this->size + 1];
        this->p[this->size] = s;
    }
    else {
        Khach* temp = new Khach[this->size];
        for(int i = 0; i < this->size; ++i){
            temp[i] = this->p[i];
        }
        delete[] this->p;
        this->p = new Khach[this->size + 1];
        for(int i = 0; i < this->size; ++i){
            this->p[i] = temp[i];
        }
        this->p[this->size] = s;
    }
    this->size++;
}
void QLKH::Remove(int maKH){
	ofstream fileKH("Khach.txt", ios::trunc);
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
	Khach* temp = new Khach[this->size - 1];
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
			fileKH << this->p[i].getTen() << ";" << this->p[i].getNgaySinh() << "; ";
			fileKH << this->p[i].getMaKH() << " " << this->p[i].getGioiTinh();
		}
		else{
			fileKH << this->p[i].getTen() << ";" << this->p[i].getNgaySinh() << "; ";
			fileKH << this->p[i].getMaKH() << " " << this->p[i].getGioiTinh() << endl;
		}
	}
	fileKH.close();
}
int QLKH::getSize(){
	return this->size;
}