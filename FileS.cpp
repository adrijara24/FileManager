#include <iostream>
#include <string>
#include "FileManager.h"

using namespace std;

//Commands:
//cdir =====> Changes current working directory
//gdir =====> Prints current working directory
//mkfile ===> Creates n files with m random characters
//cpyfile ==> Copies a file into a new directory
//cpydir ===> Copies all files into the directory to another directory


int main()
{
    string command;
    FileManager fm(".pepr");

    cout << "Insert a command: ";
    while(cin >> command && command != "END")
    {
        if(command == "cd")
        {
            string s1;
            cin >> s1;
            fm.ChangeDirectory(s1);
        }
        else if (command == "gdir")
        {
            fm.PrintDirectory();
        }
        else if (command == "mkfile")
        {
            int n, size;
            cin >> n >> size;
            fm.CreateFiles(n, size);
        }
        else if (command == "cpfile")
        {
            string s1, s2, s3;
            cin >> s1 >> s2 >> s3;
            cout << fm.CopyFile(s1, s2, s3) << " seconds" << endl;    //fileName, targetFolder, targetFileName
        }
        else if (command == "cpydir")
        {
            string s1;
            cin >> s1;
            cout << fm.CopyFiles(s1) << " seconds" << endl;     //Target directory
        }
        else
        {
            cout << "command not found" << endl;
        }
        
        cout << "Insert a command: ";
    }
}