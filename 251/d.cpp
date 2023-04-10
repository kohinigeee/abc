#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main()
{
    const int w = 1000000;
    vector<int> ans;

    int p = pow(w+1, 1.0/3); 
    // ++p;

    int ord1 = p, ord2 = p*p;

    for ( int i = 1; i < p; ++i ) {
        ans.push_back(i);
        ans.push_back(i*ord1);
        ans.push_back(i*ord2);
    }

    cout << ans.size() << endl;
    for ( auto v : ans ) cout << v << " ";
}