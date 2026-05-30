#pragma once
#include <iostream>

class NhanVien{
    protected:
        std::string name;
        int Ngay, Thang, Nam;
        bool validName();
        bool validBirth();
    public:
        NhanVien();
        NhanVien(std::string ten, int d, int m, int y);
        NhanVien(const NhanVien &other);
        virtual void Nhap();
        virtual void Xuat();
        virtual double TinhLuong() = 0;
        virtual int getType() = 0;
        virtual ~NhanVien() {}
        int getNgay();
        int getThang();
        int getNam();
};