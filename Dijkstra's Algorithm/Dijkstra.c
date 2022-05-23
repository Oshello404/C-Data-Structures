#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define MAX_DIS 999999


int cost[MAX_NODES][MAX_NODES];
int distance[MAX_NODES],path[MAX_NODES];

void initial(int m, int n);

void Dijkstra(int n);

void print_path(int n);

void initial(int m, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=i; j++)
        {
            cost[i][j]=MAX_DIS;
            cost[j][i]=MAX_DIS;
            if(j==i)
                cost[i][j]=0;
        }
    }
    int x,y,w;
    for(int i=0; i<m; i++)
    {
        scanf("%d%d%d",&x,&y,&w);
        cost[x][y]=w;
        cost[y][x]=w;
    }
}

void Dijkstra(int n)
{
    /*
        Calculate the distance from node 0 to all other nodes.
    */
    //initialize the arrays
    //visited records the nodes that have calculated
    //min records the shortest distance from other nodes to the current node
    //u represents the current node
    int visited[MAX_NODES],min,u;
    for(int i=0; i<n; i++)
    {
        path[i]=-1;
        visited[i]=0;
    }
    for(int i=0; i<n; i++)
    {
        distance[i]=cost[0][i];
        if(distance[i]<MAX_DIS)
            path[i]=0;
    }
    //Calculate the distances from 0 to other nodes
    u=0;
    for(int i=0; i<n; i++)
    {
        visited[u]=1;
        for(int j=0; j<n; j++)
        {
            //Determine if the addition of u will produce a closer path
            if(!visited[j]&&distance[u]+cost[u][j]<distance[j])
            {
                //update distance array and path array
                distance[j]=distance[u]+cost[u][j];
                path[j]=u;
            }
        }
        //Select the next node based on the shortest distance
        min=MAX_DIS;
        for(int j=0; j<n; j++)
        {
            if(visited[j]==0 && distance[j]<min)
            {
                u=j;
                min=distance[j];
            }
        }
    }
}

void print_path(int n)
{
    /*
        Output the shortest path and distance from node 0 to all other nodes.
    */
    int short_path[MAX_NODES],u,index;
    for(int i=0; i<n; i++)
    {
        index=0;
        if(i==0)
            printf("0->%d=0",i);
        else if(path[i]==-1)
            printf("0->%d=%d",i,MAX_DIS);
        else
        {
            //Store shortest path in short_path
            u=i;
            while(u!=0)
            {
                short_path[index++]=u;
                u=path[u];
            }
            short_path[index]=u;
            for(int j=index; j>0; j--)
                printf("%d->",short_path[j]);
            printf("%d=%d",short_path[0],distance[i]);
        }
        printf("\n");
    }
}

int main()
{
    int m,n;

    printf("Input the number of nodes:\n");
    scanf("%d",&n);
    printf("Input the number of edges:\n");
    scanf("%d",&m);
    printf("Input these edges:\n");
    initial(m,n);
    Dijkstra(n);
    print_path(n);
    return 0;
}
