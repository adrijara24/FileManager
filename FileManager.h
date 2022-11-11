#include <string>

using namespace std;

class FileManager
{
    string GetDirectory() const;
    string extension;
public:
    FileManager(const string &ext = ".txt");

    //Changes the current directory
    void ChangeDirectory(const string &relPath);

    //Prints the current directory
    void PrintDirectory() const;

    //Creates n files of the desired size on the current directory
    void CreateFiles(int n, unsigned long int size);

    //Copies a single file into the desired folder
    double CopyFile(const string &fileName, const string &newPath, const string &newFileName);

    //Copies all files inside the current folder
    double CopyFiles(const string &newPath);
};