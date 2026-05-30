#include <iostream>
#include <fstream>
#include "KhachHang.h"

using namespace std;

KhachHang::KhachHang()
{
    Ten = "";
    SoLuongHang = 0;
    DonGiaHang = 0;
}

KhachHang::KhachHang(string ten, int luonghang, double gia)
{
    Ten = ten;
    SoLuongHang = luonghang;
    DonGiaHang = gia;
}

KhachHang::KhachHang(const KhachHang &other)
{
    Ten = other.Ten;
    SoLuongHang = other.SoLuongHang;
    DonGiaHang = other.DonGiaHang;
}

void KhachHang::Nhap(ifstream &in)
{
    in.ignore();
    getline(in, Ten);
    in >> SoLuongHang;
    in >> DonGiaHang;
}

void KhachHang::Xuat(ofstream &out)
{
    out << "Tên: " << Ten << '\n';
}
