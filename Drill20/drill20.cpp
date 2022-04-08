#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <list>
#include <array>
#include <string>

template <typename C>
//Kiiratásnál segitség: 
void print_contents(const C&c){
    for(auto& a : c)
        std::cout << a << " ";
    std :: cout << std :: endl;
}
//Megnöveli a számot annyival
template<typename C>
void inc(C& c, int n){
    for(auto& a : c){
        a+=n;
    }
}
template<typename Iter1, typename Iter2>
// requires Input_iterator<Iter1>() && Output_iterator<Iter2>()
Iter2 copyy(Iter1 f1, Iter1 e1, Iter2 f2){
    for(Iter1 p = f1; p!=e1;++p){
        *f2++ = *p;
        //f2++;
    }
    return f2;
}

int main () 
try
{
   
    constexpr int size = 10;

    int arr [size];
    for(int i = 0; i< size; i++) arr[i] = i;

    std::array<int, size> ai;
    std::copy(arr, arr + size, ai.begin());

    std::vector<int> vi(size);
    std::copy(arr, arr + size, vi.begin());

    std::list<int> li(size);
    std::copy(arr, arr + size, li.begin());
	std::cout << "Array: " <<std::endl;
    print_contents(ai);
    std::cout << "Vector: " <<std::endl;
    print_contents(vi);
    std::cout << "List: " <<std::endl;
    print_contents(li);

    std::array<int, size> ai2 = ai;
    std::vector<int> vi2=vi;

    std::list<int>li2=li;
	std::cout << "Copy array: " <<std::endl;
    print_contents(ai2);
    std::cout << "Copy vector: " <<std::endl;
    print_contents(vi2);
    std::cout << "Copy list: " <<std::endl;
    print_contents(li2);

    inc(ai2, 2);
    inc(vi2, 3);
    inc(li2, 5);

    print_contents(ai2);
    print_contents(vi2);
    print_contents(li2);

    copyy(ai2.begin(), ai2.end(), vi2.begin());
    copyy(li2.begin(), li2.end(), ai2.begin());
    std::cout<<"copy" <<std:: endl;
    print_contents(ai2);
    print_contents(vi2);
    print_contents(li2);

    std::vector<int>::iterator vit;
    vit = std::find(vi2.begin(),vi2.end(), 3);
    if (vit != vi2.end()){
        std::cout << "Found at: " << std::distance(vi2.begin(), vit) << std::endl;
    } else{
        std ::cout << "Not found" << std::endl;
    }
    

}
catch(std::exception& e){
    std::cerr <<"Unknown exception\n";
    return 2;
}
catch(...) {
    std::cerr<<"Unknown exception\n";
    return 2;
}
