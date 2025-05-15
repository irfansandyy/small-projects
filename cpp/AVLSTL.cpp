#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

typedef __gnu_pbds::tree<int,__gnu_pbds::null_type,std::less<int>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> AVL;

int main() {
    AVL x;
    for (int i = 1 ; i <= 10 ; i += 2) x.insert(i);

    std::cout << "elemen pada index ke 0 adalah : " << *x.find_by_order(0) << std::endl;
    std::cout << "elemen pada index ke 5 adalah : " << *x.find_by_order(5) << std::endl;

    std::cout << "jumlah elemen yang lebih kecil dari 6 sebanyak : " << x.order_of_key(6) << std::endl;
}