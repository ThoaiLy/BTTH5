#include <iostream>
#include <fstream>
#include "KhachHang.h"

using namespace std;

/*Đầu vào: Không có
Đầu ra: Không có
Chức năng: Khởi tạo khách hàng với các giá trị mặc định.*/
KhachHang::KhachHang()
{
    Ten = "";
    SoLuongHang = 0;
    DonGiaHang = 0;
}

/*Đầu vào:
    ten: tên khách hàng
    luonghang: số lượng hàng mua
    gia: đơn giá hàng
Đầu ra: Không có
Chức năng: Khởi tạo khách hàng với đầy đủ thông tin.*/
KhachHang::KhachHang(string ten, int luonghang, double gia)
{
    Ten = ten;
    SoLuongHang = luonghang;
    DonGiaHang = gia;
}

/*Đầu vào:
    other: khách hàng nguồn
Đầu ra: Không có
Chức năng: Sao chép thông tin từ một khách hàng khác.*/
KhachHang::KhachHang(const KhachHang &other)
{
    Ten = other.Ten;
    SoLuongHang = other.SoLuongHang;
    DonGiaHang = other.DonGiaHang;
}

/*Đầu vào:
    in: luồng đọc file
Đầu ra: Không có
Chức năng: Đọc thông tin khách hàng từ file.*/
void KhachHang::Nhap(ifstream &in)
{
    in.ignore();
    getline(in, Ten);
    in >> SoLuongHang;
    in >> DonGiaHang;
}

/*Đầu vào:
    out: luồng ghi file
Đầu ra: Không có
Chức năng: Xuất tên khách hàng ra file.*/
void KhachHang::Xuat(ofstream &out)
{
    out << "Tên: " << Ten << '\n';
}

/*Đầu vào: Không có
Đầu ra: Không có
Chức năng: Destructor ảo của lớp KhachHang.*/
KhachHang::~KhachHang(){}