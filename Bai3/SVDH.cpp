#include <iostream>
#include "SinhVien.h"
#include "SVDH.h"
using namespace std;

/* Đầu vào: Không có
   Đầu ra: true nếu tên luận văn hợp lệ, ngược lại false
   Chức năng: Kiểm tra tên luận văn chỉ chứa chữ cái và khoảng trắng */
bool SVDH::isValidTenLV()
{
    if(LuanVan.empty())
        return false;
    for(int i = 0; i < LuanVan.length(); i++){
        if(!isalpha(LuanVan[i]) && LuanVan[i] != ' ')
            return false;
    }
    return true;
}

/* Đầu vào: Không có
   Đầu ra: Không có
   Chức năng: Khởi tạo sinh viên đại học mặc định */
SVDH::SVDH() : SinhVien()
{
    LuanVan = "";
    DiemLV = 0;
}

/* Đầu vào:
      ms: mã số sinh viên
      ten: họ tên
      dc: địa chỉ
      tc: tổng tín chỉ
      dtb: điểm trung bình
      lv: tên luận văn
      dlv: điểm luận văn
   Đầu ra: Không có
   Chức năng: Khởi tạo sinh viên đại học với đầy đủ thông tin */
SVDH::SVDH(int ms, std::string ten, std::string dc, int tc, double dtb, std::string lv, double dlv) : SinhVien(ms, ten, dc, tc, dtb)
{
    LuanVan = lv;
    DiemLV = dlv;
}

/* Đầu vào: Đối tượng sinh viên đại học khác
   Đầu ra: Không có
   Chức năng: Khởi tạo sao chép */
SVDH::SVDH(const SVDH &other) : SinhVien(other)
{
    LuanVan = other.LuanVan;
    DiemLV = other.DiemLV;
}

/* Đầu vào: Không có
   Đầu ra: Không có
   Chức năng: Nhập thông tin sinh viên đại học */
void SVDH::Nhap()
{
    SinhVien::Nhap();
    cin.ignore();
    while(true)
    {
        cout << "Nhập tên luận văn: "; getline(cin, LuanVan);
        if(!isValidTenLV())
        {
            cout << "Dữ liệu nhập sai!\n";
            continue;
        }
        break;
    }
    while(true)
    {
        cout << "Nhập điểm luận văn: "; cin >> DiemLV;
        if(cin.fail() || cin.peek() != '\n' || DiemLV < 0 || DiemLV > 10)
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
   Chức năng: Xuất thông tin sinh viên đại học */
void SVDH::Xuat()
{
    SinhVien::Xuat();
    cout << "Tên luận văn: " << LuanVan << '\n';
    cout << "Điểm luận văn: " << DiemLV << '\n';
}

/* Đầu vào: Không có
   Đầu ra:
      true nếu đủ điều kiện tốt nghiệp
      false nếu không đủ điều kiện tốt nghiệp
   Chức năng: Kiểm tra điều kiện tốt nghiệp của sinh viên đại học */
bool SVDH::DuDKTotNghiep()
{
    return TongTc >= 170 && DTB >= 5 && DiemLV >= 5;
}

/* Đầu vào: Không có
   Đầu ra: Số nguyên 2
   Chức năng: Trả về loại sinh viên đại học */
int SVDH::getType()
{
    return 2;
}