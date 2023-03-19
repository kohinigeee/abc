#include<iostream>
#include<vector>
#include<string>

using namespace std;

string fn(vector<int>& v ) {
    string s = "";
    for ( int i : v ) {
        char ch;
        if ( i == 0 ) ch = '.';
        else ch = 'A'+(i-1);
        s += ch;
    }
    return s;
}

int main()
{
     int h, w;
     cin >> h >> w;
     for ( int i = 0; i < h; ++i ) {
        vector<int> v(w);
        for ( int j = 0; j < w; ++j ) cin >> v[j];
        cout << fn(v) << endl;
     }

}