#include <bits/stdc++.h>

using namespace std;


int main() {
    cin.sync_with_stdio(false);
    int N;
    cin >> N;
    vector<string> M;
    int START_X, START_Y;
    vector<vector<int>> d(N, vector<int>(N, INT_MAX));
    for(int i=0; i<N; ++i) {
        string temp;
        cin >> temp;
        M.push_back(temp);
        for(int j=0; j<N; ++j) {
            switch(temp[j]) {
                case 'K': START_Y = i; START_X = j; break;
                case '#': d[i][j] = 0;
            }
        }
    }
    if(START_Y == START_X && START_X == N-1) {
        cout << 0 << endl;
        return 0;
    }
    queue<tuple<int,int,int>> q;
    q.push(tuple<int, int, int>(START_Y, START_X, 1));
    d[START_Y][START_X] = 0;
    //All possible moves of a knight;
    int xdiffs[] = {-2, -2, -1, 1, 2, 2, 1, -1};
    int ydiffs[] = {-1,  1,  2, 2, 1, -1, -2, -2};
    while(!q.empty()) {
        tuple<int,int,int> current = q.front();
        int y = get<0>(current);
        int x = get<1>(current);
        int steps = get<2>(current);
        q.pop();
        for(int i=0; i<8; ++i) {
            int ny = y + ydiffs[i];
            int nx = x + xdiffs[i];
            if(0<=nx && nx<N && 0<=ny && ny<N) {
                if(steps < d[ny][nx]) {
                    d[ny][nx] = steps;
                    q.push(tuple<int,int,int>(ny, nx, 1+steps));
                    if(ny == N-1 && nx == N-1) {
                        cout << steps << endl;
                        return 0;
                    }
                }
            }
        } 
    }
    cout << -1 << endl;
    return 0;
}