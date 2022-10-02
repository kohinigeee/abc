#include<iostream>
#include<vector>

#define MAXS 10000

using namespace std;

vector<vector<int>> dp;
vector<int> a, b;
int n, s;

int main()
{
    cin >> n >> s;

    dp = vector<vector<int>>(n, vector<int>(MAXS+1, 0));
    a = vector<int>(n); b = vector<int>(n);

    for ( int i = 0; i < n; ++i ) {
        cin >> a[i] >> b[i];
    }

    dp[0][a[0]] = 1;
    dp[0][b[0]] = 2;
    for ( int i = 1; i < n; ++i ) {
        for ( int v = 1; v <= MAXS; ++v ) {
            int tmpa = v-a[i];
            int tmpb = v-b[i];

            if ( tmpa >= 0 && dp[i-1][tmpa] ) dp[i][v] = 1;
            if ( tmpb >= 0 && dp[i-1][tmpb] ) dp[i][v] = 2;
        }
    }

    int v = s;
    int i = n-1;
    vector<char> ans;
    if ( dp[n-1][s] == 0 ) { cout << "No" << endl; return 0; }

    while(v > 0 ) {
        if ( dp[i][v] == 1 ) {
            ans.push_back('H');
            v -= a[i];
        } else {
            ans.push_back('T');
            v -= b[i];
        }
        --i;
    }

    cout << "Yes" << endl;
    for ( int i = ans.size()-1; i >= 0; --i ) cout << ans[i]; cout << endl;
}