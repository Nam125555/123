#include<iostream>
#include<windows.h>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<iomanip>
#include<sstream>

#define MAUCHECK 10
#define MAUKHUNG 9
#define MAUCHU 5

using namespace std;

int so_giong_heo;
int so_luong_chuong;
int so_giong_heo_muon_them;
int so_chuong_nuoi_them;
bool firstTime = true;
bool firstTime2 = true;
bool firstTime5= true;
int v=so_giong_heo+1;
int tong_so_luong_chuong_da_xuat;

struct Heo
{
    string giong;
    string don_gia;
};
Heo danhsach_heo[100];
Heo danhsach_heo_temp[100];
struct chuong_nuoi
{
    string ma_chuong;
    string so_luong;
    string ngay_nhan;
    string giong;
};
chuong_nuoi danhsach_machuong[100];
chuong_nuoi danhsach_machuong_temp[100];

struct BangGhi
{
    string ma_chuong;
    string giong_heo;
    int don_gia;
    int so_luong;
    int tong_can_nang;
    int thanh_tien;
};

BangGhi danh_Sach_bang_ghi[100];

void Loading()
{

    char a = 178 , b = 219;
    for(int j = 0;j<10;j++)
    {
        cout << b;
        Sleep(50);
    }

}

void resizeConsole(int width, int height) //Với width là chiều rộng, heigth là chiều cao
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void TextColor(int x)//X là mã màu
{
    HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, x);
}
void gotoxy(short x, short y)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD a = {x, y};
    SetConsoleCursorPosition(h, a);
}


void anConTro()
{
  HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_CURSOR_INFO cursorInfo;
  GetConsoleCursorInfo(consoleHandle, &cursorInfo);
  cursorInfo.bVisible = FALSE;
  SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

void hienThiConTro(bool hienThi)
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = hienThi; // sử dụng biến bool để kiểm tra và hiển thị con trỏ

    SetConsoleCursorInfo(consoleHandle, &info);
}
void ve_khung_chuong_trinh()
{
    for(int i=0;i<199;i++)
    {
        gotoxy(i+1,0);
        cout<<char(196);
        gotoxy(0,i+1);
        cout<<"|";
        gotoxy(199,i+1);
        cout<<"|";
    }
    for(int i=0;i<199;i++)
    {
        gotoxy(i+1,10);
        cout<<char(196);
         gotoxy(i+1,46);
        cout<<char(196);
    }
    for(int i=10;i<199;i++)
    {
        gotoxy(135,i+1);
        cout<<"|";
    }

}
void start()
{
    char k;
    do
    {
        TextColor(10);
        gotoxy(35,0);
        cout<<"======================================="<<endl;
        gotoxy(35,1);
        cout<<"|PHAN MEM QUAN LY TRANG TRAI CHAN NUOI| "<<endl;
        TextColor(4);
        gotoxy(35,2);
        TextColor(10);
        cout<<"|";
        TextColor(4);
        cout<<"      DESIGNED-DAO PHUONG NAM        ";
        TextColor(10);
        cout<<"|"<<endl;
        gotoxy(35,3);
        TextColor(10);
        cout<<"|";
        TextColor(4);
        cout<<"      MA SINH VIEN : 22021551        ";
        TextColor(10);
        cout<<"|"<<endl;
        gotoxy(35,4);
        TextColor(10);
        cout<<"======================================="<<endl;
        TextColor(14);
        gotoxy(45,10);
        cout << " ------------------" << endl;
        gotoxy(45,11);
        cout << " |   START-ENTER  |" << endl;
        gotoxy(45,12);
        cout << " ------------------" << endl;
        gotoxy(48,11);
        k = cin.get();
        system("cls");
    } while (k != '\n'); // Thay mã ASCII của phím "Enter" bằng '\n'

}


void Menu_chinh(int luaChon)
{
        int a = 15;
        int b = a + 1;
        TextColor(MAUKHUNG);
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 47; j++)
            {
                gotoxy(145 + j, a);
                cout << char(196);
            }
            a++;
            if (i != 6)
            {
                gotoxy(145, a);
                cout << "|";
                gotoxy(145 + 46, a);
                cout << "|";
            }
            a++;
        }
        if (luaChon == 1)
        {
           TextColor(MAUCHECK);
        }
        else
            TextColor(MAUCHU);
        gotoxy(147, b);
        cout << "1. Quan li giong heo\n";
        gotoxy(147, b + 2);
        if (luaChon == 2)
        {
             TextColor(MAUCHECK);
        }
        else
            TextColor(MAUCHU);
        cout << "2. Quan li chuong nuoi\n";
        gotoxy(147, b + 4);
        if (luaChon == 3)
        {
             TextColor(MAUCHECK);
        }
        else
             TextColor(MAUCHU);
        cout << "3. Cap nhat va chinh sua thong tin\n";
        if (luaChon == 4 ) {
             TextColor(MAUCHECK);
        }
        else
            TextColor(MAUCHU);
        gotoxy(147, b + 6);
        cout << "4. Quan li giao dich\n";
        if (luaChon == 5)
        {
            TextColor(MAUCHECK);
        }
        else
            TextColor(MAUCHU);
        gotoxy(147, b + 8);
        cout << "5. Them va xoa thong tin\n";
        gotoxy(147, 19);
        if (luaChon == 6)
        {
             TextColor(MAUCHECK);
        }
        else
            TextColor(MAUCHU);
        gotoxy(147, b + 10);
        cout << "6. Thoat\n";
        ve_khung_chuong_trinh();
}

