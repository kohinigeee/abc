#include<iostream>
#include<vector>
#include<set>

using namespace std;
int n, k;

bool func(int l, int r, vector<int>&a, vector<vector<int>>& s ) {
    set<long long> st;
    for ( int i = 0; i < k; ++i ) {
        if ( l+i > r ) break;

        // cout << "i = " << i << endl;
        int m = (l+i)%k;

        int ml = ((l-1)/k);
        if ( m > 0 && ml*k+m < l ) ++ml;
        int mr = (r/k); //累積和の終点
        if ( m > 0 && mr*k+m <= r ) ++mr;

        // cout << "m = " << m << ", ml = " << ml << ", mr = " << mr << endl;
        long long sum = s[m][mr]-s[m][ml];
        // cout << "sum = " << sum << endl;
        st.insert(sum);
    }
    return st.size() == 1;
}

int main()
{
    vector<int> a;

    cin >> n >> k;
    while(n--) {
        int tmp; cin >> tmp;
        a.push_back(tmp);
    }

    vector<vector<int>>s(k, vector<int>(1,0));

    for ( int i = 0; i < a.size(); ++i ) {
        int m = (i+1)%k;
        s[m].push_back(s[m].back()+a[i]);
    }

    // for ( auto v : s ) {
    //     for ( auto tmpv : v ) cout << tmpv << " "; cout << endl;
    // }

    int q;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        if ( func(l, r, a, s) ) {
            cout << "Yes" << endl;
        } else cout << "No" << endl;
    }

}