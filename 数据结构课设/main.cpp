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
	printf("按下Esc停止查看\n");
	while(1){
		if(_kbhit() && _getch()==0x1b){
			printf("查看结束...");
			Sleep(1000);
			system("cls");
			break;
		}
	}	
}

int main(){
	ArcTree Arc;
	// operation为操作选择 
	int i, P[100], D[100], first, last, operation;
	// 初始化操作 
	char tourists[INFINITY][20] = {"", "滨江楼", "揽江楼", "行政楼", "东苑操场", "明德楼", "中苑老食堂", "美食广场", "数字取证中心", "沁园34栋", "文苑20栋"};
	char introduction[INFINITY][INFINITY] = {"", "西苑教学楼", "西苑教学楼，位于学校最西边", "学校管理层办公楼", "拥有校最大的体育馆", "中苑教学楼，与明德，合取\"文明德行\"之意", "校网红食堂", "新落成的商业街，商品种类多样，满足学生需求", "主要致力于内容取证、行业特色取证、区块链取证和大数据取证等领域的研究。", "暂无", "暂无"};
	Arc.arcnum = 0, Arc.vexnum = 10;
	CreateArcTree(Arc);
	
	while(1){
		printf("\n\n**欢迎来到南信大校园导游资讯系统**\n\n");
		printf("**********下面是操作菜单:*********\n");
		printf("*********1、显示已有景点**********\n");
		printf("*********2、查看景点简介**********\n");
		printf("*********3、导航景点**************\n");
		printf("*********4、删除景点**************\n");
		printf("*********5、新增景点**************\n");
		printf("*********0、退出系统**************\n");
		printf("\n\n请选择你所需要的操作:");
		scanf("%d", &operation);
		if(operation == 1){
			system("cls"); 
			printf("\n********下面是景点的序号********\n");
			for(i = 1; i <= Arc.vexnum; i++)
				printf("%d.\t%s\n", i, tourists[i]);
			Esc_close();
			system("cls");
			continue;
		}
		else if(operation == 2){
			system("cls");
			printf("\n********下面是景点的序号********\n");
			for(i = 1; i <= Arc.vexnum; i++)
				printf("%d.\t%s\n", i, tourists[i]);
			printf("请输入您想查看的景点简介:");
			scanf("%d", &i);
			if(i > Arc.vexnum){
				printf("请输入正确的景点序号\n");
				Sleep(1000);
				continue;
			}
			printf("\n%d、%s:%s\n", i, tourists[i], introduction[i]);
			Esc_close();
			system("cls");
			continue;
		}
		else if(operation == 3){
			system("cls");
			printf("\n********下面是景点的序号********\n");
			for(i = 1; i <= Arc.vexnum; i++)
				printf("%d.\t%s\n", i, tourists[i]);
			printf("请输入您想出发和到达的景点序号:");
			scanf("%d %d", &first, &last);
			if(first <= 0 || first > Arc.vexnum || last <= 0 || last > Arc.vexnum){
				printf("\n请选择正确的景点序号!!!\n");
				Sleep(1000);
			}
			else if(first == last){
				printf("\n您输入的景点就在你所在的位置!!!\n");
				Sleep(1000);
			}
			else{
				int length = ShortestPath(Arc, P, D, first, last);
				if(length == INFINITY){
					printf("\n%s和%s之间没有通路，对不起。\n", tourists[first], tourists[last]);
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
				printf("最短路径的方案为:\n");
				while(n != 1)
					printf("%s -> ", tourists[re[n--]]);
				printf("%s\n", tourists[re[n]]);
				printf("总路程为%d\n", length);
				Esc_close();
			}
			system("cls");
			continue;
		}
		
		else if(operation == 4){
			system("cls");
			printf("\n********下面是景点的序号********\n");
			for(i = 1; i <= Arc.vexnum; i++)
				printf("%d.\t%s\n", i, tourists[i]);
			printf("请输入您想删除的景点序号:");
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
			printf("请输入您新增的景点名称:");
			scanf("%s", tourists[Arc.vexnum + 1]);
			getchar();
			Arc.vexnum += 1;
			char temp, x[INFINITY];
			printf("是否需要对此景点进行简介(备注)?(y/n):");
			scanf("%c", &temp);
			if(temp == 'y'){
				printf("请输入简介(备注):\n");
				scanf("%s", x);
				strcpy(introduction[Arc.vexnum], x);
			}
			else
				strcpy(introduction[Arc.vexnum], "暂无");
			
			printf("\n********下面是景点的序号********\n");
			for(i = 1; i <= Arc.vexnum; i++)
				printf("%d.\t%s\n", i, tourists[i]);
			InsertNode(Arc);
			Esc_close();
			system("cls");
			continue;
		}
		else if(operation == 0){
			printf("正在退出系统，请稍后...\n");
			Sleep(1000);
			system("cls");
			break;
		}
			
		else{
			printf("请输入正确的操作数\n");
			Sleep(1000);
			system("cls");
			continue;
		}
	}
	printf("\n****感谢您的使用****\n");
}
 
