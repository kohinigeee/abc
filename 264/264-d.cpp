#include<iostream>
#include<map>
#include<string>
#include<queue>

using namespace std;

string change(const string& s, int x, int y ) {
    string tmp = s;
    tmp[x] = s[y]; tmp[y] = s[x];
    return tmp;
}

int main()
{
    string str = "atcoder";
    map<string, int> m;
    queue<string> q;

    m[str] = 0;
    q.push(str);

    while(!q.empty()){
        string tmps = q.front(); q.pop();
        for ( int i = 0; i < tmps.size(); ++i ) {
            
            for ( int j = i-1; j <= i+1; j += 2 ) {
                if ( j < 0 || j >= tmps.size() ) continue;
                string tmp = change(tmps, i, j);
                if ( m.find(tmp) != m.end() ) continue;
                m[tmp] = m[tmps]+1;
                q.push(tmp);
            }
        }
    }

    string S; cin >> S;
    cout << m[S] << endl;

}