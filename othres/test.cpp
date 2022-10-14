#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<vector<int>> d = {
    {-1, 14, 6, 5, 7, 12},
    {14, -1, 10, 15, 4, 2},
    {6, 10, -1, 1, 13, 9},
    {5, 15, 1, -1, 11, 8},
    {7, 4, 13, 11, -1, 3},
    {12, 2, 9, 8, 3, -1}
};

int calcd(vector<int>& path) {
    int ans = 0;
    for ( int i = 0; i < path.size(); ++i ) {
        int to = path[(i+1)%(path.size())];
        ans += d[path[i]][to];
    }
    return ans;
}

int main()
{
    vector<string> names = {"s", "a", "b", "c", "d", "e"};

    vector<int> path = {0, 1, 3, 5, 4, 2};
    int sum = calcd(path);
    
    cout << "current sumd = " << sum << endl;

    for ( int i = 0; i < path.size(); ++i ) {
        for ( int j = i+1; j < path.size(); ++j ) {
            vector<int> nextpath = path;
            swap(nextpath[i], nextpath[j]);
            int nextd = calcd(nextpath);

            if ( nextd < sum ) {

                for ( auto c : nextpath ) cout << names[c] << ", "; cout << endl;
                cout << "total : " << nextd << endl;
                cout << endl;
            } 
        }
    }    
}