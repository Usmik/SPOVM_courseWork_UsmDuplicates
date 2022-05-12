#pragma once

#include<string>
#include<dirent.h>
#include<unistd.h>
#include<iostream>
#include<map>
#include<vector>

using namespace std;

#include"calcHashMD5.h"

class hashAnalyze;

class dirWalk
{
private:
    string directory;
    string options;
    map<string, vector<string>> hashsAndNames;
    calcHashMD5 calculateHash;
    
    friend class hashAnalyze;
public:
    void printFiles();
    void selectFilesAndHash(string dirName);
    string getDir();
    string getOpt();
    int getMapSize();
    void setOptions(int argc, char* argv[]);
    void setDir(int argc, char* argv[]);
    dirWalk();
    ~dirWalk();
};


