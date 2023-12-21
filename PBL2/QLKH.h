#ifndef QLKH_H
#define QLKH_H
#include "Khach.h"
class QLKH
{
	private:
		Khach *p;
		int size;
	public:
		QLKH();
		QLKH(int);
		~QLKH();
		void doc_file(ifstream&);
		Khach& operator[](const int&);
		friend ostream& operator<<(ostream&, const QLKH&);
		void Add(const Khach&);
		void Remove(int maKH);
		int getSize();
};

#endif


