#pragma once

#include "BaseSort.h"

// —°‘Ò≈≈–Ú
class CSelectionSort:CBaseSort
{
public:
    CSelectionSort();
    ~CSelectionSort(); 
    CSelectionSort(vector<long> user_data);
private:
    vector<long> m_data_list;
protected:
    bool sort();
public:
    bool print_the_sorted_list();
    bool get_user_data(vector<long> user_data);
    vector<long> get_sorted_data() { sort(); return m_data_list; };
};

