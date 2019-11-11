//
// Created by stas on 11.11.19.
//

#include <iostream>
#include <random>

#include "Sorts.h"
#include "Analyser.h"

int main(){
    constexpr int n = 10000;

    Analysis(&DSelectSort, n);
    std::cout << "\n";
    Analysis(&BrushSort, n);
}