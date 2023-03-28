#include<iostream>
#include<vector>

using namespace std;

void fn(vector<int>& ans, vector<string>& s, const vector<int>& sidxs, int k ) {
    vector<vector<int>> groups(26, vector<int>());
    for ( int idx : sidxs ) {
        if ( s[idx].size() <= k ) {
            ans[idx] = k; 
            continue;
        }
        int no = s[idx][k]-'a';
        groups[no].push_back(idx);
    }

    for ( auto g : groups ) {
        if ( g.size() <= 1 ) for ( int idx : g ) ans[idx] = max(ans[idx], k);
        else {
            fn(ans, s, g, k+1);
        }
    }
}

int main()
{
    int n;
    vector<string> s;
    vector<int> ans;

    cin >> n;
    s = vector<string>(n);
    ans = vector<int>(n, 0);

    for ( int i = 0; i < n; ++i ) cin >> s[i];
    vector<int> idxs(n);
    for ( int i = 0; i < n; ++i ) idxs[i] = i;

    fn(ans, s, idxs, 0);
    for( int i : ans ) cout << i << endl;
}