#include <iostream>

using namespace std;

int main() {
    // Const us a compile time constraint that an object cannot be modified

    const int i = 96;
    // i = 69; This will not compile

    const int *p1 = new int(22); // This means the value pointed to is constant not the pointer itself

    int* const p2 = (int* const)p1; // Pointer is constant, the datais not

    const int* const p3 = p2; // Both data and pointer are constant

    int const *p4 = &i;
    const int *p5 = &i;
    // both are same

    // If const is on the left of *, data is constant 
    // If const is on the right of *, pointer is constant 

    // Const can be casted / casted away
    const_cast<int&>(i) = 69; // removes const
    // i = 29; Still invalid

    int j = 11;
    const int &k = static_cast<const int&>(j); // creates a const int reference to j
    // k = 12; Invalid

    /*
        Why use const
        -> Guards against inadvertent write to the variable
        -> Self Documenting
        -> Enables compiler to optimize
        -> const variables can be put to ROM
    */
}