#include<iostream>
#include<vector>

using namespace std;

bool is_upper(char ch) {
    return ( ch >= 'A' && ch <= 'Z');
}

int is_no(char ch) {
    if ( ch >= '0' && ch <= '9' ) return ch-'0';
    else return -1;
}

bool fn( string s ) {
    if ( s.size() != 8 ) return false;
    if ( !is_upper(s[0]) ) return false;
    if ( !is_upper(s[7]) ) return false;

    int ans = 0;
    for ( int i = 1; i < 7; ++i ) {
        int tmp = is_no(s[i]);
        if ( tmp == -1 ) return false;
        ans = ans*10 + tmp;
    }

    if ( ans >= 100000 && 999999 >= ans ) return true;
    else return false;
}

int main()
{
   string s; cin >> s;
   if ( fn(s) ) cout << "Yes" << endl;
   else cout << "No" << endl; 
}