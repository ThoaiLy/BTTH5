#include <iostream>
#include <cctype>
#include "SinhVien.h"
using namespace std;

/* Đầu vào: Không có
   Đầu ra: true nếu họ tên hợp lệ, ngược lại false
   Chức năng: Kiểm tra họ tên chỉ chứa chữ cái và khoảng trắng */
bool SinhVien::isValidName()
{
    if(HoTen.empty())
        return false;
    for(int i = 0; i < HoTen.length(); i++){
        if(!isalpha(HoTen[i]) && HoTen[i] != ' ')
            return false;
    }
    return true;
}

/* Đầu vào: Không có
   Đầu ra: true nếu địa chỉ hợp lệ, ngược lại false
   Chức năng: Kiểm tra địa chỉ chỉ chứa chữ cái, chữ số và khoảng trắng */
bool SinhVien::isValidAddress()
{
    for(int i = 0; i < diaChi.length(); i++)
        if(!isdigit(diaChi[i]) && !isalpha(diaChi[i]) && diaChi[i] != ' ')
            return false;
    return true;
}

/* Đầu vào: Không có
   Đầu ra: Số lượng chữ số của MSSV
   Chức năng: Đếm số chữ số trong mã số sinh viên */
int SinhVien::CountNum()
{
    int tmp = MSSV, cnt = 0;
    while(tmp)
    {
        cnt++;
        tmp /= 10;
    }
    return cnt;
}

/* Đầu vào: Không có
   Đầu ra: Không có
   Chức năng: Khởi tạo sinh viên với các giá trị mặc định */
SinhVien::SinhVien()
{
    MSSV = 0;
    HoTen = "";
    diaChi = "";
    TongTc = 0;
    DTB = 0;
}

/* Đầu vào:
      ms: mã số sinh viên
      ten: họ tên
      dc: địa chỉ
      tc: tổng tín chỉ
      dtb: điểm trung bình
   Đầu ra: Không có
   Chức năng: Khởi tạo sinh viên với đầy đủ thông tin */
SinhVien::SinhVien(int ms, std::string ten, std::string dc, int tc, double dtb)
{
    MSSV = ms;
    HoTen = ten;
    diaChi = dc;
    TongTc = tc;
    DTB = dtb;
}

/* Đầu vào: Đối tượng sinh viên khác
   Đầu ra: Không có
   Chức năng: Khởi tạo sao chép */
SinhVien::SinhVien(const SinhVien &other)
{
    MSSV = other.MSSV;
    HoTen = other.HoTen;
    diaChi = other.diaChi;
    TongTc = other.TongTc;
    DTB = other.DTB;
}

/* Đầu vào: Không có
   Đầu ra: Không có
   Chức năng: Nhập thông tin sinh viên và kiểm tra tính hợp lệ */
void SinhVien::Nhap()
{
    while(true){
        cout << "Nhập mã số sinh viên: "; cin >> MSSV;
        if(cin.fail() || cin.peek() != '\n' || MSSV < 0 || CountNum() != 8)
        {
            cout << "Dữ liệu nhập sai!\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        cin.ignore();
        break;
    }
    while(true){
        cout << "Nhập họ tên: "; getline(cin, HoTen);
        if(!isValidName())
        {
            cout << "Dữ liệu nhập sai!\n";
            continue;
        }
        break;
    }
    while(true){
        cout << "Nhập địa chỉ: "; getline(cin, diaChi);
        if(!isValidAddress())
        {
            cout << "Dữ liệu nhập sai!\n";
            continue;
        }
        break;
    }
    while(true){
        cout << "Nhập tổng tín chỉ: "; cin >> TongTc;
        if(cin.fail() || cin.peek() != '\n' || TongTc < 0)
        {
            cout << "Dữ liệu nhập sai!\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        break;
    }
    while(true){
        cout << "Nhập điểm trung bình: "; cin >> DTB;
        if(cin.fail() || cin.peek() != '\n' ||  DTB < 0 || DTB > 10)
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
   Chức năng: Xuất thông tin sinh viên ra màn hình */
void SinhVien::Xuat()
{
    cout << "Mã số sinh viên: " << MSSV << '\n';
    cout << "Họ tên: " << HoTen << '\n';
    cout << "Địa chỉ: " << diaChi << '\n';
    cout << "Tổng tín chỉ: " << TongTc << '\n';
    cout << "Điểm trung bình: " << DTB << '\n';
}

/* Đầu vào: Không có
   Đầu ra: Điểm trung bình của sinh viên
   Chức năng: Trả về giá trị điểm trung bình */
double SinhVien::getDTB()
{
    return DTB;
}