#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<string> s;
    int n, m;

    cin >> n >> m;
    int ans = 0;
    for ( int i = 0; i < n; ++i ) {
        string tmp; cin >> tmp;
        s.push_back(tmp);
    }

    for ( int i = 0; i < n; ++i ) {
        for ( int j = i+1; j < n; ++j ) {
            bool f = true;
            for ( int k = 0; k < m; ++k ) {
                if ( s[i][k] == 'x' && s[j][k] == 'x' ) {
                    f = false;
                    break;
                }
            }
            if ( f ) ++ans;
        }
    }

    cout << ans << endl;
}