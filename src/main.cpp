#include <iostream>
#include<vector>
#include<algorithm>
#include "algorithms/mergesort.h"
#include "algorithms/quicksort.h"
#include "algorithms/insertsort.h"
#include "algorithms/heapsort.h"
#include "algorithms/insertsort.h"
#include "algorithms/bubblesort.h"
#include "algorithms/introsort.h"
#include <chrono>
#include <map>
#include <variant>
#include <iomanip>

std::vector<int> createRandomVector(int size) {
    std::vector<int> vector(size);
    for (int i = 0; i < size; i++)
        vector[i] = rand();
    return vector;
}

void sortVector(std::vector<int>::iterator start, std::vector<int>::iterator end, double sortPercentage) {
    if (sortPercentage == -1) {
        std::sort(start, end, std::greater<int>());
        return;
    }
    int size=(int) ((end-start) * sortPercentage / 100);
    auto iter = start + size;
    std::sort(start, iter);
}

std::vector<int> copyVectorAsNew(const std::vector<int> &vector) {
    std::vector<int> newVector(vector.size());

    std::copy(vector.begin(), vector.end(), newVector.begin());

    return newVector;
}

void checkIfVectorIsSortCorrectly(typename std::vector<int>::iterator start, typename std::vector<int>::iterator end) {
    while (start+1 != end) {
        if (*start > *(start + 1)) {
            std::cout << "Vector is not sorted correctly" << std::endl;
            return;
        }
        start++;
    }
    std::cout << "Vector is sorted correctly" << std::endl;
}
void checkAllVisually(){
    std::vector<int> vector = createRandomVector(10);
    InsertSort<int> insertSort;
    std::cout<<"###INSERTSORT BEFORE###"<<std::endl;
    for (const auto &item: vector) {
        std::cout<<item<<" ";
    }
    std::cout<<std::endl;
    insertSort.sort(vector.begin(),vector.end());
    std::cout<<"###INSERTSORT AFTER###"<<std::endl;
    for (const auto &item: vector) {
        std::cout<<item<<" ";
    }
    std::cout<<std::endl;

    vector = createRandomVector(10);
    HeapSort<int> heapSort;
    std::cout<<"###HEAPSORT BEFORE###"<<std::endl;
    for (const auto &item: vector) {
        std::cout<<item<<" ";
    }
    std::cout<<std::endl;
    heapSort.sort(vector.begin(),vector.end());
    std::cout<<"###HEAPSORT AFTER###"<<std::endl;
    for (const auto &item: vector) {
        std::cout<<item<<" ";
    }
    std::cout<<std::endl;

    vector = createRandomVector(10);
    QuickSort<int> quickSort;
    std::cout<<"###QUICKSORT BEFORE###"<<std::endl;
    for (const auto &item: vector) {
        std::cout<<item<<" ";
    }
    std::cout<<std::endl;
    quickSort.sort(vector.begin(),vector.end());
    std::cout<<"###QUICKSORT AFTER###"<<std::endl;
    for (const auto &item: vector) {
        std::cout<<item<<" ";
    }
    std::cout<<std::endl;

    vector = createRandomVector(10);
    MergeSort<int> mergeSort;
    std::cout<<"###MERGESORT BEFORE###"<<std::endl;
    for (const auto &item: vector) {
        std::cout<<item<<" ";
    }
    std::cout<<std::endl;
    mergeSort.sort(vector.begin(),vector.end());
    std::cout<<"###MERGESORT AFTER###"<<std::endl;
    for (const auto &item: vector) {
        std::cout<<item<<" ";
    }
    std::cout<<std::endl;


    vector = createRandomVector(10);
    IntroSort<int> introSort;
    std::cout<<"###INTROSORT BEFORE###"<<std::endl;
    for (const auto &item: vector) {
        std::cout<<item<<" ";
    }
    std::cout<<std::endl;
    introSort.sort(vector.begin(),vector.end());
    std::cout<<"###INTROESORT AFTER###"<<std::endl;
    for (const auto &item: vector) {
        std::cout<<item<<" ";
    }
    std::cout<<std::endl;

}
    void checkPercentSortFunction(){
    std::vector<int> vector = createRandomVector(20);
    std::cout<<"###VECTOR SORTED IN 0% BEFORE###"<<std::endl;
        for (const auto &item: vector) {
            std::cout<<item<<" ";
        }
        std::cout<<std::endl;
        sortVector(vector.begin(),vector.end(),0);
        std::cout<<"###VECTOR SORTED IN 0% AFTER###"<<std::endl;
        for (const auto &item: vector) {
            std::cout<<item<<" ";
        }
        std::cout<<std::endl;
        vector = createRandomVector(20);
        std::cout<<"###VECTOR SORTED IN 25% BEFORE###"<<std::endl;
        for (const auto &item: vector) {
            std::cout<<item<<" ";
        }
        std::cout<<std::endl;
        sortVector(vector.begin(),vector.end(),25);
        std::cout<<"###VECTOR SORTED IN 25% AFTER###"<<std::endl;
        for (const auto &item: vector) {
            std::cout<<item<<" ";
        }
        std::cout<<std::endl;
        vector= createRandomVector(20);
        std::cout<<"###VECTOR SORTED IN 50% BEFORE###"<<std::endl;
        for (const auto &item: vector) {
            std::cout<<item<<" ";
        }
        std::cout<<std::endl;
        sortVector(vector.begin(),vector.end(),50);
        std::cout<<"###VECTOR SORTED IN 50% AFTER###"<<std::endl;
        for (const auto &item: vector) {
            std::cout<<item<<" ";
        }
        std::cout<<std::endl;

        vector= createRandomVector(20);
        std::cout<<"###VECTOR SORTED IN 75% BEFORE###"<<std::endl;
        for (const auto &item: vector) {
            std::cout<<item<<" ";
        }
        std::cout<<std::endl;
        sortVector(vector.begin(),vector.end(),75);
        std::cout<<"###VECTOR SORTED IN 75% AFTER###"<<std::endl;
        for (const auto &item: vector) {
            std::cout<<item<<" ";
        }
        std::cout<<std::endl;


        vector= createRandomVector(20);
        std::cout<<"###VECTOR SORTED IN 95% BEFORE###"<<std::endl;
        for (const auto &item: vector) {
            std::cout<<item<<" ";
        }
        std::cout<<std::endl;
        sortVector(vector.begin(),vector.end(),95);
        std::cout<<"###VECTOR SORTED IN 95% AFTER###"<<std::endl;
        for (const auto &item: vector) {
            std::cout<<item<<" ";
        }
        std::cout<<std::endl;

        vector= createRandomVector(20);
        std::cout<<"###VECTOR SORTED IN 99% BEFORE###"<<std::endl;
        for (const auto &item: vector) {
            std::cout<<item<<" ";
        }
        std::cout<<std::endl;
        sortVector(vector.begin(),vector.end(),99);
        std::cout<<"###VECTOR SORTED IN 99% AFTER###"<<std::endl;
        for (const auto &item: vector) {
            std::cout<<item<<" ";
        }
        std::cout<<std::endl;



        vector= createRandomVector(10);
        std::cout<<"###VECTOR SORTED IN 99,7% BEFORE###"<<std::endl;
        for (const auto &item: vector) {
            std::cout<<item<<" ";
        }
        std::cout<<std::endl;
        sortVector(vector.begin(),vector.end(),99.7);
        std::cout<<"###VECTOR SORTED IN 99,7% AFTER###"<<std::endl;
        for (const auto &item: vector) {
            std::cout<<item<<" ";
        }
        std::cout<<std::endl;

        vector= createRandomVector(20);
        std::cout<<"###VECTOR SORTED IN 100% BEFORE###"<<std::endl;
        for (const auto &item: vector) {
            std::cout<<item<<" ";
        }
        std::cout<<std::endl;
        sortVector(vector.begin(),vector.end(),100);
        std::cout<<"###VECTOR SORTED IN 100% AFTER###"<<std::endl;
        for (const auto &item: vector) {
            std::cout<<item<<" ";
        }
        std::cout<<std::endl;

        vector= createRandomVector(20);
        std::cout<<"###VECTOR SORTED REVERSE BEFORE###"<<std::endl;
        for (const auto &item: vector) {
            std::cout<<item<<" ";
        }
        std::cout<<std::endl;
        sortVector(vector.begin(),vector.end(),-1);
        std::cout<<"###VECTOR SORTED REVERSE AFTER###"<<std::endl;
        for (const auto &item: vector) {
            std::cout<<item<<" ";
        }
        std::cout<<std::endl;

}
void checkAllWithAuxiliaryFunction(){
    std::vector<int> vector = createRandomVector(10000);
    InsertSort<int> insertSort;
    insertSort.sort(vector.begin(),vector.end());
    std::cout<<"###INSERTSORT###"<<std::endl;
    checkIfVectorIsSortCorrectly(vector.begin(),vector.end());

    vector = createRandomVector(10000);
    QuickSort<int> quickSort;
    quickSort.sort(vector.begin(),vector.end());
    std::cout<<"###QUICKSORT###"<<std::endl;
    checkIfVectorIsSortCorrectly(vector.begin(),vector.end());

    vector = createRandomVector(10000);
    MergeSort<int> mergeSort;
    mergeSort.sort(vector.begin(),vector.end());
    std::cout<<"###MERGESORT###"<<std::endl;
    checkIfVectorIsSortCorrectly(vector.begin(),vector.end());

    vector = createRandomVector(10000);
    HeapSort<int> heapSort;
    heapSort.sort(vector.begin(),vector.end());
    std::cout<<"###HEAPSORT###"<<std::endl;
    checkIfVectorIsSortCorrectly(vector.begin(),vector.end());

    vector = createRandomVector(10000);
    IntroSort<int> introSort;
    heapSort.sort(vector.begin(),vector.end());
    std::cout<<"###INTROSORT###"<<std::endl;
    checkIfVectorIsSortCorrectly(vector.begin(),vector.end());


}

