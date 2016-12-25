#pragma once
#include "BaseSort.h"
class CInsertionSort : CBaseSort
{
public:
    CInsertionSort();
    CInsertionSort(vector<long> user_data);
    ~CInsertionSort();
private:
    vector<long> m_data_list;
protected:
    bool sort();
public:
    bool print_the_sorted_list();
    bool get_user_data(vector<long> user_data);
    vector<long> get_sorted_data() { sort(); return m_data_list; };
    static bool sort_part(vector<long>& data, int begin, int end);

};

