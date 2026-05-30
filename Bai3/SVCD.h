#pragma once
#include <iostream>
#include "SinhVien.h"

class SVCD : public SinhVien{
    private:
        double DiemTotNghiep;
    public:
        SVCD();
        SVCD(int ms, std::string ten, std::string dc, int tc, double dtb, double dtn);
        SVCD(const SVCD &other);
        void Nhap();
        void Xuat();
        bool DuDKTotNghiep();
        int getType();
};