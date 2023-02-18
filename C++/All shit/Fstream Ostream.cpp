#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void printFile(string path)
{
    ifstream file(path);
    string line;
    if (file)
    {
        while (getline(file, line))
        {
            cout << line << endl;
        }
    }
}
void printInFile(string opath, string ipath)
{
    ifstream ifile(ipath);
    ofstream ofile(opath);
    string line;
    if (ifile)
    {
        while (getline(ifile, line))
        {
            ofile << line << endl;
        }
    }
}

int main()
{
    string path = "input.txt";
    string pathout = "output.txt";
    printFile(path);
    printInFile(pathout, path);
    return 0;
}