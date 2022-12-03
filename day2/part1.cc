#include <iostream>
//A=Rock, B=Paper, C=Scissor
//X=Rock, Y=Paper, Z=Scissor
//Rock 1p, Paper 2p, Scissor 3p
//Loss 0p, Draw 3p, Win 6p

using namespace std;
int main() {

    string line;
    int score {};

    while(getline(cin, line)) {
        
        if (line[2] == 'X') {
            score+=1;
            if (line[0] == 'A') {
                score+=3;
            } else if (line[0] == 'B') {
                score+=0;
            } else {    //'C'
                score+=6;
            }
        } else if (line[2] == 'Y') {
            score+=2;
            if (line[0] == 'A') {
                score+=6;
            } else if (line[0] == 'B') {
                score+=3;
            } else {    //'C'
                score+=0;
            }
        } else {    //'Z'
            score+=3;
            if (line[0] == 'A') {
                score+=0;
            } else if (line[0] == 'B') {
                score+=6;
            } else {    //'C'
                score+=3;
            }
        }
    }
    cout << score;

    return 0;
}