#ifndef QLP_H
#define QLP_H
#include "Phong.h"

class QLP
{
	private:
		Phong *p;
		int size;
	public:
		QLP();
		QLP(int);
		~QLP();
		int getSize();
		void doc_file(ifstream&);
		Phong& operator[](const int&);
		friend ostream& operator<<(ostream&, const QLP&);
};

#endif