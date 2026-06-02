#include <iostream>
#include <windows.h>
#include <iomanip>
#include "GiaoDich.h"
#include "GiaoDichDat.h"
#include "GiaoDichNhaPho.h"
#include "GiaoDichCHCC.h"

using namespace std;

int main()
{
    cout << fixed << setprecision(0);
    SetConsoleOutputCP(65001);

    GiaoDich *ds[10000];

    //Nhập danh sách giao dịch
    int n;
    while(true)
    {
        cout << "Nhập số lượng giao dịch: "; cin >> n;
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
        int loaiGD;
        cout << "Nhập loại giao dịch: "; cin >> loaiGD;
        if(cin.fail() || cin.peek() != '\n' || (loaiGD != 1 && loaiGD != 2 && loaiGD != 3))
        {
            cout << "Nhập sai loại giao dịch!\n";
            cin.clear();
            cin.ignore(10000, '\n');
            i--;
            continue;
        }
        else if(loaiGD == 1)
            ds[i] = new GiaoDichDat;
        else if(loaiGD == 2)
            ds[i] = new GiaoDichNhaPho;
        else
            ds[i] = new GiaoDichCHCC;
        cin.ignore();
        ds[i] -> Nhap();
    }

    //Tổng số lượng từng loại
    int sum_D = 0, sum_Np = 0, sum_Chcc = 0;
    for(int i = 0; i < n; i++)
    {
        if(ds[i] -> LayLoaiGD() == 1)
            sum_D++;
        else if(ds[i] -> LayLoaiGD() == 2)
            sum_Np++;
        else
            sum_Chcc++;
    }
    cout << "Số giao dịch đất: " << sum_D << '\n';
    cout << "Số giao dịch nhà phố: " << sum_Np << '\n';
    cout << "Số giao dịch căn hộ chung cư: " << sum_Chcc << '\n';

    //Trung bình thành tiền của giao dịch Căn hộ chung cư
    double sum = 0;
    for(int i = 0; i < n; i++)
    {
        if(ds[i] -> LayLoaiGD() == 3)
            sum += ds[i] -> ThanhTien();
    }
    if(sum_Chcc == 0)
    cout << "\nKhông có giao dịch căn hộ chung cư";
    else
        cout << "\nTrung bình thành tiền của giao dịch Căn hộ chung cư là: " << sum / sum_Chcc;
    cout << "\n--------------------------\n";

    //Cho biết Giao dịch Nhà phố có trị giá cao nhất (thành tiền)
    GiaoDich *res = nullptr;
    double Max;
    for(int i = 0; i < n; i++)
    {
        if(ds[i] -> LayLoaiGD() == 2)
        {
            if(res == nullptr)
            {
                res = ds[i];
                Max = ds[i] -> ThanhTien();
            }
            else
            {
                if(ds[i] -> ThanhTien() > Max)
                {
                    res = ds[i];
                    Max = ds[i] -> ThanhTien();
                }
            }
        }
    }
    if(res == nullptr)
        cout << "\nKhông có giao dịch nhà phố để tính giao dịch nhà phố có trị giá cao nhất";
    else
    {
        cout << "\nGiao dịch Nhà phố có trị giá cao nhất là:\n";
        res -> Xuat();
    }
    cout << "\n--------------------------\n";

    //Xuất ra danh sách các giao dịch của tháng 12 năm 2024.
    cout << "\nDanh sách các giao dịch của tháng 12 năm 2024:\n";
    bool found = false;
    for(int i = 0; i < n; i++)
    {
        if(ds[i] -> getThang() == 12 && ds[i] -> getNam() == 2024)
        {
            found = true;
            ds[i] -> Xuat();
            cout << '\n';
        }
    }
    if(!found)
        cout << "\nKhông có danh sách giao dịch của tháng 12 năm 2024";
    
    for(int i = 0; i < n; i++)
        delete ds[i];
    return 0;
}