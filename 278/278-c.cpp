#include<iostream>
#include<vector>
#include<map>
#include<utility>
#include<set>

using namespace std;

using pii = pair<int,int>;

int main()
{
    int n, q;
    set<pii> st;

    cin >> n >> q;
    for ( int i = 0; i < q; ++i ) {
        int t, a, b;

        cin >> t >> a >> b;
        pii p = make_pair(a,b);

        if ( t == 1 ) st.insert(p);
        if ( t == 2 ) st.erase(p);
        if ( t == 3 ) {
            pii p2 = make_pair(b,a);
            if ( st.find(p) == st.end() || st.find(p2) == st.end() ) cout << "No" << endl;
            else cout << "Yes" << endl;
        }
    }
}