#pragma once
#include "NhanVien.h"

class NVVP : public NhanVien{
    private:
        int SoNgayLamViec;
    public:
        NVVP();
        NVVP(std::string ten, int d, int m, int y, int songaylam);
        NVVP(const NVVP &other);
        void Nhap();
        void Xuat();
        double TinhLuong();
        int getType();
};