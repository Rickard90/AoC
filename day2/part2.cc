#include <iostream>
//A=Rock, B=Paper, C=Scissor
//X=Lose, Y=Draw, Z=Win
//Rock 1p, Paper 2p, Scissor 3p
//Loss 0p, Draw 3p, Win 6p

using namespace std;
int main() {

    string line;
    int score {};

    while(getline(cin, line)) {
        
        if (line[2] == 'X') {
            score+=0;
            if (line[0] == 'A') {
                score+=3;
            } else if (line[0] == 'B') {
                score+=1;
            } else {    //'C'
                score+=2;
            }
        } else if (line[2] == 'Y') {
            score+=3;
            if (line[0] == 'A') {
                score+=1;
            } else if (line[0] == 'B') {
                score+=2;
            } else {    //'C'
                score+=3;
            }
        } else {    //'Z'
            score+=6;
            if (line[0] == 'A') {
                score+=2;
            } else if (line[0] == 'B') {
                score+=3;
            } else {    //'C'
                score+=1;
            }
        }
    }
    cout << score;

    return 0;
}