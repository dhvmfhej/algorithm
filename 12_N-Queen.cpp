#include <iostream>
using namespace std;

int col[10];
char board[10][10];
int N, total = 0;

bool promising(int row){
    int r = 0;
    bool ret = true;
    while (r < row && ret) {
        if (col[r] == col[row] || abs(col[r] - col[row]) == row - r)
            ret = false;
        r++;
    }
    return ret;
}

void n_queen(int x) {
    if (x == N) {
        total++;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                printf("%c", board[i][j]);
            puts("");
        }
    }
    else {
        for (int i = 0; i < N; i++) {
            board[x][i] = 'Q';
            col[x] = i;
            if (promising(x))
                n_queen(x + 1);
            board[x][i] = 'X';
        }
    }
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        total = 0;
        cin >> N;
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                board[i][j] = 'X';
        n_queen(0);
        if (!total)
            puts("");
    }
}