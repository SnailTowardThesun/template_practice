#include "BaseSort.h"

bool CBaseSort::swap(long& previous, long& next)
{
    long temp = previous;
    previous = next;
    next = temp;
    return true;
}
