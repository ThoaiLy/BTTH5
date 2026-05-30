#include <iostream>
#include "GiaoDich.h"
#include "GiaoDichDat.h"

using namespace std;

/* Đầu vào: Không có
   Đầu ra: Không có
   Chức năng: Khởi tạo giao dịch đất với loại đất rỗng */
GiaoDichDat::GiaoDichDat() : GiaoDich()
{
    loai = "";
}

/* Đầu vào: Thông tin giao dịch đất
   Đầu ra: Không có
   Chức năng: Khởi tạo giao dịch đất với các giá trị được truyền vào */
GiaoDichDat::GiaoDichDat(string id, int d, int m, int y, double price, double s, string l) : GiaoDich(id, d, m, y, price, s)
{
    loai = l;
}

/* Đầu vào: other: giao dịch đất cần sao chép
   Đầu ra: Không có
   Chức năng: Tạo bản sao giao dịch đất */
GiaoDichDat::GiaoDichDat(const GiaoDichDat &other) : GiaoDich(other)
{
    loai = other.loai;
}

/* Đầu vào:Không có
   Đầu ra: Không có
   Chức năng: Nhập thông tin giao dịch đất và loại đất */
void GiaoDichDat::Nhap()
{
    GiaoDich :: Nhap();
    while(true)
    {
        cout << "Nhập loại đất: "; cin >> loai;
        if(cin.fail() || cin.peek() != '\n' || (loai != "A" && loai != "B" && loai != "C"))
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

/* Đầu vào: Không có
   Đầu ra: Không có
   Chức năng: Xuất thông tin giao dịch đất và thành tiền */
void GiaoDichDat::Xuat()
{
    GiaoDich :: Xuat();
    cout << "Loại đất: " << loai << '\n';
    cout << "Thành tiền: " << ThanhTien() << '\n';
}

/* Đầu vào: Không có
   Đầu ra: Số nguyên 1
   Chức năng: Xác định đây là giao dịch đất */
int GiaoDichDat::LayLoaiGD()
{
    return 1;
}

/* Đầu vào: Không có
   Đầu ra: Không có
   Chức năng: Tính thành tiền theo loại đất */
double GiaoDichDat::ThanhTien()
{
    if(loai == "A")
        return DienTich * DonGia * 1.5;
    else
        return DienTich * DonGia;
}

/* Đầu vào: Không có
   Đầu ra: Chuỗi string cho biết loại đất
   Chức năng: Trả về loại đất A, B hoặc C */
string GiaoDichDat::getType()
{
    return loai;
}