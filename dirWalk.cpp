#include"dirWalk.h"

void dirWalk::setOptions(int argc, char* argv[])
{
    int rez = 0;
    options = "";
    while((rez = getopt(argc, argv, "hdni")) != -1) {
        switch (rez)
        {
            case 'h': options += "h"; break;
            case 'd': options += "d"; break;
            case 'n': options += "n"; break;
            case 'i': options += "i"; break;
            case '?':cout << "UsmDuplicates [dir] [options]\n"
                          << "Available options:\n-h - Hidden files(started with '.')\n-d - Delete files\n"
                          << "-n - Skip duplicates with same Names\n-i - show additional Information\n";
                          exit(0); break;
        }
    }
}

void dirWalk::setDir(int argc, char* argv[])
{
    if(argc == 1){
        this->directory = ".";
        return;
    }
    for(int i = 1; i < argc; i++)
    {
        if(argv[i][0] != '-')
            {
                this->directory = string(argv[i]);
                return;
            }
    }
    this->directory = ".";        
}


void dirWalk::selectFilesAndHash(string dirName)
{
    DIR* dir = NULL;
    struct dirent* entry = NULL;
    if(!(dir = opendir(dirName.c_str())))
        return;

    while((entry = readdir(dir)))
    {
        string entry_name = entry->d_name;
        
        if(entry_name == "." or entry_name == "..") 
            continue;
        
        string path;
        if(dirName[dirName.length() - 1] == '/')
            path = dirName + entry_name;
        else
            path = dirName + "/" + entry_name;
        
        if(entry->d_type == DT_REG)
            {
                string hashSum = calculateHash.FileHash(path, options);
                if(hashSum != " ")
                    hashsAndNames[hashSum].push_back(path);
            }
        else if(entry->d_type == DT_DIR)
        {
            // if(path == "/sys" or path == "/proc")
            //     continue;
            if(path == "/snap" and this->options.find("h") == string::npos)
                continue;
            if(entry_name[0] == '.' and this->options.find("h") != string::npos)
                selectFilesAndHash(path);
            else if(entry_name[0] != '.')
                selectFilesAndHash(path);
        }
    }
    closedir(dir);
}

void dirWalk::printFiles()
{
    for(pair<string, vector<string>> p: this->hashsAndNames)
    {
        cout << "hash:  " << p.first << endl;
        for(string name: p.second)
            cout << "\tname:  " << name << endl;
    }
    cout << "Size of map: " << hashsAndNames.size() << endl;
}

string dirWalk::getDir()
{
    return this->directory;
}

string dirWalk::getOpt()
{
    return this->options;
}

int dirWalk::getMapSize()
{
    return this->hashsAndNames.size();
}

dirWalk::dirWalk(){}

dirWalk::~dirWalk(){}