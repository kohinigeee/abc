#include <iostream>
//#include <vector>
#include <queue>
#include <string>

using namespace std;

int main()
{
  queue<int> que;
  string str;
  int N,k;
  int sum = 0;
  int longs = 0;
  int max = 1;
  bool flag; // 1‚Ì‚Æ‚«false, 0‚Ì‚Æ‚«true

  cin >> N >> k;
  cin >> str;

  if ( str[0] == '0' ) {
    flag = true;
    longs = 1;
  } else {
    flag = false;
    longs = 1;
  }

  for ( int i = 1; i < str.size(); ++i ) {
    if ( flag ) {
      if ( str[i] == '0' ) {
        ++longs;
        //cout << "part 1" << " longs = " << longs << endl;
      } else {
        flag = false;
        que.push(longs);
        sum += longs;
        longs = 1;

        //cout << "part 2" << " longs = " << longs << ",size = " << que.size() << endl;
      }

    } else {
      if ( str[i] == '0' ) {
        flag = true;
        if ( que.size() >= k ) {
          sum = sum-que.front();
          que.pop();
        }
        ++longs;

        //cout << "part 3" << " longs = " << longs << " ,size = " << que.size() << endl;
      } else {
        ++longs;
        //cout << "part 4" << " longs = " << longs << endl;
      }
    }

    if ( sum + longs > max ) max = sum+longs;
    //cout << "max = " << max << endl << endl;
  }

  cout << max << endl;
}
