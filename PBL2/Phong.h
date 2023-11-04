#ifndef PHONG_H
#define PHONG_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Phong
{
	private:
		string soPhong;
		bool tinhTrang;
	public:
		Phong();
		Phong(string, bool);
		~Phong();
		string getSoPhong();
		bool getTinhTrang();
		void setTinhTrang(bool);
		void doc_1_dong(ifstream&);
		friend ostream& operator<<(ostream&, const Phong&);
		
};

#endif