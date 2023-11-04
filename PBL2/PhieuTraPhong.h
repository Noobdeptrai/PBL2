#ifndef PHIEUTRAPHONG_H
#define PHIEUTRAPHONG_H
#include <iostream>
#include <fstream>
using namespace std;

class PhieuTraPhong
{
	private:
		int maHD;
		int maKH;
		string checkIn;
		string checkOut;
		string thoiHan;
	public:
		PhieuTraPhong();
		PhieuTraPhong(int, int, string, string, string);
		~PhieuTraPhong();
		void doc_1_dong(ifstream&);
		friend ostream& operator<<(ostream&, const PhieuTraPhong&);
};

#endif