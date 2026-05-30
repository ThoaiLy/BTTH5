#pragma once
#include "NhanVien.h"

class NVSX : public NhanVien{
    private:
        double LuongCB;
        int SoSp;
    public:
        NVSX();
        NVSX(std::string ten, int d, int m, int y, double lcb, int ssp);
        NVSX(const NVSX &other);
        void Nhap();
        void Xuat();
        double TinhLuong();
        int getType();
};