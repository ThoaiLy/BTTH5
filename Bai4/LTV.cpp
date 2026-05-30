#include <iostream>
#include "NhanVien.h"
#include "LTV.h"

using namespace std;

/*Đầu vào: Không có
Đầu ra: Không có
Chức năng: Khởi tạo lập trình viên với số giờ làm thêm bằng 0*/
LTV::LTV() : NhanVien()
{
    SoGioLamThem = 0;
}

/*Đầu vào: Thông tin lập trình viên
Đầu ra: Không có
Chức năng: Khởi tạo lập trình viên với đầy đủ thông tin*/
LTV::LTV(std::string id, std::string ten, int t, std::string dt, std::string mail, double l, int sohlam) : NhanVien(id, ten, t, dt, mail, l)
{
    SoGioLamThem = sohlam;
}

/*Đầu vào: other: đối tượng lập trình viên cần sao chép
Đầu ra: Không có
Chức năng: Khởi tạo sao chép lập trình viên*/
LTV::LTV(const LTV &other) : NhanVien(other)
{
    SoGioLamThem = other.SoGioLamThem;
}

/*Đầu vào: Không có
Đầu ra: Không có
Chức năng: Nhập thông tin lập trình viên và số giờ làm thêm*/
void LTV::Nhap()
{
    NhanVien::Nhap();
    while(true){
        cout << "Nhập số giờ làm thêm: "; cin >> SoGioLamThem;
        if(cin.fail() || cin.peek() != '\n' || SoGioLamThem < 0)
        {
            cout << "Dữ liệu nhập sai!\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        break;
    }
}

/*Đầu vào: Không có
Đầu ra: Không có
Chức năng: Xuất thông tin lập trình viên*/
void LTV::Xuat()
{
    NhanVien::Xuat();
    cout << "Số giờ làm thêm: " << SoGioLamThem << '\n';
    cout << "Lương: " << TinhLuong() << '\n';
}

/*Đầu vào: Không có
Đầu ra: Lương của lập trình viên
Chức năng: Tính lương*/
double LTV::TinhLuong()
{
    return LuongCB + SoGioLamThem * 200000;
}

/*Đầu vào: Không có
Đầu ra: Số nguyên 1
Chức năng: Trả về loại nhân viên là lập trình viên*/
int LTV::getType()
{
    return 1;
}