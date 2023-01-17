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
    T radius;
    float area;

    public:
    circ(T rad) {
        radius = rad;
        area =0.0;
    }
    float calArea() {
        area = 3.14 * radius * radius;
        return area;
    }
};

using namespace std;

int main() {
    cout << cube<int>(6) << endl;
    cout << cube(10.1) << endl; // automatically inferred

    circ<int> simp(2); // must be specidied
    cout << simp.calArea() << endl;

    circ<float> comp(6.9);
    cout << comp.calArea() << endl;
}