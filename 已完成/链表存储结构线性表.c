#include <stdio.h>
#include <stdlib.h>

typedef struct LNode{
	int data;				//链表数据
	struct LNode* next;		//链表指针
}LNode,*LinkList;

/*头插法-建立单链表*/
LinkList HeadCreate(LinkList la)
{
	int num;
	la=(LinkList)malloc(sizeof(LNode));		//建立头结点
	la->next=NULL;
	scanf("%d",&num);
	while(num!=10)
	{
		LNode *p=(LinkList)malloc(sizeof(LNode));
		p->data=num;
		p->next=la->next;
		la->next=p;
		scanf("%d",&num);
	}
	return la;
}

/*尾插法-建立单链表*/
LinkList TailCreate(LinkList la)
{
	int num;
	la=(LinkList)malloc(sizeof(LNode));
	la->next=NULL;
	LinkList s,r=la;
	scanf("%d",&num);
	while(num!=10)
	{
		s=(LinkList)malloc(sizeof(LNode));
		s->data=num;
		r->next=s;
		r=s;
		scanf("%d",num);
	}
	r->next=NULL;
	return la;
}

/*单链表遍历*/
void TravelList(LinkList la)
{
	LinkList p=la->next;
	while(p!=NULL)
	{
		printf("%d->",p->data);
		p=p->next;
	}
	printf("\n");
}

/*单链表的按位查找*/
LinkList GetElem(LinkList la,int i)
{
	int j=1;
	LNode* p=la->next;
	if(i<1)
		return NULL;
	while(p && j<i)
	{
		p=p->next;
		j++;
	}
	return p;
}

/*单链表的按值查找*/
LinkList LocalElem(LinkList la,int e)
{
	LNode* p=la->next;
	while(p!=NULL && p->data!=e)
		p=p->next;
	return p;
}

/*单链表插入操作*/
bool InsertList(LinkList la,int i,int e)
{
	//在la链表中的i位置插入数值e
	int j=1;
	LinkList p=la,s;
	while(p && j<i)
	{
		p=p->next;
		j++;
	}
	if(p==NULL)
		return false;
	if((s=(LinkList)malloc(sizeof(LNode)))==NULL)
		return false;
	s->data=e;
	s->next=p->next;
	p->next=s;
	return true;
}

/*单链表删除操作*/
bool DeleteList(LinkList la,int i)
{
	int j=1;
	LinkList p=la,q;
	while(p && j<i)		//p指向第i-1个元素
	{
		p=p->next;
		j++;
	}
	if(p==NULL || p->next==NULL)	    //表示不存在第i-1个和第i的元素
		return false;
	q=p->next;
	p->next=q->next;
	free(q);
	return true;
}

/*单链表的表长*/
int LengthList(LinkList la)
{
	int nLen=0;
	LinkList p=la->next;
	while(p)
	{
		p=p->next;
		nLen++;
	}
	return nLen;
}

/*单链表逆置*/
LinkList Reserve(LinkList la)
{
	if(la==NULL || la->next==NULL)
		return la;
	LinkList p=la->next,q=p->next,r=q->next;
	la->next=NULL;
	p->next=NULL;
	while(r!=NULL)
	{
		q->next=p;
		p=q;
		q=r;
		r=r->next;
	}
	q->next=p;
	la->next=q;
	return la;
}

int main()
{
	LNode la;
	LinkList p;
	p=HeadCreate(&la);				//头插法创建单链表
	TravelList(p);
	printf("%p\n",GetElem(p,1));	        //获得第1个结点地址
	InsertList(p,2,10);				//在链表的第2个位置插入元素10
	TravelList(p);
	DeleteList(p,3);				//删除链表的第3个元素
	TravelList(p);
	printf("%d\n",LengthList(p));	        //获得链表长度
	p=Reserve(p);
	TravelList(p);
	return 0;
}

//运行结果
//5 6 12 7 8 14 9 3 2 5 14 10					        头插法创建链表
//14->5->2->3->9->14->8->7->12->6->5->			显示链表
//00382490								        第一个结点的地址
//14->10->5->2->3->9->14->8->7->12->6->5->		插入元素值为10的结点
//14->10->2->3->9->14->8->7->12->6->5->			删除第三个结点
//11											获得链表长度
//5->6->12->7->8->14->9->3->2->10->14->			链表逆置
//Press any key to continue
