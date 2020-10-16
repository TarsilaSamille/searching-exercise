/*
 */

#include <iostream>
#include "../include/searching.h"

namespace sa {
    /*!
     * Performs a **linear search** for `value` in `[first;last)` and returns a pointer to the location of the first occurrence of `value` in the range `[first,last]`, or `last` if no such element is found.
     * \param first Pointer to the begining of the data range.
     * \param last Pointer just past the last element of the data range.
     * \param value The value we are looking for.
     */
    value_type * lsearch( value_type * first, value_type * last, value_type value )
    {
        // TODO: Insert here your solution for the linear search problem.
        while(first != last && *first != value)
            first++;
        return first;
    }

    /*!
     * Performs a **binary search** for `value` in `[first;last)` and returns a pointer to the location of `value` in the range `[first,last]`, or `last` if no such element is found.
     * \note The range **must** be sorted.
     * \param first Pointer to the begining of the data range.
     * \param last Pointer just past the last element of the data range.
     * \param value The value we are looking for.
     */
    value_type * bsearch( value_type * first, value_type * last, value_type value )
    {
        // TODO: Insert here your solution for the binary search problem.
        if(*(first)  > value)
            return last; 
        if (*(last - 1) >= *(first)) { 
            value_type index = (last - first)/2;
            value_type * mid = (first + index) ; 

            if (*(mid) == value) 
                return mid; 
            
            if (*(mid) > value && mid != first){
                value_type * result = bsearch(first, mid - 1, value);
                return (*(result) != value && result < last && first <= result) ?
                    last : result;
            }
            if (mid != last) 
                return bsearch(mid + 1, last, value); 
        }
        return last; 
    }



    /*!
     * Returns a pointer to the first element in the range `[first, last)` that is _not less_  than (i.e. greater or equal to) `value`, or `last` if no such element is found.
     * \note The range **must** be sorted.
     * \param first Pointer to the begining of the data range.
     * \param last Pointer just past the last element of the data range.
     * \param value The value we are looking for.
     */
    value_type * lbound( value_type * first, value_type * last, value_type value )
    {
        // TODO: Insert here your solution for the lower bound problem.

        value_type * position = bsearch(first, last, value);

        if(position != last && *(position) != value )
            return lbound(first, last, value + (value_type)1); 

        if(*(position-1) >= value && position-1 <= last && first <= position-1)
           return lbound(first, position-1, value); 

        return position; 

    }

    /*!
     * Returns a pointer to the first element in the range `[first, last)` that is _greater_  than `value`, or `last` if no such element is found.
     * \note The range **must** be sorted.
     * \param first Pointer to the begining of the data range.
     * \param last Pointer just past the last element of the data range.
     * \param value The value we are looking for.
     */
    value_type * ubound( value_type * first, value_type * last, value_type value )
    {
        value_type * position = bsearch(first, last, value);

        if(*(position+1) == value && position+1 <= last && first <= position+1)
           return ubound(position+1, last, value) ; 
        return position;
    }

    
}

