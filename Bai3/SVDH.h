#pragma once
#include <iostream>
#include "SinhVien.h"

class SVDH : public SinhVien{
    private:
        std::string LuanVan;
        double DiemLV;
        bool isValidTenLV(); 
    public:
        SVDH();
        SVDH(int ms, std::string ten, std::string dc, int tc, double dtb, std::string lv, double dlv);
        SVDH(const SVDH &other);
        void Nhap();
        void Xuat();
        bool DuDKTotNghiep();
        int getType();
};