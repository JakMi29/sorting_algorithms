#ifndef SORTING_ALGORITHMS_QUICKSORT_H
#define SORTING_ALGORITHMS_QUICKSORT_H

#include <vector>

// quicksort

template<typename T>
class QuickSort {
public:

    void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end) {
        int size=end-start;
        if(size<2)
            return;
        T pivot = *(start+size/2);
        typename std::vector<T>::iterator iter1 = start;
        typename std::vector<T>::iterator iter2 = end-1;

        while (iter1 <= iter2) {
            while (*iter1 < pivot)
                iter1++;
            while (*iter2 > pivot)
                iter2--;
            if(iter1<=iter2) {
                T pom = *iter1;
                *iter1 = *iter2;
                *iter2 = pom;
                iter1++;
                iter2--;
            }
        }
        this->sort(start,iter2+1);
        this->sort(iter1,end);
    }
};

#endif //SORTING_ALGORITHMS_QUICKSORT_H
