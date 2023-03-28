#include<iostream>

using namespace std;

void fn(int* x) {
    if ( *x  <= 10 ) {
        cout << "x = " << *x << endl;
        (*x) += 1;
        fn(x);
    }
}

int main()
{
    int x = 0;
    fn(&x);

    cout << "x(fin) = " << x << endl;
}