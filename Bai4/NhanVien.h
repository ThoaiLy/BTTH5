#pragma once
#include <iostream>

class NhanVien{
    protected:
        std::string ID, HoTen, Email, SDT;
        int Tuoi;
        double LuongCB;
        bool isValidName();
        bool isValidID();
        bool isValidEmail();
        bool isValidNum();
    public:
        NhanVien();
        NhanVien(std::string id, std::string ten, int t, std::string dt, std::string mail, double l);
        NhanVien(const NhanVien &other);
        virtual void Nhap();
        virtual void Xuat();
        virtual double TinhLuong() = 0;
        virtual int getType() = 0;
        virtual ~NhanVien(){};
};