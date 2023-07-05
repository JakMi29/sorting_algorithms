#ifndef SORTING_ALGORITHMS_BUBBLESORT_H
#define SORTING_ALGORITHMS_BUBBLESORT_H

#include <vector>

// sortowanie bąbelkowe

template<typename T>
class BubbleSort {
public:
    void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end) {

        for (typename std::vector<T>::iterator it1 = start; it1 != end; it1++) {
            for (typename std::vector<T>::iterator it2 = start; it2 != end; it2++) {
                if(*it1<*it2)
                {
                    T pom=*it1;
                    *it1=*it2;
                    *it2=pom;
                }
            }
        }
    };
};

#endif //SORTING_ALGORITHMS_BUBBLESORT_H
