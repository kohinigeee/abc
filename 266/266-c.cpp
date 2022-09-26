#include<iostream>
#include<vector>
#include<string>

#define M  998244353

using namespace std;
using ll = long long;

int main()
{
    ll n;

    cin >> n;
    // ll tmp = (n-M)/M - 10;

    // ll x = 0;
    // while(1) {
    //     x = n-M*tmp;
    //     if ( x >= 0 && x < M && (n-x)%M == 0 ) {
    //         cout << x << endl;
    //         return 0;
    //     }
    //     ++tmp;
    // }

    ll x = (n%M);
    if ( x < 0 ) x += M;
    cout << x << endl;
}