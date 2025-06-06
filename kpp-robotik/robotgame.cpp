#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Robot {
public:
    int x, y;
    char lastMove = '0';
    float time = 0;
    float turnTime = 2;
    bool passThroughWall = false;
    bool invalidMove = false;

    Robot(int initialX, int initialY) {
        this->x = initialX;
        this->y = initialY;
    }

    void move(int mx, int my, char c) {
        this->invalidMove = false;
        switch (c) {
            case 'U':
                if(this->y == my - 1) {
                    cout << "Robot nabrak, silahkan diperbaiki (keluar map)" << endl;
                    this->invalidMove = true;
                    break;
                }
                this->y++;
                this->time += this->turnTime;
                break;
            case 'D':
                if(this->y == 0) {
                    cout << "Robot nabrak, silahkan diperbaiki (keluar map)" << endl;
                    this->invalidMove = true;
                    break;
                }
                this->y--;
                this->time += this->turnTime;
                break;
            case 'L':
                if(this->x == 0) {
                    cout << "Robot nabrak, silahkan diperbaiki (keluar map)" << endl;
                    this->invalidMove = true;
                    break;
                }
                this->x--;
                this->time += this->turnTime;
                break;
            case 'R':
                if(this->x == mx - 1) {
                    cout << "Robot nabrak, silahkan diperbaiki (keluar map)" << endl;
                    this->invalidMove = true;
                    break;
                }
                this->x++;
                this->time += this->turnTime;
                break;
            default:
                cout << "Salah Input (gerakan tidak dihitung)" << endl;
                this->invalidMove = true;
                break;
        }
        if(this->invalidMove) {
            return;
        }
        lastMove = c;
        return;
    }
};

class Maps {
public:
    int xSize, ySize;
    bool gameEnd = false;
    vector<vector<char>> m;

    Maps(int initializeX, int initializeY) {
        this->xSize = initializeX;
        this->ySize = initializeY;
    }

    int* loadIntoMap() {
        static int robotCoordinate[2];
        for(int i = 0; i < this->ySize; i++) {
            vector<char> mapX;
            for(int j = 0; j < this->xSize; j++) {
                char c;
                cin >> c;
                if(c == 'S') {
                    robotCoordinate[0] = j;
                    robotCoordinate[1] = this->ySize - i - 1;
                }
                mapX.push_back(c);
            }
            m.push_back(mapX);
        }
        reverse(m.begin(), m.end());
        return robotCoordinate;
    }

    void updateMove(Robot *r) {
        this->gameEnd = false;
        switch (this->m[r->y][r->x]) {
            case 'x':
                if(!r->passThroughWall) {
                    cout << "Robot nabrak, silahkan diperbaiki" << endl;
                    r->time -= r->turnTime;
                    switch (r->lastMove) {
                        case 'U':
                            r->y--;
                            break;
                        case 'D':
                            r->y++;
                            break;
                        case 'L':
                            r->x++;
                            break;
                        case 'R':
                            r->x--;
                            break;
                        default:
                            break;
                    }
                }
                break;
            case 'M':
                cout << "Bertemu dengan mekanik, siap membasmi rintangan" << endl;
                r->passThroughWall = true;
                break;
            case 'E':
                cout << "Bertemu dengan electrical, kecepatan roda naik menjadi 200%" << endl;
                r->turnTime /= 2;
                break;
            case 'P':
                cout << "Sedang mencari garis finish?" << endl;
                break;
            case 'O':
                cout << "Bertemu dengan official, diajak ngonten bareng" << endl;
                r->time *= 2;
                break;
            case 'F':
                cout << "Robot berhasil mencapai tujuan" << endl;
                this->gameEnd = true;
                break;
            default:
                break;
        }
        return;
    }
};

int main () {
    int mx, my, turn;
    int* rc;
    cin >> my >> mx;

    Maps gameMap(mx, my);
    rc = gameMap.loadIntoMap();
    Robot player(rc[0], rc[1]);

    cin >> turn;
    for(int i = 0; i < turn; i++) {
        char c;
        cin >> c;
        player.move(mx, my, c);
        if(!player.invalidMove) {   
            gameMap.updateMove(&player);
        }
        if(gameMap.gameEnd) {
            break;
        }
    }

    if(!gameMap.gameEnd) {
        cout << "Robot gagal dalam mencapai tujuan :(" << endl;
    }

    cout << "Robot telah berjalan selama " << player.time << " menit" << endl;

    return 0;
}