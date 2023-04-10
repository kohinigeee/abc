#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int h, w;

    vector<string> s;
    cin >> h >> w;

    s = vector<string>(h);
    for ( int i = 0; i < h; ++i ) cin >> s[i];

    for ( int i = 0; i < h; ++i ) {
        for ( int j = 0; j+1 < w; ++j ) {
            if ( s[i][j] == 'T' && s[i][j+1] == 'T' ) {
                s[i][j] = 'P';
                s[i][j+1] = 'C';
            } 
        }
    }

    for ( auto v : s ) {
        cout << v << endl;
    }
}