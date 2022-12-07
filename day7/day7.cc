#include <iostream>
#include <map>

using namespace std;

int main() {
    string curr_dir;
    map<string, int> dir_size;
    string line;

    while (getline(cin, line)) {
        if (line == "$ ls") {
            while (getline(cin, line)) {
                if (line[0] == '$') {
                    break;
                } else { //ls results
                    if (line.substr(0,3) != "dir") {
                        string temp_dir = curr_dir;
                        int size = stoi(line.substr(0, line.find(' ')));
                        do {
                            dir_size[temp_dir] += size;
                            temp_dir = temp_dir.substr(0, temp_dir.substr(0, temp_dir.size()-1).rfind('/')+1);
                        } while (temp_dir != "/");
                    }
                }
            } 
        }

        if (line.substr(0, 4) == "$ cd") {
            if (line[5] == '.') {
                curr_dir = curr_dir.substr(0, curr_dir.substr(0, curr_dir.size()-1).rfind('/')+1);
            } else { //cd filename
                curr_dir += line.substr(5) + "/";
            }
        }
    }


    int const size_needed = dir_size["//"] - 40000000;
    int size {}, best {dir_size["//"]};
    string dir;
    for (auto a : dir_size) {
        if (a.second <= 100000) {
            size += a.second;
        }
        if (a.second-size_needed > 0 && a.second < best) {
            best = a.second;
            dir = a.first;
        }

    }
    
    //part1
    cout << "Answer for part 1: " << size << endl;
    //part2
    cout  << "Answer for part 2: " << dir << " " << best << endl;

    return 0;
}