#include<iostream>
#include<set>

using namespace std;
using ll = long long;

ll const maxv = 1000000000;

ll biset(multiset<ll>& s, int k ) {
    ll no = 0;
    ll ok = maxv;

    while( ok - no > 1 ) {
        ll mid = (no+ok)/2;
        int idx = distance(s.begin(), s.upper_bound(mid));
        if ( idx >= k ) ok = mid;
        else no = mid;
    }

    return ok;
}

int main()
{
    multiset<ll> s;


    s.insert(3);
    s.insert(1);
    s.insert(4);


    auto no2 = s.begin(); ++no2;

    cout << distance(s.begin(), no2) << ", value = " << *no2 << endl;
    s.insert(3);
    cout << distance(s.begin(), no2) << ", value = " << *no2 << endl;
    ++no2;
    s.erase(3);
    cout << distance(s.begin(), no2) << ", value = " << *no2 << endl;


}