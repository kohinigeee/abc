
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

int main()
{

    int n;
    string s, t;

    cin >> n;
    cin >> s;
    cin >> t;

    string g = s+s+string(2*n,'a')+t+t+string(2*n, 'z');
    vector<int> ord = suffixArray(g);

    long long sum = 0;
    int cnt = 0;

    for ( int& v: ord ) {
        if ( v < n ) ++cnt;
        if ( v >= 4*n && v < 5*n ) sum += cnt;
    }
    cout << sum << endl;
}
