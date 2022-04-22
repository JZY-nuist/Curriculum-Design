#include<stdio.h>

#define INFINITY 600

#ifndef _COMMON
#define _COMMON
typedef struct ArcNode{
	int data;
	int next_index;
	ArcNode *next;
}ArcNode;

typedef struct{
	ArcNode a[INFINITY]; 
	int vexnum, arcnum;
}ArcTree;

#endif
