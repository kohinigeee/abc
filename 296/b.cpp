#include<iostream>
#include<vector>

using namespace std;

int main()
{
    char c[] = {'a','b', 'c', 'd', 'e', 'f', 'g', 'h'};
    int r[] = {8, 7, 6, 5, 4, 3, 2, 1};

    int pc = -1, pr = -1;

    for ( int i = 0; i < 8; ++i ) {
        string tmp; cin >> tmp;
        for ( int j = 0; j < 8; ++j ) {
            if ( tmp[j] == '*' ) {
                pr = i; pc = j;
            }
        }
    }

    cout << c[pc] << char(r[pr]+'0') << endl;
}