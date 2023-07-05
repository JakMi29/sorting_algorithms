#ifndef SORTING_ALGORITHMS_MERGESORT_H
#define SORTING_ALGORITHMS_MERGESORT_H

#include <vector>

// sortowanie przez scalanie

template<typename T>
class MergeSort {
public:
    void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end) {

        if (start < end - 1) {
            typename std::vector<T>::iterator middle = start + (end - start) / 2;
            this->sort(start, middle);
            this->sort(middle, end);
            this->merge(start, middle, end);
        }
    };


private:
    void merge(typename std::vector<T>::iterator start, typename std::vector<T>::iterator middle,
               typename std::vector<T>::iterator end) {

        std::vector<T> left(std::make_move_iterator(start), std::make_move_iterator(middle));
        std::vector<T> right(std::make_move_iterator(middle), std::make_move_iterator(end));
        typename std::vector<T>::iterator iter1 = left.begin();
        typename std::vector<T>::iterator iter2 = right.begin();
        typename std::vector<T>::iterator iter3 = start;
        while ((iter1 != left.end()) && (iter2 != right.end())) {

            if (*iter1 <= *iter2) {
                *iter3++ = *iter1++;
            } else {
                *iter3++ = *iter2++;
            }
        }
        while (iter1 != left.end()) {
            *iter3++ = *iter1++;
        }
        while (iter2 != right.end()) {
            *iter3++ = *iter2++;
        }
    }
};

#endif //SORTING_ALGORITHMS_MERGESORT_H
