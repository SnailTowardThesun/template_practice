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

/*
 * 有n根甘蔗，每根的每一节都不一样长，存在一个二维数组里
 * 比如[2,4,8]表示这个甘蔗有三节，第一节2cm，第二节4cm.....
 * 最多能同时砍到多少个节的缝隙
 */

#include "cut_sticks.h"
#include <map>

using namespace std;

Cuter::Cuter()
{
}

Cuter::~Cuter()
{
}

int Cuter::max_slice(STICKS stick)
{
    int ret = 0;
    map<int, int> counter;
    for (auto i : stick) {
        auto tmp = 0;
        for (auto j : i ) {
            counter[j + tmp] += 1;
            tmp += j;
        }
    }

    for (auto i : counter) {
        ret = ret < i.second ? i.second : ret;
    }

    return ret;
}
