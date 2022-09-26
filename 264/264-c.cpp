#include<vector>
#include<string>
#include<iostream>

using namespace std;
using matrix = vector<vector<int>>;

int take_bit(int x, int d ) {
    return (x>>d)&1;
}

bool comp( matrix &a, matrix &b) {
    if ( a.size() != b.size() ) return false;
    if ( a[0].size() != b[0].size() ) return false;

    for ( int i = 0; i < a.size(); ++i ) {
        for ( int j = 0; j < a[i].size(); ++j ) {
            if ( a[i][j] != b[i][j] ) return false;
        }
    }
    return true;
}

matrix convert( matrix &a, int r, int c ) {
    matrix b;
    for ( int i = 0; i < a.size(); ++i ) {
        if ( take_bit(r, i) == 0 ) continue;
        vector<int> tmp;
        for ( int j = 0; j < a[0].size(); ++j ) {
            if ( take_bit(c, j) == 1 ) tmp.push_back(a[i][j]);
        }
        b.push_back(tmp);
    }
    return b;
}

int main()
{
    matrix a, b;
    int h1, w1, h2, w2;

    cin >> h1 >> w1;
    a = matrix(h1, vector<int>(w1));
    for ( int i = 0; i < h1; ++i ) {
        for ( int j = 0; j < w1; ++j ) cin >> a[i][j];
    }

    cin >> h2 >> w2;
    b = matrix(h2, vector<int>(w2));
     for ( int i = 0; i < h2; ++i ) {
        for ( int j = 0; j < w2; ++j ) cin >> b[i][j];
    }

    for ( int r = 1; r < (1<<h1); ++r ) {
        for ( int c = 1; c < (1<<w1); ++c ) {
            matrix tmp = convert(a, r, c);
            if ( comp(tmp,b) ) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;

}