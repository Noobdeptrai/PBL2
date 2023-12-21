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
	int index1, index2, index3;
	for(int j = 0; j < ds.size; ++j){
		if(ds.p[j].getLoaiPhong() == 'B'){
			index1 = j; //cout << j << endl;
			break;
		}
	}
	for(int j = 0; j < ds.size; ++j){
		if(ds.p[j].getLoaiPhong() == 'C'){
			index2 = j; //cout << j << endl;
			break;
		}
	}
	for(int j = 0; j < ds.size; ++j){
		if(ds.p[j].getLoaiPhong() == 'D'){
			index3 = j; //cout << j << endl;
			break;
		}
	}
	o << left << setw(8) << "Phong" << "|" << setw(15) << "Tinh trang"
	<< "\t\t" << setw(8) << "Phong" << "|" << setw(15) << "Tinh trang"
	<< "\t\t" << setw(8) << "Phong" << "|" << setw(15) << "Tinh trang"
	<< "\t\t" << setw(8) << "Phong" << "|" << setw(15) << "Tinh trang" << endl;
	int j = index1, k = index2, h = index3;
	for(int i = 0; i < j; ++i){
		o << left << ds.p[i] << "\t\t" << ds.p[j] << "\t\t"
		<< ds.p[k] << "\t\t" << ds.p[h] << endl;
		j++; k++; h++;
	}
	while( k < index3 && h < ds.size){
		o << left << setw(24) << ". . . " << "\t\t" <<  setw(24) << ". . . " << "\t\t"
		<< ds.p[k] << "\t\t" << ds.p[h] << endl;
		k++; h++;
	}
	// for(int i = 0; i < ds.size; ++i){
	// 	o << ds.p[i] << endl;
	// }
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