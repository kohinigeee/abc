#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

long long gcd ( long long a, long long b ) {
    long long r;

    while ( r = a%b ) {
        a = b;
        b = r;
    }
    return b;
}

int main()
{
    vector<int> v;
    int n;

    cin >> n;
    v = vector<int>(n);

    for ( auto& a : v) cin >> a;

    prev_permutation(v.begin(), v.end());
    for ( auto a : v ) cout << a << " ";
    cout << endl;
}