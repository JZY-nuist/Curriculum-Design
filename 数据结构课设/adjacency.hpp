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




void CreateArcTree(ArcTree &ar){	// �����ڽӱ� 
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
							10, 4, 1668, 0, 0, 0}; // ��һ��Ϊ·����ʼ�㣬�ڶ���Ϊ·����ֹ�㣬������Ϊ���� ����ֹ��Ϊ0 0 0��
	i = 0; 
	while(information[i][0] != 0 && information[i][1] != 0 && information[i][2] != 0){
		first = information[i][0], last = information[i][1], length = information[i][2];
		// ����Ļ�
		ArcNode *p = &(ar.a[first]);
		while(p -> next)
			p = p -> next;
		ArcNode *temp1 = (ArcNode *) malloc(sizeof(ArcNode));
		temp1 -> data = length;
		temp1 -> next_index = last;
		temp1 -> next = p -> next;
		p -> next = temp1;
		p -> next -> next = NULL;
		// ����Ļ� 
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
		printf("��������ȷ�ľ������\n");
		return;
	}
	int i;
	// �޳������nΪ��ʼ���·�� 
	for(i = n; i< ar.vexnum; i++)
		ar.a[i].next = ar.a[i+1].next;
	ar.a[i].next = NULL;
	ar.vexnum -= 1;
	for(i = 1; i <= ar.vexnum; i++){
		ArcNode *p = &(ar.a[i]);
		while(p -> next){
			// �޳������nΪ��ֹ���·�� 
			if(p -> next -> next_index == n){
				p -> next = p -> next -> next;
				continue;
			}
			// ���n�Ժ��·�����ǰ�� 
			else if(p -> next -> next_index > n)
				p -> next -> next_index -= 1;
			p = p -> next;
		}
	}
	printf("ɾ���ɹ�!\n");
}

void InsertNode(ArcTree &ar){
	int last, length, first = ar.vexnum;
	printf("������˾�������ھ�����ż������:\n");
	printf("********(��ֹ��������0 0)*********\n");
	while(scanf("%d %d", &last, &length), last != 0 || length != 0){
		if(last <= 0 || last >= ar.vexnum){
			printf("��������ȷ�����ھ������!!!\n");
			printf("��������.\n");
		}
		// ����Ļ� 
		ArcNode *p = &(ar.a[first]);
		while(p -> next)
			p = p -> next;
		ArcNode *temp1 = (ArcNode *) malloc(sizeof(ArcNode));
		temp1 -> data = length;
		temp1 -> next_index = last;
		temp1 -> next = p -> next;
		p -> next = temp1;
		p -> next -> next = NULL;
		
		// ����Ļ� 
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
	printf("��ӳɹ�!!!\n");
}
