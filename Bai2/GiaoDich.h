#pragma once
#include <iostream>

class GiaoDich{
    protected:
        std::string ID;
        int Ngay, Thang, Nam;
        double DonGia, DienTich;
        bool isValidDay();
        bool isValidID();
    public:
        GiaoDich();
        GiaoDich(std:: string id, int d, int m, int y, double price, double s);
        GiaoDich(const GiaoDich &other);
        virtual void Nhap();
        virtual void Xuat();
        virtual int LayLoaiGD() = 0; //1 là Đất. 2 là Nhà phố. 3 là Căn hộ chung cư
        virtual double ThanhTien() = 0;
        virtual ~GiaoDich() {}
        int getNgay();
        int getThang();
        int getNam();
};