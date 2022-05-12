#pragma once

#include<vector>
#include<string>
#include<termios.h>
#include<set>

#include"dirWalk.h"
#include"removeDupes.h"

using namespace std;


class hashAnalyze
{
private:
    vector<string> similarHash;
    removeDupes removing;
public:
    void check_names(vector<string>& vect_w_names);
    void show_dupes(dirWalk* classWithMap);
    void prepare_to_delete(dirWalk* classWithMap);
    void pressAnyKey();
    hashAnalyze();
    ~hashAnalyze();
};

