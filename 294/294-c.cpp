#include<iostream>
#include<vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a = vector<int>(n), b = vector<int>(m);
    vector<int> ano = vector<int>(n), bno = vector<int>(m);
    a.push_back(1<<30);
    b.push_back(1<<30);

    for ( int i = 0; i < n; ++i ) cin >> a[i];
    for ( int j = 0; j < m; ++j ) cin >> b[j];

    int no = 1;
    int aidx = 0, bidx = 0;

    while(aidx < n || bidx < m ) {
        if ( a[aidx] < b[bidx] ) {
            ano[aidx] = no;
            ++aidx;
        } else {
            bno[bidx] = no;
            ++bidx;
        }
        ++no;
    }

    for ( auto i : ano ) cout << i << " "; cout << endl;
    for ( auto i : bno ) cout << i << " "; cout << endl;
}
