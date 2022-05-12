#pragma once

#include<iostream>
#include<string>
#include<openssl/md5.h>
#include<fstream>

using namespace std;


class calcHashMD5
{
private:
    ifstream::pos_type fileSize;
    char *memBlock;
    string hashSum;
    unsigned char md5res[MD5_DIGEST_LENGTH];

public:
    calcHashMD5();
    ~calcHashMD5();
    void hashToString();
    string FileHash(string file_name, string options);
};
