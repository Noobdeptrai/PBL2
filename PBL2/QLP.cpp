#include "QLP.h"
QLP::QLP(){
	this->p = NULL;
	this->size = 0;
}
QLP::QLP(int n){
	this->p = new Phong [n];
	this->size = n;
}
QLP::~QLP(){
	delete[] this->p;
}
int QLP::getSize(){
	return this->size;
}
Phong& QLP::operator[](const int& index){
	static Phong NGU;
	return (index >= 0 && index < this->size)
	? this->p[index] : NGU;
}
ostream& operator<<(ostream& o, const QLP& ds){
	if(ds.p == NULL){
		o << "Nothing!" << endl;
		return o;
	}
	o << "\n";
	
	for(int i = 0; i < ds.size; ++i){
		o << ds.p[i] << endl;
	}
	return o;
}
void QLP::doc_file(ifstream& filePhong){
//	int n = 0;
//	//đếm số dòng trong file
//	while(filePhong.eof() == false){
//		string x;
//		getline(filePhong, x);
//		n++;
//	}
//	filePhong.seekg(0, ios::beg);
	int n;
	filePhong >> n;
	
	this->p = new Phong [n];
	this->size = n;
	for(int i = 0; i < n; ++i){
		//đọc từng phiếu đăng ký
		string x;
		getline(filePhong, x);
		this->p[i].doc_1_dong(filePhong);
	}
}