#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main()
{
    int n;
    vector<int> s;

    cin >> n;
    s = vector<int>(n+1);
    for ( int i = 1; i <= n; ++i ) cin >> s[i];

    vector<int> in(n+1, 0);
    for ( auto v : s ) in[v] += 1;

    queue<int> que;

    for ( int i = 1; i <= n; ++i ) if ( in[i] == 0 ) que.push(i);

    while(!que.empty()) {
        int top = que.front(); que.pop();
        int to = s[top];
        in[to] -= 1;
        if ( in[to] == 0 ) que.push(to);
    }

    int ans = 0;
    for ( int i = 1; i <= n; ++i ) {
        if ( in[i] ) ans += 1;
    }
    cout << ans << endl;
}