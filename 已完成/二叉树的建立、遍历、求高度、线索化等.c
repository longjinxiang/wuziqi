#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>


typedef struct Binnode{
    char data;
    struct Binnode *lchild;
    struct Binnode *rchild;
}Binnode;
   /*按照前序遍历建立二叉树*/
void Creat_Bintree(Binnode **t)
{
   char ch;
   scanf("\n%c",&ch);
   if(ch=='0') *t=NULL;
   else
     {
       *t=(Binnode*)malloc(sizeof(Binnode));
       if(!*t)exit(OVERFLOW);
       (*t)->data=ch;
       printf("%c: left",ch); Creat_Bintree(&(*t)->lchild);
       printf("%c: right",ch);Creat_Bintree(&(*t)->rchild);
     }
}

/*按照前序递归遍历二叉树*/
void Preorder1(Binnode *t)
{
    if(t!=NULL)
    {
        printf("%c",t->data);
        Preorder1(t->lchild);
        Preorder1(t->rchild);
    }

}
/*按照中序递归遍历二叉树*/
void Inorder1(Binnode *t)
{ /* printf("\n输出中序递归遍历序列:");*/
    if(t!=NULL)
    {
        Inorder1(t->lchild);
        printf("%c",t->data);
        Inorder1(t->rchild);
    }

}

/* 按照后序递归遍历二叉树*/
void Posorder1(Binnode *t)
{  /* printf("\n输出后序递归遍历序列:");*/
    if(t!=NULL)
    {
        Posorder1(t->lchild);
        Posorder1(t->rchild);
        printf("%c",t->data);
    }
}

int deep(Binnode *t)
/*递归求二叉树高度*/
{   int ld=0;
    int rd=0;
    if(!t) return 0;
    else{ ld=deep(t->lchild); rd=deep(t->rchild); }
    if(ld>rd) return ld+1;
    else return rd+1;

}
int main()
{
    Binnode *proot=NULL;
    int p,q;
    printf("1. 创建二叉树:\n");
	printf("请按先序输入二叉树，无左右孩子的结点输入'0'值：\n");
    Creat_Bintree(&proot); /*建立二叉树时，无左右孩子的结点输入'0'值*/
    printf("\n2. 前序递归遍历:\n");
    Preorder1(proot);
    printf("\n3. 中序递归遍历:\n");
    Inorder1(proot);
    printf("\n4. 后序递归遍历:\n");
    Posorder1(proot);
    printf("\n6.递归法求二叉树高度：");
    printf("%d",deep(proot));
	getchar();
	getchar();
    return 0;
}
