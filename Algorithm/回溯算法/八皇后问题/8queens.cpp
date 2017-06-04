#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

const int NUM_QUEENS = 8;
template <typename T>
class Grid {
private:
    T v[NUM_QUEENS][NUM_QUEENS] = { {0} };
public:
    /*
     * 皇后是按列进行放置的，每列只有一个皇后，本函数是检查前col-1个皇后和现在放置在
     * (col, row) 上的皇后是否冲突
     */
    bool isSafe(int col, int row) {
        for (int i = 0; i < NUM_QUEENS; ++i) {
            for (int j = 0; j < col; ++j) {
                if (v[i][j] == 1) {
                    if ( i == row || abs(i - row) == abs(j - col) )
                        return false;
                }
            }
        }
        return true;
    }
    bool solve(int col) {
        // 进入该函数时，前col-1个皇后已经正确的放置在了棋盘上
        if (col >= NUM_QUEENS) {
            print();
            return true;
        }
        for (int rowToTry = 0; rowToTry < NUM_QUEENS; rowToTry++) {
            v[rowToTry][col] = 1;
            if (isSafe(col, rowToTry)) {
                solve(col + 1);     // recur to place rest
            }
            v[rowToTry][col] = 0;   // failed, remove, try again
        }
        return false;
    }
    void print() {
        static int count = 1;
        cout << "Case " << count++ << endl;
        for (int i = 0; i < NUM_QUEENS; i++) {
            for (int j = 0; j < NUM_QUEENS; j++) {
                v[i][j] == 1 ? printf("%c ", 2) : printf(". ");
            }
            cout << endl;
        }
        cout << endl;
    }

    void printSimply() {
        for (int i = 0; i < NUM_QUEENS; i++) {
            for (int j = 0; j < NUM_QUEENS; j++) {
                if(v[i][j] == 1)
                    cout << j + 1 << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    Grid<bool> board;
    board.solve(0);
    return 0;
}

