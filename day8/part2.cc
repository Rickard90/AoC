#include <iostream>
#include <array>

using namespace std;

int main() {
    string line;
    getline(cin, line);
    int size = line.size();
    pair<int, int> tree[size][size];

    for (int y {}; y < size; y++) {
        for (int x {}; x < size; x++) {
            int hight = line[x]-'0';
            tree[x][y].first = hight; 
            tree[x][y].second = 0; 
        }
        getline(cin, line);
    }

    int best {-1};
    for (int x {}; x < size; x++) {
        for (int y {}; y < size; y++) {

            int left {}, right {}, up {}, down {};
            for (int l {x-1}; l >= 0; l--) {
                left++;
                if (tree[l][y].first >= tree[x][y].first)
                    break;
            }
            for (int r {x+1}; r < size; r++) {
                right++;
                if (tree[r][y].first >= tree[x][y].first)
                    break;
            }
            for (int u {y-1}; u >= 0; u--) {
                up++;
                if (tree[x][u].first >= tree[x][y].first)
                    break;
            }
            for (int d {y+1}; d < size; d++) {
                down++;
                if (tree[x][d].first >= tree[x][y].first)
                    break;
            }
            tree[x][y].second = left*right*up*down;
            best= best < left*right*up*down? left*right*up*down : best;
        }
    }

    cout << endl << best;
    return 0;
}