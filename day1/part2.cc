#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string line;
    int sum {};
    vector<int> most = {0,0,0};


    while (true) {
        sum = 0;
        do {
            if (!getline(cin, line)) {
                cout << most[0]+most[1]+most[2];
                return 0;
            }
            if (line != "") {
                sum += stoi(line);
            }
        } while (line != "");
        most[0] = sum > most[0]? sum: most[0];
        sort(most.begin(), most.end());

    }
}