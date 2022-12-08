#include <iostream>
#include <array>

using namespace std;

int main() {
    string line;
    getline(cin, line);
    int size = line.size();
    pair<int, bool> tree[size][size];
    int count {};

    for (int y {}; y < size; y++) {
        for (int x {}; x < size; x++) {
            int hight = line[x]-'0';
            tree[x][y].first = hight; 
            tree[x][y].second = false; 
        }
        getline(cin, line);
    }


    for (int x {}; x < size; x++) {
        int highest {-1};
        for (int y {}; y < size; y++) {
            if (highest < tree[x][y].first) {
                highest = tree[x][y].first;
                tree[x][y].second = true;
            }
        }
    }
    for (int x {}; x < size; x++) {
        int highest {-1};
        for (int y {size-1}; y >= 0; y--) {
            if (highest < tree[x][y].first) {
                highest = tree[x][y].first;
                tree[x][y].second = true;
            }
        }
    }
    for (int y {}; y < size; y++) {
        int highest {-1};
        for (int x {}; x < size; x++) {
            if (highest < tree[x][y].first) {
                highest = tree[x][y].first;
                tree[x][y].second = true;
            }
        }
    }
    for (int y {}; y < size; y++) {
        int highest {-1};
        for (int x {size-1}; x >= 0; x--) {
            if (highest < tree[x][y].first) {
                highest = tree[x][y].first;
                tree[x][y].second = true;
            }
        }
    }

    for (int x {}; x < size; x++) {
        for (int y {}; y < size; y++) {
        if (tree[x][y].second)
            count++;
        }
    }

    cout << count;

    return 0;
}