//
//  main.c
//  BFS and DFS
//
//  Created by Bikramjit Saha on 21/07/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
#include "Queue.h"
void BFS(int G[][8],int start,int n){
    int visited[8]={0},u,v;
    int i=start;
    printf("%d ",i);
    visited[i]=1;
    enqueue(i);
    while (!isEmpty()) {
        u=dequeue();
        for (v=1; v<n; v++) {
            if (G[u][v]==1 && visited[v]==0) {
                printf("%d ",v);
                visited[v]=1;
                enqueue(v);
            }
        }
    }
}
void DFS(int G[][8],int Start,int n ){
    static int visited[8]={0};
    int u=Start,v;
    if (visited[u]==0) {
        printf("%d ",u);
        visited[u]=1;
        for (v=1; v<n; v++) {
            if (G[u][v]==1 && visited[v]==0) {
                DFS(G, v, n);
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int G[8][8]={{0,0,0,0,0,0,0,0},
                {0,0,1,1,1,0,0,0},
                {0,1,0,1,0,0,0,0},
                {0,1,1,0,1,1,0,0},
                {0,1,0,1,0,1,0,0},
                {0,0,0,1,1,0,1,1},
                {0,0,0,0,0,1,0,0},
                {0,0,0,0,0,0,0,0}};
    BFS(G, 3, 8);
    printf("\n");
    DFS(G, 3, 8);
    printf("\n");
    return 0;
}
