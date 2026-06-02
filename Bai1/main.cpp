#include <iostream>
#include <Windows.h>
#include <cfloat>
#include <iomanip>
#include "NhanVien.h"
#include "NVSX.h"
#include "NVVP.h"

using namespace std;

int main()
{
    cout << fixed << setprecision(0);
    SetConsoleOutputCP(65001);
    NhanVien *ds[10000];
    //Nhập danh sách
    int n;
    while(true)
    {
        cout << "Nhập số lượng nhân viên: "; cin >> n;
        if(cin.fail() || cin.peek() != '\n' || n < 0)
        {
            cout << "Dữ liệu nhận sai!\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        break;
    }
    for(int i = 0; i < n; i++)
    {
        int loai;
        cout << "Nhập loại nhân viên(1: Sản xuất; 2: Văn phòng): ";
        cin >> loai;
        if(cin.fail() || cin.peek() != '\n' || (loai != 1 && loai != 2))
        {
            cout << "Nhập sai loại nhân viên!\n";
            cin.clear();
            cin.ignore(10000, '\n');
            i--;
            continue;
        }
        else if(loai == 1) //Nhân viên sản xuất
            ds[i] = new NVSX;
        else //Nhân viên văn phòng
            ds[i] = new NVVP;
        cin.ignore();
        ds[i] -> Nhap();
    }

    //Xuất danh sách
    cout << "\n======Danh sách nhân viên======\n";
    if(n == 0)
    {
        cout << "Danh sách rỗng!\n";
        return 0;
    }
    for(int i = 0; i < n; i++){
        ds[i] -> Xuat();
        cout << "----------------------\n";
    }

    //Tổng lương mà công ty phải trả cho các nhân viên
    double sum = 0;
    for(int i = 0; i < n; i++)
        sum += ds[i] -> TinhLuong();
    cout << "\nTổng lương mà công ty phải trả cho các nhân viên là: " << sum << '\n';
    cout << "----------------------\n";

    //Nhân viên sản xuất lương thấp nhất
    double Min = DBL_MAX;
    NhanVien *res = nullptr;
    for(int i = 0; i < n; i++)
    {
        double l = ds[i] -> TinhLuong();
        if(ds[i]->getType() == 1 && l < Min){
            Min = l;
            res = ds[i];
        }
    }
    if(res){
        cout << "\nNhân viên sản xuất có lương thấp nhất:\n";
        res -> Xuat();
    }
    else
        cout << "\nKhông có nhân viên sản xuất.\n";
    cout << "----------------------\n";

    //Nhân viên văn phòng có tuổi cao nhất 
    NhanVien *resVP = nullptr;
    for(int i = 0; i < n; i++)
    {
        if(ds[i]->getType() == 2)
        {
            if(resVP == nullptr)
            {
                resVP = ds[i];
            }
            else
            {
                int d = ds[i]->getNgay();
                int m = ds[i]->getThang();
                int y = ds[i]->getNam();

                int dMin = resVP->getNgay();
                int mMin = resVP->getThang();
                int yMin = resVP->getNam();

                if(y < yMin || (y == yMin && m < mMin) || (y == yMin && m == mMin && d < dMin))
                {
                    resVP = ds[i];
                }
            }
        }
    }

    if(resVP)
    {
        cout << "\nNhân viên văn phòng lớn tuổi nhất:\n";
        resVP->Xuat();
    }
    else
        cout << "\nKhông có nhân viên văn phòng.\n";
    cout << "----------------------\n";

    for(int i = 0; i < n; i++)
        delete ds[i];

    return 0;
}