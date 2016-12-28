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

#include "common.h"
#include "kmp.h"

kmp::kmp(std::string buf1, std::string buf2)
{
    origin = buf2;
    find_buffer = buf1;
}

kmp::~kmp()
{

}

int kmp::do_kmp(vector<int> next)
{
    int pos = 0;

    if (origin.empty() || find_buffer.empty()) {
        return pos;
    }

    int j = 0;
    for (int i = 0; i < find_buffer.size(); ++i) {
        while (j > 0 && find_buffer[i] != origin[j]) {
            j = next[j];
        }
        if (find_buffer[i] == origin[j]) {
            j++;
        }
        if (j == origin.size()) {
            return i - j + 2;
        }
    }
    return pos;
}

vector<int> kmp::next()
{
    int len= (int) origin.length();
    int j=0;

    int *next=new int[len+1] {0};

    for(int i=1; i < len; i++)
    {
        while(j > 0 && origin[i] != origin[j]) {
            j=next[j];
        }

        if(origin[i]==origin[j]) {
            j++;
        }

        next[i+1]=j;
    }

    vector<int> list;
    for (int i = 0; i < len+1; ++i) {
        list.push_back(next[i]);
    }
    delete[] next;

    return list;
}

void kmp::print_result()
{
    int ret = 0;
    if ((ret = do_kmp(next())) == 0) {
        cout << "do kmp failed" << endl;
        return;
    }

    cout << "print the result of kmp" << endl;
    cout << "buff1: " << origin << endl;
    cout << "buff2: " << find_buffer << endl;
    cout << "the position is " << ret << endl;
}