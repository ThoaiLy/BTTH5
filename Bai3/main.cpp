#include <iostream>
#include <windows.h>
#include "SinhVien.h"
#include "SVCD.h"
#include "SVDH.h"
using namespace std;

int main()
{
    SetConsoleOutputCP(65001);

    SinhVien *ds[10000];

    int n;
    while(true)
    {
        cout << "Nhập số lượng sinh viên: "; cin >> n;
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
        cout << "Nhập loại sinh viên(1: Cao đẳng; 2: Đại học): ";
        cin >> loai;

        if(loai == 1)
            ds[i] = new SVCD;
        else if(loai == 2)
            ds[i] = new SVDH;
        else
        {
            cout << "Nhập sai loại!\n";
            i--;
            continue;
        }
        ds[i] -> Nhap();
    }

    cout << "\n======Danh sách sinh viên======\n";
    if(n == 0){
        cout << "Danh sách rỗng!\n";
        return 0;
    }
    for(int i = 0; i < n; i++)
    {
        ds[i] -> Xuat();
        cout << '\n';
    }

    //Câu c
    cout << "\n======Danh sách sinh viên đủ điều kiện tốt nghiệp======\n";
    for(int i = 0; i < n; i++)
    {
        if(ds[i] -> DuDKTotNghiep()){
            ds[i] -> Xuat();
            cout << '\n';
        }
    }

    //Câu d, g
    int num_Dh = 0, num_Cd = 0;
    cout << "\n======Danh sách sinh viên không đủ điều kiện tốt nghiệp======\n";
    for(int i = 0; i < n; i++)
    {
        if(!ds[i] -> DuDKTotNghiep()){
            if(ds[i] -> getType() == 1)
                num_Cd++;
            else
                num_Dh++;
            ds[i] -> Xuat();
            cout << '\n';
        }
    }

    cout << "Số sinh viên đại học không đủ điều kiện tốt nghiệp là: " << num_Dh << '\n';
    cout << "Số sinh viên cao đẳng không đủ điều kiện tốt nghiệp là: " << num_Cd << '\n';

    //Câu e
    double maxDH = -1;
    for(int i = 0; i < n; i++)
    {
        if(ds[i]->getType() == 2)
        {
            if(ds[i]->getDTB() > maxDH)
                maxDH = ds[i]->getDTB();
        }
    }
    if(maxDH != -1)
    {
        cout << "\nSinh viên đại học có DTB cao nhất:\n";

        for(int i = 0; i < n; i++)
        {
            if(ds[i]->getType() == 2 &&
            ds[i]->getDTB() == maxDH)
            {
                ds[i]->Xuat();
                cout << '\n';
            }
        }
    }
    else
        cout << "Danh sách không có sinh viên đại học!\n";
    
    //Câu f
    double maxCD = -1;
    for(int i = 0; i < n; i++)
    {
        if(ds[i]->getType() == 1)
        {
            if(ds[i]->getDTB() > maxCD)
                maxCD = ds[i]->getDTB();
        }
    }

    if(maxCD != -1)
    {
        cout << "\nSinh viên cao đẳng có DTB cao nhất:\n";

        for(int i = 0; i < n; i++)
        {
            if(ds[i]->getType() == 1 &&
            ds[i]->getDTB() == maxCD)
            {
                ds[i]->Xuat();
                cout << '\n';
            }
        }
    }
    else
        cout << "Danh sách không có sinh viên cao đẳng!\n";

    for(int i = 0; i < n; i++)
        delete ds[i];
    return 0;
}