#include<iostream>
#include<string>

using namespace std;

bool is_eq(char ch1, char ch2) {
    if ( ch1 == '?' || ch2 == '?' ) return true;
    return ch1 == ch2;
}

int main() {
    string s,t;

    cin >> s >> t;
    int cnt_neq = 0;
    int l = 0;
    int r = t.size();

    for ( int i = 0; i < t.size(); ++i ) {
        if ( !is_eq(s[s.size()-1-i], t[t.size()-i-1]) ) ++cnt_neq;
    }

    if ( cnt_neq == 0 ) cout << "Yes" << endl;
    else cout << "No" << endl;

    while( l < t.size() ) {
        int rno = s.size()-r;
        if ( !is_eq(s[rno], t[l]) ) --cnt_neq;
        if ( !is_eq(s[l], t[l]) ) ++cnt_neq;
        ++l;
        --r;
        if ( cnt_neq == 0 ) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}