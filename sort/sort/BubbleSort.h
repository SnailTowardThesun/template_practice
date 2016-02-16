#pragma once
#include "BaseSort.h"

// ц╟ещеепР
class CBubbleSort : CBaseSort
{
public:
	CBubbleSort();
	CBubbleSort(vector<long> user_data);
	~CBubbleSort();
private:
	vector<long> m_data_list;
protected:
	bool sort();
public:
	bool print_the_sorted_list();
	bool get_user_data(vector<long> user_data);
	vector<long> get_sorted_data() { sort(); return m_data_list; };
};

