#include <iostream>
#include <fstream>
#include "KhachHang.h"
#include "KhachHangC.h"

using namespace std;

KhachHangC::KhachHangC() : KhachHang()
{}

KhachHangC::KhachHangC(std::string ten, int luonghang, double gia) : KhachHang(ten, luonghang, gia)
{}
        
KhachHangC::KhachHangC(const KhachHangC &other) : KhachHang(other)
{}
        
void KhachHangC::Nhap(ifstream &in)
{
    KhachHang::Nhap(in);
}
        
void KhachHangC::Xuat(ofstream &out)
{
    KhachHang::Xuat(out);
    out << "Số tiền phải trả: " << TienTra() << '\n';
}

double KhachHangC::TienTra()
{
    return (SoLuongHang * DonGiaHang) * 0.5 + SoLuongHang * DonGiaHang * 0.1;
}
        
string KhachHangC::getType()
{
    return "C";
}