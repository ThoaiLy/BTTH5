#include <iostream>
#include "GiaoDich.h"
#include "GiaoDichNhaPho.h"

using namespace std;

/* Đầu vào: Không có
   Đầu ra: true nếu hợp lệ, false nếu không hợp lệ
   Chức năng: Kiểm tra địa chỉ chỉ chứa chữ, số và khoảng trắng */
bool GiaoDichNhaPho::isValidAddress()
{
    for(int i = 0; i < diaChi.length(); i++)
        if(!isdigit(diaChi[i]) && !isalpha(diaChi[i]) && diaChi[i] != ' ')
            return false;
    return true;
}

/* Đầu vào: Không có
   Đầu ra: Không có
   Chức năng: Khởi tạo giao dịch nhà phố mặc định */
GiaoDichNhaPho::GiaoDichNhaPho() : GiaoDich()
{
    loai = -1; //Tức là chưa được phân loại
    diaChi = "";
}

/* Đầu vào: Thông tin giao dịch nhà phố
   Đầu ra: Không có
   Chức năng: Khởi tạo giao dịch nhà phố với dữ liệu cho trước */
GiaoDichNhaPho::GiaoDichNhaPho(std:: string id, int d, int m, int y, double price, double s, int l, std::string address) : GiaoDich(id, d, m, y, price, s)
{
    loai = l;
    diaChi = address;
}

/* Đầu vào: other: giao dịch nhà phố cần sao chép
   Đầu ra: Không có
   Chức năng: Tạo bản sao giao dịch nhà phố */
GiaoDichNhaPho::GiaoDichNhaPho(const GiaoDichNhaPho &other) : GiaoDich(other)
{
    loai = other.loai;
    diaChi = other.diaChi;
}

/* Đầu vào: Không có
   Đầu ra: Không có
   Chức năng: Nhập loại nhà và địa chỉ */
void GiaoDichNhaPho::Nhap()
{
    GiaoDich :: Nhap();
    while(true)
    {
        cout << "Nhập loại nhà: "; cin >> loai;
        if(cin.fail() || cin.peek() != '\n' || (loai != 1 && loai != 2))
        {
            cout << "Dữ liệu nhập sai!\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        cin.ignore();
        break;
    }

    while (true)
    {
        cout << "Nhập địa chỉ: "; getline(cin, diaChi);
        if(!isValidAddress())
        {
            cout << "Dữ liệu nhập sai!\n";
            continue;
        }
        break;
    }
}

/* Đầu vào: Không có
   Đầu ra: Không có
   Chức năng: Xuất thông tin giao dịch nhà phố và thành tiền */
void GiaoDichNhaPho::Xuat()
{
    GiaoDich :: Xuat();
    if(loai == 1)
        cout << "Loại nhà: Cao cấp\n";
    else
        cout << "Loại nhà: Thường\n";
    cout << "Thành tiền: " << ThanhTien() << '\n';
}

/* Đầu vào: Không có
   Đầu ra: Số nguyên 2
   Chức năng: Xác định đây là giao dịch nhà phố */
int GiaoDichNhaPho::LayLoaiGD()
{
    return 2;
}

/* Đầu vào: Không có
   Đầu ra: Thành tiền giao dịch nhà phố
   Chức năng: Tính thành tiền giao dịch nhà phố */
double GiaoDichNhaPho::ThanhTien()
{
    if(loai == 1)
        return DienTich * DonGia;
    return DienTich * DonGia * 0.9;
}

/* Đầu vào: Không có
   Đầu ra: Loại nhà
   Chức năng: Trả về loại nhà (cao cấp hoặc thường) */
int GiaoDichNhaPho::getType()
{
    return loai;
}