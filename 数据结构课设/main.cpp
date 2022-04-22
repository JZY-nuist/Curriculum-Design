#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include"Arc.hpp"
#include"adjacency.hpp"
#include"Dijkstra.hpp"

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

void Esc_close(){
	printf("����Escֹͣ�鿴\n");
	while(1){
		if(_kbhit() && _getch()==0x1b){
			printf("�鿴����...");
			Sleep(1000);
			system("cls");
			break;
		}
	}	
}

int main(){
	ArcTree Arc;
	// operationΪ����ѡ�� 
	int i, P[100], D[100], first, last, operation;
	// ��ʼ������ 
	char tourists[INFINITY][20] = {"", "����¥", "����¥", "����¥", "��Է�ٳ�", "����¥", "��Է��ʳ��", "��ʳ�㳡", "����ȡ֤����", "��԰34��", "��Է20��"};
	char introduction[INFINITY][INFINITY] = {"", "��Է��ѧ¥", "��Է��ѧ¥��λ��ѧУ������", "ѧУ�����칫¥", "ӵ��У����������", "��Է��ѧ¥�������£���ȡ\"��������\"֮��", "У����ʳ��", "����ɵ���ҵ�֣���Ʒ�������������ѧ������", "��Ҫ����������ȡ֤����ҵ��ɫȡ֤��������ȡ֤�ʹ�����ȡ֤��������о���", "����", "����"};
	Arc.arcnum = 0, Arc.vexnum = 10;
	CreateArcTree(Arc);
	
	while(1){
		printf("\n\n**��ӭ�������Ŵ�У԰������Ѷϵͳ**\n\n");
		printf("**********�����ǲ����˵�:*********\n");
		printf("*********1����ʾ���о���**********\n");
		printf("*********2���鿴������**********\n");
		printf("*********3����������**************\n");
		printf("*********4��ɾ������**************\n");
		printf("*********5����������**************\n");
		printf("*********0���˳�ϵͳ**************\n");
		printf("\n\n��ѡ��������Ҫ�Ĳ���:");
		scanf("%d", &operation);
		if(operation == 1){
			system("cls"); 
			printf("\n********�����Ǿ�������********\n");
			for(i = 1; i <= Arc.vexnum; i++)
				printf("%d.\t%s\n", i, tourists[i]);
			Esc_close();
			system("cls");
			continue;
		}
		else if(operation == 2){
			system("cls");
			printf("\n********�����Ǿ�������********\n");
			for(i = 1; i <= Arc.vexnum; i++)
				printf("%d.\t%s\n", i, tourists[i]);
			printf("����������鿴�ľ�����:");
			scanf("%d", &i);
			if(i > Arc.vexnum){
				printf("��������ȷ�ľ������\n");
				Sleep(1000);
				continue;
			}
			printf("\n%d��%s:%s\n", i, tourists[i], introduction[i]);
			Esc_close();
			system("cls");
			continue;
		}
		else if(operation == 3){
			system("cls");
			printf("\n********�����Ǿ�������********\n");
			for(i = 1; i <= Arc.vexnum; i++)
				printf("%d.\t%s\n", i, tourists[i]);
			printf("��������������͵���ľ������:");
			scanf("%d %d", &first, &last);
			if(first <= 0 || first > Arc.vexnum || last <= 0 || last > Arc.vexnum){
				printf("\n��ѡ����ȷ�ľ������!!!\n");
				Sleep(1000);
			}
			else if(first == last){
				printf("\n������ľ�����������ڵ�λ��!!!\n");
				Sleep(1000);
			}
			else{
				int length = ShortestPath(Arc, P, D, first, last);
				if(length == INFINITY){
					printf("\n%s��%s֮��û��ͨ·���Բ���\n", tourists[first], tourists[last]);
					Esc_close();
					system("cls");
					continue;
				}
				int n = 1, re[INFINITY];
				re[n] = last;
				while(P[re[n]] != first){
					re[n + 1] = P[re[n]];
					n++;
				}
				re[++n] = first;
				printf("���·���ķ���Ϊ:\n");
				while(n != 1)
					printf("%s -> ", tourists[re[n--]]);
				printf("%s\n", tourists[re[n]]);
				printf("��·��Ϊ%d\n", length);
				Esc_close();
			}
			system("cls");
			continue;
		}
		
		else if(operation == 4){
			system("cls");
			printf("\n********�����Ǿ�������********\n");
			for(i = 1; i <= Arc.vexnum; i++)
				printf("%d.\t%s\n", i, tourists[i]);
			printf("����������ɾ���ľ������:");
			int n;
			scanf("%d", &n);
			DelelteNode(Arc, n);
			for(i = n; i <= Arc.vexnum; i++){
				strcpy(introduction[i], introduction[i+1]);
				strcpy(tourists[i], tourists[i+1]);
			}
			strcpy(tourists[i+1], "\0");
			strcpy(introduction[i+1], "\0");
			Esc_close();
			system("cls");
			continue;
		}
		
		else if(operation == 5){
			system("cls");
			printf("�������������ľ�������:");
			scanf("%s", tourists[Arc.vexnum + 1]);
			getchar();
			Arc.vexnum += 1;
			char temp, x[INFINITY];
			printf("�Ƿ���Ҫ�Դ˾�����м��(��ע)?(y/n):");
			scanf("%c", &temp);
			if(temp == 'y'){
				printf("��������(��ע):\n");
				scanf("%s", x);
				strcpy(introduction[Arc.vexnum], x);
			}
			else
				strcpy(introduction[Arc.vexnum], "����");
			
			printf("\n********�����Ǿ�������********\n");
			for(i = 1; i <= Arc.vexnum; i++)
				printf("%d.\t%s\n", i, tourists[i]);
			InsertNode(Arc);
			Esc_close();
			system("cls");
			continue;
		}
		else if(operation == 0){
			printf("�����˳�ϵͳ�����Ժ�...\n");
			Sleep(1000);
			system("cls");
			break;
		}
			
		else{
			printf("��������ȷ�Ĳ�����\n");
			Sleep(1000);
			system("cls");
			continue;
		}
	}
	printf("\n****��л����ʹ��****\n");
}
 
