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


#include "MerageSort.h"
#include "InsertionSort.h"
CMerageSort::CMerageSort()
{
}

CMerageSort::~CMerageSort()
{
}

CMerageSort::CMerageSort(vector<long> user_data)
{
    m_data_list = user_data;
}


bool CMerageSort::sort()
{
    if (m_data_list.size() == 0) return true;
    merage_sort(m_data_list, 0, m_data_list.size() - 1);
    return true;
}

void CMerageSort::merage_sort(vector<long>& data, int lo, int hi)
{
    if (lo >= hi) return;
    if (hi - lo <= ARRAY_LENGTH_WHEN_USING_INSERTION_SORT)
    {
        CInsertionSort::sort_part(data, lo, hi);
        return;
    }
    int mid = lo + (hi - lo)/2;
    merage_sort(data, lo, mid);
    merage_sort(data, mid+1, hi);
    merage_array(data, lo, mid, hi);
}

void CMerageSort::merage_array(vector<long>& array, int lo, int mid, int hi)
{
    //CInsertionSort::sort_part(array, lo, hi);
    int i = lo, j = mid + 1;
    vector<long> aux(hi+1, 0);
    //copy item into array
    for (int k = lo; k <= hi; k++)
    {
        aux[k] = array[k];
    }
    // copy the data into original array
    for (int k = lo; k <= hi; k++)
    {
        // the left is empty copy all right
        if (i > mid)
        {
            array[k] = aux[j++];
        }
        // the right is empty copy all left
        else if (j > hi)
        {
            array[k] = aux[i++];
        }
        // if left less then right, copy left
        else if (aux[i]<aux[j])
        {
            array[k] = aux[i++];
        }
        else
        {
            array[k] = aux[j++];
        }
    }
}

bool CMerageSort::print_the_sorted_list()
{
    if (m_data_list.size() == 0) return false;
    cout << "running merage sort method" << endl;
    sort();

    cout << "the result of sorted list is:" << endl;
    for (auto item : m_data_list)
    {
        cout << item << endl;
    }
    return true;
}

bool CMerageSort::get_user_data(vector<long> user_data)
{
    m_data_list = user_data;
    return true;
}