void menu_cap_nhat(int luaChon)
{
    int a = 8;
    int b = a + 1;
    TextColor(MAUKHUNG);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 47; j++)
        {
            gotoxy(40 + j, a);
            cout << char(196);
        }
        a++;
        if (i != 3)
        {
            gotoxy(40, a);
            cout << "|";
            gotoxy(40 + 46, a);
            cout << "|";
        }
        a++;
    }
    if (luaChon == 1)
    {
        TextColor(MAUCHECK);
    }
    else
    TextColor(MAUCHU);
    gotoxy(45, b);
    cout << "1. Cap nhat giong heo\n";
    gotoxy(45, b + 2);
    if (luaChon == 2)
    {
        TextColor(MAUCHECK);
    }
    else
    TextColor(MAUCHU);
    cout << "2. Cap nhat chuong nuoi\n";
    gotoxy(45, b + 4);
    if (luaChon == 3 )
    {
        TextColor(MAUCHECK);
    }
    else
        TextColor(MAUCHU);
        cout << "3. Thoat\n";
}

void menu_4(int luaChon)
{
    int a = 8;
    int b = a + 1;
    TextColor(MAUKHUNG);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 47; j++)
        {
            gotoxy(40 + j, a);
            cout << char(196);
        }
        a++;
        if (i != 3)
        {
            gotoxy(40, a);
            cout << "|";
            gotoxy(40 + 46, a);
            cout << "|";
        }
        a++;
    }
    if (luaChon == 1)
    {
        TextColor(MAUCHECK);
    }
    else
    TextColor(MAUCHU);
    gotoxy(45, b);
    cout << "1. Xuat chuong\n";
    gotoxy(45, b + 2);
    if (luaChon == 2)
    {
        TextColor(MAUCHECK);
    }
    else
    TextColor(MAUCHU);
    cout << "2. Nhat ky xuat chuong\n";
    gotoxy(45, b + 4);
    if (luaChon == 3)
    {
        TextColor(MAUCHECK);
    }
    else
    TextColor(MAUCHU);
    cout << "3. Thoat\n";

}

void menu_5(int luaChon)
{
    int a = 8;
    int b = a + 1;
    TextColor(MAUKHUNG);
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 47; j++)
        {
            gotoxy(40 + j, a);
            cout << char(196);
        }
        a++;
        if (i != 5)
        {
            gotoxy(40, a);
            cout << "|";
            gotoxy(40 + 46, a);
            cout << "|";
        }
        a++;
    }
     if (luaChon == 1)
        {
           TextColor(MAUCHECK);
        }
        else
            TextColor(MAUCHU);
        gotoxy(45, b);
        cout << "1. Them giong heo\n";
        gotoxy(45, b + 2);
        if (luaChon == 2)
        {
             TextColor(MAUCHECK);
        }
        else
            TextColor(MAUCHU);
        cout << "2. Them chuong nuoi\n";
        gotoxy(45, b + 4);
        if (luaChon == 3)
        {
             TextColor(MAUCHECK);
        }
        else
             TextColor(MAUCHU);
        cout << "3. Xoa giong heo\n";
        if (luaChon == 4 ) {
             TextColor(MAUCHECK);
        }
        else
            TextColor(MAUCHU);
        gotoxy(45, b + 6);
        cout << "4. Xoa chuong nuoi\n";
        if (luaChon == 5)
        {
            TextColor(MAUCHECK);
        }
        else
            TextColor(MAUCHU);
        gotoxy(45, b + 8);
        cout << "5. Thoat\n";

}



void Nhap_thong_tin_giong_heo()
{

    for(int i=0;i<so_giong_heo;i++)
    {
        int n=4;
        TextColor(11);
        gotoxy(4,n+i*2);
        cout<<i+1;
        gotoxy(15,n+i*2);
        getline(cin,danhsach_heo_temp[i].giong);
        gotoxy(52,n+i*2);
        getline(cin,danhsach_heo_temp[i].don_gia);

    }
}

void in_giong_heo(int so_giong_heo)
{
    for (int i = 0; i < so_giong_heo; i++)
    {
        TextColor(11);
        gotoxy(4, 4 + i * 2);
        cout << i + 1;
        gotoxy(15, 4 + i * 2);
        cout << danhsach_heo[i].giong;
        gotoxy(52, 4 + i * 2);
        cout << danhsach_heo[i].don_gia;
    }
}
void Them_thong_tin_giong_heo()
{
    for (int i = 0; i < so_giong_heo_muon_them; i++)
    {
        int n=4;
        TextColor(11);
        gotoxy(4,n+i*2);
        cout<<i+1 + so_giong_heo;
        gotoxy(15,n+i*2);
        getline(cin,danhsach_heo_temp[i+ so_giong_heo].giong);
        gotoxy(52,n+i*2);
        getline(cin,danhsach_heo_temp[i+ so_giong_heo].don_gia);
    }

    so_giong_heo += so_giong_heo_muon_them;
    so_giong_heo_muon_them = 0;
}

