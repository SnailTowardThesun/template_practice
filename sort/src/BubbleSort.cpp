/*
MIT License

Copyright (c) 2016 ME_Kun_Han

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/


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
