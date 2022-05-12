#include"hashAnalyze.h"

void hashAnalyze::show_dupes(dirWalk* classWithMap)
{
    int dupes_flag = 0;
    for(pair<string, vector<string>> p: classWithMap->hashsAndNames)
    {
        if(p.second.size() > 1 and classWithMap->options.find("n") != string::npos)
        {
            dupes_flag = 1;
            check_names(p.second);
            if(similarHash.size() <= 1)
                continue;
            cout << "\033[31m" << "Duplicates:\n" << "\033[0m";
            for(string name: similarHash)
                cout << "\t" << name << endl;
            pressAnyKey();
        }
        else if(p.second.size() > 1)
        {
            dupes_flag = 1;
            cout << "\033[31m" << "Duplicates:\n" << "\033[0m";
            for(string name: p.second)
                cout << "\t" << name << endl;
            pressAnyKey();
        }
    }

    if(!dupes_flag)
        cout << "\033[33m" << "No duplicates was founded" << "\033[0m" << endl;
    else
        cout << "\033[32m" << "You've been seen all duplicates" << "\033[0m" << endl << endl;
}


void hashAnalyze::check_names(vector<string>& vect_w_names)
{
    if(!this->similarHash.empty())
        similarHash.clear();
    set<string> uniq_names;
    for(string name: vect_w_names)
    {
        size_t last_slash = name.rfind("/");
        if(last_slash == string::npos or last_slash == (name.length() - 1))
            continue;
        string only_name = name.substr(++last_slash);
        if(uniq_names.find(only_name) == uniq_names.end())
        {
            uniq_names.insert(only_name);
            similarHash.push_back(name);
        } 
    }
}


void hashAnalyze::prepare_to_delete(dirWalk* classWithMap)
{
    int dupes_flag = 0;
    for(pair<string, vector<string>> p: classWithMap->hashsAndNames)
    {
        if(p.second.size() > 1 and classWithMap->options.find("n") != string::npos)
        {
            dupes_flag = 1;
            check_names(p.second);
            if(similarHash.size() <= 1)
                continue;
            removing.fileDeleting(similarHash);
        }
        else if(p.second.size() > 1)
        {
            dupes_flag = 1;
            removing.fileDeleting(p.second);
        }
    }

    if(!dupes_flag)
        cout << "\033[33m" << "No duplicates was founded" << "\033[0m" << endl;
    else
        cout << "\033[32m" << "You've processed all duplicates" << "\033[0m" << endl << endl;
}


void hashAnalyze::pressAnyKey()
{
    static struct termios oldt, newt;
    cout << "\033[35m" <<"Press key to continue..." << "\033[0m"<< endl;
    tcgetattr( STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO );      

    tcsetattr( STDIN_FILENO, TCSANOW, &newt);
    getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt);
}


hashAnalyze::hashAnalyze(){}

hashAnalyze::~hashAnalyze(){}