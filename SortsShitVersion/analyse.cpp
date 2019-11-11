#ifndef ANALYSE_CPP
#define ANALYSE_CPP

#include <chrono>
#include <ctime>

void Analysis(void (*sort)(int* a, int n, int& count_compare, int& count_swap), int*array, int n){
    int count_compare = 0;
    int count_swap = 0;

    auto start = std::chrono::system_clock::now();
    sort(array, n, count_compare, count_swap);
    auto end = std::chrono::system_clock::now();
    auto delta_millis = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    std::cout << "Сортировка выполнелась за " << delta_millis << "мс\n"
              << "Количесво сравнений: " << count_compare << '\n'
              << "Количество перстановок: " << count_swap << '\n';

}

#endif