void Nhap_chuong_nuoi()
{
    for(int i=0;i<so_luong_chuong;i++)
    {
        int n=4;
        TextColor(11);
        gotoxy(4,n+i*2);
        TextColor(11);
        getline(cin,danhsach_machuong_temp[i].ma_chuong);
        gotoxy(20,n+i*2);
        getline(cin,danhsach_machuong_temp[i].so_luong);
        gotoxy(32,n+i*2);
        getline(cin,danhsach_machuong_temp[i].ngay_nhan);
        gotoxy(52,n+i*2);
        getline(cin,danhsach_machuong_temp[i].giong);

    }
}

void Them_chuong_nuoi()
{
    for(int i=0;i<so_chuong_nuoi_them;i++)
    {
        int n=4;
        TextColor(11);
        gotoxy(4,n+i*2);
        getline(cin,danhsach_machuong_temp[i+so_luong_chuong].ma_chuong);
        gotoxy(20,n+i*2);
        getline(cin,danhsach_machuong_temp[i+so_luong_chuong].so_luong);
        gotoxy(32,n+i*2);
        getline(cin,danhsach_machuong_temp[i+so_luong_chuong].ngay_nhan);
        gotoxy(52,n+i*2);
        getline(cin,danhsach_machuong_temp[i+so_luong_chuong].giong);

    }
    so_luong_chuong += so_chuong_nuoi_them;
    so_chuong_nuoi_them = 0;
}



void in_chuong_nuoi(int so_luong_chuong)
{
    for (int i = 0; i < so_luong_chuong; i++)
    {
        TextColor(11);
        gotoxy(4, 4 + i * 2);
        cout << danhsach_machuong[i].ma_chuong;
        gotoxy(20, 4 + i * 2);
        cout << danhsach_machuong[i].so_luong;
        gotoxy(32, 4 + i * 2);
        cout << danhsach_machuong[i].ngay_nhan;
        gotoxy(52, 4 + i * 2);
        cout << danhsach_machuong[i].giong;
    }
}
double tong_so_chuong_nuoi_da_xuat;




void xuat_nhat_ky()
{
    int row=4;
    double tong_so_tien = 0;
    for(int f= 0; f < v+so_giong_heo; f++)
    {
        if (!danh_Sach_bang_ghi[f].ma_chuong.empty())
        {
            gotoxy(4,row);
            cout<< danh_Sach_bang_ghi[f].ma_chuong ;
            gotoxy(17,row);
            cout<< danh_Sach_bang_ghi[f].giong_heo ;
            gotoxy(32,row);
            cout<< danh_Sach_bang_ghi[f].don_gia ;
            gotoxy(50,row);
            cout<< danh_Sach_bang_ghi[f].so_luong;
            gotoxy(70,row);
            cout<< danh_Sach_bang_ghi[f].tong_can_nang ;
            gotoxy(90,row);
            cout<< danh_Sach_bang_ghi[f].thanh_tien ;
            gotoxy(106,row);
            cout<<"Da xuat";
            tong_so_tien+=danh_Sach_bang_ghi[f].thanh_tien;
            row+=2;
        }
    }
    int count = 0;
    for (int i = 0; i < v + so_giong_heo; i++)
    {
        if (!danh_Sach_bang_ghi[i].ma_chuong.empty())
        {
            count++;
        }
    }
     gotoxy(0,row);
    cout<<"Tong so tien thu duoc la : "<<tong_so_tien;
    gotoxy(0,row+1);
    cout<<"Tong so chuong nuoi da xuat : "<<count;
    gotoxy(0,row+2);
    cout<<"Tong so chuong nuoi chua xuat : "<<so_luong_chuong-count;
}


void ve_bang_giong_heo(int &so_giong_heo)
{
    for (int i = 0; i < so_giong_heo+2; i++)
    {
        int k=1;
        for (int j = 0; j < 75; j++)
        {
            TextColor(10);
            gotoxy(j, k + i * 2);
            cout << char(196);
        }
    }

    for (int i = 0; i < so_giong_heo+1; i++)
    {
        int m=2;
        int j=0;
        TextColor(10);
        gotoxy(j, m + i * 2);
        cout<<"|";
        gotoxy(j+74, m + i * 2);
        cout<<"|";
        gotoxy(10, m + i * 2);
        cout<<"|";
        gotoxy(40, m + i * 2);
        cout<<"|";
    }
    TextColor(6);
    gotoxy(4,2);
    cout<<"STT";
    gotoxy(15,2);
    cout<<"  Giong heo";
    gotoxy(52,2);
    cout<<"Don gia-VND  ";
}


