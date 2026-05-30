#pragma once
#include "GiaoDich.h"

class GiaoDichDat : public GiaoDich{
    private:
        std::string loai;
    public:
        GiaoDichDat();
        GiaoDichDat(std:: string id, int d, int m, int y, double price, double s, std::string l);
        GiaoDichDat(const GiaoDichDat &other);
        void Nhap();
        void Xuat();
        int LayLoaiGD();
        double ThanhTien();
        std::string getType();
};