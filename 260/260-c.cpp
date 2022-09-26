#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<long long> red(11), blue(11);
    int x, y, n;

    cin >> n >> x >> y;
    red[1] = 0;
    blue[1] = 1;
    for ( int i = 2; i <= n; ++i ) {
        blue[i] = y*blue[i-1]+red[i-1];
        red[i] = x*blue[i]+red[i-1];
    }

    cout << red[n] << endl;
}