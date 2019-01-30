#include<stdio.h>
#include"stdlib.h"
#include"malloc.h"
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define TRUE 1
#define FALSE 0
typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;
void ShowLNode(LinkList L){
	LinkList p = NULL;
	printf("\n遍历结果为：");
	for(p=L->next;p;p=p->next){
		printf("%8d",p->data);
	}
}
void Init_LNode(LinkList L){
	L->data = 0;
	L->next = NULL;
}
void CreatLNode(LinkList L){
	LinkList p = L,	q = NULL ; int i,n;
    printf("输入的元素个数：");
    scanf("%d",&n);
    printf("输入的数据：");
	for(i=0;i<n;i++){
		printf("\n第%d个数据：",i+1);
		q = (LinkList)malloc(sizeof(LNode));
		scanf("%d",&(q->data));
		q->next = p->next;
		p->next = q;
		p = q;
	}
}
int GetElem_L(LinkList L,int i){
	int count;
	LinkList p = NULL;
	for(p=L->next,count=1;p&&count<i;p=p->next,count++);
	if(!p||count>i){
		return FALSE;
	}
	return p->data;
}//得到第i个位置的值
int GetLoc_L(LinkList L,int e){
	int count;
	LinkList p = L->next;
	for(count=0;p&&p->data!=e;count++){
		p = p->next;
	}
	if(!p) return FALSE;
	return count+1;
}//元素值与e相等的位置
int ListInsert_L(LinkList L,int i,ElemType e){
	LinkList p = L;LinkList s = NULL;
	int j = 0;
	while(p&&j<i-1){
		p = p->next;
		++j;
	}
	if(!p||j>i-1) return FALSE;
	s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return TRUE;
} //插入
int ListDelete_L(LinkList L,int i){
	LinkList p = L,q = NULL; int j = 0;
	while(p->next&&j<i-1){
		p = p->next;
		++j;
	}
	if(!(p->next)||j>i-1){
		return FALSE;
	}
	q = p->next;
	p->next = q->next;
	return TRUE;
}
void ListSort_L(LinkList L){
	int temp = 0;
	LinkList p,q;
	for(p=L;p;p=p->next)
	  for(q=L;q->next;q=q->next)
	    if((q->data)>(q->next->data)){
	    	temp = q->data;
	    	q->data = q->next->data;
	    	q->next->data = temp;
		}
	printf("\n排序完成");
}
void MergeList_L(LinkList La,LinkList Lb,LinkList Lc){
	LinkList pa,pb,pc;
	pa = La->next; pb = Lb->next;
	Lc = pc = La;
	while(pa&&pb){
		if(pa->data<=pb->data){
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa?pa:pb;
}
