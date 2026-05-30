#include <iostream>
#include <fstream>
#include "KhachHang.h"
#include "KhachHangB.h"

using namespace std;

KhachHangB::KhachHangB() : KhachHang()
{
    SoNamTT = 0;
}
        
KhachHangB::KhachHangB(std::string ten, int luonghang, double gia, int namtt) : KhachHang(ten, luonghang, gia)
{
    SoNamTT = namtt;
}
        
KhachHangB::KhachHangB(const KhachHangB &other) : KhachHang(other)
{
    SoNamTT = other.SoNamTT;
}
     
void KhachHangB::Nhap(ifstream &in)
{
    KhachHang::Nhap(in);
    in >> SoNamTT;
}

void KhachHangB::Xuat(ofstream &out)
{
    KhachHang::Xuat(out);
    out << "Số tiền phải trả: " << TienTra() << '\n';
}
        
double KhachHangB::TienTra()
{
    double KM = max(SoNamTT * 0.05, 0.5);
    return (SoLuongHang * DonGiaHang) * (1 - KM) + SoLuongHang * DonGiaHang * 0.1;
}

string KhachHangB::getType()
{
    return "B";
}