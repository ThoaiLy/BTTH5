#pragma once
#include <iostream>
#include <fstream>

class KhachHang{
    protected:
        std::string Ten;
        int SoLuongHang;
        double DonGiaHang;
    public:
        KhachHang();
        KhachHang(std::string ten, int luonghang, double gia);
        KhachHang(const KhachHang &other);
        virtual void Nhap(std::ifstream &in);
        virtual void Xuat(std::ofstream &out);
        virtual double TienTra() = 0;
        virtual std::string getType() = 0;
        virtual ~KhachHang(){}
};