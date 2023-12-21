#ifndef QLTP_H
#define QLTP_H
#include "QLP.h"
#include "PhieuTraPhong.h"
#include "QLDK.h"

class QLTP
{
	private:
		PhieuTraPhong *p;
		int size;
	public:
		QLTP();
		QLTP(int);
		~QLTP();
		void doc_file(ifstream&, QLP&, QLDK&);
		PhieuTraPhong& operator[](const int&);
		friend ostream& operator<<(ostream&, const QLTP&);
		void Remove(int);
		int getSize();
};

#endif