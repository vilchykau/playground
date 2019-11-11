#ifndef DATA_SAVER_CPP
#define DATA_SAVER_CPP

#include <fstream>
#include <string>

void SaveResult(int *a, int n, const std::string& file_name){
    std::ofstream file(file_name);
    for(int i = 0; i < n; ++i){
        file << a[i] << ' ';
    }
    file.close();
}

#endif