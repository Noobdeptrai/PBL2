#ifndef KHACH_H
#define KHACH_H
#include <iostream>
using namespace std;

//Phòng: số phòng, đơn giá, tình trạng, loại phòng
//Khách: tên, mã khách hàng, giới tính, ngày sinh
//Phiếu đăng ký: mã hóa đơn, mã khách hàng, ngày checkIn, số phòng, số người ở, thời hạn
//Phiếu trả phòng: mã hóa đơn, mã khách hàng, ngày checkIn, ngày checkOut, thời hạn
class Khach
{
	private:
		string ten;
		int maKH;
		int gioiTinh;
		string ngaySinh;
	public:
		Khach();
		Khach(string, int, int, string);
		~Khach();
		void doc_1_khach(ifstream&);
		friend ostream& operator<<(ostream&, const Khach&);
		
};

#endif


