#include <iostream>
#include "NhanVien.h"
#include "KCV.h"

using namespace std;

/*Đầu vào: Không có
Đầu ra: Không có
Chức năng: Khởi tạo kiểm chứng viên với số lỗi bằng 0*/
KCV::KCV() : NhanVien()
{
    SoLoi = 0;
}

/*Đầu vào: Thông tin kiểm chứng viên
Đầu ra: Không có
Chức năng:
    - Khởi tạo kiểm chứng viên với đầy đủ thông tin*/
KCV::KCV(std::string id, std::string ten, int t, std::string dt, std::string mail, double l, int soloi) : NhanVien(id, ten, t, dt, mail, l)
{
    SoLoi = soloi;
}

/*Đầu vào: other: đối tượng kiểm chứng viên cần sao chép
Đầu ra: Không có
Chức năng: Khởi tạo sao chép kiểm chứng viên*/
KCV::KCV(const KCV &other) : NhanVien(other)
{
    SoLoi = other.SoLoi;
}

/*Đầu vào: Không có
Đầu ra: Không có
Chức năng: Nhập thông tin kiểm chứng viên và số lỗi phát hiện*/
void KCV::Nhap()
{
    NhanVien::Nhap();
    while(true){
        cout << "Nhập số lỗi phát hiện: "; cin >> SoLoi;
        if(cin.fail() || cin.peek() != '\n' || SoLoi < 0)
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
Chức năng: Xuất thông tin kiểm chứng viên*/
void KCV::Xuat()
{
    NhanVien::Xuat();
    cout << "Số lỗi phát hiện: " << SoLoi << '\n';
    cout << "Lương: " << TinhLuong() << '\n';
}

/*Đầu vào: Không có
Đầu ra: Lương của kiểm chứng viên
Chức năng: Tính lương*/
double KCV::TinhLuong()
{
    return LuongCB + SoLoi * 50000;
}

/*Đầu vào: Không có
Đầu ra:Số nguyên 2
Chức năng: Trả về loại nhân viên là kiểm chứng viên*/
int KCV::getType()
{
    return 2;
}