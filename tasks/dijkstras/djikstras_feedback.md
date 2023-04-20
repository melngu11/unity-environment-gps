# Djikstra's Feedback
I got the code to compile and the algorithm is correct, nice job! I have a couple of feedback remarks/suggestions

**Obstacles**
https://github.com/melngu11/unity-environment-gps/blob/main/tasks/dijkstras/dijkstra001.cpp#108

https://github.com/melngu11/unity-environment-gps/blob/main/tasks/dijkstras/dijkstra001.cpp#39

For appending the obstacles I suggest you initialize a vector or set of obstacles and then loop through the coordinates to append it to the grid. This gives you two advantages: 
- It's easier to read and to add additional coordinates to your map 
- When you interface this with your valid check you don't have to add these coordinates for your condition check 
- Also please refactor your method name from valid to is_valid

Here's the example

```cpp
#include <iostream>
#include <cmath>
#include <vector>
#include <assert.h>     

int main ()
{
    const int N = 20; // size of the grid

    //Obstacle List
    std::vector<std::pair<int,int>> obstacles;
    obstacles.push_back(std::make_pair(5,5));
    obstacles.push_back(std::make_pair(5,6));

    std::vector<std::vector<char>> grid(N, std::vector<char>(N, '.'));
    //append obstacles to our grid
    for (int i = 0; i < obstacles.size(); i++){
        int obs_x = obstacles[i].first;
        int obs_y = obstacles[i].second;
        grid[obs_x][obs_y] = 'X';
    }
    //sanity check to make sure that coordinate 5,5 is an obtacle
    assert(grid[5][5] == 'X');

    //check if current position is obstacle, your valid method    
    for (int i = 0; i < obstacles.size(); i++){
        int obs_x = obstacles[i].first;
        int obs_y = obstacles[i].second;

        if (current_x == obs_x && current_y == obs_y){
            std::cout << "Obstacle on top" << std::endl;
            std::cout << "Obstacle at: " << obs_x << " " << obs_y << std::endl;
        }
    }
    
}

```

**Dist method**
https://github.com/melngu11/unity-environment-gps/blob/main/tasks/dijkstras/dijkstra001.cpp#29

Nice job on implementing this method! I have a couple of suggestions for here as well:
- Could you please refactor the method name from dist to compute_distance()? 
- Also I see that you set it to your constant **STRAIGHT_COST** and **DIAG_COST**,I would like you to change the implementation of this method by computing the euclidean(Pythagorean theorem) distance, here's an example

```cpp
double compute_distance(int x1, int y1, int x2, int y2){
    /**
     * Instead of setting constant distances I want you to
     * compute the Euclidean distance between two points
    */
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

```
