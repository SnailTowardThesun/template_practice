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

