#pragma once
#include "BaseSort.h"

// ¿ìËÙÅÅĞò
class CQuickSort
{
public:
    CQuickSort();
    CQuickSort(vector<long> user_data);
    ~CQuickSort();
private:
    vector<long> m_data_list;
    bool quick_sort(vector<long>& data, int start, int end);
    int Partition(vector<long>& data, int start, int end);
protected:
    bool sort();
public:
    bool print_the_sorted_list();
    bool get_user_data(vector<long> user_data);
    vector<long> get_sorted_data() { sort(); return m_data_list; };
};

