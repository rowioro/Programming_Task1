#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

const int n = 4;

struct SStudent
{
    string imie;
    double ocena;
};

int main()
{
    SStudent A[n][n];
    string nazwa_plk;
    double suma, suma_k;
    int licz_stud, licz_k = 0;

    cout << "Podaj nazwe pliku: ";
    cin >> nazwa_plk;
    ifstream plik(nazwa_plk.c_str());
    if (!plik.good())
    {
        cout << "Nie ma takiego pliku!";
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            plik >> A[i][j].imie >> A[i][j].ocena;
    }
    plik.close();

    cout << "Drukujemy tablice z danymi: " << endl;
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(5) << A[i][j].imie << setw(5) << A[i][j].ocena << '\t';
        cout << endl;
    }

    suma = 0;
    licz_stud = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= i - 1; j++)
            if (A[i][j].imie[A[i][j].imie.size() - 1] == 'a' || A[i][j].imie[A[i][j].imie.size() - 1] == 'k')
            {
                if (A[i][j].ocena >= 3)
                {
                    suma += A[i][j].ocena;
                }
                licz_stud++;
            }
    }
    cout << endl;
    cout << "Srednia ocen wybranych studentow = " << suma / licz_stud << endl;

    for (int j = 0; j < n; j++)
    {
        suma_k = 0;
        for (int i = 0; i < n; i++)
        {
            suma_k += A[i][j].ocena;
        }
        if (suma_k / n > suma / licz_stud)
            licz_k++;
    }
    cout << endl;
    cout << "Wszystkich kolumn w tablicy ze srednia wieksza jest: " << licz_k << endl;

    cout << endl;
    system("PAUSE");
    return 0;
}
