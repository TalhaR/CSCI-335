#include <iostream>
#include <vector>

template<typename Iterator, typename object>
Iterator my_find(Iterator start, Iterator end, const object& x) {
    for(Iterator itr = start; i < end; ++itr) {
        if (itr = x) {
            return itr;
        }
    }
    return end;
}

int main() {
    std::vector<int> vec{1, 2, 3, 4, 5};
    
    std::vector<int>::iterator itr;
    
    my_find(vec.begin(), vec.end(), 4);
}