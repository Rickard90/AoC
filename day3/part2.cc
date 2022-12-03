#include <iostream>
#include <set>

using namespace std;

int main() {
    string line1, line2, line3;
    int sum {};

    while (getline(cin, line1)) {
        set<int> elf1, elf2;
        getline(cin,line2);
        getline(cin,line3);
        for (char c : line1) {
            if (c > 96 && c < (96+27)) {
                elf1.emplace(c-96);
            } else {
                elf1.emplace(c-65+27);
            }
        }
        for (char c : line2) {
            if (c > 96 && c < (96+27)) {
                elf2.emplace(c-96);
            } else {
                elf2.emplace(c-65+27);
            }
        }
        for (char c : line3) {
            if (c > 96 && c < (96+27)) {
                if (elf1.count(c-96) && elf2.count(c-96)) {
                    sum += c-96;
                    break;
                }
            } else {
                if (elf1.count(c-65+27) && elf2.count(c-65+27)) {
                    sum += c-65+27;
                    break;
                }
            }
        }
    }

    cout << sum;

    return 0;
}