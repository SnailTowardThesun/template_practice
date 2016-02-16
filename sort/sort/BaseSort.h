#pragma once
// this is the base sort 
// try to use template,but now just ignore the template
#include <vector>
#include <iostream>
using namespace std;
class CBaseSort
{
public:
	CBaseSort() {};
	virtual ~CBaseSort() {};
protected:
	virtual bool sort() = 0;
	static bool swap(long& previous, long& next);
public:
	virtual bool print_the_sorted_list() = 0;
	virtual bool get_user_data(vector<long> user_data) = 0;
	virtual vector<long> get_sorted_data() = 0;
};

