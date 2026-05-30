#include <iostream>
#include "NVVP.h"
#include "NhanVien.h"

using namespace std;

/*Đầu vào: Không có
Đầu ra: Không có
Chức năng: Khởi tạo nhân viên văn phòng với giá trị mặc định.*/
NVVP::NVVP() : NhanVien()
{
    SoNgayLamViec = 0;
}

/*Đầu vào:
    ten: họ tên
    d, m, y: ngày sinh
    l: lương
    songaylam: số ngày làm việc
Đầu ra: Không có
Chức năng: Khởi tạo nhân viên văn phòng.*/
NVVP::NVVP(std::string ten, int d, int m, int y, int songaylam) : NhanVien(ten, d, m, y)
{
    SoNgayLamViec = songaylam;
}

/*Đầu vào:
    other: đối tượng nhân viên văn phòng
Đầu ra: Không có
Chức năng: Khởi tạo bản sao nhân viên văn phòng.*/
NVVP::NVVP(const NVVP &other) : NhanVien(other)
{
    SoNgayLamViec = other.SoNgayLamViec;
}

/*Đầu vào: Không có
Đầu ra: Không có
Chức năng: Nhập thông tin nhân viên văn phòng.*/
void NVVP::Nhap()
{
    NhanVien::Nhap();
    while(true)
    {
        cout << "Nhập số ngày làm việc: ";
        cin >> SoNgayLamViec;
        if(cin.fail() || cin.peek() != '\n' || SoNgayLamViec < 0)
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
Chức năng: Xuất thông tin và lương nhân viên văn phòng.*/
void NVVP::Xuat()
{
    NhanVien::Xuat();
    cout << "Số ngày làm việc: " << SoNgayLamViec << '\n';
    cout << "Lương: " << TinhLuong() << '\n';
}

/*Đầu vào: Không có
Đầu ra: Tiền lương nhân viên văn phòng
Chức năng: Tính lương */
double NVVP::TinhLuong()
{
    return SoNgayLamViec * 100000;
}

/*Đầu vào: Không có
Đầu ra: Số nguyên 2
Chức năng: Trả về loại để xác định là nhân viên văn phòng.*/
int NVVP::getType()
{
    return 2;
}