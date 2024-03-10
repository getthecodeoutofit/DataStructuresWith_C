#include<stdio.h>

int main(){
    int nodes,edges;
    int u,v;
    printf("Enter the number of nodes and edges: ");
    scanf("%d %d",&nodes,&edges);
    int matrix[nodes+1][edges+1];
    for(int i=0;i<edges;i++){
        printf("Enter the node having edge: ");
        scanf("%d %d",&u,&v);
        matrix[u][v]=1;
        matrix[v][u]=1;
    }
    return 0;
}