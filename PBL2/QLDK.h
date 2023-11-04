#ifndef QLDK_H
#define QLDK_H
#include "PhieuDangKy.h"
#include "QLP.h"

class QLDK
{
	private:
		PhieuDangKy *p;
		int size;
	public:
		QLDK();
		QLDK(int);
		~QLDK();
		void doc_file(ifstream&, QLP&);
		PhieuDangKy& operator[](const int&);
		friend ostream& operator<<(ostream&, const QLDK&);
};

#endif