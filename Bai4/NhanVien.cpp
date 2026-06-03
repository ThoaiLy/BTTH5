#include <iostream>
#include "NhanVien.h"

using namespace std;

/*Đầu vào: Không có
Đầu ra: true nếu họ tên hợp lệ, false nếu không hợp lệ
Chức năng: Kiểm tra họ tên không rỗng và chỉ chứa chữ cái hoặc khoảng trắng*/
bool NhanVien::isValidName()
{
    if(HoTen.empty())
        return false;
    for(int i = 0; i < HoTen.length(); i++){
        if(!isalpha(HoTen[i]) && HoTen[i] != ' ')
            return false;
    }
    return true;
}

/*Đầu vào: Không có
Đầu ra: true nếu mã hợp lệ, false nếu không hợp lệ
Chức năng: Kiểm tra mã nhân viên không rỗng và chỉ chứa chữ hoặc số*/
bool NhanVien::isValidID()
{
    if(ID.empty())
        return false;
    for(int i = 0; i < ID.length(); i++)
        if(!isdigit(ID[i]) && !isalpha(ID[i]))
            return false;
    return true;
}

/*Đầu vào: Không có
Đầu ra: true nếu email hợp lệ, false nếu không hợp lệ
Chức năng:  Kiểm tra email không rỗng và chỉ chứa chữ, số, ký tự '@' hoặc '.'*/
bool NhanVien::isValidEmail()
{
    if(Email.empty())
        return false;

    int cntAt = 0;
    int posAt = -1;

    for(int i = 0; i < Email.length(); i++)
    {
        char c = Email[i];

        if(!isalnum(c) && c != '@' && c != '.')
            return false;

        if(c == '@')
        {
            cntAt++;
            posAt = i;
        }
    }

    if(cntAt != 1)
        return false;

    if(posAt == 0 || posAt == Email.length() - 1) //Ký tự @ không được nằm ở đầu hoặc cuối email
        return false;

    bool hasDot = false; //Kiểm tra có kí tự '.' không
    for(int i = posAt + 1; i < Email.length(); i++)
    {
        if(Email[i] == '.')
        {
            hasDot = true;
            break;
        }
    }

    return hasDot;
}

/*Đầu vào: Không có
Đầu ra: true nếu số điện thoại hợp lệ, false nếu không hợp lệ
Chức năng: Kiểm tra số điện thoại bắt đầu bằng số 0 và chỉ chứa chữ số*/
bool NhanVien::isValidNum()
{
    if(SDT.empty() || SDT[0] != '0' || SDT.length() != 10)
        return false;
    for(int i = 0; i < SDT.length(); i++)
        if(!isdigit(SDT[i]))
            return false;
    return true;
}

/*Đầu vào: Không có
Đầu ra: Không có
Chức năng: Khởi tạo nhân viên với các giá trị mặc định*/
NhanVien::NhanVien()
{
    ID = "";
    HoTen = "";
    Tuoi = 0;
    Email = "";
    SDT = "";
    LuongCB = 0;
}

/*Đầu vào:
    - id: mã nhân viên
    - ten: họ tên
    - t: tuổi
    - dt: số điện thoại
    - mail: email
    - l: lương cơ bản
Đầu ra: Không có
Chức năng: Khởi tạo nhân viên với đầy đủ thông tin*/
NhanVien::NhanVien(std::string id, std::string ten, int t, std::string dt, std::string mail, double l)
{
    ID = id;
    HoTen = ten;
    Tuoi = t;
    Email = mail;
    SDT = dt;
    LuongCB = l;
}

/*Đầu vào: other: đối tượng nhân viên cần sao chép
Đầu ra: Không có
Chức năng: Khởi tạo sao chép đối tượng nhân viên*/
NhanVien::NhanVien(const NhanVien &other)
{
    ID = other.ID;
    HoTen = other.HoTen;
    Tuoi = other.Tuoi;
    Email = other.Email;
    SDT = other.SDT;
    LuongCB = other.LuongCB;
}

/*Đầu vào: Không có
Đầu ra: Không có
Chức năng: Nhập và kiểm tra tính hợp lệ của thông tin nhân viên*/
void NhanVien::Nhap()
{
    while(true){
        cout << "Nhập mã nhân viên: "; getline(cin, ID);
        if(!isValidID())
        {
            cout << "Dữ liệu nhập sai!\n";
            continue;
        }
        break;
    }
    while(true){
        cout << "Nhập họ tên: "; getline(cin, HoTen);
        if(!isValidName())
        {
            cout << "Dữ liệu nhập sai!\n";
            continue;
        }
        break;
    }
    while(true){
        cout << "Nhập tuổi: "; cin >> Tuoi;
        if(cin.fail() || cin.peek() != '\n' || Tuoi < 0)
        {
            cout << "Dữ liệu nhập sai!\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        cin.ignore();
        break;
    }
    while(true){
        cout << "Nhập email: "; getline(cin, Email);
        if(!isValidEmail())
        {
            cout << "Dữ liệu nhập sai!\n";
            continue;
        }
        break;
    }
    while(true){
        cout << "Nhập số điện thoại: "; getline(cin, SDT);
        if(!isValidNum())
        {
            cout << "Dữ liệu nhập sai!\n";
            continue;
        }
        break;
    }
    while(true){
        cout << "Nhập lương cơ bản: "; cin >> LuongCB;
        if(cin.fail() || cin.peek() != '\n' || LuongCB < 0)
        {
            cout << "Dữ liệu nhập sai!\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        break;
    }
}

/*Đầu vào: Không có
Đầu ra: Không có
Chức năng: Xuất thông tin cơ bản của nhân viên*/
void NhanVien::Xuat()
{
    cout << "Mã nhân viên: " << ID << '\n';
    cout << "Họ tên: " << HoTen << '\n';
    cout << "Tuổi: " << Tuoi << '\n';
    cout << "Email: " << Email << '\n';
    cout << "Số điện thoại: " << SDT << '\n';
    cout << "Lương cơ bản: " << LuongCB << '\n';
}


/*Đầu vào: Không có
Đầu ra: Không có
Chức năng: Destructor ảo của lớp NhanVien.*/
NhanVien::~NhanVien(){}