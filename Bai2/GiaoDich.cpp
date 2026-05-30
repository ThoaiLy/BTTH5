#include <iostream>
#include "GiaoDich.h"

using namespace std;

/* Đầu vào: Không có
   Đầu ra: true nếu ngày hợp lệ, false nếu không hợp lệ
   Chức năng: Kiểm tra tính hợp lệ của ngày giao dịch theo lịch */
bool GiaoDich::isValidDay()
{
    if(Thang < 1 || Thang > 12 || Nam < 1900)
        return false;
    if(Thang == 2)
    {
        if(Nam % 400 == 0 || Nam % 4 == 0 && Nam % 100 != 0)
            if(Ngay < 1 || Ngay > 29)
                return false;
        else
            if(Ngay < 1 || Ngay > 28)
                return false;
    }
    else if(Thang == 1 || Thang == 3 || Thang == 5 || Thang == 7 || Thang == 8 || Thang == 10 || Thang == 12)
        if(Ngay < 1 || Ngay > 31)
            return false;
    else
        if(Ngay < 1 || Ngay > 30)
            return false;
    return true;
}

/* Đầu vào: Không có
   Đầu ra: true nếu mã hợp lệ, false nếu không hợp lệ
   Chức năng: Kiểm tra mã giao dịch không rỗng và chỉ chứa chữ hoặc số */
bool GiaoDich::isValidID()
{
    if(ID.empty())
        return false;
    for(int i = 0; i < ID.length(); i++)
        if(!isdigit(ID[i]) && !isalpha(ID[i]))
            return false;
    return true;
}

/* Đầu vào: Không có
   Đầu ra: Không có
   Chức năng: Khởi tạo giao dịch với các giá trị mặc định */
GiaoDich::GiaoDich()
{
    ID = "";
    Ngay = 1;
    Thang = 1;
    Nam = 2000;
    DonGia = DienTich = 0;
}

/* Đầu vào:
      id: mã giao dịch
      d, m, y: ngày giao dịch
      price: đơn giá
      s: diện tích
   Đầu ra: Không có
   Chức năng: Khởi tạo giao dịch với các giá trị được truyền vào */
GiaoDich::GiaoDich(string id, int d, int m, int y, double price, double s)
{
    ID = id;
    Ngay = d;
    Thang = m;
    Nam = y;
    DonGia = price;
    DienTich = s;
}

/* Đầu vào:
      other: giao dịch cần sao chép
   Đầu ra: Không có
   Chức năng: Tạo bản sao của một giao dịch */
GiaoDich::GiaoDich(const GiaoDich &other)
{
    ID = other.ID;
    Ngay = other.Ngay;
    Thang = other.Thang;
    Nam = other.Nam;
    DonGia = other.DonGia;
    DienTich = other.DienTich;
}

/* Đầu vào: Không có
   Đầu ra: Không có
   Chức năng: Nhập mã giao dịch, ngày giao dịch, đơn giá và diện tích */
void GiaoDich::Nhap()
{
    while(true){
        cout << "Nhập mã giao dịch: "; getline(cin, ID);
        if(!isValidID())
        {
            cout << "Dữ liệu nhập sai!\n";
            continue;
        }
        break;
    }
    
    while(true)
    {
        cout << "Nhập ngày giao dịch: ";
        cin >> Ngay >> Thang >> Nam;
        if(cin.fail() || cin.peek() != '\n' || !isValidDay())
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
        cout << "Nhập đơn giá: "; cin >> DonGia;
        if(cin.fail() || cin.peek() != '\n' || DonGia < 0)
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
        cout << "Nhập diện tích: "; cin >> DienTich;
        if(cin.fail() || cin.peek() != '\n' || DienTich < 0)
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
   Chức năng: Xuất các thông tin cơ bản của giao dịch */
void GiaoDich::Xuat()
{
    cout << "Mã giao dịch: " << ID << '\n';
    cout << "Ngày giao dịch: " << Ngay << '/' << Thang << '/' << Nam << '\n';
    cout << "Đơn giá: " << DonGia << '\n';
    cout << "Diện tích: " << DienTich << '\n';
}

/* Đầu vào: Không có
   Đầu ra: Ngày giao dịch
   Chức năng: Trả về ngày giao dịch */
int GiaoDich::getNgay()
{
    return Ngay;
}

/* Đầu vào: Không có
   Đầu ra: Tháng giao dịch
   Chức năng: Trả về tháng giao dịch */
int GiaoDich::getThang()
{
    return Thang;
}

/* Đầu vào: Không có
   Đầu ra: Năm giao dịch
   Chức năng: Trả về năm giao dịch */
int GiaoDich::getNam()
{
    return Nam;
}
