#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<string>
#include<utility>

using namespace std;

vector<pair<char, int>> bunkai (string s ) {
    char ch = '0';
    int i = 0;
    vector<pair<char, int>> v;

    s = s+"0";

    while( s[i] != '0' ) {
        if ( s[i] != ch ) {
            int cnt = 0;
            ch = s[i];
            while( s[i] == ch ) { ++cnt; ++i; }
            v.push_back(make_pair(ch, cnt));
        }
    }
    return v;
}

bool func( string s, string t ) {
    vector<pair<char,int>> v1, v2;

    v1 = bunkai(s);
    v2 = bunkai(t);

    if ( v1.size() != v2.size() ) return false;
    for ( int i = 0; i < v1.size(); ++i ) {
        if ( v1[i].first != v2[i].first) return false;
        if ( v1[i].second > v2[i].second ) return false;
        if ( v1[i].second == 1 && v2[i].second >= 2 ) return false;
    }
    return true;

}

int main()
{
    string s;
    string t;

    cin >> s;
    cin >> t;
    if ( func( s, t ) ) cout << "Yes" << endl;
    else cout << "No" << endl;
}