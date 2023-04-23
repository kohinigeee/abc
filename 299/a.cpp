#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int n; cin >> n;
    string s; cin >> s;

    vector<int> pos;
    int b;

    for ( int i = 0; i < s.size(); ++i ) {
        if ( s[i] == '|' ) pos.push_back(i);
        if ( s[i] == '*' ) b = i;
    }

    string ans  = "out";
    if ( b > pos[0] && b < pos[1] ) ans = "in";

    cout << ans << endl;
}