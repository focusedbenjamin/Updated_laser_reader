#include <iostream>
#include <new>

int main(){
    try {
        int* Array= new int[100000000000];
        std::cout << "Tried Successfully\n";
    } catch (std::bad_alloc& e) {
    std::cerr << "bad_alloc caught: "<< e.what() << '\n';
    }
    return 0;

}