void ve_bang_chuong_nuoi( int &so_luong_chuong)
{
    for (int i = 0; i < so_luong_chuong+2; i++)
    {
        int k=1;
        for (int j = 0; j < 75; j++)
        {
            TextColor(10);
            gotoxy(j, k + i * 2);
            cout << char(196);
        }
    }

    for (int i = 0; i < so_luong_chuong+1; i++)
    {
        int m=2;
        int j=0;
        TextColor(10);
        gotoxy(j, m + i * 2);
        cout<<"|";
        gotoxy(j+74, m + i * 2);
        cout<<"|";
        gotoxy(15, m + i * 2);
        cout<<"|";
        gotoxy(30, m + i * 2);
        cout<<"|";
        gotoxy(50, m + i * 2);
        cout<<"|";
    }
    TextColor(6);
    gotoxy(4,2);
    cout<<"Ma chuong";
    gotoxy(16,2);
    cout<<"So luong heo ";
    gotoxy(32,2);
    cout<<"Ngay nhap heo  ";
    gotoxy(56,2);
    cout<<"Giong heo ";
}


void ve_bang_cap_nhat_giong_heo( int k ,int m , int n)
{
    for (int i = 0; i < 3; i++)
    {

        for (int j = 0; j < 75; j++)
        {
            TextColor(10);
            gotoxy(j, k + i * 2);
            cout << char(196);
        }
    }

    for (int i = 0; i < 2; i++)
    {
        int j=0;
        TextColor(10);
        gotoxy(j, m + i * 2);
        cout<<"|";
        gotoxy(j+74, m + i * 2);
        cout<<"|";
        gotoxy(10, m + i * 2);
        cout<<"|";
        gotoxy(40, m + i * 2);
        cout<<"|";
    }
    TextColor(6);
    gotoxy(4,n);
    cout<<"STT";
    gotoxy(15,n);
    cout<<"  Giong heo";
    gotoxy(48,n);
    cout<<"Don gia (don vi :VND)";
}


void ve_bang_cap_nhat_chuong_nuoi(int k ,int m , int n)
{

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 75; j++)
        {
            TextColor(10);
            gotoxy(j, k + i * 2);
            cout << char(196);
        }
    }

    for (int i = 0; i < 2; i++)
    {
        int j=0;
        TextColor(10);
        gotoxy(j, m + i * 2);
        cout<<"|";
        gotoxy(j+74, m + i * 2);
        cout<<"|";
        gotoxy(15, m + i * 2);
        cout<<"|";
        gotoxy(30, m + i * 2);
        cout<<"|";
        gotoxy(50, m + i * 2);
        cout<<"|";
    }
    TextColor(6);
    gotoxy(4,m);
    cout<<"Ma chuong";
    gotoxy(16,m);
    cout<<" So luong heo ";
    gotoxy(32,m);
    cout<<"Ngay nhap heo ";
    gotoxy(56,m);
    cout<<"Giong heo ";
}


void ve_bang_xuat_chuong()
{
    for (int i = 0; i < 3 ; i++)
    {
        int k=1;
        for (int j = 0; j < 110; j++)
        {
            TextColor(10);
            gotoxy(j, k + i * 2);
            cout << char(196);
        }
    }

    for (int i = 0; i < 2; i++)
    {
        int m=2;
        int j=0;
        TextColor(10);
        gotoxy(j, m + i * 2);
        cout<<"|";
        gotoxy(j+109, m + i * 2);
        cout<<"|";
        gotoxy(15, m + i * 2);
        cout<<"|";
        gotoxy(30, m + i * 2);
        cout<<"|";
        gotoxy(47, m + i * 2);
        cout<<"|";
        gotoxy(65, m + i * 2);
        cout<<"|";
        gotoxy(85, m + i * 2);
        cout<<"|";
    }
    TextColor(6);
    gotoxy(4,2);
    cout<<"Ma chuong";
    gotoxy(17,2);
    cout<<" Giong heo";
    gotoxy(32,2);
    cout<<"Don gia-VND  ";
    gotoxy(50,2);
    cout<<"So luong heo";
    gotoxy(66,2);
    cout<<"Tong can nang(kg)  ";
    gotoxy(88,2);
    cout<<"Thanh tien-VND  ";
}

int dem_so_luong_chuong_da_xuat()
{
    int count = 0;
    for (int i = 0; i < v + so_giong_heo; i++)
    {
        if (!danh_Sach_bang_ghi[i].ma_chuong.empty())
        {
            count++;
        }
    }
    return count;
}


void ve_bang_ghi_nhat_ky()
{
    tong_so_chuong_nuoi_da_xuat=dem_so_luong_chuong_da_xuat();
    for (int i = 0; i < tong_so_chuong_nuoi_da_xuat+2; i++)
    {
        int k=1;
        for (int j = 0; j < 120; j++)
        {
            TextColor(10);
            gotoxy(j, k + i * 2);
            cout << char(196);
        }
    }

    for (int i = 0; i < tong_so_chuong_nuoi_da_xuat+1; i++)
    {
        int m=2;
        int j=0;
        TextColor(10);
        gotoxy(j, m + i * 2);
        cout<<"|";
        gotoxy(j+119, m + i * 2);
        cout<<"|";
        gotoxy(15, m + i * 2);
        cout<<"|";
        gotoxy(30, m + i * 2);
        cout<<"|";
        gotoxy(47, m + i * 2);
        cout<<"|";
        gotoxy(64, m + i * 2);
        cout<<"|";
        gotoxy(86, m + i * 2);
        cout<<"|";
        gotoxy(104, m + i * 2);
        cout<<"|";
    }
    TextColor(6);
    gotoxy(4,2);
    cout<<"Ma chuong";
    gotoxy(17,2);
    cout<<"Giong heo";
    gotoxy(32,2);
    cout<<"Don gia-VND  ";
    gotoxy(50,2);
    cout<<"So luong heo  ";
    gotoxy(67,2);
    cout<<"Tong can nang(kg)  ";
    gotoxy(88,2);
    cout<<"Thanh tien-VND  ";
    gotoxy(107,2);
    cout<<"Trang thai  ";
}

