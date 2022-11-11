#include "FileManager.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <filesystem>
#include <fstream>
#include <chrono>

namespace fs = std::filesystem;

FileManager::FileManager(const string &ext)
{
    fs::current_path(fs::path("./"));
    srand(time(NULL));
    extension = ext;
}

string FileManager::GetDirectory() const
{
    return fs::current_path().string();
}

void FileManager::ChangeDirectory(const string &relDir)
{
    string newPath = (fs::current_path() / fs::path(relDir)).string();
    if(fs::is_directory(fs::path(newPath)))
        fs::current_path(fs::path(newPath));
    else
        cout << "error: path is not a directory" << endl;
}

void FileManager::PrintDirectory() const
{
    cout << GetDirectory() << endl;
}

void FileManager::CreateFiles(int n, unsigned long int size)
{
    for(int i = 0; i < n; ++i)
    {
        string fileName = GetDirectory() + "/" + "file_num_" + to_string(i + 1) + extension;
        cout << fileName << endl;
        std::ofstream file(fileName);
        if(!file.is_open())
        {
            cout << "file already exists" << endl;
            fs::remove(fs::path(GetDirectory() + "/" + fileName));
            file = std::ofstream(fileName);
        }

        unsigned long int objSize = size;

        const unsigned long int MaxStringSize = 200;
        const string characters = " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
        int chSize = characters.size();
        cout << objSize << endl;
        while(objSize > 0)
        {
            unsigned long int size = min(objSize, MaxStringSize);
            string s = string(size, ' ');
            for(int j = 0; j < size; ++j)
            {
                s[j] = rand() % chSize;
            }
            file << s;

            objSize -= size;
        }
        cout << "File " << to_string(i + 1) << " created" << endl;

        file.close();
    }
    
    cout << "All files created" << endl;
}

double FileManager::CopyFile(const string &fileName, const string &newPath, const string &newFileName)
{
    fs::path from, to;
    from = fs::path(GetDirectory() + "\\" + fileName);
    if(fs::is_directory(from))
    {
        cout << "error: input path is a directory" << endl;
        return -1.0;
    }
    to = fs::path(GetDirectory() / fs::path(newPath));
    to = fs::path(to / newFileName);
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    //calculate time
    bool res = fs::copy_file(from, to);
    //stop calculating time
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> time = end - start;
    

    if(res)
        cout << "File copied" << endl;
    else
        cout << "File could not be copied" << endl;
    return time.count();
}

double FileManager::CopyFiles(const string &newPath)
{
    fs::path to = fs::path(GetDirectory() / fs::path(newPath));
    if(fs::exists(to))
    {
        cout << "error: input path exists" << endl;
        return -1.0;
    }

    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    //calculate time
    fs::copy(fs::current_path().string(), to.string());
    //stop calculating time
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> time = end - start;
    return time.count();
}