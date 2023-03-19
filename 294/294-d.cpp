#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main()
{
    int n, q;
    priority_queue<int, vector<int>, greater<int>> pq;
    int not_called_cnt = 0;
    vector<bool> called;
    vector<int> ans;

    cin >> n >> q;
    called = vector<bool>(n, false);

    while(q--) {
        int cmd;
        cin >> cmd;
        if ( cmd == 1 ) {
            pq.push(not_called_cnt);
            ++not_called_cnt;
        } else if ( cmd == 2 ) {
            int x; cin >> x; --x;
            called[x] = true;
        } else {
            while(!pq.empty()) {
                int no = pq.top();
                if ( called[no] == false ) {
                    ans.push_back(no+1);
                    break;
                }
                pq.pop();
            }
        }
    }

    for ( int i : ans ) {
        cout << i << endl;
    }
}