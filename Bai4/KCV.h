#pragma once
#include <iostream>
#include "NhanVien.h"

class KCV : public NhanVien{
    private:
        int SoLoi;
    public:
        KCV();
        KCV(std::string id, std::string ten, int t, std::string dt, std::string mail, double l, int soloi);
        KCV(const KCV &other);
        void Nhap();
        void Xuat();
        double TinhLuong();
        int getType();
};