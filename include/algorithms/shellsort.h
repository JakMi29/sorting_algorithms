#ifndef SORTING_ALGORITHMS_SHELLSORT_H
#define SORTING_ALGORITHMS_SHELLSORT_H

#include <vector>

// sortowanie Shella

template<typename T>
class ShellSort {
public:
    void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end) {
        for (int i = this->size(start, end); i > 0; i = i / 2) {
            for (typename std::vector<T>::iterator it = start + i; it < end; it++) {
                int pom = *it;
                typename std::vector<T>::iterator it2 = it;
                for (; it2 >= start + i && *(it2 - i) > pom; it2 -= i) {
                    *it2 = *(it2 - i);
                }
                *it2 = pom;
            }
        }
    };

    int size(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end) {
        int size = 0;
        for (typename std::vector<T>::iterator it = start; it != end; it++) {
            size++;
        }
        return size;
    }
};

#endif //SORTING_ALGORITHMS_SHELLSORT_H
