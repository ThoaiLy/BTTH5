#pragma once
#include <iostream>
#include "NhanVien.h"

class LTV : public NhanVien{
    private:
        int SoGioLamThem;
    public:
        LTV();
        LTV(std::string id, std::string ten, int t, std::string dt, std::string mail, double l, int sohlam);
        LTV(const LTV &other);
        void Nhap();
        void Xuat();
        double TinhLuong();
        int getType();
};