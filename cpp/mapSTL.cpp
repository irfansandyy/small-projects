#include <iostream>
#include <map>

int main() {
    std::map<int,int> map_int_int;
    std::map<int,std::string> map_int_string;
    std::map<std::string,int> map_string_int;

    for (int i = 1 ; i <= 5 ; i++) {
        map_int_int[i] = i * 5;
    }

    map_int_string[1] = "satu";
    map_int_string[2] = "dua";
    map_int_string[3] = "tiga";

    for (std::map<int,std::string>::iterator it = map_int_string.begin() ; it != map_int_string.end() ; ++it) {
        std::pair<int,std::string> cur = *it;
        map_string_int[cur.second] = cur.first;
    }    

    std::cout << "ukuran map_int_string : " << map_int_string.size() << std::endl;
    map_int_string.clear();
    std::cout << "ukuran map_int_string setelah diclear : " << map_int_string.size() << std::endl;

    for (int i = 1 ; i <= 7 ; i++) {
        if (map_int_int.count(i))
            std::cout << "elemen dengan key " << i << " ada di dalam map" << std::endl;
        else
            std::cout << "elemen dengan key " << i << " tidak ada di dalam map" << std::endl; 
    }
}