void kiem_tra_giong_heo_cap_nhat(int so_giong_heo)
{
    string giong_heo;
    TextColor(MAUKHUNG);
    cout<<"Nhap vao giong heo ma ban muon cap nhap thong tin : ";
    getline(cin,giong_heo);
    bool da_tim_thay_heo = false;
    for (int i = 0; i < so_giong_heo; i++)
    {
        if (danhsach_heo_temp[i].giong == giong_heo)
        {
            da_tim_thay_heo = true;
            ve_bang_cap_nhat_giong_heo(1,2,2);
            TextColor(11);
            gotoxy(4, 4 );
            cout << i + 1;
            gotoxy(15, 4 );
            cout << danhsach_heo_temp[i].giong;
            gotoxy(52, 4 );
            cout << danhsach_heo_temp[i].don_gia;
            gotoxy(0,6);
            TextColor(MAUKHUNG);
            cout<<"Cap nhat : ";
            ve_bang_cap_nhat_giong_heo(7,8,8);
            TextColor(11);
            gotoxy(4,10);
            cout<<i+1;
            gotoxy(15,10);
            getline(cin,danhsach_heo_temp[i].giong);
            gotoxy(52,10);
            getline(cin,danhsach_heo_temp[i].don_gia);
            break;

        }

     }
     if (!da_tim_thay_heo)
     {
        gotoxy(0,20);
        cout << "Khong tim thay heo thuoc giong " << giong_heo << endl;
     }
}

void kiem_tra_chuong_nuoi_cap_nhap(int so_luong_chuong)
{
    string ma_chuong;
    TextColor(MAUKHUNG);
    cout<<"Nhap vao ma chuong nuoi ma ban muon cap nhat : ";
    getline(cin,ma_chuong);
    bool da_tim_thay= false;
    for (int i = 0; i < so_luong_chuong; i++)
    {
        if (danhsach_machuong_temp[i].ma_chuong == ma_chuong)
        {
            da_tim_thay = true;
            ve_bang_cap_nhat_chuong_nuoi(1,2,2);
            TextColor(11);
            gotoxy(4, 4 );
            cout << danhsach_machuong_temp[i].ma_chuong;
            gotoxy(20, 4 );
            cout << danhsach_machuong_temp[i].so_luong;
            gotoxy(32, 4 );
            cout << danhsach_machuong_temp[i].ngay_nhan;
            gotoxy(52, 4 );
            cout << danhsach_machuong_temp[i].giong;
            gotoxy(0,6);
            cout<<"Cap nhat : ";
            ve_bang_cap_nhat_chuong_nuoi(7,8,8);
            TextColor(11);
            gotoxy(4,10);
            getline(cin,danhsach_machuong_temp[i].ma_chuong);
            gotoxy(20,10);
            getline(cin,danhsach_machuong_temp[i].so_luong);
            gotoxy(32,10);
            getline(cin,danhsach_machuong_temp[i].ngay_nhan);
            gotoxy(52,10);
            getline(cin,danhsach_machuong_temp[i].giong);

            break;
        }


    }
    if (!da_tim_thay)
    {
        gotoxy(0,20);
        cout << "Khong tim thay ma chuong " << ma_chuong << endl;
    }
}

