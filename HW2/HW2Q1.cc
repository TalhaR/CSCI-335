/**
 * @author Talha Rahman
 *  Class: CSCI-335
 *  Program descrption: this is a global function that returns
 *  an iterator to an object x, if it exists within the bounds 
 *  of start and end. Else if the element is not found then it 
 *  will return end.
 */

template<typename Iterator, typename object>
Iterator my_find(Iterator start, Iterator end, const object& x) {
    for(Iterator itr = start; itr < end; ++itr) {
        if (*itr == x) {
            return itr;
        }
    }
    return end;
}