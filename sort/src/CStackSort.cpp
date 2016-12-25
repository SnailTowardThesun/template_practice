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

#include "CStackSort.h"
using namespace std;

CStackSort::CStackSort(vector<long> data)
{
    data_list = data;
}

CStackSort::~CStackSort()
{

}

bool CStackSort::heap_min_create(vector<long>& data)
{
    bool ret = true;
    if (data.size() == 0)
    {
        cout << "data size is 0." << endl;
        return false;
    }

    int pos = (int) (data.size() / 2 - 1);
    for (; pos >= 0; pos--)
    {
        heap_min_fixdown(data, pos, (int) data.size());
    }

    return ret;
}

void CStackSort::heap_min_fixdown(vector<long>& data, int pos, int total)
{
    int temp = (int) data[pos];
    int j = (int) pos * 2 + 1;
    while (j < total)
    {
        if (j + 1 < total && data[j + 1] < data[j])
        {
            j++;
        }

        if (data[j] >= temp)
        {
            break;
        }

        data[pos] = data[j];
        pos = j;
        j = 2 * pos + 1;
    }
    data[pos] = temp;
}

bool CStackSort::heap_min_sort(vector<long> data, vector<long>& result)
{
    bool ret = true;
    result = data;

    if (!(ret = heap_min_create(result)))
    {
        cout << "create min stack failed." << endl;
        return ret;
    }

    int size = (int) (result.size());
    for (int i = size - 1; i > 0; --i)
    {
        swap(result[i], result[0]);
        heap_min_fixdown(result, 0, i);
    }

    return ret;
}

bool CStackSort::heap_max_create(vector<long>& data)
{
    bool ret = true;

    if (data.size() == 0)
    {
        cout << "data is empty." << endl;
        return false;
    }

    int pos = (int) (data.size() / 2 - 1);
    for (; pos >=0; pos--)
    {
        heap_max_fixdown(data, pos, (int) data.size());
    }

    return ret;
}

void CStackSort::heap_max_fixdown(vector<long>& data, int pos, int total)
{
    int temp = (int) data[pos];
    int j = pos * 2 + 1;
    while (j < total)
    {
        if (j + 1 < total && data[j+1] > data[j])
        {
            j++;
        }

        if (data[j] <= temp)
        {
            break;
        }

        data[pos] = data[j];
        pos = j;
        j = 2 * pos + 1;
    }
    data[pos] = temp;
}

bool CStackSort::heap_max_sort(vector<long> data, vector<long>& result)
{
    bool ret = true;
    result = data;

    if (!(ret = heap_max_create(result)))
    {
        cout<< "create max stack failed." << endl;
        return ret;
    }

    for (int i = (int) (result.size() - 1); i > 0; i--)
    {
        swap(result[i], result[0]);
        heap_max_fixdown(result, 0, i);
    }

    return ret;
}

bool CStackSort::heap_sort(vector<long> data, vector<long>& result, heapType type)
{
    switch(type)
    {
    case MAX_HEAP:
        return heap_max_sort(data, result);
    case MIN_HEAP:
        return heap_min_sort(data, result);
    default:
        cout << "the type is error " << type << endl;
        return false;
    }
}

bool CStackSort::sort()
{
    bool ret = true;
    // max head
    if (!(ret = heap_sort(data_list, max_head, MAX_HEAP)))
    {
        cout << "max head sort failed." << endl;
        return ret;
    }

    // min head
    if (!(ret = heap_sort(data_list, min_head, MIN_HEAP)))
    {
        cout << "min head sort failed." << endl;
        return ret;
    }

    return ret;
}

bool CStackSort::print_the_sorted_list()
{
    if (data_list.empty())
    {
        cout<< "the data is empty" << endl;
        return true;
    }

    if (!sort())
    {
        cout << "sort failed." << endl;
        return false;
    }

    // max head
    cout << "max head" << endl;
    for (auto i : max_head)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "min head" << endl;
    for (auto i : min_head)
    {
        cout << i << " ";
    }
    cout << endl;

    return true;
}

bool CStackSort::get_user_data(vector<long> user_data)
{
    return true;
}

vector<long> CStackSort::get_sorted_data()
{
    vector<long> ret;
    return ret;
}
