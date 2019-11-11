//
// Created by stas on 11.11.19.
//

#include <iostream>
#include <random>

void DSelectSort(int* a, int start, int end){
    while(end - start > 1){
        int min_ = start;
        int max_ = start;

        for(int i = start; i <= end; ++i){
            if(a[i] < a[min_]){
                min_ = i;
            }else if(a[i] > a[max_]){
                max_ = i;
            }
        }

        std::swap(a[start], a[min_]);
        std::swap(a[end], a[max_]);

        --end;
        ++start;
    }
}

int main(){
    int* a = new int[20];
    for(int i = 0; i < 20; ++i){
        a[i] = std::rand() % 100;
    }

    DSelectSort(a, 0, 19);

    for(int i = 0; i < 20; ++i){
        std::cout << a[i] << ' ';
    }
}