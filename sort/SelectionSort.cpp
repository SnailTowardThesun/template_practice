#include "SelectionSort.h"



CSelectionSort::CSelectionSort()
{
}


CSelectionSort::~CSelectionSort()
{
}

CSelectionSort::CSelectionSort(vector<long> user_data)
{
    m_data_list = user_data;
}


bool CSelectionSort::sort()
{
    if (m_data_list.size() == 0) return true;
    for (size_t i = 0; i < m_data_list.size(); i++)
    {
        for (size_t j = i; j < m_data_list.size() - 1; j++)
        {
            if (m_data_list[i] > m_data_list[j + 1])
                swap(m_data_list[i], m_data_list[j + 1]);
        }
    }
    return true;
}

bool CSelectionSort::print_the_sorted_list()
{
    if (m_data_list.size() == 0) return false;
    cout << "running selection sort method" << endl;
    sort();

    cout << "the result of sorted list is:" << endl;
    for (auto item : m_data_list)
    {
        cout << item << endl;
    }
    return true;
}

bool CSelectionSort::get_user_data(vector<long> user_data)
{
    m_data_list = user_data;
    return true;
}
