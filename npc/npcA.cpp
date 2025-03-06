#include <iostream>
using namespace std;

int main() {
    int place[2], pisi[2], elsi[2], vdiff1, vdiff2, turn = 0, diff = 0;
    char c;
    cin >> place[0] >> place[1];
    cin >> pisi[0] >> pisi[1];
    cin >> elsi[0] >> elsi[1];
    cin >> c;

    while((pisi[0] != elsi[0] || pisi[1] != elsi[1]) && c == 'P') { 
        vdiff1 = abs(elsi[0] - pisi[0] + elsi[1] - pisi[1]);           
        if(turn % 2 == 0) {   
            if((pisi[0] < elsi[0]) && (pisi[0] != elsi[0])) {
                pisi[0]++;
                turn++;
            } else if(pisi[0] > elsi[0] && (pisi[0] != elsi[0])) {
                pisi[0]--;
                turn++;
            } else if(pisi[1] < elsi[1]) {
                pisi[1]++;
                turn++;
            } else if(pisi[1] > elsi[1]) {
                pisi[1]--;
                turn++;
            }
        }
        if(turn % 2 == 1) {
            if((elsi[0] < pisi[0]) && (pisi[0] != elsi[0]) && (elsi[0] > place[0])) {
                elsi[0]--;
                turn++;
            } else if((elsi[0] > pisi[0]) && (pisi[0] != elsi[0]) && (elsi[0] < place[0])) {
                elsi[0]++;
                turn++;
            } else if((elsi[1] < pisi[1]) && (elsi[1] > place[1])) {
                elsi[1]--;
                turn++;
            } else if((elsi[1] > pisi[1]) && (elsi[1] < place[1])) {
                elsi[1]++;
                turn++;
            } else if((pisi[0] != elsi[0]) && (elsi[0] > place[0])) {
                elsi[0]--;
                turn++;
            } else if((pisi[0] != elsi[0]) && (elsi[0] < place[0])) {
                elsi[0]++;
                turn++;
            } else if(elsi[1] > place[1]) {
                elsi[1]--;
                turn++;
            } else if(elsi[1] < place[1]) {
                elsi[1]++;
                turn++;
            }
        }
        
        vdiff2 = abs(elsi[0] - pisi[0] + elsi[1] - pisi[1]);

        if(vdiff1 == vdiff2) {
            diff++;
        }
        if(diff > 4) {
            cout << "0" << endl;
            break;
        }
    }

    while((pisi[0] != elsi[0] || pisi[1] != elsi[1]) && c == 'E') { 
        vdiff1 = abs(elsi[0] - pisi[0] + elsi[1] - pisi[1]);           
        if(turn % 2 == 1) {   
            if((pisi[0] < elsi[0]) && (pisi[0] != elsi[0])) {
                pisi[0]++;
                turn++;
            } else if(pisi[0] > elsi[0] && (pisi[0] != elsi[0])) {
                pisi[0]--;
                turn++;
            } else if(pisi[1] < elsi[1]) {
                pisi[1]++;
                turn++;
            } else if(pisi[1] > elsi[1]) {
                pisi[1]--;
                turn++;
            }
        }
        if(turn % 2 == 0) {
            if((elsi[0] < pisi[0]) && (pisi[0] != elsi[0]) && (elsi[0] > place[0])) {
                elsi[0]--;
                turn++;
            } else if((elsi[0] > pisi[0]) && (pisi[0] != elsi[0]) && (elsi[0] < place[0])) {
                elsi[0]++;
                turn++;
            } else if((elsi[1] < pisi[1]) && (elsi[1] > place[1])) {
                elsi[1]--;
                turn++;
            } else if((elsi[1] > pisi[1]) && (elsi[1] < place[1])) {
                elsi[1]++;
                turn++;
            } else if((pisi[0] != elsi[0]) && (elsi[0] > place[0])) {
                elsi[0]--;
                turn++;
            } else if((pisi[0] != elsi[0]) && (elsi[0] < place[0])) {
                elsi[0]++;
                turn++;
            } else if(elsi[1] > place[1]) {
                elsi[1]--;
                turn++;
            } else if(elsi[1] < place[1]) {
                elsi[1]++;
                turn++;
            }
        }

        cout << elsi[0] << " " << elsi[1] << endl;
        cout << pisi[0] << " " << pisi[1] << endl;
        
        vdiff2 = abs(elsi[0] - pisi[0] + elsi[1] - pisi[1]);

        if(vdiff1 == vdiff2) {
            diff++;
        }
        if(diff > 4) {
            cout << "0" << endl;
            break;
        }
    }

    if(diff <= 4) {
        cout << turn << endl;
    }
}