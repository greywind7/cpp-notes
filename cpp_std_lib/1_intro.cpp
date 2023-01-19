#include <iostream>

// Templates are used to reduce code redundancy for different data types
// function templates can infer type, but class templates; you must specify type

// function template
template <typename T>
T cube (T x) {
    return x*x*x;
}

// class template
template <typename T>
class circ {
    public:
    T radius;
    float area;

    void setArea() {
        area = 3.14 * radius * radius;
    }

    circ(T rad) {
        radius = rad;
        setArea();
    }

    float getArea() {return area;}
};

// do something with decltype here
template <typename A, typename B>
circ<A> operator * (const circ<A> cla, circ<B> clb) {
    circ<A>temp(cla.radius * clb.radius);
    temp.setArea();
    return temp;
}

using namespace std;

int main() {
    cout << cube<int>(6) << endl;
    cout << cube(10.1) << endl; // automatically inferred

    circ<int> simp(2); // must be specidied
    simp = cube(simp);
    cout << "Area be like " << simp.getArea() << endl;

    circ<float> comp(6.9);
    cout << comp.getArea() << endl;
    
    circ lol = simp * comp;
    cout << "complex area be like; " << lol.getArea();
    
}

/* Standard Template Library
 * 
 * STL separates algorithms from Containers
 * So if there are N algos and M containers
 * We have N * M implementations
 * Bad bad bad
 * 
 * For this we have iterators
 * Each container is supposed to provide an iterator and algos use that
 *
*/