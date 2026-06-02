#include <iostream>
#include <fstream>
#include "KhachHang.h"
#include "KhachHangC.h"

using namespace std;

/*Đầu vào: Không có
Đầu ra: Không có
Chức năng: Khởi tạo khách hàng loại C mặc định.*/
KhachHangC::KhachHangC() : KhachHang()
{}

/*Đầu vào:
    ten: tên khách hàng
    luonghang: số lượng hàng
    gia: đơn giá hàng
Đầu ra: Không có
Chức năng: Khởi tạo khách hàng loại C với đầy đủ thông tin.*/
KhachHangC::KhachHangC(std::string ten, int luonghang, double gia) : KhachHang(ten, luonghang, gia)
{}

/*Đầu vào:
    other: khách hàng loại C nguồn
Đầu ra: Không có
Chức năng: Sao chép khách hàng loại C.*/
KhachHangC::KhachHangC(const KhachHangC &other) : KhachHang(other)
{}

/*Đầu vào:
    in: luồng đọc file
Đầu ra: Không có
Chức năng: Nhập thông tin khách hàng loại C từ file.*/
void KhachHangC::Nhap(ifstream &in)
{
    KhachHang::Nhap(in);
}

/*Đầu vào:
    out: luồng ghi file
Đầu ra: Không có
Chức năng: Xuất thông tin khách hàng loại C ra file.*/
void KhachHangC::Xuat(ofstream &out)
{
    KhachHang::Xuat(out);
    out << "Số tiền phải trả: " << TienTra() << '\n';
}

/*Đầu vào: Không có
Đầu ra: Trả về số tiền phải trả
Chức năng: Tính tiền phải trả*/
double KhachHangC::TienTra()
{
    return (SoLuongHang * DonGiaHang) * 0.5 + SoLuongHang * DonGiaHang * 0.1;
}

/*Đầu vào: Không có
Đầu ra: Trả về chuỗi string "C" cho biết loại khách hàng
Chức năng: Cho biết loại khách hàng*/
string KhachHangC::getType()
{
    return "C";
}