#include <bits/stdc++.h>
using namespace std;

bool visited[MAXN];
void bfs(int root){
    memset(visited, 0, sizeof visited);
    queue<int> q;
    visited[root] = 1;
    q.push(root);
    while(!q.empty()){
        //get front node
        //pop front node
        //find adjacents of the front node
            //if an adjacent is not visited yet
                //mark it as visited and push it to queue
    }
}

int main(){

}
