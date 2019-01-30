#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"math.h"
#define true 1
#define false 0
#define OPSETSIZE 8
typedef int Status;

unsigned char Prior[8][8] =
{ // 运算符优先级表
    // '+' '-' '*' '/' '(' ')' '#' '^'
    /*'+'*/'>','>','<','<','<','>','>','<',
    /*'-'*/'>','>','<','<','<','>','>','<',
    /*'*'*/'>','>','>','>','<','>','>','<',
    /*'/'*/'>','>','>','>','<','>','>','<',
    /*'('*/'<','<','<','<','<','=',' ','<',
    /*')'*/'>','>','>','>',' ','>','>','>',
    /*'#'*/'<','<','<','<','<',' ','=','<',
    /*'^'*/'>','>','>','>','<','>','>','>'
};

typedef struct StackChar
{
    char c;
    struct StackChar *next;
}SC;       //StackChar类型的结点SC

typedef struct StackFloat
{
    float f;
    struct StackFloat *next;
}SF;       //StackFloat类型的结点SF

SC *Push(SC *s,char c)          //SC类型的指针Push，返回p
{
    SC *p=(SC*)malloc(sizeof(SC));
    p->c=c;
    p->next=s;
    return p;
}

SF *Push(SF *s,float f)        //SF类型的指针Push，返回p
{
    SF *p=(SF*)malloc(sizeof(SF));
    p->f=f;
    p->next=s;
    return p;
}

SC *Pop(SC *s)    //SC类型的指针Pop
{
    SC *q=s;
    s=s->next;
    free(q);
    return s;
}

SF *Pop(SF *s)      //SF类型的指针Pop
{
    SF *q=s;
    s=s->next;
    free(q);
    return s;
}

float Operate(float a,unsigned char theta, float b)      //计算函数Operate
{
    switch(theta)
    {
    case '+': return a+b;
    case '-': return a-b;
    case '*': return a*b;
    case '/': return a/b;
    case '^': return pow(a,b);
    default : return 0;
    }
}

char OPSET[OPSETSIZE]={'+','-','*','/','(',')','#','^'};

Status In(char Test,char *TestOp)
{
    int Find=false;
    for (int i=0; i< OPSETSIZE; i++)
    {
        if(Test == TestOp[i])
            Find= true;
    }
    return Find;
}

Status ReturnOpOrd(char op,char *TestOp)
{
    for(int i=0; i< OPSETSIZE; i++)
    {
        if (op == TestOp[i])
            return i;
    }
}

char precede(char Aop, char Bop)
{
    return Prior[ReturnOpOrd(Aop,OPSET)][ReturnOpOrd(Bop,OPSET)];
}

float EvaluateExpression(char* MyExpression)
{
    // 算术表达式求值的算符优先算法
    // 设OPTR和OPND分别为运算符栈和运算数栈，OP为运算符集合
    SC *OPTR=NULL;       // 运算符栈，字符元素
    SF *OPND=NULL;       // 运算数栈，实数元素
    char TempData[20];
    float Data,a,b;
    char theta,*c,Dr[]={'#','\0'};
    OPTR=Push(OPTR,'#');
    c=strcat(MyExpression,Dr);
    strcpy(TempData,"\0");//字符串拷贝函数
    while (*c!= '#' || OPTR->c!='#')
    {
        if (!In(*c, OPSET))
        {
            Dr[0]=*c;
            strcat(TempData,Dr);           //字符串连接函数
            c++;
            if (In(*c, OPSET))
            {
                Data=atof(TempData);       //字符串转换函数(double)
                OPND=Push(OPND, Data);
                strcpy(TempData,"\0");
            }
        }
        else    // 不是运算符则进栈
        {
            switch (precede(OPTR->c, *c))
            {
            case '<': // 栈顶元素优先级低
                OPTR=Push(OPTR, *c);
                c++;
                break;
            case '=': // 脱括号并接收下一字符
                OPTR=Pop(OPTR);
                c++;
                break;
            case '>': // 退栈并将运算结果入栈
                theta=OPTR->c;OPTR=Pop(OPTR);
                b=OPND->f;OPND=Pop(OPND);
                a=OPND->f;OPND=Pop(OPND);
                OPND=Push(OPND, Operate(a, theta, b));
                break;
            } //switch
        }
    } //while
    return OPND->f;
} //EvaluateExpression

int main(void)
{
    char s[128];
    puts("请输入表达式:");
    gets(s);
    puts("该表达式的值为:");
    printf("%s\b=%g\n",s,EvaluateExpression(s));
    system("pause");
    return 0;
}
