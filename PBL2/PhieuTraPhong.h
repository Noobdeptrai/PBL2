#ifndef PHIEUTRAPHONG_H
#define PHIEUTRAPHONG_H
#include "Date.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class PhieuTraPhong
{
	private:
		int maHD;
		int maKH;
		Date checkIn;
		Date checkOut;
		Date thoiHan;
	public:
		PhieuTraPhong();
		//PhieuTraPhong(int, int, string, string, string);
		~PhieuTraPhong();
		void doc_1_dong(ifstream&);
		friend ostream& operator<<(ostream&, const PhieuTraPhong&);

		int getMaHD();
		int getMaKH();
		Date getCheckIn();
		Date getCheckOut();
		Date getThoiHan();
};

#endif