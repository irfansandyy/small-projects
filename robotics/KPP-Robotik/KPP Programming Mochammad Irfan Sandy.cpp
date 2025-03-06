#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

struct State {
    int x, y, time;
    bool canPassWalls, hasElectricianBuff;
    vector<char> path;

    State(int _x, int _y, bool _canPassWalls, bool _hasElectricianBuff,int _time, const vector<char>& _path) {
            this->x = _x;
            this->y = _y;
            this->canPassWalls = _canPassWalls;
            this->hasElectricianBuff = _hasElectricianBuff;
            this->time = _time;
            this->path = _path;
        }

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
        this->lastMove = c;
        return;
    }
};

class Maps {
public:
    int xSize, ySize, startX, startY, finishX, finishY;
    bool gameEnd = false;
    vector<vector<char>> m;

    Maps(int initializeX, int initializeY) {
        this->xSize = initializeX;
        this->ySize = initializeY;
    }

    void loadIntoMap() {
        for(int i = 0; i < this->ySize; i++) {
            vector<char> mapX;
            for(int j = 0; j < this->xSize; j++) {
                char c;
                cin >> c;
                if(c == 'S') {
                    this->startX = j;
                    this->startY = this->ySize - i - 1;
                }
                if(c == 'F') {
                    this->finishX = j;
                    this->finishY = this->ySize - i - 1;
                }
                mapX.push_back(c);
            }
            m.push_back(mapX);
        }
        reverse(m.begin(), m.end());
        return;
    }

    void updateMove(Robot *r) {
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
                this->gameEnd = true;
                break;
            default:
                break;
        }
        return;
    }

    vector<char> findOptimalPath() {
        vector<vector<vector<vector<bool>>>> visited(this->xSize, vector<vector<vector<bool>>>(this->ySize, vector<vector<bool>>(2, vector<bool>(2, false))));
        priority_queue<State, vector<State>, greater<State>> pq;
        pq.push(State(this->startX, this->startY, false, false, 0, vector<char>()));

        while (!pq.empty()) {
            State current = pq.top();
            pq.pop();

            if (current.x == this->finishX && current.y == this->finishY) {
                return current.path;
            }

            if (visited[current.x][current.y][current.canPassWalls][current.hasElectricianBuff]) continue;
            visited[current.x][current.y][current.canPassWalls][current.hasElectricianBuff] = true;

            for (int i = 0; i < 4; i++) {
                int nx = current.x + dx[i];
                int ny = current.y + dy[i];
                
                if (nx < 0 || nx >= this->xSize || ny < 0 || ny >= this->ySize) continue;
                if (m[ny][nx] == 'x' && !current.canPassWalls) continue;

                int newTime = current.time + (current.hasElectricianBuff ? 1 : 2);
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
    int mx, my;
    cin >> my >> mx;

    Maps gameMap(mx, my);
    gameMap.loadIntoMap();
    Robot player(gameMap.startX, gameMap.startY);

    vector<char> optimalPath = gameMap.findOptimalPath();

    if (optimalPath.empty()) {
        cout << "Peta tidak bisa diselesaikan" << endl;
    } else {
        cout << "Jalan tercepat: ";
        for (char move : optimalPath) {
            cout << move;
        }
        cout << endl;
        cout << "Jumlah gerakan: " << optimalPath.size() << endl;

        for (char move : optimalPath) {
            player.move(mx, my, move);
            if (!player.invalidMove) {
                gameMap.updateMove(&player);
            }
            if (gameMap.gameEnd) {
                break;
            }
        }

        if (!gameMap.gameEnd) {
            cout << "Robot gagal dalam mencapai tujuan :(" << endl;
        }
        cout << "Robot telah berjalan selama " << player.time << " menit" << endl;
    }

    return 0;
}