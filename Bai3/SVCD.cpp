#include <iostream>
#include "SinhVien.h"
#include "SVCD.h"
using namespace std;

/* Đầu vào: Không có
   Đầu ra: Không có
   Chức năng: Khởi tạo sinh viên cao đẳng mặc định */
SVCD::SVCD() : SinhVien()
{
    DiemTotNghiep = 0;
}

/* Đầu vào:
      ms: mã số sinh viên
      ten: họ tên
      dc: địa chỉ
      tc: tổng tín chỉ
      dtb: điểm trung bình
      dtn: điểm tốt nghiệp
   Đầu ra: Không có
   Chức năng: Khởi tạo sinh viên cao đẳng với đầy đủ thông tin */
SVCD::SVCD(int ms, std::string ten, std::string dc, int tc, double dtb, double dtn) : SinhVien(ms, ten, dc, tc, dtb)
{
    DiemTotNghiep = dtn;
}

/* Đầu vào: Đối tượng sinh viên cao đẳng khác
   Đầu ra: Không có
   Chức năng: Khởi tạo sao chép */
SVCD::SVCD(const SVCD &other) : SinhVien(other)
{
    DiemTotNghiep = other.DiemTotNghiep;
}

/* Đầu vào: Không có
   Đầu ra: Không có
   Chức năng: Nhập thông tin sinh viên cao đẳng */
void SVCD::Nhap()
{
    SinhVien::Nhap();
    while(true){
        cout << "Nhập điểm tốt nghiệp: "; cin >> DiemTotNghiep;
        if(cin.fail() || cin.peek() != '\n' || DiemTotNghiep < 0 || DiemTotNghiep > 10)
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
   Chức năng: Xuất thông tin sinh viên cao đẳng */
void SVCD::Xuat()
{
    SinhVien::Xuat();
    cout << "Điểm tốt nghiệp: " << DiemTotNghiep << '\n';
}

/* Đầu vào: Không có
   Đầu ra:
      true nếu đủ điều kiện tốt nghiệp
      false nếu không đủ điều kiện tốt nghiệp
   Chức năng: Kiểm tra điều kiện tốt nghiệp của sinh viên cao đẳng */
bool SVCD::DuDKTotNghiep()
{
    return TongTc >= 120 && DTB >= 5 && DiemTotNghiep >= 5;
}

/* Đầu vào: Không có
   Đầu ra: Sô nguyên 1
   Chức năng: Trả về loại sinh viên cao đẳng */
int SVCD::getType()
{
    return 1;
}