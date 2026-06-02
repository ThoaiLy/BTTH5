#include <iostream>
#include <iomanip>
#include <windows.h>
#include "NhanVien.h"
#include "KCV.h"
#include "LTV.h"
using namespace std;

int main()
{
    cout << fixed << setprecision(0);
    SetConsoleOutputCP(65001);

    NhanVien *ds[10000];

    //Câu a
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
    cin.ignore();

    for(int i = 0; i < n; i++)
    {
        int loai;
        cout << "Nhập loại nhân viên(1: Lập trình viên; 2: Kiểm chứng viên): ";
        cin >> loai; cin.ignore();
        if(loai == 1)
            ds[i] = new LTV;
        else if(loai == 2)
            ds[i] = new KCV;
        else
        {
            cout << "Nhập sai dữ liệu!\n";
            i--;
            continue;
        }
        ds[i] -> Nhap();
    }

    //Câu b
    cout << "\n======Danh sách nhân viên======\n";
    if(n == 0){
        cout << "Danh sách rỗng!\n";
        return 0;
    }
    for(int i = 0; i < n; i++)
    {
        ds[i] -> Xuat();
        cout << '\n';
    }

    //Câu c, d, e
    cout << "\n======Danh sách nhân viên lương thấp hơn lương trung bình======\n";
    double LuongTB, sum = 0;
    int posMax = -1, posMin = -1;
    for(int i = 0; i < n; i++){
        if(posMax == -1)
            posMax = i;
        else
            if(ds[posMax] -> TinhLuong() < ds[i] -> TinhLuong())
                posMax = i;
        
        if(posMin == -1)
            posMin = i;
        else
            if(ds[posMin] -> TinhLuong() > ds[i] -> TinhLuong())
                posMin = i;
        
        sum += ds[i] -> TinhLuong();
    }
    LuongTB = sum / n;

    for(int i = 0; i < n; i++)
    {
        if(ds[i] -> TinhLuong() < LuongTB)
        {
            ds[i] -> Xuat();
            cout << '\n';
        }
    }

    cout << "Nhân viên có lương cao nhất:\n"; ds[posMax] -> Xuat();
    cout << "\nNhân viên có lương thấp nhất:\n"; ds[posMin] -> Xuat();

    //Câu f, g
    int LTVMax = -1, KCVMin = -1;
    for(int i = 0; i < n; i++)
    {
        if(ds[i] -> getType() == 1){
            if(LTVMax == -1)
                LTVMax = i;
            if(ds[LTVMax] -> TinhLuong() < ds[i] -> TinhLuong())
                LTVMax = i;
        }
        else{
            if(KCVMin == -1)
                KCVMin = i;
            if(ds[KCVMin] -> TinhLuong() > ds[i] -> TinhLuong())
                KCVMin = i;
        }
    }
    if(LTVMax != -1){
        cout << "\nLập trình viên có lương cao nhất:\n";
        ds[LTVMax] -> Xuat();
        cout << '\n';
    }
    else
        cout << "Danh sách không có lập trình viên!\n";

    if(KCVMin != -1){
        cout << "Kiểm chứng viên có lương thấp nhất :\n";
        ds[KCVMin] -> Xuat();
        cout << '\n';
    }
    else
        cout << "Danh sách không có kiểm chứng viên!\n";
    
    for(int i = 0; i < n; i++)
        delete ds[i];
    
    return 0;
}