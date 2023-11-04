#ifndef QLTP_H
#define QLTP_H
#include "PhieuTraPhong.h"

class QLTP
{
	private:
		PhieuTraPhong *p;
		int size;
	public:
		QLTP();
		QLTP(int);
		~QLTP();
		void doc_file(ifstream&);
		PhieuTraPhong& operator[](const int&);
		friend ostream& operator<<(ostream&, const QLTP&);
};

#endif