#include <iostream>
#include <stack>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    stack<string> starting_lines;
    vector<stack<char>> stacks;
    string line;

    getline(cin, line);
    while (line[1] != '1') {
        starting_lines.push(line);
        getline(cin, line);
    }
    stacks.resize(line[line.size()-2]-'0');

    while (!starting_lines.empty()) {
        line = starting_lines.top();
        starting_lines.pop();
        for (size_t i = 0; i < line.size(); i++) {
            if (line[i] == '[') {
                stacks[i/4].push(line[i+1]);
            }
        }
    }

    getline(cin, line); //empty line
    while (getline(cin, line)) {
        stringstream ss;
        int amount, from, to;
        ss.str(line);
        ss >> line >> amount >> line >> from >> line >> to;
        for (int i = 0; i < amount; i++) {
            stacks[to-1].push(stacks[from-1].top());
            stacks[from-1].pop();
        }
        
    }
    for (auto s : stacks) {
        cout << s.top();
    }



    return 0;
}