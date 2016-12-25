#include "QuickSort.h"



CQuickSort::CQuickSort()
{
}


CQuickSort::~CQuickSort()
{
}

CQuickSort::CQuickSort(vector<long> user_data)
{
    m_data_list = user_data;
}


bool CQuickSort::sort()
{
    if (m_data_list.size() == 0) return true;
    quick_sort(m_data_list, 0, m_data_list.size()-1);
    return true;
}

bool CQuickSort::quick_sort(vector<long>& array, int start, int end)
{
    if (start < end) {
        int q = Partition(array, start, end); //分割成两部分  
        quick_sort(array, start, q - 1);
        quick_sort(array, q + 1, end);
    }
    return true;
}

int CQuickSort::Partition(vector<long>& data, int start, int end)
{
    long x = data[start];
    int i = start;
    for (int j = start + 1; j <= end; j++) {
        if (data[j] <= x) {
            i++;
            swap(data[i], data[j]);
        }
    }
    swap(data[i], data[start]); //把基准的值放在中间，则左边都小于他，右边都大于他 
    return i;
}

bool CQuickSort::print_the_sorted_list()
{
    if (m_data_list.size() == 0) return false;
    cout << "running quick sort method" << endl;
    sort();

    cout << "the result of sorted list is:" << endl;
    for (auto item : m_data_list)
    {
        cout << item << endl;
    }
    return true;
}

bool CQuickSort::get_user_data(vector<long> user_data)
{
    m_data_list = user_data;
    return true;
}
