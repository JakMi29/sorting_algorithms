#ifndef SORTING_ALGORITHMS_INSERTSORT_H
#define SORTING_ALGORITHMS_INSERTSORT_H
#include <vector>

// sortowanie przez wstawianie

template <typename T>
class InsertSort
{
public:
    void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end)
    {
        for (typename std::vector<T>::iterator it1=start;it1!=end;it1++) {
            T value=*it1;
            typename std::vector<T>::iterator it2=it1-1;
            while(it2>=start&&*it2>value) {
                *(it2+1) = *it2;
                it2--;
            }
            *(it2+1)=value;
        }

    };
};

#endif //SORTING_ALGORITHMS_INSERTSORT_H
