#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

typedef struct _adjlist {
     int node;
     struct _adjlist *link;
} adjlist;

typedef struct {
  int size;
  int last;
  int *elements;
} queue;

queue* createQ(int size)
{
  queue *q;
  q = (queue*)malloc(sizeof(queue));
  q->size = size;
  q->elements = (int*)malloc(size * sizeof(int));
  q->last = -1;
  return q;
}

int IsEmptyQ(queue *q){
  if (q->last == -1) return 1;
  else return 0;
}

int IsFullQ(queue *q){
  if (q->last == q->size - 1) return 1;
  else return 0;
}


void enqueue(queue *q, int e){
  if (!IsFullQ(q)) {
	q->last++;
	q->elements[q->last] = e;
  }
  else  printf("Error\n");
}

int dequeue(queue *q){
  int i, j;
  if (!IsEmptyQ(q)) {
    i = q->elements[0];
    for (j = 1; j <= q->last; j++)
	q->elements[j-1] = q->elements[j];
    q->last--;
    return i;
   } else  printf("Error\n");
}



adjlist graph[MAX_NODES];

int visited[MAX_NODES];    // 0-unvisited    1-visited

void insert(int v1, int v2);

void bfs(int v);



void insert(int v1, int v2)
{
    adjlist *elem = (adjlist*)malloc(sizeof(adjlist));
    elem->node = v2;

    adjlist *pre = &graph[v1];
    adjlist *p = pre->link;
    while(p!=NULL && p->node>v2)
    {
        pre = p;
        p = p->link;
    }
    elem->link = p;
    pre->link = elem;
}

void bfs(int v)
{
    int curNode;
    queue *Q = createQ(MAX_NODES);
    enqueue(Q, v);
    visited[v] = 1;

    while(!IsEmptyQ(Q)){
        curNode = dequeue(Q);
        printf("%d ",curNode);
        adjlist *p = &graph[curNode];
        p = p->link;
        while(p!=NULL){
           if(visited[p->node]==0)
           {
               enqueue(Q, p->node);
               visited[p->node] = 1;
           }
           p = p->link;
        }
    }

}

int main()
{
    int m,a,b;

    // initialize
    for(int i=0;i<MAX_NODES;i++)
    {
	graph[i].link=NULL;
	visited[i]=0;  // unvisited
    }


    printf("Input the number of edges:\n");
    scanf("%d",&m);
    printf("Input these edges:\n");
    for(int i=0; i<m; i++)
    {
        scanf("%d %d", &a, &b);
        insert(a,b);
	    insert(b,a);
    }
    if(m > 0){
        bfs(0);
    }
    return 0;
}


