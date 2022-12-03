#include <iostream>
#include <set>

using namespace std;

int main() {
    string line;
    int sum {};

    while (getline(cin, line)) {
        set<int> part1;
        for (size_t i {}; i < line.size()/2; i++) {
            if (line[i] > 96 && line[i] < (96+27)) {
                part1.emplace(line[i]-96);
            } else {
                part1.emplace(line[i]-65+27);
            }
        }
        for (size_t i {line.size()/2}; i < line.size(); i++) {
            if (line[i] > 96 && line[i] < (96+27)) {
                if (part1.count(line[i]-96)) {
                    sum += line[i]-96;
                    cout << line[i]-96 << endl;
                    break;
                }
            } else {
                if (part1.count(line[i]-65+27)) {
                    sum += line[i]-65+27;
                    cout << line[i]-65+27 << endl;
                    break;
                }
            }
        }

    }

    //cout << static_cast<int>('a')-96 << endl;
    //cout << static_cast<int>('A')-65+27 << endl;
    //cout << static_cast<int>('P')-65+27 << endl;
    cout << sum;

    return 0;
}