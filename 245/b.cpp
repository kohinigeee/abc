#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

int main()
{
    int n;
    set<int> a;

    cin >> n;
    while(n--) {
        int tmp; cin >> tmp; 
        a.insert(tmp);
    }

    int ans;
    for ( ans = 0; ans <= 3000; ++ans ) {
        if ( a.find(ans) == a.end() ) break;
    }

    cout << ans << endl;
}