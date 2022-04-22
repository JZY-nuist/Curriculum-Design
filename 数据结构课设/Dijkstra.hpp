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

// �����ڽӱ��Dijkstra�㷨 
int ShortestPath(ArcTree ar, int *P, int *D, int first, int last)	// P[i] ΪVi��ǰ���ڵ㣬D[i]��ʾ��V0��Vi����СȨֵ 
{
	int i, j, k, min;
	int final[INFINITY] = {0}, re[INFINITY];	// final[i] = 1 ����˵��Ѿ������V_first��Vi����̾���
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
