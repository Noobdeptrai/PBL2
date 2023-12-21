#include "Date.h"
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
#include <conio.h>
#include <stdlib.h>
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
	dsTP.doc_file(fileTraPhong, dsP, dsDK);

	fileKhach.close();
	fileDK.close();
	fileTraPhong.close();
	filePhong.close();
	
	int lc;
	do{
		first:
		system("CLS");
		cout << "\t\t--------------MENU--------------" << endl;
		cout << "1/ In du lieu ra man hinh." << endl;
		cout << "2/ Thue phong." << endl; 
		cout << "3/ Tra phong." << endl;
		cout << "4/ Xoa." << endl;
		cout << "5/ Tim kiem thong tin khach hang." << endl;
		cout << "6/ Sap xep." << endl;
		cout << "7/ Thong ke tong so tien theo loai phong." << endl; 
		cout << "0/ Thoat." << endl;
		cout << "Choose: "; second: cin >> lc;
		switch(lc){
			case 1:{
				system("CLS");
				cout << "1/ In danh sach thong tin khach hang." << endl;
				cout << "2/ In danh sach hoa don thue phong." << endl;
				cout << "3/ In danh sach hoa don tra phong." << endl;
				cout << "4/ In danh sach phong" << endl;
				cout << "5/ Quay lai menu chinh." << endl;
				cout << "Choose: "; function1:
				int lc2; cin >> lc2;
				switch(lc2){
					case 1:{
						system("CLS");
						cout << "\nDANH SACH THONG TIN KHACH HANG: \n";
						ifstream fileKhach("Khach.txt", ios::in);
						ds.doc_file(fileKhach);
						cout << ds;
						fileKhach.close();
						getch();
						goto first;
					}
					case 2:{
						system("CLS");
						cout << "\nDANH SACH HOA DON THUE PHONG: \n";
						ifstream fileDK("PhieuDangKy.txt", ios::in);
						dsDK.doc_file(fileDK, dsP);
						cout << dsDK;
						fileDK.close();
						getch();
						goto first;
					}
					case 3:{
						system("CLS");
						cout << "\nDANH SACH HOA DON TRA PHONG: \n";
						ifstream fileTraPhong("PhieuTraPhong.txt", ios::in);
						dsTP.doc_file(fileTraPhong, dsP, dsDK);
						fileTraPhong.close();
						cout << dsTP;
						getch();
						goto first;
					}
					case 4:{
						system("CLS");
						cout << "\n\tDANH SACH PHONG: \n";
						cout << dsP;
						cout << "\n(Nhan phim bat ky de thoat)";
						getch();
						goto first;
					}
					case 5:{
						goto first;
					}
					default:{
						cout << "\nVui long nhap lai!";
						goto function1;
					}
				}
			}
			case 2:{
				function2:
				system("CLS");
				string ten; string ngaySinh; int maKH; int gioiTinh;
				ifstream fileKhach("Khach.txt", ios::in);
				ds.doc_file(fileKhach);
				fileKhach.close();
				int index;
				cout << "-------------NHAP THONG TIN KHACH HANG-------------\n";
				function20:
				cout << "Nhap ma khach hang: "; function21: cin >> maKH; index = -1;

				if(maKH > 9999 || maKH < 1000){
					cout << "\nMA KH KHONG HOP LE, VUI LONG NHAP LAI!!";
					goto function21;
				}
				for(int i = 0; i < ds.getSize(); ++i){
					if(ds[i].getMaKH() == maKH){
						index = i;
						cout << "Co phai day la KH ban can nhap thong tin?\n\n";
						cout << ds[index];
						cout << "\n1. Tiep tuc.";
						cout << "\n2. Nhap lai.";
						cout << "\nChoose: ";
						int lc; function22: cin >> lc;
						switch(lc){
							case 1:{
								goto function24;
							}
							case 2:{
								goto function20;
							}
							default:{
								cout << "\nVUI LONG NHAP LAI!";
								goto function22;
							}
						}
					}
				}
				cout << "Nhap ten: "; cin.ignore(); function23: getline(cin, ten);
				for(int i = 0; i < ds.getSize(); ++i){
					if(ds[i].getTen().compare(ten) == 0){
						cout << "\nTEN BI TRUNG, VUI LONG NHAP LAI!!\n";
						goto function23;
					}
				}
				cout << "Nhap ngay sinh: "; getline(cin, ngaySinh);
				cout << "Nhap gioi tinh: "; cin >> gioiTinh;
				cout << "\nDA NHAP XONG THONG TIN KHACH HANG!!\n";
//				Khach s(ten, maKH, gioiTinh, ngaySinh);
//				cout << s;
				function24:
				ofstream fileKH("Khach.txt", ios::app);
				if(index == -1){
					fileKH << "\n";
					fileKH << ten << ";" << ngaySinh << "; ";
					fileKH << maKH << " " << gioiTinh;
				}
				
				fileKH.close();

				ifstream fileDK("PhieuDangKy.txt", ios::in);
				ifstream filePhong("Phong.txt", ios::in);
				dsP.doc_file(filePhong);
				dsDK.doc_file(fileDK, dsP);
				fileDK.close();
				filePhong.close();

				int maHD; string checkIn, soPhong; int n; string thoiHan;
				cout << "\n\n-------------HOA DON THUE PHONG-------------\n";
				cout << "Nhap ma hoa don: "; function25: cin >> maHD; cin.ignore();
				if(maHD < 10000 || maHD > 99999){
					cout << "MA HD KHONG HOP LE, VUI LONG NHAP LAI!!\n";
					goto function25;
				}
				for(int i = 0; i < dsDK.getSize(); ++i){
					if(maHD == dsDK[i].getMaHD()){
						cout << "MA HD BI TRUNG, VUI LONG NHAP LAI!!\n";
						goto function25;
					}
				}
				function26:
				index = -1;
				cout << "Nhap so phong: "; function27: getline(cin, soPhong);
				for(int i = 0; i < dsP.getSize(); ++i){
					if(dsP[i].getSoPhong().compare(soPhong) == 0){
						index = i;
						if(dsP[index].getTinhTrang() == true){
							cout << "Phong con trong, co the thue duoc!\n";
							dsP[index].setTinhTrang(false);
						}
						else {
							cout << "Phong dang duoc su dung, vui long chon phong khac!\n";
							goto function26;
						}
					}
				}
				if(index == -1){
					cout << "SO PHONG KHONG HOP LE, VUI LONG NHAP LAI!!\n";
					goto function27;
				}
				cout << "Nhap ngay check in: "; getline(cin, checkIn);
				cout << "Nhap so nguoi: "; cin >> n; cin.ignore();
				cout << "Nhap thoi han: "; getline(cin, thoiHan);
				cout << "\nHOA DON THUE HANG DA HOAN THANH!!";

				ofstream fileDangKy("PhieuDangKy.txt", ios::app);
				fileDangKy << "\n";
				fileDangKy << maHD << " " << maKH 
				<< " " << checkIn << ";" << soPhong
				<< "; " << n << " " << thoiHan;

				fileDangKy.close();
				cout << "\n(Nhan phim bat ky de quay ve menu chinh!)";				
				getch();
				goto first;
			}
			case 3:{
				function4:
				system("CLS"); int maHD; int index; string checkOut;
				ifstream fileDK("PhieuDangKy.txt", ios::in);
				ifstream fileTraPhong("PhieuTraPhong.txt", ios::in);
				ifstream filePhong("Phong.txt", ios::in);
				dsP.doc_file(filePhong);
				dsDK.doc_file(fileDK, dsP);
				dsTP.doc_file(fileTraPhong, dsP, dsDK);
				fileDK.close();
				fileTraPhong.close();
				filePhong.close();
				cout << "\n-------------HOA DON TRA PHONG-------------\n";
				cout << "Nhap ma HD cua KH can tra phong: "; function41: cin.ignore(); cin >> maHD; index = -1;
				for(int i = 0; i < dsTP.getSize(); ++i){
					if(maHD == dsTP[i].getMaHD()){
						cout << "HOA DON NAY DA DUOC THANH TOAN, VUI LONG NHAP LAI!!\n";
						goto function41;
					}
				}
				for(int i = 0; i < dsDK.getSize(); ++i){
					if(maHD == dsDK[i].getMaHD()){
						index = i;
					}
				}
				if(index == -1){
					cout << "MA HD KHONG HOP LE, VUI LONG NHAP LAI!!\n";
					goto function41;
				}
				else{
					cout << "Nhap ngay tra phong: "; cin.ignore(); getline(cin, checkOut);
				}
				ofstream fileTP("PhieuTraPhong.txt", ios::app);
				fileTP << "\n";
				fileTP << dsDK[index].getMaHD() << " " << dsDK[index].getMaKH() << " "
				<< dsDK[index].getCheckIn() << ";" << checkOut << ";" << dsDK[index].getCheckOut();
				fileTP.close();
				
				for(int i = 0; i < dsP.getSize(); ++i){
					if(dsDK[index].getSoPhong().compare(dsP[i].getSoPhong()) == 0){
						dsP[i].setTinhTrang(true);
					}
				}
				
				Date checkOut1(checkOut), checkIn1(dsDK[index].getCheckIn());
				int n = checkOut1 - checkIn1;
				string s = dsDK[index].getSoPhong();
				char c = s[0]; int i = 0; int donGia;
				while(c == ' '){
					i++;
					c = s[i];
				}
				switch(c){
					case 'A':{
						donGia = 400;
						break;
					}
					case 'B':{
						donGia = 300;
						break;
					}
					case 'C':{
						donGia = 200;
						break;
					}
					case 'D':{
						donGia = 200;
						break;
					}
					default:{
						cout << "ERROR!!\n";
						getch();
						goto first;
						break;
					}
				}
				cout << "\nSO NGAY O: " << n;
				cout << "\nDON GIA: " << donGia << " (Phong loai " << c << ")";
				cout << "\nSO TIEN CAN PHAI THANH TOAN: " << donGia * n << " (don vi tien te)\n";
				cout << "\n(Nhan phim bat ky de quay ve menu chinh!)";				
				getch();
				goto first;
			}
			case 4:{
				//function3:
				system("CLS");
				cout << "1/ Xoa KH.\n";
				cout << "2/ Xoa hoa don.\n";
				cout << "0/ Quay lai menu chinh.\n";
				cout << "Choose: "; function3:
				int lc2; cin >> lc2;
				switch(lc2){
					case 1:{
						system("CLS");
						int maKH;
						ifstream fileKhach("Khach.txt", ios::in);
						ds.doc_file(fileKhach);
						// cout << ds;
						
						cout << "Nhap ma KH can xoa: "; function31: 
						cin >> maKH;
						int index = -1; 
						for(int i = 0; i < ds.getSize(); ++i){
							if(ds[i].getMaKH() == maKH){
								index = i;
							}
						}
						if(index == -1){
							cout << "Ma KH khong hop le!\n";
							goto function31;
						}
						
						ds.Remove(maKH);
						
						cout << "\nXoa KH thanh cong!";
						// cout << dsTP;

						cout << "\nNhan phim bat ky de quay ve menu chinh!";
						getch();
						goto first;
					}
					case 2:{
						system("CLS");
						int maHD; int index1, index2; int maKH; string soPhong;
						ifstream fileDK("PhieuDangKy.txt", ios::in);
						ifstream filePhong("Phong.txt", ios::in);
						// QLDK dsDK; QLP dsP;
						dsP.doc_file(filePhong);
						dsDK.doc_file(fileDK, dsP);
						fileDK.close();
						filePhong.close();
						ifstream fileTraPhong("PhieuTraPhong.txt", ios::in);
						// QLTP dsTP;
						dsTP.doc_file(fileTraPhong, dsP, dsDK);
						fileTraPhong.close();
						cout << "Nhap ma hoa don can xoa: "; function32: cin >> maHD; index1 = -1; index2 = -1;
						for(int i = 0; i < dsDK.getSize(); ++i){
							if(maHD == dsDK[i].getMaHD()){
								index1 = i;
								soPhong = dsDK[i].getSoPhong();
								maKH = dsDK[i].getMaKH();
								dsDK.Remove(maKH);
							}
						}
						if(index1 == -1){
							cout << "MA HOA DON KHONG HOP LE, VUI LONG NHAP LAI!!\n";
							goto function32;
						}
						for(int i = 0; i < dsTP.getSize(); ++i){
							if(maHD == dsTP[i].getMaHD()){
								index2 = i;
								maKH = dsTP[i].getMaKH();
								dsTP.Remove(maKH);
							}
						}
						if(index2 == -1){
							// cout << "\nSo phong: " << soPhong;
							for(int i = 0; i < dsP.getSize(); ++i){
								if(soPhong.compare(dsP[i].getSoPhong()) == 0){
									dsP[i].setTinhTrang(true);
								}
							}
						}
						cout << "\nXoa hoa don thanh cong!!";
						// dsDK.Remove(maKH);
						// // cout << dsDK;

						
						// dsTP.Remove(maKH);
						// fileKhach.close();

						getch();
						goto first;
					}
					case 0:{
						goto first;
					}
					default:{
						cout << "Vui long nhap lai!!\n";
						goto function3;
					}
				}

				
			}
			case 5:{
				system("CLS");
				cout << "1/ Tim kiem theo ma KH." << endl;
				cout << "2/ Tim kiem theo so phong." << endl;
				// cout << "3/ Tim kiem theo ma hoa don." << endl;
				cout << "0/ Quay lai menu chinh." << endl;
				cout << "Choose: "; function5:
				int lc2; cin >> lc2;
				switch(lc2){
					case 1:{
						system("CLS");
						cout << "Ma KH hien co: " << endl;
						ifstream fileKhach("Khach.txt", ios::in);
						ds.doc_file(fileKhach);
						fileKhach.close();

						for(int i = 0; i < ds.getSize(); ++i){
							cout << ds[i].getMaKH() << endl;
						}
						cout << "Choose: "; 
						function51:
						int maKH; cin >> maKH;
						int index = -1;
						for(int i = 0; i < ds.getSize(); ++i){
							if(ds[i].getMaKH() == maKH){
								index = i;
							}
						}
						if(index == -1){
							cout << "\nMa KH khong hop le, vui long nhap lai!!";
							goto function51;
						}
						// cout << endl;
						cout << left << setw(20) << "Ten KH" << "|" << setw(10) << "Ma KH" << "|" << setw(13) << "Gioi tinh" << "|" << setw(15) << "Ngay sinh" << endl;
						cout << ds[index];
						cout << "\n(Nhan phim bat ky de thoat)";
						getch();
						goto first;
					}
					case 2:{
						system("CLS");
						cout << "Cac phong hien dang duoc su dung: " << endl;
						ifstream fileDK("PhieuDangKy.txt", ios::in);
						dsDK.doc_file(fileDK, dsP);
						fileDK.close();
						ifstream fileKhach("Khach.txt", ios::in);
						ds.doc_file(fileKhach);
						fileKhach.close();

						for(int i = 0; i < dsP.getSize(); ++i){
							if(dsP[i].getTinhTrang() == false){
								cout << dsP[i].getSoPhong() << endl;
							}
						}
						cout << "Choose: "; 
						function42:
						string soPhong; cin >> soPhong;
						
						int index = -1; int maKH;

						for(int i = 0; i < dsP.getSize(); ++i){
							if(dsP[i].getTinhTrang() == false && dsP[i].getSoPhong().compare(soPhong) == 0 ){
								for(int i = 0; i < dsDK.getSize(); ++i){
									if(dsDK[i].getSoPhong().compare(soPhong) == 0){
										maKH = dsDK[i].getMaKH();
									}
								}
								for(int i = 0; i < ds.getSize(); ++i){
									if(ds[i].getMaKH() == maKH){
										index = i;
									}
								}
							}
						}
						if(index == -1){
							cout << "\nSo phong khong hop le, vui long nhap lai!!";
							goto function42;
						}
						cout << left << setw(20) << "Ten KH" << "|" << setw(10) << "Ma KH" << "|" << setw(13) << "Gioi tinh" << "|" << setw(15) << "Ngay sinh" << endl;
						cout << ds[index];
						cout << "(Nhan phim bat ky de quay ve menu chinh)";
						getch();
						goto first;
					}
					case 0:{
						goto first;
					}
					default:{
						cout << "\nVui long nhap lai!";
						goto function5;
					}
				}

			}
			case 6:{
				function6: system("CLS");
				cout << "1/ Sap xep khach hang theo gioi tinh.\n";
				cout << "0/ Quay lai menu chinh.\n";
				cout << "Choose: "; function61: int lc3; cin >> lc3;
				switch(lc3){
					case 1:{
						ifstream fileKhach("Khach.txt", ios::in);
						ds.doc_file(fileKhach);
						fileKhach.close();
						cout << left << setw(20) << "Ten KH" << "|" << setw(10) << "Ma KH" << "|" << setw(13) << "Gioi tinh" << "|" << setw(15) << "Ngay sinh" << endl;
						for(int i = 0; i < ds.getSize(); ++i){
							if(ds[i].getGioiTinh() == 1){
								cout << ds[i];
							}
						}
						cout << "--------------------------------------------------------\n";
						for(int j = 0; j < ds.getSize(); ++j){
							if(ds[j].getGioiTinh() == 0){
								cout << ds[j];
							}
						}
						getch();
						goto first;
					}
					case 0:{
						goto first;
					}
					default:{
						cout << "Vui long nhap lai!!\n";
						goto function61;
					}
				}
			}
			case 7:{
				function7: system("CLS");
				int arr[4] = {0,0,0,0};
				int maHD; char c; string s; int index1;
				ifstream fileDK("PhieuDangKy.txt", ios::in);
				ifstream fileTraPhong("PhieuTraPhong.txt", ios::in);
				ifstream filePhong("Phong.txt", ios::in);
				dsP.doc_file(filePhong);
				dsDK.doc_file(fileDK, dsP);
				dsTP.doc_file(fileTraPhong, dsP, dsDK);
				fileDK.close();
				fileTraPhong.close();
				filePhong.close();
				
				for(int i = 0; i < dsTP.getSize(); ++i){
					// cout << i ;
					maHD = dsTP[i].getMaHD();
					index1 = i;
					for(int j = 0; j < dsDK.getSize(); ++j){
						if(maHD == dsDK[j].getMaHD()){
							// cout << j << endl;
							s = dsDK[j].getSoPhong();
							char c = s[0]; int k = 0;
							while(c == ' '){
								k++;
								c = s[k];
							}
							Date checkOut1(dsTP[index1].getCheckOut()), checkIn1(dsTP[index1].getCheckIn());
							int n = checkOut1 - checkIn1;

							switch(c){
								case 'A':{
									int res = n * 400;
									arr[0] += res;
									break;
								}
								case 'B':{
									int res = n * 300;
									arr[1] += res;
									break;
								}
								case 'C':{
									int res = n * 200;
									arr[2] += res;
									break;
								}
								case 'D':{
									int res = n * 200;
									arr[3] += res;
									break;
								}
								default:{
									cout << "ERROR!!\n";
									exit(0);
								}
							}
						}
					}
				}
				cout << "----------BANG THONG KE TONG TIEN THEO LOAI PHONG----------\n\n";
				cout << "\t" << left << setw(12) << "Loai phong" << "|" << setw(30) << "Tong tien" << " \n";
				cout << "\t--------------------------------\n";
				cout << "\t" << left << setw(12) << "A" << "|" << arr[0] << " (don vi tien te)\n";
				cout << "\t" << left << setw(12) << "B" << "|" << arr[1] << " (don vi tien te)\n";
				cout << "\t" << left << setw(12) << "C" << "|" << arr[2] << " (don vi tien te)\n";
				cout << "\t" << left << setw(12) << "D" << "|" << arr[3] << " (don vi tien te)\n";

				cout << "\n(Nhan phim bat ky de thoat)";
				getch();
				goto first;
			}
			case 0:{
				exit(0);
			}
			default:{
				cout << "\nVui long nhap lai!!\n";
				goto second;
			}
		}
	}while(lc);
	
}
int main() {
	//menu();
	//kế thừa, đa hình
	
	//sắp xếp (loại phỏng)
	//tìm khách hàng theo các tiêu chí khác nhau và in ra màn hình (mã HĐ)

	// ifstream fileKhach("Khach.txt", ios::in);
	// QLKH ds;
	// ds.doc_file(fileKhach);
	// fileKhach.close();
	// ds.Remove(2310);
	// cout << ds;

	// ifstream fileDK("PhieuDangKy.txt", ios::in);
	// ifstream filePhong("Phong.txt", ios::in);
	// QLDK dsDK; QLP dsP; 
	// dsP.doc_file(filePhong);
	// dsDK.doc_file(fileDK, dsP);
	// fileDK.close();
	// filePhong.close();
	// // dsDK.Remove(0);
	// cout << dsDK;

	// ifstream fileTraPhong("PhieuTraPhong.txt", ios::in);
	// QLTP dsTP;
	// dsTP.doc_file(fileTraPhong);
	// fileTraPhong.close();
	// // dsTP.Remove(0);
	// cout << dsTP;
	
	cout << "\nOK";	
	return 0;
}