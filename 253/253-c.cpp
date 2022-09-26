#include<iostream>
#include<map>
#include<queue>
#include<algorithm>

using namespace std;

int main()
{
    int q;
    map<int, int> cnt;
    priority_queue<int> maxq;
    priority_queue<int, vector<int>, greater<int>> minq;

    cin >> q;
    for ( int i = 0; i < q; ++i ) {
        int cmd, x, c; 
        cin >> cmd;
        if ( cmd == 1 ) {
            
            cin >> x;
            if ( cnt.find(x) == cnt.end() || cnt[x] == 0 ) {
                cnt[x] = 1;
                maxq.push(x);
                minq.push(x);
            } else cnt[x] += 1;
        } else if ( cmd == 2 ) {
            cin >> x >> c;
            cnt[x] = max(0, cnt[x]-c);
        } else {
            int maxv;
            int minv;
            while(1) {
                maxv = maxq.top();
                if ( cnt[maxv] > 0 ) { break;}
                else maxq.pop();
            }
            while(1) {
                minv = minq.top();
                if ( cnt[minv] > 0 ) { break; }
                else minq.pop();
            }
            cout << maxv-minv << endl;
        }
    }

}
