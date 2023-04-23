#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int n;

    cin >> n;

    int l = 1, r = n;

    while( l+1 < r ) {
        int mid = (l+r)/2;

        cout << "? " << mid << endl;
        
        int val; cin >> val;
        if ( val == 1 ) r = mid;
        else l = mid;
    }

    cout << "! " << l << endl;
}