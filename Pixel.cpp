#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
vector <int> PixVal;


void Numbercatcher(string PixInfline)
{
    stringstream tmp;
    string temp;
    int found;
    tmp << PixInfline;
    while (!tmp.eof())
    {
        tmp >> temp;
        if (stringstream(temp) >> found)
        {
            PixVal.push_back(found);
        }
    }
}



int main()
{
    string line;
    string test;
    int type = 0, width = 0, height = 0;
    fstream file;
    string path = "C:\\Users\\Vanisch\\source\\repos\\Pixel\\letterj.pbm";
    vector <string> PixInf;

    file.open(path, ios::in);
    if (file.good() == true)
    {
        while (!file.eof())
        {
            getline(file, line);
            if (line[0] == '#')
                continue;
            else
                PixInf.push_back(line);
        }
        file.close();
        if (PixInf[0][1] == '1' || PixInf[0][1] == '4')
            type = 1;
        if (PixInf[0][1] == '2' || PixInf[0][1] == '5')
            type = 2;
        if (PixInf[0][1] == '3' || PixInf[0][1] == '6')
            type = 3;
        PixInf.erase(PixInf.begin());
        for (int i = 0;i <= PixInf.size() - 1;i++)
        {
            Numbercatcher(PixInf[i]);
        }
        width = PixVal[0];
        PixVal.erase(PixVal.begin());
        height = PixVal[0];
        PixVal.erase(PixVal.begin());
        cout << type << " " << width << " " << height << endl;
        for (int i = 0;i <= PixVal.size() - 1;i++)
        {
            cout << PixVal[i];
        }

    }
    return(0);
}