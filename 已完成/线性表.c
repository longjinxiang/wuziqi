#include"stdio.h"
#include"malloc.h"
#include"stdlib.h"
#include"SqList.h"
#include"LNode.h"
#define TRUE 1
#define FALSE 0
SqList L;
void SelectType();
void SelectSq();
void SelectLN();
void Create_Sq(){
	system("cls");
	L = (SqList)malloc(sizeof(SqList));
	InitList_Sq(L);
	printf("");
    CreatList_Sq(L);
    printf("");
    ShowList_Sq(L);
	printf("\n请按任意键返回菜单。");
	getchar();
	getchar();
	SelectSq();

}
void Find_Sq(){
	int num,tag;
	system("cls");
    printf("");
    printf("请输入你想查找的元素：\n");
    while(1){
    	scanf("%d",&num);
    	tag =  ListFind_Sq(L,num);
    	if(tag==FALSE){
    		printf("输入错误，请重新输入！");
		}
		else{
			printf("你查找的元素的位置在第%d处",tag);
			break;
		}
	}
	printf("");
	printf("\n请按任意键返回菜单。");
	getchar();
	getchar();
	SelectSq();
}
void Insert_Sq(){
	system("cls");
	int pos = 0,value = 0;

	printf("请输入你想插入的位置和插入的数值：(请用空格隔开)");
	scanf("%d%d",&pos,&value);
	ListInsert_Sq(L,pos,value);
	ShowList_Sq(L);
	printf("\n请按任意键返回菜单。");
	getchar();
	getchar();
	SelectSq();
}
void Delete_Sq(){
	system("cls");
	int pos;
	printf("请输入你想删除元素的位置：");
	scanf("%d",&pos);
	ListDelete_Sq(L,pos);
	ShowList_Sq(L);
	printf("\n请按任意键返回菜单。");
	getchar();
	getchar();
	SelectSq();
}
void Sort_Sq(){
	system("cls");
	ListSort_Sq(L);
	ShowList_Sq(L);
	printf("\n请按任意键返回菜单。");
	getchar();
	getchar();
	SelectSq();
}
void Merge_Sq(){
	int tag;
	SqList H = (SqList)malloc(sizeof(SqList));
	SqList M = (SqList)malloc(sizeof(SqList));
	system("cls");
	printf("将之前的顺序表排序\n");
	ListSort_Sq(L);
	printf("\n排序完成！\n") ;
	ShowList_Sq(L);
	printf("\n你需要创建另一个顺序表！\n");
	printf("\n请按任意键进入输入另一个顺序表界面。");
	getchar();
	getchar();
	system("cls");
	InitList_Sq(H);
	InitList_Sq(M);
	CreatList_Sq(H);
	printf("将之后的顺序表排序\n");
	ListSort_Sq(H);
	ShowList_Sq(H);
	printf("\n按任意键返回合并界面！");
	getchar();
	getchar();
	system("cls");
	MergeList_Sq(L,H,M);
	printf("合并完成！\n");
	ShowList_Sq(M);
	printf("\n请按任意键返回菜单。");
	getchar();
	SelectSq();
}
void SelectSq(){
	int Selection,tag = 0;
	system("cls");
	printf("0.创建一个顺序表\n");
	printf("1.在顺序表中查找元素位置\n");
	printf("2.在指定位置插入元素\n");
	printf("3.删除指定位置的元素\n");
	printf("4.顺序表排序\n");
	printf("5.合并两个顺序表\n");
	printf("6.退出程序\n");
	printf("请选择：");
	while(1){
		scanf("%d",&Selection);
		switch(Selection){
			case 0:
				Create_Sq();
				break;
			case 1:
				Find_Sq();
				break;
			case 2:
				Insert_Sq();
				break;
			case 3:
				Delete_Sq();
				break;
			case 4:
				Sort_Sq();
				break;
			case 5:
				Merge_Sq();
				break;
			case 6:
				SelectType();
				break;
			default:
				printf("输入错误！请重新输入！");
				continue;
		}
	}
	system("pause");
}
LinkList H = NULL;
void Create_LN(){
	system("cls");
	H = (LinkList)malloc(sizeof(LNode));
	Init_LNode(H);
	CreatLNode(H);
    ShowLNode(H);
	printf("\n请按任意键返回菜单。");
	getchar();
	getchar();
	SelectLN();
}
void GetElem_LN(){
	int pos,tag;
	system("cls");
	 printf("请输入你想查找的位置：\n");
	 while(1){
	 	scanf("%d",&pos);
	 	tag = GetElem_L(H,pos);

	 if(tag==FALSE){
    		printf("输入错误，请重新输入！");
		}
		else{
			printf("此位置的元素为%d",tag);
			break;
		}
	}
	printf("\n请按任意键返回菜单。");
	getchar();
	getchar();
	SelectLN();
}
void Insert_LN(){
	system("cls");
	int pos = 0,value = 0;
	printf("请输入你想插入的位置和插入的数值：(请用空格隔开)");
	scanf("%d%d",&pos,&value);
	ListInsert_L(H,pos,value);
	ShowLNode(H);
	printf("\n请按任意键返回菜单。");
	getchar();
	getchar();
	SelectLN();
}
void Delete_LN(){
	system("cls");
	int pos;
	printf("请输入你想删除元素的位置：");
	scanf("%d",&pos);
	ListDelete_L(H,pos);
	ShowLNode(H);
	printf("\n请按任意键返回菜单。");
	getchar();
	getchar();
	SelectLN();
}
void Sort_LN(){
	system("cls");
	ListSort_L(H);
	ShowLNode(H);
	printf("\n请按任意键返回菜单。");
	getchar();
	getchar();
	SelectLN();
}
void Merge_LN(){
	int tag;
	LinkList M,N;
	M = (LinkList)malloc(sizeof(LNode));
	N = (LinkList)malloc(sizeof(LNode));
	system("cls");
	printf("将之前的顺序表排序\n");
	ListSort_L(H);
	ShowLNode(H);
	printf("\n你需要创建另一个顺序表！\n");
	printf("\n请按任意键进入输入另一个链表界面。");
	getchar();
	getchar();
	system("cls");
	Init_LNode(M);
	Init_LNode(N);
	CreatLNode(M);
	printf("将之后的顺序表排序\n");
	ListSort_L(M);
	ShowLNode(M);
	printf("\n按任意键返回合并界面！");
	getchar();
	getchar();
	system("cls");
	MergeList_L(H,M,N);
	printf("合并完成！\n");
	ShowLNode(H);
	printf("\n请按任意键返回菜单。");
	getchar();
	SelectLN();
}
void SelectLN(){
	int Selection,tag = 0;
	system("cls");
	printf("0.创建链表\n");
	printf("1.查找某个位置的值\n");
	printf("2.在指定位置插入\n");
	printf("3.删除指定元素\n");
	printf("4.链表排序\n");
	printf("5.合并两个链表\n");
	printf("6.退出程序\n");
	printf("请选择：");
	while(1){
		scanf("%d",&Selection);
		switch(Selection){
			case 0:
				Create_LN();
				break;
			case 1:
				GetElem_LN();
				break;
			case 2:
				Insert_LN();
				break;
			case 3:
				Delete_LN();
				break;
			case 4:
				Sort_LN();
				break;
			case 5:
				Merge_LN();
				break;
			case 6:
				SelectType();
				break;
			default:
				printf("输入错误，重新输入！");
				continue;
		}
	}
	system("pause");
}
void SelectType(){
	int Selection = 0;
	system("cls");
	printf("1.顺序表");
	printf("2.链表\n\n");
	printf("请选择：");
	while(1){
		scanf("%d",&Selection);
		switch(Selection){
			case 1:
				SelectSq();
				break;
			case 2:
				SelectLN();
				break;
			default:
				printf("输入错误，请重新输入！");
				continue;
		}
		if(Selection==1||2) break;
	}
}
int main (){

	SelectType();

}

