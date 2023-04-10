#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);

    for ( int i = 0; i < n; ++i ) cin >> a[i];
    int q;
    cin >> q;
    while(q--) {
        int cmd; cin >> cmd;
        if ( cmd == 1 ) {
            int k, x; cin >> k >> x;
            a[k-1] = x;
        } else {
            int k;
            cin >> k;
            cout << a[k-1] << endl;
        }
    }
}