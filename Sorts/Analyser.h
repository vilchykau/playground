//
// Created by stas on 11.11.19.
//

#ifndef ANALYSER_H
#define ANALYSER_H

#include <chrono>
#include <ctime>

struct Operations{
    int swap_count = 0;
    int compare_count = 0;

    void Swap(int& a, int& b){
        std::swap(a, b);
        ++swap_count;
    };

    bool CompareL(int& a, int& b){
        compare_count++;
        return a < b;
    }

    bool CompareH(int& a, int& b){
        compare_count++;
        return a > b;
    }
};


long Time(void (*fun)(int*, int , Operations&), int *a, int n, Operations& operations){
    auto start = std::chrono::system_clock::now();
    fun(a, n, operations);
    auto end = std::chrono::system_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

void Analysis(void (*sort)(int*, int , Operations&), int n){
    int* a = new int[n];
    for(int i = 0; i < n; ++i){
        a[i] = std::rand() % 1000;
    }

    Operations operations;
    auto time = Time(sort, a, n, operations);
    std::cout << "Swap count: " << operations.swap_count << '\n'
              << "Compare count: " << operations.compare_count << '\n'
              << "Time: " << time << '\n';

    delete[] a;
}

#endif //PLAYGROUND_ANALYSER_H
