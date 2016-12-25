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


#include "QuickSort.h"
using namespace std;

CQuickSort::CQuickSort(vector<long> user_data)
{
    m_data_list = user_data;
}

CQuickSort::~CQuickSort()
{
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
        int q = Partition(array, start, end); // divide into two parts
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
    swap(data[i], data[start]);
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
