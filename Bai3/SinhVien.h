#pragma once
#include <iostream>

class SinhVien{
    protected:
        int MSSV;
        std::string HoTen, diaChi;
        int TongTc;
        double DTB;
        bool isValidName();
        bool isValidAddress();
        int CountNum();
    public:
        SinhVien();
        SinhVien(int ms, std::string ten, std::string dc, int tc, double dtb);
        SinhVien(const SinhVien &other);
        virtual void Nhap();
        virtual void Xuat();
        virtual bool DuDKTotNghiep() = 0;
        virtual int getType() = 0;
        virtual ~SinhVien() {}
        double getDTB();
};