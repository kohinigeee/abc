#include<iostream>
#include<vector>

using namespace std;

int main() {
    int n, m;
    vector<int> a;

    cin >> n >> m;
    while(m--) {
        int tmp; cin >> tmp;
        a.push_back(tmp);
    }
    a.push_back(1000);

    vector<int> st;
    vector<int> ans;
    int idx = 0;
    for ( int i = 1; i <= n; ++i ) {
        st.push_back(i);
        if ( i == a[idx] ) {
            ++idx;
        } else {
            while(!st.empty()) {
                ans.push_back(st.back()); st.pop_back();
            }
        }
    }

    for ( auto i : ans ) cout << i << " "; cout << endl;
}