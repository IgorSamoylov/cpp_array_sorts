#pragma once

#include "ARRAY_SORTS.h"

template<class Iter>
void merge_sort_inplace(Iter first, Iter last)
{
    if (1 < last - first) {
        Iter middle = first + (last - first) / 2;
        merge_sort_inplace(first, middle);
        merge_sort_inplace(middle, last);
        std::inplace_merge(first, middle, last);
    }
}


template <typename T>
void merge_sort(std::vector<T>& array) {
    if (1 < array.size()) {
        std::vector<T> array1(array.begin(), array.begin() + array.size() / 2);
        merge_sort(array1);
        std::vector<T> array2(array.begin() + array.size() / 2, array.end());
        merge_sort(array2);
        
        merge(array1.begin(), array1.end(),
            array2.begin(), array2.end(), array.begin());
    }
}


template <typename T>
void merge_sort_iterative_prim_t(T* v, size_t size) {
    T* buffer = new T[size];
    // step_increment means half of each processing group in each traversal
    for (size_t step_increment = 1; step_increment <= size / 2; step_increment *= 2) {

        
        for (size_t i = 0; i < size; i += step_increment << 1) {

            size_t begin_index = i;
            size_t middle_index = i + step_increment;
            size_t end_index = middle_index + step_increment;
            size_t buffer_iter = 0;

            //Merging
            while (begin_index < i + step_increment
                && middle_index < end_index
                && middle_index < size) {

                if (v[begin_index] <= v[middle_index])
                    buffer[buffer_iter++] = v[begin_index++];
                else buffer[buffer_iter++] = v[middle_index++];
            }
            // Appending tails
            while(begin_index < i + step_increment) 
                buffer[buffer_iter++] = v[begin_index++];
            while (middle_index < end_index
                && middle_index < size)
                buffer[buffer_iter++] = v[middle_index++];
        }
        // Simple assign the source pointer to the buffer array
        v = buffer;  
    }
    delete[] buffer;
}

