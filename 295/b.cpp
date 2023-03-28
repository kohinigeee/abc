#include<iostream>
#include<vector>

using namespace std;

int di[] = {1,-1, 1, -1};
int dj[] = {1, 1, -1, -1};
int r,c;

void fn(int i, int j, int power, vector<string>& board) {
            for ( int dx = 0; dx <= power; ++dx ) {
                int dy = power-dx;
                for ( int k = 0; k < 4; ++k ) {
                    int new_i = i+dy*di[k];
                    int new_j = j+dx*dj[k];

                    if ( new_i >= 0 && new_i < r && new_j >= 0 && new_j < c ) {
                        if ( board[new_i][new_j] == '#' ) board[new_i][new_j] = '.';
                    }
                }
            }
    board[i][j] = '.';
    if ( power >= 1 ) fn(i, j, power-1, board);
}

int main()
{
    vector<string> board;

    cin >> r >> c;
    for ( int i = 0; i < r; ++i ) {
        string tmp; cin >> tmp;
        board.push_back(tmp);
    }

    for ( int i = 0; i < r; ++i ) {
        for ( int j = 0; j < c; ++j ) {
            if ( board[i][j] == '.' || board[i][j] == '#' ) continue;
            int power = board[i][j]-'0';

            fn(i,j,power,board);
        }
    }
    for ( auto s : board ) cout << s << endl;
}