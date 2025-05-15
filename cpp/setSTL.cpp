#include <iostream>
#include <set>

int main() {
    std::set<int> mySet;

    for (int i = 1 ; i <= 10 ; i++) {
        for (int j = 1 ; j <= 10 ; j++)
            mySet.insert(i);
    }

    std::cout << "ukuran set sekarang : " << mySet.size() << std::endl;
    std::cout << "elemen - elemen di dalam set : ";
    for (std::set<int>::iterator it = mySet.begin() ; it != mySet.end() ; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    for (int i = 7 ; i <= 12 ; i++) {
        if (mySet.count(i)) std::cout << i << " ada di dalam set" << std::endl;
        else std::cout << i << " tidak ada di dalam set" << std::endl;
    }

    std::set<int>::iterator lo,hi;
    mySet.erase(5);
    lo = mySet.lower_bound(4);
    hi = mySet.upper_bound(4);
}