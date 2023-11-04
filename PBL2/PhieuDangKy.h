#ifndef PHIEUDANGKY_H
#define PHIEUDANGKY_H
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

class PhieuDangKy
{
	private:
		int maHD;
		int maKH;
		string checkIn;
		string soPhong;
		int soNguoi;
		string checkOut;
	public:
		PhieuDangKy();
		PhieuDangKy(int, int, string, string, int, string);
		~PhieuDangKy();
		void doc_1_dong(ifstream&);
		friend ostream& operator<<(ostream&, const PhieuDangKy&);
		string getSoPhong();
		void setSoPhong(string);
};

#endif