//
// Created by stas on 11.11.19.
//

#include <iostream>
#include <cstring>

#include "sorts.cpp"
#include "data_generation.cpp"
#include "data_saver.cpp"
#include "analyse.cpp"

int ReadArraySize(){
    int n;
    std::cout << "Укажите размер массива: ";
    std::cin >> n;
    return n;
}

int ReadGenerateType(){
    int n;
    std::cout << "Укажите способ ввода 1)Консоль, 2)Файл(input.txt), 3)Случайно: ";
    std::cin >> n;
    return n;
}

void GenerateArray(int *a ,int type, int size){
    switch (type){
        case 1:
            FillFromConsole(a, size);
            break;
        case 2:
            FillFromFile(a, size);
            break;
        case 3:
            FillRandom(a, size);
            break;
    }
}

int main(){
    setlocale(LC_ALL, "Russian");

    int array_size = ReadArraySize();
    int generate_type = ReadGenerateType();

    int *a1 = new int[array_size];
    int *a2 = new int[array_size];
    GenerateArray(a1, generate_type, array_size);
    memcpy(a2, a1, sizeof(int) * array_size);

    std::cout << "Сортировка расчёской: \n";
    Analysis(&BrushSort, a1, array_size);
    std::cout << "\n\n";

    std::cout << "Сортировка выбором: \n";
    Analysis(&DSelectSort, a2, array_size);
    std::cout << "\n\n";

    SaveResult(a1, array_size, "brush_out.txt");
    SaveResult(a2, array_size, "select_out.txt");
}