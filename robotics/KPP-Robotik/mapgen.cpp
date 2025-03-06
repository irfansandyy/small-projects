#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

const int SIZE = 100;
const char WALL = 'x';
const char EMPTY = '.';
const char START = 'S';
const char FINISH = 'F';
const char MECHANIC = 'M';
const char ELECTRICIAN = 'E';
const char PROGRAMMER = 'P';
const char OFFICIAL = 'O';

vector<vector<char>> generateMap() {
    vector<vector<char>> map(SIZE, vector<char>(SIZE, EMPTY));
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, SIZE - 1);

    // Place walls randomly (about 30% of the map)
    for (int i = 0; i < SIZE * SIZE * 0.6; ++i) {
        int x = dis(gen);
        int y = dis(gen);
        map[y][x] = WALL;
    }

    // Place start, finish, and special tiles
    vector<pair<int, int>> specialPositions;
    for (int i = 0; i < 6; ++i) {  // Start, Finish, M, E, P, O
        int x, y;
        do {
            x = dis(gen);
            y = dis(gen);
        } while (map[y][x] != EMPTY || find(specialPositions.begin(), specialPositions.end(), make_pair(x, y)) != specialPositions.end());
        specialPositions.push_back({x, y});
    }

    map[specialPositions[0].second][specialPositions[0].first] = START;
    map[specialPositions[1].second][specialPositions[1].first] = FINISH;
    map[specialPositions[2].second][specialPositions[2].first] = MECHANIC;
    map[specialPositions[3].second][specialPositions[3].first] = ELECTRICIAN;
    map[specialPositions[4].second][specialPositions[4].first] = PROGRAMMER;
    map[specialPositions[5].second][specialPositions[5].first] = OFFICIAL;

    // Ensure a path exists
    int currentX = specialPositions[0].first;
    int currentY = specialPositions[0].second;
    for (long long unsigned int i = 1; i < specialPositions.size(); ++i) {
        int targetX = specialPositions[i].first;
        int targetY = specialPositions[i].second;
        while (currentX != targetX || currentY != targetY) {
            if (currentX < targetX) currentX++;
            else if (currentX > targetX) currentX--;
            if (currentY < targetY) currentY++;
            else if (currentY > targetY) currentY--;
            if (map[currentY][currentX] == WALL) map[currentY][currentX] = EMPTY;
        }
    }

    return map;
}
