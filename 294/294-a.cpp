#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n;

    cin >> n;

    while(n--) {
        int tmp; cin >> tmp;
        if ( !(tmp % 2 ) ) {
            cout << tmp << " ";
        }
    }
    cout << endl;

}