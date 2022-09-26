#include<iostream>
#include<vector>
#include<stack>
#include<utility>

using namespace std;

using pii = pair<int,int>;

int main()
{
  stack<pii> st;
  int sum = 0, n;
  st.push(make_pair(-1, 0));

  cin >> n;

  while(n--) {
    int a;
    cin >> a;
    pii item = st.top();

    if ( item.first != a ) {
      st.push(make_pair(a, 1));
      sum += 1;
    } else {
      st.pop();
      item.second += 1;
      sum += 1;
      if ( item.first == item.second ) sum -= item.first;
      else st.push(item);
    }

    cout << sum << endl;
  }
}
