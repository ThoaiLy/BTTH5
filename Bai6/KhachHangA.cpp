#include <iostream>
#include <fstream>
#include "KhachHang.h"
#include "KhachHangA.h"

using namespace std;

KhachHangA::KhachHangA() : KhachHang()
{}

KhachHangA::KhachHangA(std::string ten, int luonghang, double gia) : KhachHang(ten, luonghang, gia)
{}
        
KhachHangA::KhachHangA(const KhachHangA &other) : KhachHang(other)
{}
        
void KhachHangA::Nhap(ifstream &in)
{
    KhachHang::Nhap(in);
}
        
void KhachHangA::Xuat(ofstream &out)
{
    KhachHang::Xuat(out);
    out << "Số tiền phải trả: " << TienTra() << '\n';
}

double KhachHangA::TienTra()
{
    return SoLuongHang * DonGiaHang + SoLuongHang * DonGiaHang * 0.1;
}
        
string KhachHangA::getType()
{
    return "A";
}