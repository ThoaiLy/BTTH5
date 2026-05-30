#include <iostream>
#include "GiaoDich.h"
#include "GiaoDichCHCC.h"

using namespace std;

/* Đầu vào: Không có
   Đầu ra: true nếu hợp lệ, false nếu không hợp lệ
   Chức năng: Kiểm tra mã căn hộ chỉ chứa chữ và số */
bool GiaoDichCHCC::isValid()
{
    if(maCan.empty())
        return false;
    for(int i = 0; i < maCan.length(); i++)
        if(!isdigit(maCan[i]) && !isalpha(maCan[i]))
            return false;
    return true;
}

/* Đầu vào: Không có
   Đầu ra: Không có
   Chức năng: Khởi tạo giao dịch căn hộ chung cư mặc định */
GiaoDichCHCC::GiaoDichCHCC() : GiaoDich()
{
    viTriTang = 0;
    maCan = "";
}

/* Đầu vào: Thông tin căn hộ chung cư
   Đầu ra: Không có
   Chức năng: Khởi tạo giao dịch căn hộ chung cư */
GiaoDichCHCC::GiaoDichCHCC(string id, int d, int m, int y, double price, double s, int vt, string macan) : GiaoDich(id, d, m, y, price, s)
{
    viTriTang = vt;
    maCan = macan;
}

/* Đầu vào: other: giao dịch căn hộ cần sao chép
   Đầu ra: Không có
   Chức năng: Tạo bản sao giao dịch căn hộ chung cư */
GiaoDichCHCC::GiaoDichCHCC(const GiaoDichCHCC &other) : GiaoDich(other)
{
    viTriTang = other.viTriTang;
    maCan = other.maCan;
}

/* Đầu vào: Không có
   Đầu ra: Không có
   Chức năng: Nhập vị trí tầng và mã căn */
void GiaoDichCHCC::Nhap()
{
    GiaoDich::Nhap();
    while(true)
    {
        cout << "Nhập tầng: "; cin >> viTriTang;
        if(cin.fail() || cin.peek() != '\n' || viTriTang <= 0)
        {
           cout << "Dữ liệu nhập sai!\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        cin.ignore();
        break;
    }

    while(true)
    {
        cout << "Nhập mã căn: "; getline(cin, maCan);
        if(!isValid())
        {
           cout << "Dữ liệu nhập sai!\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        break;
    }
}

/* Đầu vào: Không có
   Đầu ra: Không có
   Chức năng: Xuất thông tin căn hộ chung cư và thành tiền */
void GiaoDichCHCC::Xuat()
{
    GiaoDich :: Xuat();
    cout << "Vị trí tầng: " << viTriTang << '\n';
    cout << "Mã căn: " << maCan << '\n';
    cout << "Thành tiền: " << ThanhTien() << '\n';
}

/* Đầu vào: Không có
   Đầu ra: Số nguyên 3
   Chức năng: Xác định đây là giao dịch căn hộ chung cư */
int GiaoDichCHCC::LayLoaiGD()
{
    return 3;
}

/* Đầu vào: Không có
   Đầu ra: Thành tiền giao dịch căn hộ chung cư
   Chức năng: Tính thành tiền theo vị trí tầng */
double GiaoDichCHCC::ThanhTien()
{
    if(viTriTang == 1)
        return DienTich * DonGia * 2;
    else if(viTriTang >= 15)
        return DienTich * DonGia * 1.2;
    else
        return DienTich * DonGia;
}

/* Đầu vào: Không có
   Đầu ra: Vị trí tầng
   Chức năng: Trả về vị trí tầng của căn hộ */
int GiaoDichCHCC::getViTriTang()
{
    return viTriTang;
}