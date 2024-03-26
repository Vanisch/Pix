#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    string line;
    int type,width,height;
    fstream file;
    string path = "C:\\Users\\Vanisch\\source\\repos\\Pixel\\letterj.pbm";
    vector <string> PixInf;
    vector <int> PixVal;

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
        type = PixInf[0][1];
        PixInf.erase(PixInf.begin());
        
        for (int i = 0;i <= PixInf.size()-1;i++)
        { 
            type = PixInf[i][1];


        }
    }
    return(0);
}