#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct Edge {
  int v;
  int w;
  struct Edge *next;
} Edge;

typedef struct Graph {
  Edge *edges[MAX_VERTICES + 1];
  int n;
  int e;
} Graph;

void addEdge(Graph *g, int u, int v, int w) {
  Edge *e = malloc(sizeof(Edge));
  e->v = v;
  e->w = w;
  e->next = g->edges[u];
  g->edges[u] = e;
}

Graph *createGraph(int n) {
  int i;
  Graph *g = malloc(sizeof(Graph));
  g->n = n;
  g->e = 0;
  for (i = 1; i <= n; i++) g->edges[i] = NULL;
  return g;
}

void printGraph(Graph *g) {
  int i;
  for (i = 1; i <= g->n; i++) {
    Edge *e = g->edges[i];
    printf("%d: ", i);
    while (e != NULL) {
      printf(" %d(%d)", e->v, e->w);
      e = e->next;
    }
    printf("\n");
  }
}

int main(void) {
  Graph *g = createGraph(6);
  addEdge(g, 1, 2, 1);
  addEdge(g, 1, 3, 2);
  addEdge(g, 2, 4, 3);
  addEdge(g, 2, 5, 4);
  addEdge(g, 3, 5, 5);
  addEdge(g, 4, 5, 6);
  addEdge(g, 4, 6, 7);
  addEdge(g, 5, 6, 8);
  printGraph(g);
  return 0;
}
