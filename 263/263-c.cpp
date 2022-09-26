#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;

void func ( vector<int>& ans, int i) {

    if ( i == ans.size() ) { for ( auto a : ans ) cout << a << " "; cout << endl; return; }
    int minv = 1;
    if ( i > 0 ) minv = ans[i-1]+1;

    if ( m-minv + i+1 < ans.size() ) return;
    for ( int v = minv; v <= m; ++v ) {
        ans[i] = v;
        func(ans, i+1);
    }
}

int main()
{
    cin >> n >> m;
    vector<int> ans(n, -1);

    func(ans, 0);
}