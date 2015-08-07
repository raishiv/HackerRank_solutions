/*Problem Statement

Given an undirected graph consisting of N nodes (labelled 1 to N) where a specific given node S represents the start position and an edge between any two nodes is of length 6 units in the graph.

It is required to calculate the shortest distance from start position (Node S) to all of the other nodes in the graph.

Note 1: If a node is unreachable , the distance is assumed as −1. 
Note 2: The length of each edge in the graph is 6 units.

Input Format

The first line contains T, denoting the number of test cases. 
First line of each test case has two integers N, denoting the number of nodes in the graph and M, denoting the number of edges in the graph. 
The next M lines each consist of two space separated integers x y, where x and y denote the two node between which the edge exists. 
The last line has an integer S, denoting the starting position.

Constraints 
1≤T≤10 
2≤N≤1000 
1≤M≤N×(N−1)2 
1≤x,y,S≤N

While performing the traversal, if there are edges between the same pair of nodes with different weights, the last one (most recent) is to be considered as the only edge between them.

Output Format

For each of T test cases, print a single line consisting of N−1 space separated integers, denoting the shortest distances of the N-1 nodes from starting position S.

For unreachble nodes, print −1.*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<queue>
using namespace std;


int main() { 
    int T;
    cin>>T;
    while(T--){
        int N,M;
        cin>>N>>M;
        vector<bool> v(N+1,false);
        int edge = M;
        vector< vector<int> > graph(N+1);
        int a,b;
        while(edge--){
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        int S;
        cin>>S;
        vector<int> dist(N+1,0);
        queue<int> q;
        q.push(S);
        v[S] = true;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            for(int i=0; i< graph[temp].size(); i++){
                if(v[(graph[temp][i])]== false){
                    q.push(graph[temp][i]);
                    v[(graph[temp][i])] = true;
                    dist[(graph[temp][i])] = dist[temp] + 6; 
                }
                
            }
        }
        for(int j=1; j<=N;j++){
            if(dist[j]== 0){
                dist[j] = -1;
            }
        }
       
        for(int k=1; k< dist.size(); k++){
            if(k != S){
                cout<<dist[k]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
