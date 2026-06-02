#include <iostream>
#include <fstream>
#include "KhachHang.h"
#include "KhachHangB.h"

using namespace std;

/*Đầu vào: Không có
Đầu ra: Không có
Chức năng: Khởi tạo khách hàng loại B mặc định.*/
KhachHangB::KhachHangB() : KhachHang()
{
    SoNamTT = 0;
}

/*Đầu vào:
    ten: tên khách hàng
    luonghang: số lượng hàng
    gia: đơn giá
    namtt: số năm thân thiết
Đầu ra: Không có
Chức năng: Khởi tạo khách hàng loại B.*/
KhachHangB::KhachHangB(std::string ten, int luonghang, double gia, int namtt) : KhachHang(ten, luonghang, gia)
{
    SoNamTT = namtt;
}

/*Đầu vào:
    other: khách hàng loại B nguồn
Đầu ra: Không có
Chức năng: Sao chép khách hàng loại B.*/
KhachHangB::KhachHangB(const KhachHangB &other) : KhachHang(other)
{
    SoNamTT = other.SoNamTT;
}
     
/*Đầu vào:
    in: luồng đọc file
Đầu ra: Không có
Chức năng: Nhập thông tin khách hàng loại B từ file.*/
void KhachHangB::Nhap(ifstream &in)
{
    KhachHang::Nhap(in);
    in >> SoNamTT;
}

/*Đầu vào:
    out: luồng ghi file
Đầu ra: Không có
Chức năng: Xuất thông tin khách hàng loại B ra file.*/
void KhachHangB::Xuat(ofstream &out)
{
    KhachHang::Xuat(out);
    out << "Số tiền phải trả: " << TienTra() << '\n';
}
  
/*Đầu vào: Không có
Đầu ra: Trả về số tiền phải trả
Chức năng: Tính tiền phải trả*/
double KhachHangB::TienTra()
{
    double KM = max(SoNamTT * 0.05, 0.5);
    return (SoLuongHang * DonGiaHang) * (1 - KM) + SoLuongHang * DonGiaHang * 0.1;
}

/*Đầu vào: Không có
Đầu ra: Trả về chuỗi string "B" cho biết loại khách hàng
Chức năng: Cho biết loại khách hàng*/
string KhachHangB::getType()
{
    return "B";
}