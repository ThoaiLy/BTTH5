#include <iostream>
#include "NVSX.h"
#include "NhanVien.h"

using namespace std;

/*Đầu vào: Không có
Đầu ra: Không có
Chức năng: Khởi tạo nhân viên sản xuất với giá trị mặc định.*/
NVSX::NVSX() : NhanVien()
{
    LuongCB = 0;
    SoSp = 0;
}

/*Đầu vào:
    ten: họ tên
    d, m, y: ngày sinh
    l: lương
    lcb: lương cơ bản
    ssp: số sản phẩm
Đầu ra: Không có
Chức năng: Khởi tạo nhân viên sản xuất.*/
NVSX::NVSX(string ten, int d, int m, int y, double lcb, int ssp) : NhanVien(ten, d, m, y)
{
    LuongCB = lcb;
    SoSp = ssp;
}

/*Đầu vào:
    other: đối tượng nhân viên sản xuất
Đầu ra: Không có
Chức năng: Khởi tạo bản sao nhân viên sản xuất.*/
NVSX::NVSX(const NVSX &other) : NhanVien(other)
{
    LuongCB = other.LuongCB;
    SoSp = other.SoSp;
}

/*Đầu vào: Không có
Đầu ra: Không có
Chức năng: Nhập thông tin nhân viên sản xuất.*/
void NVSX::Nhap()
{
    NhanVien :: Nhap();
    while(true)
    {
        cout << "Nhập lương cơ bản: ";
        cin >> LuongCB;
        if(cin.fail() || cin.peek() != '\n' || LuongCB < 0)
        {
            cout << "Dữ liệu nhập sai!\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        break;
    }

    while(true)
    {
        cout << "Nhập số sản phẩm: ";
        cin >> SoSp;
        if(cin.fail() || cin.peek() != '\n' || SoSp < 0)
        {
            cout << "Dữ liệu nhập sai!\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        break;
    }
    cin.ignore();
}

/*Đầu vào: Không có
Đầu ra: Không có
Chức năng: Xuất thông tin và lương nhân viên sản xuất.*/
void NVSX::Xuat()
{
    NhanVien :: Xuat();
    cout << "Lương cơ bản: " << LuongCB << '\n';
    cout << "Số sản phẩm: " << SoSp << '\n';
    cout << "Lương: " << TinhLuong() << '\n';
}

/*Đầu vào: Không có
Đầu ra: Tiền lương nhân viên sản xuất
Chức năng: Tính lương */
double NVSX::TinhLuong()
{
    return LuongCB + SoSp * 5000;
}

/*Đầu vào: Không có
Đầu ra: Số nguyên 1
Chức năng: Trả về loại để xác định là nhân viên sản xuất.*/
int NVSX::getType()
{
    return 1;
}