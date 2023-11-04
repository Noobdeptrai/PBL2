#include "Khach.h"
#include "QLKH.h"
#include "PhieuDangKy.h"
#include "PhieuTraPhong.h"
#include "QLTP.h"
#include "QLDK.h"
#include "QLP.h"
#include <bits/stdc++.h>
#include <iomanip>
#include <cstring>
using namespace std;

void menu(){
	ifstream fileKhach("Khach.txt", ios::in);
	ifstream fileDK("PhieuDangKy.txt", ios::in);
	ifstream fileTraPhong("PhieuTraPhong.txt", ios::in);
	ifstream filePhong("Phong.txt", ios::in);
	if(fileKhach.fail()){
		cout << "\nKhong mo dc file khach hang!!";
		exit(0);
	}
	if(fileDK.fail()){
		cout << "\nKhong mo dc file phieu dang ky!!";
		exit(0);
	}
	if(fileTraPhong.fail()){
		cout << "\nKhong mo dc file phieu tra phong!!";
		exit(0);
	}
	if(filePhong.fail()){
		cout << "\nKhong mo dc file phieu tra phong!!";
		exit(0);
	}
	QLKH ds; QLDK dsDK; QLTP dsTP; QLP dsP;
	ds.doc_file(fileKhach);
	dsP.doc_file(filePhong);
	dsDK.doc_file(fileDK, dsP);
	dsTP.doc_file(fileTraPhong);

	fileKhach.close();
	fileDK.close();
	fileTraPhong.close();
	filePhong.close();
	
	int lc;
	do{
		cout << "\n\t\t--------------MENU--------------" << endl;
		cout << "1/ In danh sach thong tin khach hang." << endl;
		cout << "2/ In danh sach hoa don thue phong." << endl;
		cout << "3/ In danh sach hoa don tra phong." << endl;
		cout << "4/ In danh sach phong." << endl;
		cout << "5/ Nhap thong tin khach hang." << endl;
		cout << "6/ Thanh toan." << endl;
		cout << "Choose: "; cin >> lc;
		switch(lc){
			case 1:{
				cout << "\nDANH SACH THONG TIN KHACH HANG: \n";
				ifstream fileKhach("Khach.txt", ios::in);
				ds.doc_file(fileKhach);
				cout << ds;
				fileKhach.close();
				break;
			}
			case 2:{
				cout << "\nDANH SACH HOA DON THUE PHONG: \n";
			
				cout << dsDK;
				break;
			}
			case 3:{
				cout << "\nDANH SACH HOA DON TRA PHONG: \n";
				
				cout << dsTP;
				break;
			}
			case 4:{
				cout << "\nDANH SACH PHONG: \n";
				
				cout << dsP;
				break;
			}
			case 5:{
				cout << "\nNhap thong tin khach hang: \n";
				string ten; string ngaySinh; int maKH; int gioiTinh;
				cin.ignore();
				cout << "Nhap ten: "; getline(cin, ten);
				cout << "Nhap ngay sinh: "; getline(cin, ngaySinh);
				cout << "Nhap ma khach hang: "; cin >> maKH;
				cout << "Nhap gioi tinh: "; cin >> gioiTinh;
//				Khach s(ten, maKH, gioiTinh, ngaySinh);
//				cout << s;
				ofstream fileKH("Khach.txt", ios::app);
				fileKH << "\n";
				fileKH << ten << ";" << ngaySinh << "; ";
				fileKH << maKH << " " << gioiTinh;
				
				fileKH.close();
				break;
			}
			case 6:{
				cout << "\nThanh toan.";
				break;
			}
			default:{
				cout << "\nVui long nhap lai!!";
				break;
			}
		}
	}while(lc);
	
}
int main() {
	menu();
	//nhập thông tin khách hàng, phiếu đăng ký
	//tìm khách hàng theo các tiêu chí khác nhau và in ra màn hình
	
	cout << "\nOK" ;	
	return 0;
}