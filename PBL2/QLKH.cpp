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
	o << "\n";
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
