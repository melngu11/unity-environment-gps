#include <iostream>
#include <cmath>
#include <vector>
#include <set>         
#include <assert.h>     

const int N = 20; // size of the grid

double compute_distance(int x1, int y1, int x2, int y2){
    /**
     * Instead of setting constant distances I want you to
     * compute the Euclidean distance between two points
    */
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main (){

    std::vector<std::pair<int,int>> obstacles;
    
    obstacles.push_back(std::make_pair(5,5));
    obstacles.push_back(std::make_pair(5,6));

    std::vector<std::vector<char>> grid(N, std::vector<char>(N, '.'));
    for (int i = 0; i < obstacles.size(); i++){
        int obs_x = obstacles[i].first;
        int obs_y = obstacles[i].second;
        grid[obs_x][obs_y] = 'X';
    }

    assert(grid[5][5] == 'X');

    int current_x = 5;
    int current_y = 5;
    /**
     * Refactor to check if within obstacle
    */
    for (int i = 0; i < obstacles.size(); i++){
        int obs_x = obstacles[i].first;
        int obs_y = obstacles[i].second;

        if (current_x == obs_x && current_y == obs_y){
            std::cout << "Obstacle on top" << std::endl;
            std::cout << "Obstacle at: " << obs_x << " " << obs_y << std::endl;
        }
    }

    int next_x = 6;
    int next_y = 6;
    double distance = compute_distance(current_x, current_y, next_x, next_y);
    std::cout << "Distance: " << distance << std::endl;

    std::set<std::pair<int, int>> s;    
    int nx = 5;
    int ny = 5;
    s.insert(std::make_pair(nx,ny));

    int some_x = 5;
    int some_y = 5;
    if (s.find(std::make_pair(some_x, some_y)) != s.end()){
        std::cout << "Found" << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }
}

