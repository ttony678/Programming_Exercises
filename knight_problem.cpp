#include <iostream>
using namespace std;

struct point {
    int x, y;
};

void ul(int **board, int m, int n, point start, int value) {
    //cout << board[0][0] << endl;
    point tempPoint;
    tempPoint.x = start.x - 1;
    tempPoint.y = start.y - 2;
    if(
}

void populateCells(int **board, int m, int n, point startPoint, int value){
    ul(board, m, n, startPoint, value);
}

bool isInBounds(point Point, int m, int n){
    // Ensuring start and end are in bounds of 2-D array
    if (Point.x < 0 || Point.x >= m || Point.y < 0 || Point.y >= n)
        cout << "Error" << endl;
        return 0;
    }
    else {return 1;}
}

int shortest_path(int m, int n, point start, point end) {

    // Creating 2-D array
    int **board;
    board = new int *[m];
    for (int i = 0; i < m; i++) {
        board[i] = new int[n];
    }

    // Populating board with -1 flags to denote unused spaces
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = -1;
        }
    }

    if(!isInBounds(start, m, n))
        return 0;
    if(!isInBounds(end, m, n))
        return 0;

    board[start.x][start.y] = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] != -1) {
                point tempStartPoint;
                tempStartPoint.x = i;
                tempStartPoint.y = j;
                int value = board[i][j];
                populateCells(board, m, n, tempStartPoint, value);
            }
        }
    }


    return 0;
}


int main() {

    point start;
    point end;
    start.x = 0;
    start.y = 0;
    end.x = 3;
    end.y = 3;

    int m = 5;
    int n = 5;

    int x = shortest_path(m, n, start, end);

    return 0;
}
