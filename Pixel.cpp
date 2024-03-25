#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
    string linia;
    fstream plik;
    string path = "C:\\Users\\Vanisch\\source\\repos\\Pixel\\letterj.pbm";

    plik.open(path, ios::in);
    if (plik.good() == true)
    {
        while (!plik.eof())
        {
            getline(plik, linia);
            cout << linia << endl;
        }
        plik.close();
    }

    system("PAUSE");
    return(0);
}