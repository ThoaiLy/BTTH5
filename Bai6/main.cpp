#include <iostream>
#include <fstream>
#include <iomanip>
#include "KhachHang.h"
#include "KhachHangA.h"
#include "KhachHangB.h"
#include "KhachHangC.h"

using namespace std;

int main()
{
    ifstream in("XYZ.INP");
    ofstream out("XYZ.OUT");
    if(!in || !out)
    {
        cout << "Không mở được file!\n";
        return 0;
    }

    out << fixed << setprecision(0);
    KhachHang *ds[10000];
    int x, y, z, n = 0;
    in >> x >> y >> z;
    for(int i = 0; i < x; i++)
    {
        ds[n] = new KhachHangA;
        ds[n] -> Nhap(in);
        n++;
    }
    for(int i = 0; i < y; i++)
    {
        ds[n] = new KhachHangB;
        ds[n] -> Nhap(in);
        n++;
    }
    for(int i = 0; i < z; i++)
    {
        ds[n] = new KhachHangC;
        ds[n] -> Nhap(in);
        n++;
    }

    out << x << " " << y << " " << z << '\n';
    for(int i = 0; i < n; i++)
    {
        /*if(ds[i] -> getType() == "A")
            out << "Khách hàng loại A\n";
        else if(ds[i] -> getType() == "B")
            out << "Khách hàng loại B\n";
        else
            out << "Khách hàng loại C\n";*/
        ds[i] -> Xuat(out);
        out << '\n';
    }

    double sum = 0;
    out << "Tổng tiền công ty thu được: ";
    for(int i = 0; i < n; i++)
        sum += ds[i] -> TienTra();
    out << sum;

    for(int i = 0; i < n; i++)
        delete ds[i];

    in.close();
    out.close();

    return 0;
}