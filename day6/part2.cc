#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

bool contains_duplicates(vector<char> v) {
    sort(v.begin(), v.end());
    return adjacent_find(v.begin(), v.end()) != v.end();
}

int main() {
    char newest {};
    int index {};
    string line {};
    cin >> newest;
    vector<char> previous (14, newest);

    while (cin >> newest) {
        previous[index%14] = newest;
        if (!contains_duplicates(previous)) {
            break;
        }
        index++;
    }

    cout << index+2;
    return 0;
}
