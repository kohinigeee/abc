#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

#define MAX_CARD (200000)

using namespace std;
int main(){
    int N,Q,i,j,x;
    cin >> N >> Q;
    vector<vector<int>> B(N+1);
    vector<set<int>> cards;

    cards = vector<set<int>>(MAX_CARD+1, set<int>());
    for(int I=0;I<Q;I++){
        cin >> x;
        if(x==1){
            cin >> i >> j;
            B[j].push_back(i);
            cards[i].insert(j);
        }
        if(x==2){
            cin >> i;
            int n =B[i].size();
            sort(B[i].begin(),B[i].end());
            for(int J=0;J<n;J++){
                cout << B[i][J] <<" ";
            }
            cout << "\n";
        }
        if(x==3){
            cin >> i;
            for ( auto it : cards[i] ) cout << it << " ";
            cout << "\n";
        }
        
    }
}