#pragma once
#include <iostream>
#include <fstream>
#include "KhachHang.h"

class KhachHangA : public KhachHang{
    public:
        KhachHangA();
        KhachHangA(std::string ten, int luonghang, double gia);
        KhachHangA(const KhachHangA &other);
        void Nhap(std::ifstream &in);
        void Xuat(std::ofstream &out);
        double TienTra();
        std::string getType();
};