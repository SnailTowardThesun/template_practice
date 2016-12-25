#include "InsertionSort.h"



CInsertionSort::CInsertionSort()
{
}


CInsertionSort::~CInsertionSort()
{
}

CInsertionSort::CInsertionSort(vector<long> user_data)
{
    m_data_list = user_data;
}


bool CInsertionSort::sort()
{
    if (m_data_list.size() == 0) return true;
    
    for (size_t i = 1; i < m_data_list.size(); i++)
    {
        for (size_t j = i; j > 0; j--)
        {
            if (m_data_list[j] < m_data_list[j - 1])
                swap(m_data_list[j], m_data_list[j - 1]);
        }
    }
    return true;
}

bool CInsertionSort::print_the_sorted_list()
{
    if (m_data_list.size() == 0) return false;
    cout << "running insertion sort method" << endl;
    sort();

    cout << "the result of sorted list is:" << endl;
    for (auto item : m_data_list)
    {
        cout << item << endl;
    }
    return true;
}

bool CInsertionSort::get_user_data(vector<long> user_data)
{
    m_data_list = user_data;
    return true;
}


bool CInsertionSort::sort_part(vector<long>& data, int begin, int end)
{
    if (data.size() == 0) return false;
    for (int i = begin + 1; i <= end; i++)
    {
        for (int j = i; j > begin; j--)
        {
            if (data[j] < data[j - 1])
                swap(data[j], data[j - 1]);
        }
    }
    return true;
}
