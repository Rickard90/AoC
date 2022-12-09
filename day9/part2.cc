#include <iostream>
#include <set>

using namespace std;

int main() {
    string line;
    int x[10] {} , y[10] {};
    set<pair<int, int>> visited;

    pair<int, int> moves[5][5] = {{pair(1, 1), pair(1, 1), pair(0, 1), pair(-1, 1), pair(-1, 1)}, 
                                  {pair(1, 1), pair(0, 0), pair(0, 0), pair(0, 0), pair(-1, 1)},
                                  {pair(1, 0), pair(0, 0), pair(0, 0), pair(0, 0), pair(-1, 0)},
                                  {pair(1, -1), pair(0, 0), pair(0, 0), pair(0, 0), pair(-1, -1)},
                                  {pair(1, -1), pair(1, -1), pair(0, -1), pair(-1, -1), pair(-1, -1)}};

    while (getline(cin, line)) {
        int n = stoi(line.substr(2));
        for (; n > 0; n--) {
            if (line[0] == 'U') {
                y[0]--;
            } else if (line[0] == 'D') {
                y[0]++;
            } else if (line[0] == 'L') {
                x[0]--;
            } else { //R
                x[0]++;
            }
            int change_x, change_y;
            for (int i = 1; i < 10; i++){
                change_x = moves[y[i]-y[i-1]+2][x[i]-x[i-1]+2].first;
                change_y = moves[y[i]-y[i-1]+2][x[i]-x[i-1]+2].second;
                x[i] += change_x;
                y[i] += change_y;
            }
            visited.emplace(pair(y[9], x[9]));
        }
    }

    cout << visited.size();

    return 0;
}