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

class CStackSort : CBaseSort
{
private:
    vector<long> data_list;
    vector<long> max_head;
    vector<long> min_head;
    enum heapType{
        MAX_HEAP = 0,
        MIN_HEAP
    };
public:
    CStackSort(vector<long> data);
    virtual ~CStackSort();
private:
    virtual bool heap_min_create(vector<long>& data);
    virtual void heap_min_fixdown(vector<long>& data, int pos, int total);
    virtual bool heap_min_sort(vector<long>data, vector<long>& result);

    virtual bool heap_max_create(vector<long>& data);
    virtual void heap_max_fixdown(vector<long>& data, int pos, int total);
    virtual bool heap_max_sort(vector<long>data, vector<long>& result);

    virtual bool heap_sort(vector<long> data, vector<long>& result, heapType type);
protected:
    virtual bool sort();
public:
    virtual bool print_the_sorted_list();
    virtual bool get_user_data(vector<long> user_data);
    virtual vector<long> get_sorted_data();
};
