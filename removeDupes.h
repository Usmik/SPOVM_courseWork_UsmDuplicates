#pragma once
#include<iostream>
#include<vector>

using namespace std;

class removeDupes
{
private:
    int choice;
public:
    void fileDeleting(vector<string>& fileNames);
    int correctChoice(int min, int max);
    removeDupes();
    ~removeDupes();
};

