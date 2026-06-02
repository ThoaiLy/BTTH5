#include <iostream>
#include <fstream>
#include "KhachHang.h"
#include "KhachHangA.h"

using namespace std;

/*Đầu vào: Không có
Đầu ra: Không có
Chức năng: Khởi tạo khách hàng loại A mặc định.*/
KhachHangA::KhachHangA() : KhachHang()
{}

/*Đầu vào:
    ten: tên khách hàng
    luonghang: số lượng hàng mua
    gia: đơn giá hàng
Đầu ra: Không có
Chức năng: Khởi tạo khách hàng loại A với đầy đủ thông tin.*/
KhachHangA::KhachHangA(std::string ten, int luonghang, double gia) : KhachHang(ten, luonghang, gia)
{}

/*Đầu vào:
    other: khách hàng loại A nguồn
Đầu ra: Không có
Chức năng: Sao chép khách hàng loại A.*/
KhachHangA::KhachHangA(const KhachHangA &other) : KhachHang(other)
{}

/*Đầu vào:
    in: luồng đọc file
Đầu ra: Không có
Chức năng: Nhập thông tin khách hàng loại A từ file.*/
void KhachHangA::Nhap(ifstream &in)
{
    KhachHang::Nhap(in);
}
 
/*Đầu vào:
    out: luồng ghi file
Đầu ra: Không có
Chức năng: Xuất thông tin khách hàng loại A ra file.*/
void KhachHangA::Xuat(ofstream &out)
{
    KhachHang::Xuat(out);
    out << "Số tiền phải trả: " << TienTra() << '\n';
}

/*Đầu vào: Không có
Đầu ra: Trả về số tiền phải trả
Chức năng: Tính tiền phải trả*/
double KhachHangA::TienTra()
{
    return SoLuongHang * DonGiaHang + SoLuongHang * DonGiaHang * 0.1;
}

/*Đầu vào: Không có
Đầu ra: Trả về chuỗi string "A" cho biết loại khách hàng
Chức năng: Cho biết loại khách hàng*/
string KhachHangA::getType()
{
    return "A";
}