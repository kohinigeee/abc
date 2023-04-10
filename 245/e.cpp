#include<iostream>
#include<set>
#include<vector>
#include<algorithm>

#define CHOCO 0
#define BOX 1

using namespace std;
using ll = long long;

struct Item {
    ll h, w;
    int type;
};

int main()
{
    int n, m;

    cin >> n >> m;

    vector<ll> a(n), b(n), c(m), d(m);
    vector<Item> v;

    for ( int i = 0; i < n; ++i ) cin >> a[i];
    for ( int i = 0; i < n; ++i ) cin >> b[i];
    for ( int i = 0; i < m; ++i ) cin >> c[i];
    for ( int i = 0; i < m; ++i ) cin >> d[i];

    for ( int i = 0; i < n; ++i ) v.push_back(Item{a[i], b[i], CHOCO}); 
    for ( int i = 0; i < m; ++i ) v.push_back(Item{c[i], d[i], BOX}); 

    auto comp = [](Item& i1, Item& i2 ) {
        if ( i1.h == i2.h ) {
            return i1.type > i2.type;
        }
        return i1.h > i2.h;
    };


    sort(v.begin(), v.end(), comp);

    multiset<ll> boxs;

    for ( auto i : v ) {
        if ( i.type == BOX ) boxs.insert(i.w);
        else {
            auto it = boxs.lower_bound(i.w);
            if( it == boxs.end() ) {
                cout << "No" << endl;
                return 0;
            }
            boxs.erase(it);
        }
    }

    cout << "Yes" <<endl;
}