#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

vector<int> suffixArray(string t) {
    vector<int> ord(t.size(), -1);
    vector<int> v(t.size(), -1);
    int n = t.size();

    for ( int i = 0; i < v.size(); ++i ) { 
        v[i] = t[i];
        ord[i] = i;
    }

    sort(ord.begin(), ord.end(), [&v]( int x, int y) { return v[x] < v[y]; } );
    for ( int i = 0; i < ord.size(); ++i ) v[ord[i]] = i;

    int maxk = 1;
    while( maxk < t.size() ) maxk *= 2;

    for ( int k = 2; k <= maxk; k *= 2 ) {
        sort(ord.begin(), ord.end(), [n,k,&v]( int x, int y ) {
            if ( v[x] == v[y] ) {
                int j = k/2;
                int vx = ( x+j < n) ? v[x+j] : -1;
                int vy = ( y+j < n) ? v[y+j] : -1; 
                return vx < vy;
            }
            return v[x] < v[y];
        });


        for ( int i = 0; i < n; ++i ) v[ord[i]] = i;
    }

    return ord;
}

bool isMatch(vector<int>& ord,string t, string p) {

    int l = -1, r = t.size();

    while( l+1 < r ) {
        int mid = (l+r)/2;

        string s = t.substr(ord[mid], p.size());
        // cout << "substr : " << s << endl;
        int comp = s.compare(p);
        if ( comp == 0 ) return true;
        if ( comp < 0 ) l = mid;
        else r = mid;
    }
    return false;
}

int main()
{

    int n;
    int q;
    string t;

    cin >> t;
    vector<int> ord = suffixArray(t);

    cin >> q;
    while(q--) {
        string s; cin >> s;
        if ( isMatch(ord, t, s) ) cout << 1 << endl;
        else cout << 0 << endl;
    }
}
