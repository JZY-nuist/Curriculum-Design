#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Arc.hpp"

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




void CreateArcTree(ArcTree &ar){	// 创建邻接表 
	int i, first, last, length;
	for(i = 1; i <= ar.vexnum; i++)
		ar.a[i].next = NULL;
	int information[][3] = {1, 4, 1677, 1, 8, 997, 1, 10, 233,\
	 						2, 1, 22, 2, 3, 134, 2, 5, 776,\
							2, 6, 888, 2, 9, 633, 3, 1, 1198,\
							3, 7, 739, 3, 8, 456, 3, 10, 1344,\
							4, 2, 357, 4, 3, 444, 4, 6, 674,\
							5, 1, 866, 5, 4, 412, 5, 9, 454,\
							7, 1, 999, 7, 5, 200, 8, 3, 321,\
							8, 9, 333, 9, 7, 656, 10, 1, 210,\
							10, 4, 1668, 0, 0, 0}; // 第一列为路的起始点，第二列为路的终止点，第三列为距离 ，终止符为0 0 0。
	i = 0; 
	while(information[i][0] != 0 && information[i][1] != 0 && information[i][2] != 0){
		first = information[i][0], last = information[i][1], length = information[i][2];
		// 正向的弧
		ArcNode *p = &(ar.a[first]);
		while(p -> next)
			p = p -> next;
		ArcNode *temp1 = (ArcNode *) malloc(sizeof(ArcNode));
		temp1 -> data = length;
		temp1 -> next_index = last;
		temp1 -> next = p -> next;
		p -> next = temp1;
		p -> next -> next = NULL;
		// 反向的弧 
		ArcNode *q = &(ar.a[last]);
		while(q -> next)
			q = q -> next;
		ArcNode *temp2 = (ArcNode *) malloc(sizeof(ArcNode));
		temp2 -> data = length;
		temp2 -> next_index = first;
		temp2 -> next = q -> next;
		q -> next = temp2;
		q -> next -> next = NULL;
		ar.arcnum += 2;
		i++;
	}
}


void DelelteNode(ArcTree &ar, int n){
	if(n < 1 || n > ar.vexnum){
		printf("请输入正确的景点序号\n");
		return;
	}
	int i;
	// 剔除以序号n为起始点的路径 
	for(i = n; i< ar.vexnum; i++)
		ar.a[i].next = ar.a[i+1].next;
	ar.a[i].next = NULL;
	ar.vexnum -= 1;
	for(i = 1; i <= ar.vexnum; i++){
		ArcNode *p = &(ar.a[i]);
		while(p -> next){
			// 剔除以序号n为终止点的路径 
			if(p -> next -> next_index == n){
				p -> next = p -> next -> next;
				continue;
			}
			// 序号n以后的路径序号前移 
			else if(p -> next -> next_index > n)
				p -> next -> next_index -= 1;
			p = p -> next;
		}
	}
	printf("删除成功!\n");
}

void InsertNode(ArcTree &ar){
	int last, length, first = ar.vexnum;
	printf("请输入此景点的相邻景点序号及其距离:\n");
	printf("********(终止输入输入0 0)*********\n");
	while(scanf("%d %d", &last, &length), last != 0 || length != 0){
		if(last <= 0 || last >= ar.vexnum){
			printf("请输入正确的相邻景点序号!!!\n");
			printf("继续输入.\n");
		}
		// 正向的弧 
		ArcNode *p = &(ar.a[first]);
		while(p -> next)
			p = p -> next;
		ArcNode *temp1 = (ArcNode *) malloc(sizeof(ArcNode));
		temp1 -> data = length;
		temp1 -> next_index = last;
		temp1 -> next = p -> next;
		p -> next = temp1;
		p -> next -> next = NULL;
		
		// 反向的弧 
		ArcNode *q = &(ar.a[last]);
		while(q -> next)
			q = q -> next;
		ArcNode *temp2 = (ArcNode *) malloc(sizeof(ArcNode));
		temp2 -> data = length;
		temp2 -> next_index = first;
		temp2 -> next = q -> next;
		q -> next = temp2;
		q -> next -> next = NULL;
		ar.arcnum += 2;
	}
	printf("添加成功!!!\n");
}
