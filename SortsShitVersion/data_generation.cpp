#ifndef DATA_GENERATION_CPP
#define DATA_GENERATION_CPP

#include <iostream>
#include <fstream>
#include <random>
#include <ctime>

void FillFromFile(int* a, int n){
    std::ifstream file("input.txt");
    for(int i = 0; i < n; ++i){
        file >> a[i];
    }
    file.close();
}

void FillRandom(int* a, int n){
    std::srand(std::time(nullptr));
    for(int i = 0; i < n; ++i){
        a[i] = rand() % 100000;
    }
}

void FillFromConsole(int *a, int n){
    for(int i = 0; i < n; ++i){
        std::cin >> a[i];
    }
}

#endif