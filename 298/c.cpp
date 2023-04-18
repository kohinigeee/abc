#include<iostream>
#include<vector>
#include<vector>

using namespace std;

vector<vector<int>> kaiten(vector<vector<int>> a , int n) {
    vector<vector<int>> ans = vector<vector<int>>(n, vector<int>(n));

    for ( int i = 0; i < n; ++i ) {
        for ( int j = 0; j < n; ++j ) {
            ans[i][j] = a[n-1-j][i];
        }
    }
    return ans;
}

bool eq(vector<vector<int>>& a, vector<vector<int>>& b, int n ) {
    for ( int i = 0; i < n; ++i ) {
        for ( int j = 0; j < n; ++j ) {
            if ( a[i][j] == 1 ) {
                if ( b[i][j] == 0 ) return false;
            }
        }
    }
    return true;
}

int main() {
    int n;

    cin >> n;
    vector<vector<int>> a(n, vector<int>(n)), b(n, vector<int>(n));

    for ( int i = 0; i < n; ++i ) {
        for ( int j = 0; j < n; ++j ) cin >> a[i][j];
    }
    for ( int i = 0; i < n; ++i ) {
        for ( int j = 0; j < n; ++j ) cin >> b[i][j];
    }

    string ans = "No";

    if ( eq(a,b,n) ) ans = "Yes";
    for ( int i = 0; i < 3; ++i ) {
        a = kaiten(a,n);
        if ( eq(a, b, n) ) ans = "Yes";

    }

    cout << ans << endl;
}