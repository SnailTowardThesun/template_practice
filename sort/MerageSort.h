#pragma once
#include "BaseSort.h"
// ∫œ≤¢≈≈–Ú
class CMerageSort : CBaseSort
{
public:
    CMerageSort();
    CMerageSort(vector<long> user_data);
    ~CMerageSort();
private:
    const int ARRAY_LENGTH_WHEN_USING_INSERTION_SORT = 3;
    vector<long> m_data_list;
    void merage_sort(vector<long>& data, int lo, int high);
    void merage_array(vector<long>& data, int lo, int mid, int hi);
protected:
    bool sort();
public:
    bool print_the_sorted_list();
    bool get_user_data(vector<long> user_data);
    vector<long> get_sorted_data() { sort(); return m_data_list; };
};