int main(int argc, char *argv[]) {
  std::vector<int> originalTableOfVectors[100];
     std::vector<int> tableOfVectorsToSort[100];
     double percents[] = {50};
     int size[] = {10000,50000,100000,500000,1000000};

     for (const auto &size1: size) {

         for (auto &tableOfVector: originalTableOfVectors) {
             tableOfVector = createRandomVector(size1);
         }

         IntroSort<int> bubbleSort;

         for (const auto &percent: percents) {

             for (int i = 0; i < 100; i++) {
                 tableOfVectorsToSort[i] = copyVectorAsNew(originalTableOfVectors[i]);
                 sortVector(tableOfVectorsToSort[i].begin(), tableOfVectorsToSort[i].end(), percent);
             }

             auto start = clock();
             for (auto &i: tableOfVectorsToSort) {
                 bubbleSort.sort(i.begin(), i.end());
             }
             auto stop = clock();


             auto duration = (double) (stop - start) / (double) CLOCKS_PER_SEC;
             std::string s = "in: " + ((percent == -1.0) ? "reverse order" : std::to_string(percent) + "%");
             std::cout << "Intro Sort time: " << std::fixed << duration << std::setprecision(8) << "s "
                       << "vector size: " << size1 << " sorted " << s << std::endl;
         }
         }
     /*for (const auto &size1: size) {

         for (auto &tableOfVector: originalTableOfVectors) {
             tableOfVector = createRandomVector(size1);
         }
         QuickSort<int> bubbleSort;

         for (const auto &percent: percents) {

             for(int i=0;i<100;i++){
                 tableOfVectorsToSort[i]= copyVectorAsNew(originalTableOfVectors[i]);
                 sortVector(tableOfVectorsToSort[i], percent);
             }

             auto start = clock();
             for(auto & i : tableOfVectorsToSort){
                 bubbleSort.sort(i.begin(), i.end());
             }
             auto stop = clock();

             auto duration = (double) (stop - start) / (double) CLOCKS_PER_SEC;
             std::string s="in: " + ((percent==-1.0) ? "reverse order" : std::to_string(percent)+"%");
             std::cout << "Quick sort time: " << std::fixed << duration << std::setprecision(8) << "s "
                       << "vector size: " << size1 << " sorted " << s <<std::endl;
         }
     }*/

    return 0;
}
