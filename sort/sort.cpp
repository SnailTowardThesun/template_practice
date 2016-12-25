#include "common.h"
// the entrance of program
vector<long> data_for_test = { 9,6,8,7,3,4,5,1,2,10 };
int main(void)
{
    cout<<"run sort test"<<endl;

    // bubble sort
    CBubbleSort* pBubble = new CBubbleSort(data_for_test);
    //pBubble->print_the_sorted_list();
    delete pBubble;

    // selection sort
    CSelectionSort* pSelection = new CSelectionSort(data_for_test);
    //pSelection->print_the_sorted_list();
    delete pSelection;

    // insertion sort
    CInsertionSort* pInsertion = new CInsertionSort(data_for_test);
    //pInsertion->print_the_sorted_list();
    delete pInsertion;

    CMerageSort* pMerage = new CMerageSort(data_for_test);
    //pMerage->print_the_sorted_list();
    delete pMerage;

    CQuickSort* pQuick = new CQuickSort(data_for_test);
    pQuick->print_the_sorted_list();
    delete pQuick;

    getchar();
    return 0;
}
