#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n;
    string s;

    cin >> n >> s;
    int cnt = 0;
    for ( int i = 0; i < n; ++i ) {
        if ( s[i] == '\"' ) cnt = (cnt+1)%2;
        else if ( !cnt && s[i] == ',' ) s[i] = '.';
    }

    cout << s << endl;
}