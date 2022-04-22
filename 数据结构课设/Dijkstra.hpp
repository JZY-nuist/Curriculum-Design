#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Arc.hpp"

#define INFINITY 600

/*
typedef struct ArcNode{
	int data;
	int next_index;
	ArcNode *next;
}ArcNode;

typedef struct{
	ArcNode a[INFINITY]; 
	int vexnum, arcnum;
}ArcTree;
*/

// 基于邻接表的Dijkstra算法 
int ShortestPath(ArcTree ar, int *P, int *D, int first, int last)	// P[i] 为Vi的前驱节点，D[i]表示从V0到Vi的最小权值 
{
	int i, j, k, min;
	int final[INFINITY] = {0}, re[INFINITY];	// final[i] = 1 代表此点已经求出从V_first到Vi的最短距离
	for(i = 1; i <= ar.vexnum; i++){
		P[i] = first;
		D[i] = INFINITY;
	}
	ArcNode *t = &(ar.a[first]);
	t = t -> next;
	while(t)
	{
		D[t -> next_index] = t -> data;
		t = t->next;
	}
	D[first] = 0, final[first] = 1;
	
	for(i = 1; i < ar.vexnum; i++)
	{
		min = INFINITY;
		for(j = 1; j <= ar.vexnum; j++)
		{
			if(!final[j] && D[j] < min)
			{
				k = j;
				min = D[j];
			}
		}
		
		final[k] = 1;
		
		t = &(ar.a[k]);
		t = t -> next;
		while(t){
			if(!final[t->next_index] && (min + t->data < D[t->next_index])){
				D[t->next_index] = min + t->data;
				P[t->next_index] = k;
			}
			t = t -> next;
		}
	}
	return D[last];
 }
