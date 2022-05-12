#include"calcHashMD5.h"


string calcHashMD5::FileHash(string file_name, string options)
{
    ifstream file(file_name, ios::ate);

    if(!file.is_open()){
        if(options.find("i") != string::npos)
            cout << "Unnable to open\t" << file_name << endl;
        return " ";
    }

    fileSize = file.tellg();
    memBlock = new char[fileSize];

    file.seekg(0, ios::beg);
    file.read(memBlock, fileSize);
    file.close();

    MD5((unsigned char*) memBlock, fileSize, md5res);
    free(memBlock);

    hashToString();

    if(options.find("i") != string::npos)
    {
        cout << "File size: \t" << fileSize << endl 
             << "File name: \t" << file_name << endl
             << "File hash: \t" << hashSum << endl;
    }

    return hashSum;
}

void calcHashMD5::hashToString()
{
    if(!hashSum.empty())
        hashSum.clear();
    
    char bufHash[3];
    
    for(int i = 0; i < MD5_DIGEST_LENGTH; i++)
    {
        sprintf(bufHash, "%02x", md5res[i]);
        hashSum += bufHash[0];
        hashSum += bufHash[1];
    }
}


calcHashMD5::calcHashMD5(){}

calcHashMD5::~calcHashMD5(){}
