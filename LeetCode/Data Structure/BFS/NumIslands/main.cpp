#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Position{
public:
    int i;
    int j;
    
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int num = 0;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == '1'){
                    num++;
                    Position pos;
                    pos.i = i;
                    pos.j = j;
                    bfs(pos, grid);
                    //cout<<"ok"<<endl;
                }
            }
        }

        return num;
    }

    int bfs(Position pos, vector<vector<char>>& grid){
        queue<Position> que;
        grid[pos.i][pos.j] = '0';
        que.push(pos);
        while (!que.empty())
        {
            Position cur = que.front();
            int i = cur.i;
            int j = cur.j;
            //cout << i << ", " << j << endl;
            if(j+1 < grid[i].size() && grid[i][j+1] == '1'){
                Position right;
                right.i = i;
                right.j = j+1;
                grid[i][j+1] = '0';
                que.push(right);
                
            }
            if(j-1 >= 0 && grid[i][j-1] == '1'){
                Position left;
                left.i = i;
                left.j = j-1;
                grid[i][j-1] = '0';
                que.push(left);                
            }
            if(i+1 < grid.size() && grid[i + 1][j] == '1'){
                Position down;
                down.i = i+1;
                down.j = j;
                grid[i+1][j] = '0';
                que.push(down);                
            }
            if(i-1 >= 0 && grid[i - 1][j] == '1'){
                Position up;
                up.i = i-1;
                up.j = j;
                grid[i-1][j] = '0';
                que.push(up);                
            }

            
            que.pop();
            //cout << que.size() << endl;
        }
        return 0;
    }
};