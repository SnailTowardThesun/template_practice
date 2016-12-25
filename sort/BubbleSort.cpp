#include "BubbleSort.h"

CBubbleSort::CBubbleSort()
{
}

CBubbleSort::CBubbleSort(vector<long> user_data)
{
    m_data_list = user_data;
}

CBubbleSort::~CBubbleSort()
{
}

bool CBubbleSort::sort()
{
    if (m_data_list.size() == 0) return true;
    for (size_t i = 0; i < m_data_list.size(); i++)
    {
        for (size_t j = 0; j < m_data_list.size()-1; j++)
        {
            if (m_data_list[j] > m_data_list[j+1]) 
                swap(m_data_list[j], m_data_list[j+1]);
        }
    }
    return true;
}

bool CBubbleSort::print_the_sorted_list()
{
    if (m_data_list.size() == 0) return false;
    cout << "running bubble sort method" << endl;
    sort();

    cout << "the result of sorted list is:" << endl;
    for(auto item : m_data_list)
    {
        cout << item << endl;
    }
    return true;
}

bool CBubbleSort::get_user_data(vector<long> user_data)
{
    m_data_list = user_data;
    return true;
}
