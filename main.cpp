#include"calcHashMD5.h"
#include"dirWalk.h"
#include"hashAnalyze.h"

#include<chrono>

int main(int argc, char* argv[])
{
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();

    dirWalk dirs;
    dirs.setDir(argc, argv);
    dirs.setOptions(argc, argv);
    
    cout << "\033[36m" << "\nUsmDuplicates starts calculation...\n" 
         << "directory:\t" << dirs.getDir() << "\033[0m" <<endl;
    
    dirs.selectFilesAndHash(dirs.getDir());
    if(dirs.getOpt().find("i") != string::npos)
        cout << "\033[33m" << "Amount of unique elements:"
             << dirs.getMapSize() << endl;
    

    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    if(dirs.getOpt().find("i") != string::npos)
        cout << "Time difference = " 
             << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << "[ms]" << "\033[0m" << endl;
    
    hashAnalyze analyze;
    if(dirs.getOpt().find("d") == string::npos)
        analyze.show_dupes(&dirs);
    else
        analyze.prepare_to_delete(&dirs);
        
}