void lua_chon_chuc_nang_Menu_cap_nhat()
{
	system("cls");
    ve_khung_chuong_trinh();
	int luaChon = 1;
	anConTro();

	menu_cap_nhat(1);

	while (1)
    {
		char phim = _getch();
		int key = (int)phim;

		switch (key)
		{

            case 72:
                luaChon--;
                if (luaChon <= 0)
                {
                    luaChon = 3;
                }
                break;
            case 80:
                luaChon++;
                if (luaChon >= 4)
                {
                    luaChon = 1;
                }
                break;
            case 13:
            {
                switch (luaChon)
                {
                    case 1:
                    {
                        system("cls");
                        hienThiConTro(true);
                        kiem_tra_giong_heo_cap_nhat(so_giong_heo);
                        hienThiConTro(false);
                        break;
                    }
                    case 2:
                    {
                        system("cls");
                        hienThiConTro(true);
                        kiem_tra_chuong_nuoi_cap_nhap(so_luong_chuong);
                        hienThiConTro(false);

                        break;
                    }
                     case 3:
                    {
                        system("cls");
                        return;
                        break;
                    }
                }
            }
            break;
		}
		menu_cap_nhat(luaChon);
    }
}
void kiem_tra_ma_xuat_chuong_lan_1()
{
    string ma_chuong;
    int row=4;
    int t=0;
    gotoxy(4,row);
    getline(cin,ma_chuong);
    bool da_tim_thay = false;
    bool da_tim_thay_don_gia = false;
    for (int i = 0; i < so_luong_chuong; i++)
    {
        if (danhsach_machuong_temp[i].ma_chuong == ma_chuong)
        {
            da_tim_thay = true;
            bool da_tim_heo = false;
            for(int j=0; j < so_giong_heo; j++)
            {
                if ( danhsach_heo_temp[j].giong == danhsach_machuong_temp[i].giong)
                {
                    string tong_can_nang;
                    da_tim_heo = true;
                    da_tim_thay_don_gia =true;
                    gotoxy(17,row);
                    cout<<danhsach_machuong_temp[i].giong;
                    gotoxy(50,row);
                    cout<<danhsach_machuong_temp[i].so_luong;
                    gotoxy(33,row);
                    cout<<danhsach_heo_temp[j].don_gia;
                    gotoxy(70,row);
                    getline(cin,tong_can_nang);

                    gotoxy(88,row);
                    int a,b,c;
                    stringstream(danhsach_heo_temp[j].don_gia)>>a;
                    stringstream(danhsach_machuong_temp[i].so_luong)>>b;
                    stringstream(tong_can_nang)>>c;
                    cout<<a*b*c;
                    danh_Sach_bang_ghi[t].ma_chuong = ma_chuong;
                    danh_Sach_bang_ghi[t].giong_heo = danhsach_machuong_temp[i].giong;
                    danh_Sach_bang_ghi[t].don_gia = a;
                    danh_Sach_bang_ghi[t].so_luong = b;
                    danh_Sach_bang_ghi[t].tong_can_nang = c;
                    danh_Sach_bang_ghi[t].thanh_tien = a * b * c;
                    t=t+1;
                    break;
                }
                if(!da_tim_thay_don_gia)
                {
                    gotoxy(0,21);
                    TextColor(MAUKHUNG);
                    cout<<"Khong tim thay giong heo";
                }

            }
        }
    }


    if(!da_tim_thay)
    {
        gotoxy(0,20);
        TextColor(MAUKHUNG);
        cout<<"Khong tim thay ma chuong";
    }
    row+=2;
}

void kiem_tra_ma_xuat_chuong_lan_2()
{

        string ma_chuong;
        int row=4;
        TextColor(11);
        gotoxy(4,row);
        getline(cin,ma_chuong);
        bool da_tim_thay = false;
        for (int i = 0; i < so_luong_chuong; i++)
        {
            if (danhsach_machuong_temp[i].ma_chuong == ma_chuong)
            {
                da_tim_thay = true;
                bool da_tim_heo = false;
                for(int j=0; j < so_giong_heo; j++)
                {
                    if ( danhsach_heo_temp[j].giong == danhsach_machuong_temp[i].giong)
                    {
                        string tong_can_nang;
                        da_tim_heo = true;
                        gotoxy(17,row);
                        cout<<danhsach_machuong_temp[i].giong;
                        gotoxy(50,row);
                        cout<<danhsach_machuong_temp[i].so_luong;
                        gotoxy(33,row);
                        cout<<danhsach_heo_temp[j].don_gia;
                        gotoxy(70,row);
                        getline(cin,tong_can_nang);
                        gotoxy(88,row);
                        int a,b,c;
                        stringstream(danhsach_heo_temp[j].don_gia)>>a;
                        stringstream(danhsach_machuong_temp[i].so_luong)>>b;
                        stringstream(tong_can_nang)>>c;
                        cout<<a*b*c;

                        danh_Sach_bang_ghi[v].ma_chuong = ma_chuong;
                        danh_Sach_bang_ghi[v].giong_heo = danhsach_machuong_temp[i].giong;
                        danh_Sach_bang_ghi[v].don_gia = a;
                        danh_Sach_bang_ghi[v].so_luong = b;
                        danh_Sach_bang_ghi[v].tong_can_nang = c;
                        danh_Sach_bang_ghi[v].thanh_tien = a * b * c;
                        v=v+1;
                    }

                }
            }
        }


        if(!da_tim_thay)
        {
            gotoxy(0,20);
            TextColor(MAUKHUNG);
            cout<<"Khong tim thay ma chuong";
        }
        row+=2;
        v=v+so_giong_heo;

}


void chon_chuc_nang_xuat_chuong_lan_1()
{
    TextColor(MAUKHUNG);
    cout<<"Nhap vao ma chuong nuoi da xuat : ";
    ve_bang_xuat_chuong();
    kiem_tra_ma_xuat_chuong_lan_1();
}


void chon_chuc_nang_xuat_chuong_lan_2()
{
    tong_so_chuong_nuoi_da_xuat=dem_so_luong_chuong_da_xuat();
    if(tong_so_chuong_nuoi_da_xuat<so_luong_chuong)
    {
        TextColor(MAUKHUNG);
        cout<<"Nhap vao ma chuong nuoi ban muon xuat : ";
        ve_bang_xuat_chuong();
        kiem_tra_ma_xuat_chuong_lan_2();
    }
    else
    {
        cout<<"Ban da xuat het so chuong nuoi hien co trong trang trai";
    }
}

