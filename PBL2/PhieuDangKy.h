#ifndef PHIEUDANGKY_H
#define PHIEUDANGKY_H
#include "Date.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

class PhieuDangKy
{
	private:
		int maHD;
		int maKH;
		Date checkIn;
		string soPhong;
		int soNguoi;
		Date checkOut;
	public:
		PhieuDangKy();
		//PhieuDangKy(int, int, string, string, int, string);
		~PhieuDangKy();
		void doc_1_dong(ifstream&);
		friend ostream& operator<<(ostream&, const PhieuDangKy&);
		void setSoPhong(string);

		int getMaHD();
		int getMaKH();
		Date getCheckIn();
		string getSoPhong();
		int getSoNguoi();
		Date getCheckOut();
};

#endif