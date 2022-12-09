#include <iostream>
#include <set>

using namespace std;

int main() {
    string line;
    int h_x {}, h_y {}, t_x {}, t_y {};
    set<pair<int, int>> visited;

    pair<int, int> moves[5][5] = {{pair(1, 1), pair(1, 1), pair(0, 1), pair(-1, 1), pair(-1, 1)}, 
                                  {pair(1, 1), pair(0, 0), pair(0, 0), pair(0, 0), pair(-1, 1)},
                                  {pair(1, 0), pair(0, 0), pair(0, 0), pair(0, 0), pair(-1, 0)},
                                  {pair(1, -1), pair(0, 0), pair(0, 0), pair(0, 0), pair(-1, -1)},
                                  {pair(1, -1), pair(1, -1), pair(0, -1), pair(-1, -1), pair(-1, -1)}};

    while (getline(cin, line)) {
        int n = stoi(line.substr(2));
        int h_change_x {}, h_change_y {}, t_change_x {}, t_change_y {};
        if (line[0] == 'U') {
            h_change_y--;
        } else if (line[0] == 'D') {
            h_change_y++;
        } else if (line[0] == 'L') {
            h_change_x--;
        } else { //R
            h_change_x++;
        }
        for (; n > 0; n--) {
            h_x += h_change_x;
            h_y += h_change_y;
            t_change_x = moves[t_y-h_y+2][t_x-h_x+2].first;
            t_change_y = moves[t_y-h_y+2][t_x-h_x+2].second;
            t_x += t_change_x;
            t_y += t_change_y;
            visited.emplace(pair(t_x, t_y));
        }
    }

    cout << visited.size();

    return 0;
}