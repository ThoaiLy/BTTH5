#pragma once
#include <iostream>
#include <fstream>
#include "KhachHang.h"

class KhachHangB : public KhachHang{
    private:
        int SoNamTT;
    public:
        KhachHangB();
        KhachHangB(std::string ten, int luonghang, double gia, int namtt);
        KhachHangB(const KhachHangB &other);
        void Nhap(std::ifstream &in);
        void Xuat(std::ofstream &out);
        double TienTra();
        std::string getType();
};