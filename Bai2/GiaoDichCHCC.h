#pragma once
#include <iostream>
#include "GiaoDich.h"

class GiaoDichCHCC : public GiaoDich{
    private:
        int viTriTang;
        std::string maCan;
        bool isValid(); //Để kiểm tra hợp lệ mã căn
    public:
        GiaoDichCHCC();
        GiaoDichCHCC(std:: string id, int d, int m, int y, double price, double s, int vt, std::string macan);
        GiaoDichCHCC(const GiaoDichCHCC &other);
        void Nhap();
        void Xuat();
        int LayLoaiGD();
        double ThanhTien();
        int getViTriTang();
};