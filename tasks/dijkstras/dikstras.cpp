#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define INF = 1000000;

//Define grid
const int ROW = 20;
const int COL = 20;


int grid[ROW][COL];
int distance[ROW][COL];
bool visisted[ROW][COL];
pair<int,int> parent[ROW][COL];

//Get neighbors of current node
vector<pair<int,int>> get_neighbors(pair<int,int> &current){
    int row = current.first;
    int col = current.second;
    //Vector of neighboring nodes
    vector<pair<int,int>> neighbors;

   

}


void dijstra(pair<int,int> start, pair<int,int>goal){
    return;
}

int main(){
    for (int i = 0; i <20; i++){
        for (int j = 0 ; j < 20; j++){
            grid[i][j] = 0;
        }
    }
}
