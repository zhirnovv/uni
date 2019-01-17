#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

const int MAX = 21;
int start_i = 0, start_j = 0, finish_i = 0, finish_j = 0;

void labyrinthRead(int r, int c, int labyrinth[][MAX]) {
    cin.get();
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c + 1; j++) {
            char ch;
            ch = cin.get();
            switch (ch) {
            case 'X': {
                labyrinth[i][j] = -1;
                break;
            }
            case ' ': {
                labyrinth[i][j] = 0;
                break;
            }
            case 'F': {
                labyrinth[i][j] = 1;
                finish_i = i;
                finish_j = j;
                break;
            }
            case 'S': {
                labyrinth[i][j] = 0;
                start_i = i;
                start_j = j;
                break;
            }
            }
        }
    }
}

void pushSides(queue<int> *q_i, queue<int> *q_j, queue<int> *q_side, int positions[][MAX], int labyrinth[][MAX]) {
    int i = q_i->front();
    int j = q_j->front();
    int side = q_side->front();
    switch (side) {
    case 1: {
        if (labyrinth[i][j - 1] != -1 && positions[i][j - 1] != side) {
            q_i->push(i);
            q_j->push(j - 1);
            q_side->push(side);
            positions[i][j - 1] = side;
            labyrinth[i][j - 1] = labyrinth[i][j] + 1;
        }
        if (labyrinth[i - 1][j] != -1 && positions[i - 1][j] != 2) {
            q_i->push(i - 1);
            q_j->push(j);
            q_side->push(2);
            positions[i - 1][j] = 2;
            labyrinth[i - 1][j] = labyrinth[i][j] + 1;
        }
        break;
    }
    case 2: {
        if (labyrinth[i - 1][j] != -1 && positions[i - 1][j] != side) {
            q_i->push(i - 1);
            q_j->push(j);
            q_side->push(side);
            positions[i - 1][j] = side;
            labyrinth[i - 1][j] = labyrinth[i][j] + 1;
        }
        if (labyrinth[i][j + 1] != -1 && positions[i][j + 1] != 3) {
            q_i->push(i);
            q_j->push(j + 1);
            q_side->push(3);
            positions[i][j + 1] = 3;
            labyrinth[i][j + 1] = labyrinth[i][j] + 1;
        }
        break;
    }
    case 3: {
        if (labyrinth[i][j + 1] != -1 && positions[i][j + 1] != side) {
            q_i->push(i);
            q_j->push(j + 1);
            q_side->push(side);
            positions[i][j + 1] = side;
            labyrinth[i][j + 1] = labyrinth[i][j] + 1;
        }
        if (labyrinth[i + 1][j] != -1 && positions[i + 1][j] != 4) {
            q_i->push(i + 1);
            q_j->push(j);
            q_side->push(4);
            positions[i + 1][j] = 4;
            labyrinth[i + 1][j] = labyrinth[i][j] + 1;
        }
        break;
    }
    case 4: {
        if (labyrinth[i + 1][j] != -1 && positions[i + 1][j] != side) {
            q_i->push(i + 1);
            q_j->push(j);
            q_side->push(side);
            positions[i + 1][j] = side;
            labyrinth[i + 1][j] = labyrinth[i][j] + 1;
        }
        if (labyrinth[i][j - 1] != -1 && positions[i][j - 1] != 1) {
            q_i->push(i);
            q_j->push(j - 1);
            q_side->push(1);
            positions[i][j - 1] = 1;
            labyrinth[i][j - 1] = labyrinth[i][j] + 1;
        }
        break;
    }
    }
}

int bfs(int labyrinth[][MAX]){
    queue<int> q_i;
    queue<int> q_j;
    queue<int> q_side;
    int positions[MAX][MAX] = { {} };
    for (int i = 1; i < 5; i++) {
        q_i.push(start_i);
        q_j.push(start_j);
        q_side.push(i);
    }
    int i, j;
    while (i != finish_i || j != finish_j) {
        i = q_i.front();
        j = q_j.front();
        pushSides(&q_i, &q_j, &q_side, positions, labyrinth);
        q_i.pop();
        q_j.pop();
        q_side.pop();
    }
    return labyrinth[finish_i][finish_j];
}


int main() {
    int labyrinth[MAX][MAX] = {};
    static int r = 0, c = 0;
    cin >> r >> c;
    labyrinthRead(r, c, labyrinth);
    int steps = bfs(labyrinth);
    cout << steps << endl;
    return 0;
}
