#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<algorithm>

using namespace std;

int n, m;
vector<string> s;
set<string> t;
bool f = false;
string ans = "";

void dfs( string tmps, vector<int>& ord, int sno, int count_char, int max_count) {
    if ( count_char > max_count ) return;
    if ( tmps.size() > 16 ) return;
    if ( tmps.size() >= 3 && sno == ord.size() && t.find(tmps) == t.end() ) ans = tmps;
    if ( tmps.size() >= 16 || sno >= ord.size() ) return;

    if ( sno < ord.size() ) {
        string tmps_2 = tmps+s[ord[sno]];
        if ( sno+1 < ord.size() ) tmps_2 += '_';
        dfs(tmps_2, ord, sno+1, count_char, max_count);
    }
    if ( tmps != "" ) {
        dfs( tmps+'_', ord, sno, count_char+1, max_count);
    }
}

int main()
{

    cin >> n >> m;

    vector<int> ord(n);
    s = vector<string>(n);
    int sum = 0;

    for ( int i = 0; i < n; ++i ) {
        ord[i] = i;
        cin >> s[i];
        sum += s[i].size();
    }

    for ( int i = 0; i < m; ++i ) {
        string tmp; cin >> tmp;
        t.insert(tmp);
    }

    if ( n == 1 ) {
        if ( t.find(s[0]) == t.end() && s[0].size()>= 3 ) cout << s[0] << endl;
        else cout << -1 << endl;
        return 0;
    }

    do{
        dfs("", ord, 0, 0, 16-(n-1)-sum);
        if( ans != "" ) { cout << ans << endl; return 0; }
    } while(next_permutation(ord.begin(), ord.end()));
    cout << -1 << endl;
}