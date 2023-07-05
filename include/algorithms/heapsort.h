#ifndef SORTING_ALGORITHMS_HEAPSORT_H
#define SORTING_ALGORITHMS_HEAPSORT_H

#include <vector>

template<typename T>
class Heap {
private:
    typename std::vector<T>::iterator start;
    typename std::vector<T>::iterator end;

public:
    Heap(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end) {
        this->start = start;
        this->end = end;
        int size = this->size();
        typename std::vector<T>::iterator lastParent = start + size / 2 - 1;
        for (typename std::vector<T>::iterator parent = lastParent; parent >= start; parent--) {
            heapify(parent);
        }
    }

    void removeMax();

    std::size_t size();

    bool empty();

    T &operator[](int index);

    void heapify(typename std::vector<T>::iterator root);
};

template<typename T>
void Heap<T>::removeMax() {

    T pom=*start;
    *start=*(end-1);
    *(end-1)=pom;
    end--;
    typename std::vector<T>::iterator lastParent = start + size() / 2 - 1;
    for (typename std::vector<T>::iterator parent = lastParent; parent >= start; --parent) {
        heapify(parent);
    }
}

template<typename T>
std::size_t Heap<T>::size() {
    return this->end - this->start;
}

template<typename T>
bool Heap<T>::empty() {
    if (this->end - this->start == 0)
        return true;
    return false;
}

template<typename T>
T &Heap<T>::operator[](int index) {
    static T t;
    if(index<0 || index>end-start){
        std::cout<<"Wrong index"<<std::endl;
        return t;
    }
    t=*(start+index-1);
    return t;
}

template<typename T>
void Heap<T>::heapify(typename std::vector<T>::iterator root) {
    int parent = root-start;
    typename std::vector<T>::iterator leftChild = start +2 * parent + 1;
    typename std::vector<T>::iterator rightChild = start +2 * parent + 2;

    typename std::vector<T>::iterator rootValue = root;
    if (leftChild < end && *leftChild > *rootValue) {
        rootValue = leftChild;
    }
    if (rightChild < end && *rightChild > *rootValue) {
        rootValue =rightChild;
    }

    if (rootValue != root) {
        T pom = *root;
        *root = *rootValue;
        *rootValue = pom;
        heapify(rootValue);
    }

}

// sortowanie przez kopcowanie

template<typename T>
class HeapSort {
public:
    void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end) {
        Heap<T> heap(start, end);

        while (heap.size() != 0) {
            heap.removeMax();
        }
    };
};

#endif //SORTING_ALGORITHMS_HEAPSORT_H
