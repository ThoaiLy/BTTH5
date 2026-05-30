#pragma once
#include <iostream>
#include <fstream>
#include "KhachHang.h"

class KhachHangC : public KhachHang{
    public:
        KhachHangC();
        KhachHangC(std::string ten, int luonghang, double gia);
        KhachHangC(const KhachHangC &other);
        void Nhap(std::ifstream &in);
        void Xuat(std::ofstream &out);
        double TienTra();
        std::string getType();
};