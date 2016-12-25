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
    //��Ԫ�ؿ���������������
    for (int k = lo; k <= hi; k++)
    {
        aux[k] = array[k];
    }
    //Ȼ���չ������ݴӸ��������п�����ԭʼ��array��
    for (int k = lo; k <= hi; k++)
    {
        //������Ԫ��û�ˣ� ֱ�ӽ��ұߵ�ʣ��Ԫ�ض��ϲ�����ԭ������
        if (i > mid)
        {
            array[k] = aux[j++];
        }//����ұ�Ԫ��û���ˣ�ֱ�ӽ��������ʣ��Ԫ�ض��ϲ���ԭ������
        else if (j > hi)
        {
            array[k] = aux[i++];
        }//�������ұ�С������ߵ�Ԫ�ؿ�����ԭ������
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
