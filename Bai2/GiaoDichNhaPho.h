#pragma once
#include <iostream>
#include "GiaoDich.h"

class GiaoDichNhaPho : public GiaoDich{
    private:
        int loai; //1: Cao cấp 2: Thường
        std::string diaChi;
        bool isValidAddress();
    public:
        GiaoDichNhaPho();
        GiaoDichNhaPho(std:: string id, int d, int m, int y, double price, double s, int l, std::string address);
        GiaoDichNhaPho(const GiaoDichNhaPho &other);
        void Nhap();
        void Xuat();
        int LayLoaiGD();
        double ThanhTien();
        int getType();
};