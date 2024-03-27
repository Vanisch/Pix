#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <stdio.h>


using namespace std;
vector <int> PixVal;                                          //Vector with all pixel Value


void Numbercatcher(string PixInfline)                         //Tool for changing string to int.
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


unsigned long CRGB(int r, int g, int b)                       //Tool to change RGB valoues to binary number.
{
    return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}


int main()
{
    start:
    string line,test,path,answer;
    int type = 0, width = 0, height = 0, uniq = 0,notuniq = 0, max = 0,x=0;
    fstream file;
    vector <string> PixInf;                                   //Vector with all data from file.
    vector <int> PixMax;                                      //Vecotr with
    vector <int> temp;                                        //Vector to store unique Values and it size define how much unique colors the image have.


    PixInf.clear(),PixMax.clear(),PixVal.clear(),temp.clear(),line.clear(), test.clear(), path.clear(), answer.clear(); // Cleaning before a new program run.
                                                              //User give his path to the file he wants to check.
    cout << "Input path to your image.(Remember to use double backslash!!): ";


    file.open(path, ios::in);
    if (file.good() == true)
    {
        while (!file.eof())                                  //Getting data from file.
        {
            getline(file, line);
            if (line[0] == '#')
                continue;
            else
                PixInf.push_back(line);
        }
        file.close();

        
        if (PixInf[0][1] == '1' || PixInf[0][1] == '4')     //Reading type of image.
            type = 1;
        if (PixInf[0][1] == '2' || PixInf[0][1] == '5')
            type = 2;
        if (PixInf[0][1] == '3' || PixInf[0][1] == '6')
            type = 3;
        PixInf.erase(PixInf.begin());

            
        for (int i = 0;i <= PixInf.size() - 1;i++)         //Converting string values to int.
        {
            Numbercatcher(PixInf[i]);
        }

        
        width = PixVal[0];                                //Saving width and height.
        PixVal.erase(PixVal.begin());
        height = PixVal[0];
        PixVal.erase(PixVal.begin());


        if (type == 2 || type == 3)                       //Eresing depth value from values of colors.
        {
            PixVal.erase(PixVal.begin());
        }

        
        if (type == 3)                                   //Converting RGB values to one number.
        {
            for (int i = 0;i <= (PixVal.size() / 3) - 1;i++)
            {
                temp.push_back(CRGB(PixVal[x], PixVal[x + 1], PixVal[x + 2]));
                x = x + 3;
            }
            PixVal = temp;
        }


        temp = PixVal;                                  //Getting how much unique colors we have.
        sort(temp.begin(), temp.end());
        temp.erase(unique(temp.begin(), temp.end()), temp.end());
        uniq = temp.size();


        for (int i = 0; i <= temp.size() - 1;i++)      //Counting the number of diffrenet colored pixels and storing data in vector with format [unique color,number of pixels in this color,unique color(1),number of pixels in this color(1)]
        {;
            PixMax.push_back(temp[i]);
            PixMax.push_back(count(PixVal.begin(), PixVal.end(), temp[i]));

        }


        x = 0;                                        //Checking which color is most common.
        for (int i = 0; i <= (PixMax.size() / 2) - 1;i++)
        {
            if (PixMax[x + 1] > max)
            {
                max = PixMax[x + 1];
                notuniq = PixMax[x];
            }
            x = x + 2;
        }

                                                     //Give user the answers.
        cout << "Width= " << width << " pixels." << endl << "Height= " << height << " pixels." << endl << "The most common color is: " << hex << notuniq << dec << " and it appears " << max << " times." << endl << "Total numebr of unique colors is: " << uniq << "." << endl;
        
        
        while (true)                                //Loop for repeating or ending program.
        {
            cout << "Do you want to load differen image?. (Y/N): " ;
            cin >> answer;
            if (answer == "Y")
            {
                goto start;
            }
            if (answer == "N")
            {
                cout << "Thanks for using my program :D";
                return 0;
            }
            cout << "!! Write correct response !!"<<endl;
        }

    }
    else
        cout << "Invalid path!!";
    return(404);
}