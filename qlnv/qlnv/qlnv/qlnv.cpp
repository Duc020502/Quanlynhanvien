// qlnv.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// qlnhanvien.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include<conio.h> 
#include<stdio.h> 
#include<fstream>
#include <string>
#include <Windows.h>
#include <stdlib.h>
#include"dohoa.h"
using namespace std;
int capnhatt(string emloyf[50], int& t)
{

    for (int i = 0; i < 50; i++)
    {
        if (emloyf[i] == "\0")
        {
            t = i;
            break;
        }
    }
    return t;
}
void docamin(string aminf[], fstream& f3)
{
    f3.open("Administrators.txt", ios::in);
    for (int i = 0; i < 6; i++)
    {
        getline(f3, aminf[i], '\n');
    }
    f3.close();
}
void docemloy(string emloyf[], fstream& f1)
{

    f1.open("Employees.txt", ios::in);

    for (int i = 0; i < 20; i++)
    {
        getline(f1, emloyf[i], '\n');
    }
    f1.close();
}
void docemloycn(string emloyfcn[], fstream& f2)
{
    f2.open("thongtin.txt", ios::in);
    for (int i = 0; i < 50; i++)
    {
        getline(f2, emloyfcn[i], '\n');
    }
    f2.close();
}
void nhapmkamin(string  useramin, char mkamin[], string aminf[])
{

    for (int i = 0; i < 3; i++)
    {
        int size = 0;
        char  a = 'l';
        bool u;
        string  useramin;
        char mkamin[50];
        textcolor(12);
        cout << "\t\t\t\t\t*********************************\n";
        cout << "\t\t\t\t\t*\t";
        textcolor(11);
        cout << " DANG NHAP ADMIN\t";
        textcolor(12);
        cout << "*\n";
        cout << "\t\t\t\t\t*********************************\n";
        textcolor(11);
        cout << "\t\t\t\t\t Nhap user: ";
        if (i == 0)
        {
            cin.ignore();
        }
        getline(cin, useramin);
        cout << "\n\t\t\t\t\t Nhap password: ";

        while (a != 13)//13 = enter
        {

            a = _getch();
            if (a == 13)
            {
                break;
            }
            if (mkamin[0] == '\0')
            {
                while (true)
                {
                    a = _getch();
                    if (a != 8)
                    {
                        break;
                    }
                }
            }
            else if (a == 8)
            {
                if (size != 0)
                {
                    mkamin[size] = '\0';
                    size--;
                    cout << "\b \b";
                }
            }
            else
            {
                cout << a;
                mkamin[size] = a;
                size++;
                Sleep(200);
                cout << "\b \b*";
            }
        }

        mkamin[size] = '\0';
        for (int i = 0; i < 6; i += 2)
        {
            if (useramin != aminf[i] || mkamin != aminf[i + 1])
            {
                u = true;
            }
            else
            {
                u = false;
                break;
            }
        }

        if (u == false)
        {
            system("cls");
            textcolor(12);
            cout << "\n\t\t\t\t*********";
            textcolor(11);
            cout << " Dang Nhap Thanh Cong ";
            textcolor(12);
            cout << "*********\n";
            Sleep(2000);
            system("cls");
            break;
        }
        else
        {
            textcolor(11);
            cout << "\n\t\t\t Sai User hoac sai Psssword\n";
            cout << "\t\t\t Ban con " << 3 - (i + 1) << " lan dang nhap!!!\n";
            cout << "\t\t\tXin moi nhap lai\n";
            _getch();
            system("cls");
            if (i == 2)
            {
                cout << "\t\t\t\tBan Da sai 3 lan chut ban may man lan sau!!!";
                Sleep(2000);
                exit(0);

            }
            system("cls");
        }

    }

}
void nhapmkemloy(string  useremloy, char mkemloy[], string emloyf[], int& k, int t)
{
    fstream f;
    docemloy(emloyf, f);
    capnhatt(emloyf, t);
    for (int i = 0; i < 3; i++)
    {
        int size = 0;
        char  a = 'l';
        bool u;
        textcolor(12);
        cout << "\t\t\t\t\t*********************************\n";
        cout << "\t\t\t\t\t*";
        textcolor(11);
        cout << "\tDANG NHAP EMPLOYEES";
        textcolor(12);
        cout << "\t*\n";
        cout << "\t\t\t\t\t*********************************\n";
        textcolor(11);
        cout << "\t\t\t\t\t Nhap user: ";
        if (i == 0)
        {
            cin.ignore();
        }
        getline(cin, useremloy);
        cout << "\n\t\t\t\t\t Nhap password: ";
        while (a != 13)//13 = enter
        {
            a = _getch();
            if (a == 13)
            {
                break;
            }
            if (mkemloy[0] == '\0')
            {
                while (true)
                {
                    a = _getch();
                    if (a != 8)
                    {
                        break;
                    }
                }
            }
            else if (a == 8)
            {
                if (size != 0)
                {
                    mkemloy[size] = '\0';
                    size--;
                    cout << "\b \b";
                }
            }
            else
            {
                cout << a;
                mkemloy[size] = a;
                size++;
                Sleep(200);
                cout << "\b \b*";
            }
        }
        mkemloy[size] = '\0';
        for (int i = 0; i < t; i += 2)
        {
            if (emloyf[i] != useremloy || emloyf[i + 1] != mkemloy)
            {
                u = false;
            }
            else
            {
                u = true;
                k = i;
                break;
            }
        }

        if (u == true)
        {
            system("cls");
            textcolor(12);
            cout << "\n\n\t\t\t\t*******";
            textcolor(11);
            cout << " Dang Nhap Thanh Cong!!!";
            textcolor(12);
            cout << " *********\n";
            Sleep(2000);
            system("cls");
            break;

        }
        else
        {
            textcolor(11);
            cout << "\n\t\t\t\t Sai User hoac sai Psssword\n";
            cout << "\t\t\t\t Ban con " << 3 - (i + 1) << " lan dang nhap!!!\n";
            cout << "\t\t\t\tXin moi nhap lai\n";
            _getch();
            system("cls");
            if (i == 2)
            {
                cout << "\t\t\t\tBan Da sai 3 lan chut ban may man lan sau!!!!";
                Sleep(2000);
                exit(0);
            }
            system("cls");
        }
    }
    if (emloyf[k + 1] == "111111")
    {
        textcolor(11);
        system("cls");
        cout << "\n\tTai khoan lan dau dang nhap, hay doi mat khau!!!\n";
        cout << "\n\tMat khau moi cua ban la (khac 111111): ";
        cin >> emloyf[k + 1];
        f.open("Employees.txt", ios::out);
        for (int i = 0; i < t + 2; i++)
        {
            f << emloyf[i] << endl;
        }
        f.close();
        system("cls");
        cout << "\t\t\tMat khau thay doi thanh cong !!!";
        Sleep(2000);
        system("cls");
    }
}
void khoan_cach(int k) {
    for (int i = 0; i <= k; i++)
    {
        
        cout<< " ";
      
    }

}
void menuemloy(int& k, string emloyfcn[], string emloyf[])
{
    while (true)
    {
        int chon;
        fstream f, f1;
        string text;
        int t;
        docemloycn(emloyfcn, f1);
        docemloy(emloyf, f);
        capnhatt(emloyf, t);
        textcolor(12);
        cout << "\t\t\t\t**************";
        textcolor(11);
        cout << " MENU EMPLOY";
        textcolor(12);
        cout << " *****************\n";
        textcolor(11);
        cout << "\t\t\t\t\t 1.Xem thong tin tai khoan.\n";
        cout << "\t\t\t\t\t 2.Doi Password.\n";
        cout << "\t\t\t\t\t 3.Thoat.\n";
        cout << "\t\t\t\t Ban muon lam gi? ";
        cin >> chon;
        if (chon == 1)
        {

            system("cls");

            for (int i = 2 * k; i < (2 * k + 4); i += 4)
            {
                int string_size = 25 - emloyfcn[i].size();
                int string_size1 = 30 - emloyfcn[i+1].size();
                int string_size2 = 15 - emloyfcn[i+2].size();
                int string_size3 = emloyfcn[i+3].size();

                textcolor(12);

                printf(" %-25s %-30s %-15s %-30s \n", "Ho va ten", "Dia chi", "SDT", "Email\n");
                textcolor(11);

                cout << " " << emloyfcn[i]; khoan_cach(string_size);
                cout << emloyfcn[i+1]; khoan_cach(string_size1);
                cout << emloyfcn[i+2]; khoan_cach(string_size2);
                cout << emloyfcn[i+3] << "\n";


              
            }
            _getch();
            system("cls");
        }
        else if (chon == 2)
        {
            for (int i = 0; i < 100; i++)
            {

                int size = 0;
                char  a = 'l';
                bool u;
                string useremloy;
                char mkemloy[50];
                system("cls");
                textcolor(12);
                cout << "\t\t\t\t************";
                textcolor(11);
                cout << " Xac Nhan Lai Danh Tinh";
                textcolor(12);
                cout << " ************ \n";
                textcolor(11);
                cout << "\t\t\t\t\t Nhap user: ";
                if (i == 0) cin.ignore();
                getline(cin, useremloy);

                cout << "\n\t\t\t\t\t Nhap password: ";

                while (a != 13)//13 = enter
                {

                    a = _getch();
                    if (a == 13)
                    {
                        break;
                    }
                    if (mkemloy[0] == '\0')
                    {
                        while (true)
                        {
                            a = _getch();
                            if (a != 8)
                            {
                                break;
                            }
                        }
                    }
                    else if (a == 8)
                    {
                        if (size != 0)
                        {
                            mkemloy[size] = '\0';
                            size--;
                            cout << "\b \b";
                        }
                    }
                    else
                    {
                        cout << a;
                        mkemloy[size] = a;
                        size++;
                        Sleep(200);
                        cout << "\b \b*";
                    }
                }

                mkemloy[size] = '\0';


                for (int i = 0; i < t; i += 2)
                {
                    if (emloyf[i] != useremloy || emloyf[i + 1] != mkemloy)
                    {
                        u = false;
                    }
                    else
                    {
                        u = true;
                        k = i;
                        break;
                    }
                }

                if (u == true)
                {
                    system("cls");
                    textcolor(11);
                    cout << "\n\t\t\t\t Xac Nhan Danh Tinh Thanh Cong!!! \n";
                    Sleep(2000);
                    system("cls");

                    break;
                }
                else
                {
                    system("cls");
                    cout << "\n\t\t\t\t Sai User hoac sai Psssword\n";
                    cout << "\t\t\t\tXin moi nhap lai\n";
                    _getch();
                    system("cls");
                }
            }
            while (true)
            {
                cout << "\n\t\t\tNhap mat khau thay doi: ";
                cin >> emloyf[k + 1];
                cout << "\n\t\t\tNhap lai mat khau thay doi:";
                cin >> text;
                if (emloyf[k + 1] == text)
                {
                    fstream f;
                    f.open("Employees.txt", ios::out);
                    for (int i = 0; i < t; i++)
                    {
                        f << emloyf[i] << endl;

                    }
                    f.close();
                    system("cls");
                    cout << "\t\t\t\t Da Doi Mat Khau Thanh Cong !!!";
                    Sleep(2000);
                    system("cls");
                    break;
                }
                else
                {
                    system("cls");
                    cout << "\t\t\t\tMat khau khong khop, nhap lai";
                    Sleep(2000);
                    system("cls");
                }
            }
        }
        else
        {
            break;
        }
    }
}
void menuamin(string emloyf[], int t, string emloyfcn[])
{
    while (true)
    {
        int chon;
        fstream f, f1;
        docemloycn(emloyfcn, f1);
        docemloy(emloyf, f);
        capnhatt(emloyf, t);
        textcolor(12);
        cout << "\t\t\t\t************** ";
        textcolor(11);
        cout << "MENU ADMINISTRATORS";
        textcolor(12);
        cout << " *****************\n";
        textcolor(11);
        cout << "\t\t\t\t\t 1.Them Employee.\n";
        cout << "\t\t\t\t\t 2.Xoa Employee.\n";
        cout << "\t\t\t\t\t 3.Tim Employee.\n";
        cout << "\t\t\t\t\t 4.Cap nhat Employee.\n";
        cout << "\t\t\t\t\t 5.Hien thi thong tin Employee.\n";
        cout << "\t\t\t\t\t 6.Thoat.\n";
        cout << "\t\t\t\t Ban muon lam gi? ";
        cin >> chon;
        if (chon == 1)
        {
            system("cls");
            bool j;
            while (true)
            {
                cout << "\n\t\t\t\t Nhap username: ";
                cin >> emloyf[t];
                for (int i = 0; i < t; i += 2)
                {
                    if (emloyf[i] == emloyf[t])
                    {
                        cout << "\tUsername da ton tai!!!\n";
                        cout << "\tXin moi nhap lai!!!";
                        j = true;
                        _getch();
                        system("cls");
                        break;
                    }
                    else j = false;
                }
                if (j == false)
                {
                    system("cls");
                    textcolor(12);
                    cout << "\t\t\t\t********";
                    textcolor(11);
                    cout << " Nhap Thong Tin Ca Nhan";
                    textcolor(12);
                    cout << " ********";
                    textcolor(11);
                    cout << "\n\t\t\t Ho va Ten: ";
                    cin >> emloyfcn[2 * t];
                    cout << "\n\t\t\t Dia chi: ";
                    cin >> emloyfcn[2 * t + 1];
                    cout << "\n\t\t\t So dien thoai: ";
                    cin >> emloyfcn[2 * t + 2];
                    cout << "\n\t\t\t Email: ";
                    cin >> emloyfcn[2 * t + 3];
                    f.open("thongtin.txt", ios::out);
                    for (int i = 0; i < 2 * t + 4; i++)
                    {
                        f << emloyfcn[i] << endl;
                    }
                    f.close();
                    f.open("Employees.txt", ios::out);
                    for (int i = 0; i < t + 2; i++)
                    {
                        f << emloyf[i] << endl;
                        if (i == t)
                        {
                            f << "111111";
                        }
                    }
                    f.close();
                    for (int i = 0; i < 50; i++)
                    {
                        if (emloyf[i] == "\0")
                        {
                            t = i;
                            break;
                        }
                    }
                    system("cls");
                    cout << "\n\n\t\t\t\tThem nhan vien thanh cong !!!!";
                    Sleep(2000);
                    system("cls");
                    break;
                }
            }
        }
        else if (chon == 2)
        {
            system("cls");
            int so = 1, o;
          
               
                textcolor(12);
                printf("\t\t%-10s %-25s \n","\t\tStt", "Ho va ten\n");
                
                
                for (int i = 0; i < t*2 ; i += 4)
                {
                    int string_size = 25 - emloyfcn[i].size();
                    textcolor(12);

                    cout << "\t\t\t\t " << so << ".       ";
                    textcolor(11);
                    
                    cout << emloyfcn[i]; khoan_cach(string_size);
                    cout << "\n";
                    
                    so++;
                }
                
         
            cout << "\n\t\t\tBan muon xoa employees nao? ";
            cin >> o;
            if (o > so || o <= 0)
            {
                system("cls");
                cout << "\t\t\t\t\tKhong co trong danh sach";
                Sleep(2000);
                system("cls");
            }
            int p = o * 2 - 2;
            for (int i = p; i < t + 3; i++)
            {
                emloyf[i] = emloyf[i + 2];
            }
            f.open("Employees.txt", ios::out);
            for (int i = 0; i < t; i++)
            {
                f << emloyf[i] << endl;
            }
            f.close();
            int g = o * 4 - 4;
            int s = t * 2 + 5;
            for (int i = g; i < s; i++)
            {
                emloyfcn[i] = emloyfcn[i + 4];
            }
            f.open("thongtin.txt", ios::out);
            for (int i = 0; i < t * 2; i++)
            {
                f << emloyfcn[i] << endl;
            }
            f.close();
            system("cls");
            cout << "\n\n\t\t\tXoa tai khoan thanh cong !!!";
            Sleep(2000);
            system("cls");
        }
        else if (chon == 3)
        {
            system("cls");
            int so = 1, o;
            textcolor(12);
            printf("\t\t%-10s %-25s \n", "\t\tStt", "Ho va ten\n");
            for (int i = 0; i < t * 2; i += 4)
            {
                int string_size = 25 - emloyfcn[i].size();
                textcolor(12);

                cout << "\t\t\t\t " << so << ".       ";
                textcolor(11);

                cout << emloyfcn[i]; khoan_cach(string_size);
                cout << "\n";

                so++;
            }
            cout << "\t\tBan muon xem thong tin cua ai? ";
            cin >> o;
            if (o > so || o <= 0)
            {
                cout << "Khong co trong danh sach";
                break;
            }
            system("cls");
            

                int string_size = 25 - emloyfcn[o * 4 - 4].size();
                int string_size1 = 30 - emloyfcn[o * 4 - 3].size();
                int string_size2 = 15 - emloyfcn[o * 4 - 2].size();
                int string_size3 = emloyfcn[o * 4 - 1].size();

                textcolor(12);
                
                printf(" %-25s %-30s %-15s %-30s \n", "Ho va ten", "Dia chi", "SDT", "Email\n");
                textcolor(11);

                cout <<" "<< emloyfcn[o * 4 - 4]; khoan_cach(string_size);
                cout << emloyfcn[o * 4 - 3]; khoan_cach(string_size1);
                cout << emloyfcn[o * 4 - 2]; khoan_cach(string_size2);
                cout << emloyfcn[o * 4 - 1] << "\n";
      
            _getch();
            system("cls");
        }
        else if (chon == 4)
        {
            system("cls");
            int so = 1, o,o1;
            textcolor(12);
            printf("\t\t%-10s %-25s \n", "\t\tStt", "Ho va ten\n");
            for (int i = 0; i < t * 2; i += 4)
            {
                int string_size = 25 - emloyfcn[i].size();
                textcolor(12);

                cout << "\t\t\t\t " << so << ".       ";
                textcolor(11);

                cout << emloyfcn[i]; khoan_cach(string_size);
                cout << "\n";

                so++;
            }
            cout << "\t\t\t\tBan muon thay doi thong tin cua ai? ";
            cin >> o;
            if (o > so || o <= 0)
            {
                cout << "Khong co trong danh sach";
                break;
            }
            system("cls");
            int string_size = 25 - emloyfcn[o * 4 - 4].size();
            int string_size1 = 30 - emloyfcn[o * 4 - 3].size();
            int string_size2 = 15 - emloyfcn[o * 4 - 2].size();
            int string_size3 = emloyfcn[o * 4 - 1].size();

            textcolor(12);

            printf(" %-25s %-30s %-15s %-30s \n", "1.Ho va ten", "2.Dia chi", "3.SDT", "4.Email\n");
            textcolor(11);

            cout << " " << emloyfcn[o * 4 - 4]; khoan_cach(string_size);
            cout << emloyfcn[o * 4 - 3]; khoan_cach(string_size1);
            cout << emloyfcn[o * 4 - 2]; khoan_cach(string_size2);
            cout << emloyfcn[o * 4 - 1] << "\n";
            cout << "\t\t\t\tBan muon thay doi thong tin gi? ";
            cin >> o1;
            system("cls");
            if (o1 == 1)
            {
                cout << "\t\tCap nhat ho va ten: ";
                cin >> emloyfcn[o * 4 - 4];
            }
            else if (o1 == 2)
            {
                cout << "\t\tCap nhat dia chi: ";
                cin >> emloyfcn[o * 4 - 3];
            }
            else if (o1 == 3)
            {
                cout << "\t\tCap nhat SDT: ";
                cin >> emloyfcn[o * 4  - 2];
            }
            else if (o1 == 4)
            {
                cout << "\t\tCap nhat Email: ";
                cin >> emloyfcn[o * 4 - 1];
            }
            f.open("thongtin.txt", ios::out);
            for (int i = 0; i < t * 2; i++)
            {
                f << emloyfcn[i] << endl;
            }
            f.close();
            system("cls");
            cout << "\n\n\t\t\tCap nhat thong tin thanh cong !!!";
            Sleep(2000);
            system("cls");
        }
        else if (chon == 5)
        {
        int r = 1;
            system("cls");
            textcolor(12);
             printf("%-5s %-25s %-30s %-15s %-30s \n", "Stt", "Ho va ten", "Dia chi", "SDT", "Email\n");
            for (int i = 0; i < t * 2; i += 4)
            {
                
                    int string_size =25- emloyfcn[i].size();
                    int string_size1 = 30-emloyfcn[i+1].size();
                    int string_size2 = 15-emloyfcn[i+2].size();
                    int string_size3 = emloyfcn[i+3].size();
                     
              
                textcolor(11);
               
               cout << r << "     "; r++;
               cout<< emloyfcn[i]; khoan_cach(string_size);
               cout << emloyfcn[i+1]; khoan_cach(string_size1);
               cout << emloyfcn[i+2]; khoan_cach(string_size2);
               cout << emloyfcn[i+3]<<"\n";
              

            }
            _getch();
            system("cls");
        }
        else
        {
            break;
        }

    }
}

