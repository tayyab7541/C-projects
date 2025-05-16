#include<iostream>
using namespace std;

template <class T>
class date {
    T day, month, year;
public:
    date() {}  // default constructor
    date(T d, T m, T y) : day(d), month(m), year(y) {}
    
    // Correct friend declaration for template operator
    friend bool operator==(const date<T>&, const date<T>&);
};

// Template operator definition
template<class T> 
bool operator==(const date<T> &obj1, const date<T> &obj2) {
    return (obj1.day == obj2.day) && 
           (obj1.month == obj2.month) && 
           (obj1.year == obj2.year);
}

int main() {
    date<int> d1(2, 10, 2006), d2(2, 10, 2006);
    if (d1 == d2) {
        cout << "both dates are equal\n";
    } else {
        cout << "dates are not equal\n";
    }
    return 0;
}