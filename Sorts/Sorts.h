#ifndef SORTS_H
#define SORTS_H

#include "Analyser.h"

void DSelectSort(int* a, int n, Operations& operations){
    int start = 0;
    int end = n-1;
    int min_;
    int max_;
    while(end - start > 1){
        min_ = start;
        max_ = start;

        for(int i = start; i <= end; ++i){
            if(operations.CompareL(a[i], a[min_])){
                min_ = i;
            }else if(operations.CompareH(a[i], a[max_])){
                max_ = i;
            }
        }

        operations.Swap(a[start], a[min_]);
        operations.Swap(a[end], a[max_]);

        --end;
        ++start;
    }
}

void BrushSort(int* a, int n, Operations& operations){
    int gap = n;
    bool flag = true;
    while ((gap > 1) || flag) {
        gap = (gap * 10) / 13;
        if (gap < 1)
            gap = 1;
        flag = false;
        for (int i = 0; i < n - gap; i++) {
            if (operations.CompareH(a[i], a[i + gap])) {
                operations.Swap(a[i], a[i + gap]);
                flag = true;
            }
        }
    }
}
#endif
