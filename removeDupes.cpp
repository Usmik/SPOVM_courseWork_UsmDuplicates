#include"removeDupes.h"

void removeDupes::fileDeleting(vector<string>& fileNames)
{
    while(true)
    {
        if(fileNames.empty())
            return;
        cout << "\033[33m" <<"\nEnter the number of duplicate that you want to" 
        << "\033[31m" <<" DELETE:" << "\033[0m" << endl;
        cout << "\033[32m" << "\t[ 0 ] - Skip" << "\033[0m" << endl;
        int i = 1;
        for(string name: fileNames)
            cout << "\t[ " << i++ << " ] - " << name << endl;
        
        choice = correctChoice(0, (int)fileNames.size());
        if(choice == 0)
            return;
        remove(fileNames[choice - 1].c_str());
        cout << endl << "\033[31m" << fileNames[choice - 1] << " was deleted!" << "\033[0m" << endl; 
        fileNames.erase(fileNames.begin() + choice - 1);
    }
}

int removeDupes::correctChoice(int min, int max)
{
    int res;
    while(true)
    {
        cout << "Enter = ";
        cin >> res;
        if(!cin.good() or cin.peek() != '\n')
            {   
                cout << "\033[35m" << "Entered number contain letters or punctuations\n"
                     << "Try again\n" << "\033[0m";
                cin.clear();
                cin.ignore(100, '\n');
                continue;
            }
        if(res > max or res < min)
        {
            cout << "\033[35m" << "Limit has been violated\nTry again\n" << "\033[0m";
            cin.clear();
            cin.ignore(100, '\n');
            continue;
        }
        break;
    }
    return res;
}

removeDupes::removeDupes()
{
}

removeDupes::~removeDupes()
{
}