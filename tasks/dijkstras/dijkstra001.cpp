// Dijkstra.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Current working cpp

#include <iostream>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

const int N = 20; // size of the grid
const double INF = 1e9; // a large value to represent infinity
const double DIAG_COST = 1.41; // cost of diagonal movement = ~sqrt(1)
const double STRAIGHT_COST = 1.0; // cost of horizontal or vertical movement

struct Node {
    int x, y;  // (x,y)
    double cost;
    Node(int x, int y, double cost) : x(x), y(y), cost(cost) {}
    // compare the cost of the two nodes, node with the highest priority (i.e., the lowest cost) is at the top
    bool operator < (const Node& other) const {
        return cost > other.cost;
    }
};

// compute the distance between two nodes if the coordinates are they share x or y coordinate then the movement is horizontal or vertical
// otherwise it is a diagonal movement
double dist(int x1, int y1, int x2, int y2) {
    if (x1 == x2 || y1 == y2) {
        return STRAIGHT_COST;
    }
    else {
        return DIAG_COST;
    }
}

// check if a node is valid (i.e., not an obstacle and within the grid)
bool valid(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= N) {
        return false; // out of bounds
    }
    if (x == 5 && y >= 5 && y <= 7) {
        return false; // obstacle
    }
    if (x == 10 && y == 12) {
        return false; // obstacle
    }
    if (x == 9 && y == 12) {
        return false; // obstacle
    }
    if (x == 8 && y == 12) {
        return false; // obstacle
    }
    if (x == 7 && y == 12) {
        return false; // obstacle
    }
    return true; // valid node
}

// implement Dijkstra's algorithm
void dijkstra(int sx, int sy, int gx, int gy, vector<vector<double>>& dists, vector<vector<pair<int, int>>>& prevs) {
   
    dists.assign(N, vector<double>(N, INF));     // Initialize the distances array to INF for all nodes for unvisited, cost to node is unknown
    prevs.assign(N, vector<pair<int, int>>(N, { -1, -1 }));         // Initialize the previous nodes array to - 1, -1 for all nodes. This value indicates that no previous node exists for the particular node
    dists[sx][sy] = 0; // distance to start node is 0
    // priority queue to store nodes in increasing order of distance
    priority_queue<Node> pq;
    pq.push(Node(sx, sy, 0));
    while (!pq.empty()) {
        Node curr = pq.top(); //smallest cost is at top
        pq.pop();
        int x = curr.x;
        int y = curr.y;
        double cost = curr.cost;
        //Check if the current node has already been visited with a shorter distance and skip it if so.
        if (dists[x][y] < cost) {
            continue; // this node has already been visited with a shorter distance, skip
        }
        // visit neighbors
        for (int dx = -1; dx <= 1; dx++) { //checks for constraint of grid, coordinates must be postiive
            for (int dy = -1; dy <= 1; dy++) {
                if (dx == 0 && dy == 0) {
                    continue; // don't consider the current node
                }
                int nx = x + dx;
                int ny = y + dy;
                if (valid(nx, ny)) {
                    double new_cost = cost + dist(x, y, nx, ny);
                    if (new_cost < dists[nx][ny]) {
                        dists[nx][ny] = new_cost; // update distance to neighbor
                        prevs[nx][ny] = { x, y }; // update previous node to backtrack the shortest path
                        pq.push(Node(nx, ny, new_cost)); // add neighbor to priority queue
                    }
                }
            }
        }
    }
}

int main() {
    // initialize the grid with obstacles, start, and goal nodes
    // '.' denotes nodes within the coordinate
    vector<vector<char>> grid(N, vector<char>(N, '.'));
    grid[0][0] = 'S'; // start node
    grid[N-1][N-1] = 'G'; // goal node (19,19)

    // Add obstacles marked by #
    grid[5][5] = '#';
    grid[5][6] = '#';
    grid[5][7] = '#';
    grid[10][12] = '#';
    grid[9][12] = '#';
    grid[8][12] = '#';
    grid[7][12] = '#';

    //print the grid after set up
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // run Dijkstra's algorithm to find the shortest path
    vector<vector<double>> dists;
    vector<vector<pair<int, int>>> prevs;
    dijkstra(0, 0, N - 1, N - 1, dists, prevs);

    // backtrack from the goal node to the start node to mark the shortest path with '*' 
    int x = N - 1, y = N - 1;
    while (x != 0 || y != 0) {
        grid[x][y] = '*';
        int nx = prevs[x][y].first;
        int ny = prevs[x][y].second;
        x = nx;
        y = ny;
    }
    grid[0][0] = 'S'; // mark the start node as 'S' again
    grid[N - 1][N - 1] = 'G'; // mark the goal node as 'G' again 

    // print the final grid with the shortest path

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}