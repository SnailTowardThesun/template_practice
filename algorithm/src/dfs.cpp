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

#include "dfs.h"
#include "common.h"
#include "stdlib.h"
using namespace std;

dfs::dfs(int d)
{
    depth = d;
    for (int i = 0; i < 10; i++)
    {
        num[i] = visit[i] = 0;
    }
}

dfs::~dfs()
{

}

void dfs::do_dfs(int d)
{
    for (int i = 1; i <= depth; ++i)
    {
        if (visit[i] == 0)
        {
            visit[i] = 1;
            num[d] = i;
            if (d == depth)
            {
                for (int n = 1; n <= depth; ++n)
                {
                    cout << num[n] << " ";
                }
                cout << endl;
            }
            else
            {
                do_dfs(d + 1);
            }
            visit[i] = 0;
        }
    }
}

void dfs::print_result()
{
    cout << "ready to output permutation, depth=" << depth << endl;
    do_dfs(1);
}
