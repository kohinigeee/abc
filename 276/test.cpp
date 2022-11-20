#include<iostream>
#include<utility>
#include<set>

using namespace std;

int main()
{
    pair<int,int> a, b;
    multiset<int> st;

    a = make_pair(0, 1);
    b = make_pair(2, 10);

    st.insert(5);
    st.insert(10);
    st.insert(8);

    cout << distance(st.begin(), st.find(8)) << endl; 

}