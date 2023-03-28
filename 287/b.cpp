#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main() {
    int n, m;
    vector<string> s;
    set<string> t;

    cin >> n >> m;
    for ( int i = 0; i < n; ++i) {
        string tmp; cin >> tmp;
        s.push_back(tmp.substr(3, 3));
    }

    for ( int i = 0; i < m; ++i ) {
        string tmp; cin >> tmp;
        t.insert(tmp);
    }

    int ans = 0;
    for ( auto tmp : s ) {
        if ( t.find(tmp) != t.end() ) ++ans;
    }

    cout << ans << endl;
}