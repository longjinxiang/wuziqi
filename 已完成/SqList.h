#include<stdio.h>
#include"stdlib.h"
#include"malloc.h"
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define TRUE 1
#define FALSE 0
typedef int ElemType;
typedef struct{
	ElemType *elem;
	int len;
	int cursize;
}*SqList;
int InitList_Sq(SqList L){
	L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if(! L->elem){
		return FALSE;
	}
	L->len = 0;
	L->cursize = LIST_INIT_SIZE;
	return TRUE;
}//构造一个空的线性表L
int ListInsert_Sq(SqList L,int i,ElemType e){
	ElemType *newbase;
	if(i<1||i>L->len+1){
		return FALSE;
	}
	if(L->len>=L->cursize){
		newbase = (ElemType *)realloc(L->elem,(L->cursize+LISTINCREMENT) * sizeof(ElemType));
		if(! newbase){
			return FALSE;
		}
		L->elem = newbase;
		L->cursize = L->cursize+LISTINCREMENT;
	}
	ElemType *q = &(L->elem[i-1]),*p;
	for(p = &L->elem[L->len-1];p>=q;--p){
		*(p+1) = *p;
	}
	*q = e;
	++L->len;
	return TRUE;
} //在第i个位置插入新元素e
int ListDelete_Sq(SqList L,int i){
	if(i<1||i>L->len){
		return FALSE;
	}
	int *p = &L->elem[i-1];
	int *q = &L->elem[L->len-1];
	for(++p;p<=q;++p){
		*(p-1) = *p;
	}
	--L->len;
	return TRUE;
}//删除第i个元素
int ListFind_Sq(SqList L,ElemType e){
	int i=0;
	while(i<L->len-1&&L->elem[i]!=e) i++;
	if(i<=L->len-1) return(i+1);
	else return -1;
}
int ListSort_Sq(SqList L){
	int i,j,temp;
	for(j=0;j<L->len-1;j++)
	  for(i=0;i<L->len-1-j;i++)
	    if(L->elem[i]>L->elem[i+1]){
	    	temp = L->elem[i];
	    	L->elem[i] = L->elem[i+1];
	    	L->elem[i+1] = temp;
		}
	printf("\n排序完成！");
	return TRUE;
}
void MergeList_Sq(SqList La,SqList Lb,SqList Lc){
	int *pa = La->elem; int *pb = Lb->elem;
	Lc->cursize = Lc->len = La->len+Lb->len;
	int *pc = Lc->elem = (ElemType *)malloc(Lc->cursize * sizeof(ElemType));
	if(!Lc->elem) printf("创建失败！");
	int *pa_last = La->elem+La->len-1;
	int *pb_last = Lb->elem+Lb->len-1;
	while(pa<=pa_last&&pb<=pb_last){
		if(*pa <= *pb) *pc++ = *pa++;
		else *pc++ = *pb++;
	}
	while(pa<=pa_last) *pc++ = *pa++;
	while(pb<=pb_last) *pc++ = *pb++;
}//合并
void CreatList_Sq(SqList L){
	int i;
	printf("\n顺序表的长度n=");
	scanf("%d",&(L->len));
	for(i=0;i<L->len;i++){
		printf("\n元素%d为：",i+1);
		scanf("%d",&(L->elem[i]));
	}
	printf("\n顺序表创建成功！");
}
void ShowList_Sq(SqList L){
	int i;
	printf("\n遍历结果为：");
	for(i=0;i<L->len;i++){
		printf("%8d",L->elem[i]);
	}
}
