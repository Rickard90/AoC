#include <iostream>
#include <sstream>

using namespace std;

int main() {
    stringstream ss;
    string line;
    int result, a_low, a_high, b_low, b_high;
    char c;

    while (getline(cin, line)) {
        ss.str(line);
        ss >> a_low >> c >> a_high >> c >> b_low >> c >> b_high;
        ss.clear();
        if ((a_low <= b_low && a_high >= b_high) || (a_low >= b_low && a_high <= b_high)) {
            result++;
        }
    }
    cout << result;
    return 0;
}