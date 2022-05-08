#include <iostream>
#include <vector>

#include "include/persegipanjang.hpp"

using namespace std;

void PrintPP(persegipanjang& pp)
{
    cout << "X Pusat    : " << pp.GetXpusat() << "   ";
    cout << "Y Pusat    : " << pp.GetYpusat() << endl;
    cout << "Panjang    : " << pp.Getpanjang() << "      ";
    cout << "Lebar      : " << pp.Getlebar() << endl;
    cout << "X Min      : " << pp.GetXmin() << "    ";
    cout << "X Max      : " << pp.GetXmax() << endl;
    cout << "Y Min      : " << pp.GetYmin() << "    ";
    cout << "Y Max      : " << pp.GetYmax() << endl;
}

int main()
{
    int Xpusat, Ypusat, panjang, lebar ;

    system("CLS||clear") ;

    cout << "Persegi Panjang 1" << endl;

    cout << endl << "Titik Tengah X : ";
    cin >> Xpusat ;
    cout << endl << "Titik Tengah Y : ";
    cin >> Ypusat ;
    cout << endl << "Panjang        : ";
    cin >> panjang ;
    cout << endl << "Lebar          : ";
    cin >> lebar ;

    persegipanjang pp1(Xpusat, Ypusat, panjang, lebar) ;

    system("CLS||clear");

    cout << "Persegi Panjang 2" << endl;

    cout << endl << "Titik Tengah X     : ";
    cin >> Xpusat ;
    cout << endl << "Titik Tengah Y     : ";
    cin >> Ypusat ;
    cout << endl << "Panjang            : ";
    cin >> panjang ;
    cout << endl << "Lebar              : ";
    cin >> lebar ;

    persegipanjang pp2(Xpusat, Ypusat, panjang, lebar) ;

    while(1)
    {
        system("CLS||clear");

        cout << "Persegi Panjang 1" << endl;
        PrintPP(pp1);
        cout << endl;
        cout << "Persegi Panjang 2" << endl;
        PrintPP(pp2);

        cout << endl;
        cout << "Operasi: " << endl;
        cout << "1. +" << endl;
        cout << "2. -" << endl;
        cout << "3. ==" << endl;
        cout << "4. ++" << endl;
        cout << "5. --" << endl;
        cout << "6. []" << endl;
        cout << "0. Keluar" << endl;
        cout << endl << "-> ";

        int input;
        string blank;
        cin >> input;
        cin.ignore();

        switch (input)
        {
        case 1:
        {
            system("CLS||clear");

            if(!(pp1 == pp2)) {
                cout << "Persegi Panjang yang Tidak Beririsan";
                cin.ignore();
                break;
            }

            persegipanjang pp3 = pp1 + pp2;
            
            cout << "Persegi Panjang yang Baru" << endl;
            PrintPP(pp3);

            cin.ignore();
            break;
        }

        case 2:
        {
            system("CLS||clear");

            if(!(pp1 == pp2)) {
                cout << "Persegi Panjang yang Tidak Beririsan";
                cin.ignore();
                break;
            }

            persegipanjang pp3 = pp1 - pp2;
            
            cout << "Persegi Panjang yang Baru" << endl;
            PrintPP(pp3);

            cin.ignore();
            break;
        }
        
        case 3:
        {
            system("CLS||clear");
            cout << "Apakah Persegi Panjangnya termasuk Beririsan?" << endl;
            cout << (pp1 == pp2 ? "Ya" : "Tidak");

            cin.ignore();
            break;
        }

        case 4:
        {
            pp1++;
            pp2++;

            break;
        }

        case 5:
        {
            pp1--;
            pp2--;

            break;
        }

        case 6:
        {
            system("CLS||clear");

            cout << "Persegi Panjang 1" << endl;
            cout << "[0] " << pp1[0] << "   ";
            cout << "[1] " << pp1[1] << "   ";
            cout << "[2] " << pp1[2] << "   ";
            cout << "[3] " << pp1[3] << "   ";

            cout << endl << endl;

            cout << "Persegi Panjang 2" << endl;
            cout << "[0] " << pp2[0] << "   ";
            cout << "[1] " << pp2[1] << "   ";
            cout << "[2] " << pp2[2] << "   ";
            cout << "[3] " << pp2[3] << "   ";

            cin.ignore();
            break;
        }

        case 0:
            return 0;
        
        default:
            break;
        }

    }

    return 0;
}