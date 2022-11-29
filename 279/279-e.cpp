#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n, m;
    vector<int> edges;
    vector<int> upper_no, upper_line;
    vector<int> below;
    vector<int> ans;

    cin >> n >> m;
    edges = vector<int>(m);
    upper_no = vector<int>(n+1);
    upper_line = vector<int>(n+1);
    below = vector<int>(n+1);

    for ( int i = 0; i < m; ++i ) {
        cin >> edges[i];
    }

    for ( int i = 0; i <= n; ++i ) {
        upper_no[i] = upper_line[i] = i;
        below[i] = i;
    }

    for ( auto v : edges ) {
        swap(upper_no[upper_line[v]], upper_no[upper_line[v+1]]);
        swap(upper_line[v], upper_line[v+1]);
    }

    for ( int i = 0; i < m; ++i ) {
        int edge = edges[m-1-i];
        swap(upper_no[upper_line[edge]], upper_no[upper_line[edge+1]]);
        swap(upper_line[edge], upper_line[edge+1]); 

        ans.push_back(below[upper_no[1]]);
        swap(below[edge], below[edge+1]);
    }

    for ( int i = 0; i < m; ++i ) {
        cout << ans[m-1-i] << endl;
    }
}