void chuc_nang_xuat_chuong()
{
    if(firstTime5)
    {
        chon_chuc_nang_xuat_chuong_lan_1();
        firstTime5=false;
    }
    else
    {
        chon_chuc_nang_xuat_chuong_lan_2();
    }

}
void hienThiMenu_4()
{
	system("cls");
	string ma_chuong;
	int a,b,c;
	anConTro();

	int luaChon = 1;

	menu_4(1);

	while (1)
    {
		char phim = _getch();
		int key = (int)phim;

		switch (key)
		{

            case 72:
                luaChon--;
                if (luaChon <= 0)
                {
                    luaChon = 3;
                }
                break;
            case 80:
                luaChon++;
                if (luaChon >= 4)
                {
                    luaChon = 1;
                }
                break;
            case 13:
            {
                switch (luaChon)
                {

                    case 1:
                    {
                        system("cls");
                        hienThiConTro(true);
                        chuc_nang_xuat_chuong();
                        hienThiConTro(false);
                        break;
                    }
                     case 2:
                    {
                        system("cls");
                        ve_bang_ghi_nhat_ky();
                        xuat_nhat_ky();
                        cin.ignore();
                        break;
                    }
                     case 3:
                    {
                        system("cls");
                        return ;
                        break;
                    }
                }
            }
            break;
		}
		menu_4(luaChon);
    }
}

void xoa_giong_heo(int k, int& so_giong_heo)
{
    // Dịch chuyển phần tử phía sau lên một bậc
    for (int i = k-1; i < so_giong_heo - 1; i++)
    {
        danhsach_heo[i] = danhsach_heo[i+1];
    }
    // Giảm số lượng phần tử của mảng
    so_giong_heo--;
}
void xoa_chuong_nuoi(int k, int& so_luong_chuong)
{
    // Dịch chuyển phần tử phía sau lên một bậc
    for (int i = k-1; i < so_luong_chuong - 1; i++)
    {
        danhsach_machuong[i] = danhsach_machuong[i+1];
    }
    // Giảm số lượng phần tử của mảng
    so_luong_chuong--;
}

int tim_chuong(string& ma_chuong, const int& so_luong_chuong)
{
    for (int i = 0; i < so_luong_chuong; i++)
    {
        if (danhsach_machuong[i].ma_chuong == ma_chuong)
        {
            return i; // Trả về vị trí phần tử có mã chuồng trùng
        }
    }
    return -1; // Không tìm thấy phần tử có mã chuồng trùng
}


void lua_chon_chuc_nang_Menu_5()
{
	system("cls");

	int luaChon = 1;
	anConTro();

	menu_5(1);

	while (1)
    {
		char phim = _getch();
		int key = (int)phim;

		switch (key)
		{

            case 72:
                luaChon--;
                if (luaChon <= 0)
                {
                    luaChon = 5;
                }
                break;
            case 80:
                luaChon++;
                if (luaChon >= 6)
                {
                    luaChon = 1;
                }
                break;
            case 13:
            {
                switch (luaChon)
                {
                    case 1:
                    {
                        system("cls");
                        hienThiConTro(true);
                        TextColor(MAUKHUNG);
                        cout<<"Nhap vao so giong heo ma ban muon them : ";
                        cin>>so_giong_heo_muon_them;
                        cin.ignore();
                        ve_bang_giong_heo(so_giong_heo_muon_them);
                        Them_thong_tin_giong_heo();
                        hienThiConTro(false);
                        break;
                    }
                    case 2:
                    {
                        system("cls");
                        hienThiConTro(true);
                        TextColor(MAUKHUNG);
                        cout<<"Nhap vao so chuong nuoi ma ban muon them : ";
                        cin>>so_chuong_nuoi_them;
                        cin.ignore();
                        ve_bang_chuong_nuoi(so_chuong_nuoi_them);
                        Them_chuong_nuoi();
                        hienThiConTro(false);
                        break;
                    }
                    case 3:
                    {
                        system("cls");
                        hienThiConTro(true);
                        for (int i = 0; i < so_giong_heo; i++)
                        {
                            danhsach_heo[i] = danhsach_heo_temp[i];
                        }
                        ve_bang_giong_heo(so_giong_heo);
                        in_giong_heo(so_giong_heo);
                        int xoa;
                        gotoxy(0,1+(so_giong_heo+2)*2);
                        cout<<"Nhap vao so thu tu cua giong heo ban muon xoa : ";
                        cin>>xoa;
                        bool found = false;
                        for (int i = 0; i < so_giong_heo; i++)
                        {
                            if (xoa == i + 1)
                            {
                                xoa_giong_heo(xoa, so_giong_heo);
                                system("cls");
                                gotoxy(50, 4 + (so_giong_heo + 2) * 2);
                                Loading();
                                gotoxy(50, 6 + (so_giong_heo + 2) * 2);
                                cout << "Da luu";
                                cin.ignore();
                                found = true;
                                break;
                            }
                        }

                        if (!found)
                        {
                            gotoxy(0, 6 + (so_giong_heo + 2) * 2);
                            cout << "Gia tri ban nhap khong ton tai";
                        }
                        cin.ignore();
                        hienThiConTro(false);
                        break;
                    }
                    case 4:
                    {
                        system("cls");
                        hienThiConTro(true);
                        for (int i = 0; i < so_luong_chuong; i++)
                        {
                                danhsach_machuong[i] = danhsach_machuong_temp[i];
                        }
                        ve_bang_chuong_nuoi(so_luong_chuong);
                        in_chuong_nuoi(so_luong_chuong);
                        gotoxy(0,1+(so_luong_chuong+2)*2);
                        cout<<"Nhap vao ma chuong ban muon xoa : ";
                        string ma_chuong;
                        getline(cin, ma_chuong);
                        int index = tim_chuong(ma_chuong, so_luong_chuong);
                        if (index == -1)
                        {
                            gotoxy(0, 6 + (so_luong_chuong + 2) * 2);
                            cout << "Ma chuong ban nhap khong ton tai";
                        }
                        else
                        {
                            xoa_chuong_nuoi(index,so_luong_chuong);
                            gotoxy(0, 4+ (so_giong_heo + 2) * 2);
                            system("cls");
                            gotoxy(50, 4 + (so_giong_heo + 2) * 2);
                            Loading();
                            gotoxy(50, 6 + (so_giong_heo + 2) * 2);
                            cout << "Da luu";
                        }
                        cin.ignore();
                        hienThiConTro(false);

                        break;
                    }
                    case 5:
                    {
                        system("cls");
                        return;
                        break;
                    }
                }
            }
            break;
		}
		menu_5(luaChon);

    }
}


