#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int l = 1, r = n;

    int a = 1, b = n;
    int tmpn = n;
    int ansj = -1;
    while( l < r ) {
        int mid = (l+r)/2;
        int lno, rno;
        tmpn = r-l;

        // cout << "l = " << l << ", r=" << r << ", mid=" << mid << ", tmpn=" << tmpn << endl;

        cout << "? " << a << " " << b << " " << l << " " << mid << endl;
        cin >> lno;
        rno = tmpn-lno;

        if ( rno < lno ) {
            l = mid+1;
        } else r = mid;
    }
    ansj = l;
    // cout << "ansj = " << ansj <<endl;

    l = 1, r = n;
    int c = 1, d = n;
    int ansi = -1;
    tmpn = n;
    while( l < r ) {
        int mid = (l+r)/2;
        int lno, rno;
        tmpn = r-l;
        cout << "? " << l << " " << mid << " " << c << " " << d << endl;
        cin >> lno;
        rno = tmpn-lno;

        if ( rno < lno ) {
            l = mid+1;
        } else r = mid;
    }
    ansi = l;

    cout << "! " << ansi << " " << ansj <<endl;
}