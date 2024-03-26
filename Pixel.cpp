#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm> 

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
    int type = 0, width = 0, height = 0, uniq = 0, max =0;
    fstream file;
    string path = "C:\\Users\\Vanisch\\source\\repos\\Pixel\\FEEP.pgm";
    vector <string> PixInf;
    vector <int> PixMax;

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
        if (type == 2 || type == 3)
        {
            PixVal.erase(PixVal.begin());
        }

        vector <int> temp = PixVal;
        sort(temp.begin(), temp.end());
        temp.erase(unique(temp.begin(), temp.end()), temp.end());
        uniq = temp.size();
        if (type == 1|| type==2)
        {
            for (int i = 0; i <= temp.size() - 1;i++)
            {
                PixMax.push_back(temp[i]);
                PixMax.push_back(count(PixVal.begin(), PixVal.end(), temp[i]));

            }
        }
        if (type == 3)
        for (int i = 0;i <= PixMax.size() - 1;i++)
        {
            cout << PixMax[i] << endl;
        }
        return(0);
    }
}