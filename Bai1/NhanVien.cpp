#include<iostream>
#include "NhanVien.h"

using namespace std;

/*Đầu vào: Không có
Đầu ra: Không có
Chức năng: Khởi tạo nhân viên với các giá trị mặc định.*/
NhanVien::NhanVien()
{
    name = "";
    Ngay = 1;
    Thang = 1;
    Nam = 2000;
}

/*Đầu vào:
    ten: họ tên nhân viên
    d, m, y: ngày sinh
    l: lương
Đầu ra: Không có
Chức năng: Khởi tạo nhân viên với thông tin được truyền vào.*/
NhanVien::NhanVien(string ten, int d, int m, int y)
{
    name = ten;
    Ngay = d;
    Thang = m;
    Nam = y;
}

/*Đầu vào:
    other: đối tượng nhân viên
Đầu ra: Không có
Chức năng: Khởi tạo bản sao của một nhân viên.*/
NhanVien::NhanVien(const NhanVien &other)
{
    name = other.name;
    Ngay = other.Ngay;
    Thang = other.Thang;
    Nam = other.Nam;
}

/*Đầu vào: Không có
Đầu ra:
    true: tên hợp lệ
    false: tên không hợp lệ
Chức năng: Kiểm tra tên chỉ chứa chữ cái và khoảng trắng.*/
bool NhanVien::validName()
{
    for(int i = 0; i < name.length(); i++){
        if(!isalpha(name[i]) && name[i] != ' ')
        {
            return false;
        }
    }
    return true;
}

/*Đầu vào: Không có
Đầu ra:
    true: ngày sinh hợp lệ
    false: ngày sinh không hợp lệ
Chức năng: Kiểm tra tính hợp lệ của ngày tháng năm sinh.*/
bool NhanVien::validBirth()
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

/*Đầu vào: Không có
Đầu ra: Không có
Chức năng: Nhập họ tên và ngày sinh nhân viên.*/
void NhanVien::Nhap()
{
    while(true)
    {
        cout << "Nhập tên: "; getline(cin, name);
        if(!validName())
        {
            cout << "Dữ liệu nhập sai!\n";
            continue;
        }
        break;
    }

    while(true){
        cout << "Nhập ngày tháng năm sinh: ";
        cin >> Ngay >> Thang >> Nam;
        if(cin.fail() || cin.peek() != '\n' || !validBirth())
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
Chức năng: Xuất họ tên và ngày sinh nhân viên.*/
void NhanVien::Xuat()
{
    cout << "Tên: " << name << '\n';
    cout << "Ngày sinh: " << Ngay << '/' << Thang << '/' << Nam << '\n';
}

/*Đầu vào: Không có
Đầu ra: Ngày sinh
Chức năng: Trả về ngày sinh của nhân viên.*/
int NhanVien::getNgay()
{
    return Ngay;
}

/*Đầu vào: Không có
Đầu ra: Tháng sinh
Chức năng: Trả về tháng sinh của nhân viên.*/
int NhanVien::getThang()
{
    return Thang;
}

/*Đầu vào: Không có
Đầu ra: Năm sinh
Chức năng: Trả về năm sinh của nhân viên.*/
int NhanVien::getNam()
{
    return Nam;
}