void lua_chon_chuc_nang_Menu_chinh()
{
	system("cls");

	int luaChon = 1;
    anConTro();
	Menu_chinh(1);

	while (1)
    {
		char phim = _getch();
		int key = (int)phim;

		switch (key)
		{

            case 72:
                luaChon--;
                if (luaChon <= 0)
                {
                    luaChon = 6;
                }
                break;
            case 80:
                luaChon++;
                if (luaChon >= 7)
                {
                    luaChon = 1;
                }
                break;
            case 13:
            {
                switch (luaChon)
                {
                    case 1:
                    {
                        system("cls");
                        hienThiConTro(true);
                        if (firstTime)
                        {
                            TextColor(MAUKHUNG);
                            cout << "Nhap vao so luong giong heo ban co trong trang trai : ";
                            cin >> so_giong_heo;
                            cin.ignore();
                            ve_bang_giong_heo(so_giong_heo);
                            Nhap_thong_tin_giong_heo();
                            firstTime = false;
                        }
                        else
                        {
                            system("cls");
                            hienThiConTro(false);
                            if (so_giong_heo_muon_them != 0)
                            {

                                ve_bang_giong_heo(so_giong_heo);
                                in_giong_heo(so_giong_heo);
                            }

                            else
                            {
                                for (int i = 0; i < so_giong_heo; i++)
                                {
                                        danhsach_heo[i] = danhsach_heo_temp[i];
                                }
                                ve_bang_giong_heo(so_giong_heo);
                                in_giong_heo(so_giong_heo);
                            }

                        }
                        cin.ignore();
                        hienThiConTro(false);
                        break;

                    }
                    case 2:
                    {
                        system("cls");
                        hienThiConTro(true);
                        if (firstTime2)
                        {
                            TextColor(MAUKHUNG);
                            cout<<"Nhap vao so luong chuong nuoi : ";
                            cin>>so_luong_chuong;
                            cin.ignore();
                            ve_bang_chuong_nuoi(so_luong_chuong);
                            Nhap_chuong_nuoi();
                            firstTime2 = false;
                        }
                        else
                        {
                            system("cls");
                            hienThiConTro(false);
                            if (so_chuong_nuoi_them != 0)
                            {

                                ve_bang_chuong_nuoi(so_luong_chuong);
                                in_chuong_nuoi(so_luong_chuong);

                            }

                            else
                            {
                                for (int i = 0; i < so_luong_chuong; i++)
                                {
                                        danhsach_machuong[i] = danhsach_machuong_temp[i];
                                }
                                ve_bang_chuong_nuoi(so_luong_chuong);
                                in_chuong_nuoi(so_luong_chuong);
                            }

                        }
                        cin.ignore();
                        hienThiConTro(false);
                        break;
                    }
                    case 3:
                    {
                        system("cls");
                        lua_chon_chuc_nang_Menu_cap_nhat();

                        break;
                    }
                    case 4:
                    {
                        system("cls");
                        hienThiMenu_4();


                        break;
                    }
                    case 5:
                    {

                        system("cls");
                        lua_chon_chuc_nang_Menu_5();
                        break;
                    }
                    case 6:
                    {
                        system("cls");
                        cout<<"CAM ON BAN DA SU DUNG PHAN MEM !"<<endl;
                        return;
                        break;
                    }
                }
            }
            break;
		}
		Menu_chinh(luaChon);

	}
}


int main()
{

    resizeConsole(1500, 800);
    start();

    char thu_lai_chuong_trinh;
    do
    {
        lua_chon_chuc_nang_Menu_chinh();
        cout << "Ban co muon thu lai chuong trinh Y|N : ";
        cin >> thu_lai_chuong_trinh;
        system("cls");
        ve_khung_chuong_trinh(); // vẽ khung sau khi in ra menu
    } while (toupper(thu_lai_chuong_trinh) == 'Y');

    system("PAUSE");
    return 0;
}