int  menudangnhap(int& cho)
{
    textcolor(12);
    cout << "\n\n\n\t\t\t\t\t*************";
    textcolor(11);
    cout << " XIN CHAO ";
    textcolor(12);
    cout << "*************\n";
    cout << "\t\t\t\t\t 1.";
    textcolor(11);
    cout << "Administrator \n";
    textcolor(12);
    cout << "\t\t\t\t\t 2.";
    textcolor(11);
    cout << "Employees \n";
    cout << "\t\t\t\tChuc vu cua ban la gi? ";
    cin >> cho;
    system("cls");
    return cho;
}
int main()
{
    fstream f1, f2, f3;
    string useramin, useremloy;
    char mkamin[50], mkemloy[50];
    string  aminf[6], emloyf[50], emloyfcn[50];
    int k;
    int t;
    docemloy(emloyf, f1);
    capnhatt(emloyf, t);
    int cho;
    textcolor(12);
    cout << "\n\n\n\t\t\t\t\t*************";
    textcolor(11);
    cout << " XIN CHAO ";
    textcolor(12);
    cout << "*************\n";
    Sleep(1500);
    system("cls");
    textcolor(11);
    docemloycn(emloyfcn, f2);
    while (true)
    {
        menudangnhap(cho);
        if (cho == 1)
        {
            docamin(aminf, f3);
            nhapmkamin(useramin, mkamin, aminf);
            menuamin(emloyf, t, emloyfcn);
            system("cls");
        }
        else if (cho == 2)
        {
            docemloy(emloyf, f1);
            nhapmkemloy(useremloy, mkemloy, emloyf, k, t);
            menuemloy(k, emloyfcn, emloyf);
            system("cls");
        }
        else
        {
            system("cls");
            cout << "\t\t\t\t XIN LOI KHONG CO CHUC VU PHU HOP\n";
        }

    }
}