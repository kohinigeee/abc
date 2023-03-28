#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};

    int no = v.end()-lower_bound(v.begin(), v.end(), 3);
    
    cout << no << endl;
}