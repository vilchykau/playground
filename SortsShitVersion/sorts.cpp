

#ifndef SORTS_CPP
#define SORTS_CPP


#include <utility>

void DSelectSort(int* a, int n, int& count_compare, int& count_swap){
    int start = 0;
    int end = n-1;
    int min_;
    int max_;
    while(end - start > 1){
        min_ = start;
        max_ = start;

        for(int i = start; i <= end; ++i){
            if(++count_compare && a[i] < a[min_]){
                min_ = i;
            }else if(++count_compare && a[i] > a[max_]){
                max_ = i;
            }
        }

        std::swap(a[start], a[min_]); count_swap++;
        std::swap(a[end], a[max_]); count_swap++;

        --end;
        ++start;
    }
}

void BrushSort(int* a, int n, int& count_compare, int& count_swap){
    int gap = n;
    bool flag = true;
    while ((gap > 1) || flag) {
        gap = (gap * 10) / 13;
        if (gap < 1)
            gap = 1;
        flag = false;
        for (int i = 0; i < n - gap; i++) {
            if (++count_compare && a[i] > a[i + gap]) {
                std::swap(a[i], a[i + gap]); ++count_swap;
                flag = true;
            }
        }
    }
}
#endif

