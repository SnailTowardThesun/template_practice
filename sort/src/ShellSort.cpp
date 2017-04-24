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


#include "ShellSort.h"



CShellSort::CShellSort()
{
}


CShellSort::~CShellSort()
{
}

bool CShellSort::sort()
{
    int N = user_data.size();
    int n = 1;

    while(h < N/3)
    {
        h = 3*h + 1;
    }

    while(h >= 1)
    {
        for (int i = h; i < N; ++i)
        {
            for (int j = i; j >= h && m_data_list[j] < m_data_list[j - h]; j -= h)
            {
                swap(m_data_list[j], m_data_list[j-h]);
            }
        }
    }
    return true;
}

bool CShellSort::print_the_sorted_list()
{
    for (auto i : m_data_list)
    {
        cout << i << " ";
    }
    cout << endl;
    return true;
}

bool CShellSort::get_user_data(vector<long> user_data)
{
    m_data_list = user_data;
}

vector<long> CShellSort::get_sorted_data()
{
    return m_data_list;
}