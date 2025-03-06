#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include "mapgen.cpp"
using namespace std;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

struct State {
    int x, y;
    bool canPassWalls;
    bool hasElectricianBuff;
    double time;
    vector<char> path;

    State(int _x, int _y, bool _canPassWalls, bool _hasElectricianBuff,double _time, const vector<char>& _path)
        : x(_x), y(_y), canPassWalls(_canPassWalls), hasElectricianBuff(_hasElectricianBuff),time(_time), path(_path) {}

    bool operator>(const State& other) const {
        return time > other.time;
    }
};

class Robot {
public:
    int x, y;
    char lastMove = '0';
    int time = 0;
    int turnTime = 2;
    bool passThroughWall = false;

    Robot(int initialX, int initialY) {
        this->x = initialX;
        this->y = initialY;
    }

    bool move(int mx, int my, char c) {
        bool invalidMove = false;
        switch (c) {
            case 'U':
                if(this->y == my - 1) {
                    cout << "Robot nabrak, silahkan diperbaiki (keluar map)" << endl;
                    invalidMove = true;
                    break;
                }
                this->y++;
                this->time += this->turnTime;
                break;
            case 'D':
                if(this->y == 0) {
                    cout << "Robot nabrak, silahkan diperbaiki (keluar map)" << endl;
                    invalidMove = true;
                    break;
                }
                this->y--;
                this->time += this->turnTime;
                break;
            case 'L':
                if(this->x == 0) {
                    cout << "Robot nabrak, silahkan diperbaiki (keluar map)" << endl;
                    invalidMove = true;
                    break;
                }
                this->x--;
                this->time += this->turnTime;
                break;
            case 'R':
                if(this->x == mx - 1) {
                    cout << "Robot nabrak, silahkan diperbaiki (keluar map)" << endl;
                    invalidMove = true;
                    break;
                }
                this->x++;
                this->time += this->turnTime;
                break;
            default:
                cout << "Salah Input (gerakan tidak dihitung)" << endl;
                invalidMove = true;
                break;
        }
        if(invalidMove) {
            return invalidMove;
        }
        lastMove = c;
        return invalidMove;
    }
};

class Maps {
public:
    int xSize, ySize, finishX, finishY;
    vector<vector<char>> m;

    Maps(int initializeX, int initializeY) {
        this->xSize = initializeX;
        this->ySize = initializeY;
    }

    int* loadIntoMap(vector<vector<char>> _m) {
        static int robotCoordinate[2];
        for(int i = 0; i < this->ySize; i++) {
            for(int j = 0; j < this->xSize; j++) {
                char c;
                c = _m[i][j];
                if(c == 'S') {
                    robotCoordinate[0] = j;
                    robotCoordinate[1] = this->ySize - i - 1;
                }
                if(c == 'F') {
                    this->finishX = j;
                    this->finishY = this->ySize - i - 1;
                }
            }
        }
        reverse(_m.begin(), _m.end());
        this->m = _m;
        return robotCoordinate;
    }

    bool updateMove(Robot *r) {
        bool gameEnd = false;
        switch (this->m[r->y][r->x]) {
            case 'x':
                if(!r->passThroughWall) {
                    cout << "Robot nabrak, silahkan diperbaiki" << endl;
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
                r->turnTime = 1;
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
                gameEnd = true;
                break;
            default:
                break;
        }
        return gameEnd;
    }

    vector<char> findOptimalPath(int startX, int startY) {
        vector<vector<vector<vector<bool>>>> visited(xSize, vector<vector<vector<bool>>>(ySize, vector<vector<bool>>(2, vector<bool>(2, false))));
        priority_queue<State, vector<State>, greater<State>> pq;
        pq.push(State(startX, startY, false, false, 0, vector<char>()));

        while (!pq.empty()) {
            State current = pq.top();
            pq.pop();

            if (current.x == finishX && current.y == finishY) {
                return current.path;
            }

            if (visited[current.x][current.y][current.canPassWalls][current.hasElectricianBuff]) continue;
            visited[current.x][current.y][current.canPassWalls][current.hasElectricianBuff] = true;

            for (int i = 0; i < 4; i++) {
                int nx = current.x + dx[i];
                int ny = current.y + dy[i];
                
                if (nx < 0 || nx >= xSize || ny < 0 || ny >= ySize) continue;
                if (m[ny][nx] == 'x' && !current.canPassWalls) continue;

                double newTime = current.time + (current.hasElectricianBuff ? 1 : 2);
                bool newCanPassWalls = current.canPassWalls;
                bool newHasElectricianBuff = current.hasElectricianBuff;
                vector<char> newPath = current.path;

                if (m[ny][nx] == 'M') {
                    newCanPassWalls = true;
                } else if (m[ny][nx] == 'E') {
                    newHasElectricianBuff = true;
                } else if (m[ny][nx] == 'O') {
                    newTime = current.time * 2 + (current.hasElectricianBuff ? 1 : 2);
                }

                char direction = (i == 0) ? 'U' : (i == 1) ? 'D' : (i == 2) ? 'R' : 'L';
                newPath.push_back(direction);

                if (!visited[nx][ny][newCanPassWalls][newHasElectricianBuff]) {
                    pq.push(State(nx, ny, newCanPassWalls, newHasElectricianBuff, newTime, newPath));
                }
            }
        }
        return vector<char>();
    }
};

int main() {
    while(true) {
        int mx= 100, my = 100;

        vector<vector<char>> m = generateMap();

        Maps gameMap(mx, my);
        int* rc = gameMap.loadIntoMap(m);
        Robot player(rc[0], rc[1]);

        vector<char> optimalPath = gameMap.findOptimalPath(rc[0], rc[1]);

        if (optimalPath.empty()) {
            cout << "No path found to reach the goal!" << endl;
        } else {
            cout << "Optimal path: ";
            for (char move : optimalPath) {
                cout << move;
            }
            cout << endl;
            cout << "Number of moves: " << optimalPath.size() << endl;

            bool gameEnd = false;
            for (char move : optimalPath) {
                bool invalidMove = player.move(mx, my, move);
                if (!invalidMove) {
                    gameEnd = gameMap.updateMove(&player);
                }
                if (gameEnd) {
                    break;
                }
            }

            if (!gameEnd) {
                cout << "Robot gagal dalam mencapai tujuan :(" << endl;
            }

            cout << "Robot telah berjalan selama " << player.time << " menit" << endl;
        }
    }
    return 0;
}