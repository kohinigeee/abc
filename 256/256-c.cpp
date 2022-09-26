#include<iostream>
#include<vector>

using namespace std;

int masu[3][3];
int h[3];
int w[3];

int main()
{
    int cnt = 0;
    for ( int i = 0; i < 3; ++i ) cin >> h[i];
    for ( int i = 0; i < 3; ++i ) cin >> w[i];

    for ( int a = 1; a < 30; ++a ) {
        masu[0][0] = a;
        for ( int b = 1; b < 30; ++b ) {
            masu[0][1] = b;
            for ( int c = 1; c < 30; ++c ) {
                masu[1][0] = c;
                for ( int d = 1; d < 30; ++d ) {
                    masu[1][1] = d;

                    masu[0][2] = h[0]-masu[0][0]-masu[0][1];
                    if ( masu[0][2] <= 0 ) continue;
                    masu[1][2] = h[1]-masu[1][0]-masu[1][1];
                    if ( masu[1][2] <= 0 ) continue;
                    masu[2][0] = w[0]-masu[0][0]-masu[1][0];
                    if ( masu[2][0] <= 0 ) continue;
                    masu[2][1] = w[1]-masu[0][1]-masu[1][1];
                    if ( masu[2][1] <= 0 ) continue;

                    masu[2][2] = h[2]-masu[2][0]-masu[2][1];
                    if ( masu[2][2] <= 0 ) continue;
                    if ( masu[0][2]+masu[1][2]+masu[2][2] != w[2] ) continue;
                    ++cnt;

                }
            }
        }
    }

    cout << cnt << endl;
}