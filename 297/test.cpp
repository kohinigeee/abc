#include<iostream>
#include<set>

using namespace std;

int main()
{
    set<int> s;

    s.insert(10);
    s.insert(5);
    s.insert(2);

    auto it = s.begin();

    cout << (*it) << endl;
}