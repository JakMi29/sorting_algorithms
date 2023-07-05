#ifndef SORTING_ALGORITHMS_INTROSORT_H
#define SORTING_ALGORITHMS_INTROSORT_H
#include <vector>
#include <math.h>

// sortowanie introspektywne

template <typename T>
class IntroSort {
public:
    void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end) {
        int maxDepth = log((end - start)) * 2;
        introSort(start, end, maxDepth);
    };

    void introSort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end, int max_depth) {
        int size = end - start;
        if (size <= 1)
            return;
        if (size < 16) {
            InsertSort<T> insertSort;
            insertSort.sort(start, end);
            return;
        }
        if (max_depth == 0) {

            HeapSort<T> heapSort;
            heapSort.sort(start, end);
            return;
        } else {
            typename std::vector<T>::iterator pivot = partition(start, end);
            introSort(start, pivot, max_depth - 1);
            introSort(pivot, end, max_depth - 1);
        }

    }


    typename std::vector<T>::iterator
    partition(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end) {
         start + (end - start) / 2;
        typename std::vector<T>::iterator pivot = start + (end - start) / 2;;
        T pivotValue = *pivot;

        typename std::vector<T>::iterator left = start;
        typename std::vector<T>::iterator right = end - 1;

        while (left <= right) {
            while (*left < pivotValue) {
                left++;
            }
            while (*right > pivotValue) {
                right--;
            }
            if (left <= right) {
                T pom = *left;
                *left = *right;
                *right = pom;
                left++;
                right--;
            }
        }
        return right;
    }
};
#endif //SORTING_ALGORITHMS_INTROSORT_H
