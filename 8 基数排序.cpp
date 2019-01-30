#include <iostream>
using namespace std;
const int base=10;
struct wx
{
	int num;
	wx *next;
	wx()
	{
		next=NULL;
	}
};
wx *headn,*curn,*box[base],*curbox[base];

void basesort(int t)
{
	int i,k=1,r,bn;
// k,r 分别表示10的幂次方，用来得到相应位上的单个数字，比如 k=10，r=100，数字207，则 十位上 0 = //(207/r)%10
	for(i=1;i<=t;i++)
	{
		k*=base;
	}
	r=k*base;
//curbox和box中的指针指向相同的位置，当curbox中有新元素时，curbox指向会发生变化，形成box元素为//头指针，curbox元素相当于滑动指针，这样可以通过比较两者的不同来判断指针的走向。
	for(i=0;i<base;i++)
	{
		curbox[i]=box[i];
	}

	for(curn=headn->next;curn!=NULL;curn=curn->next)
	{
                 bn=(curn->num%r)/k;               // bn表示元素相应位上的值，
		curbox[bn]->next=curn;             //curbox[i]的next指向相应位为i的元素
		curbox[bn]=curbox[bn]->next;    //此时curbox[i]向后移位，以box[i]为首的链表长度增加
	}
	curn=headn;
	for(i=0;i<base;i++)
	{
		if(curbox[i]!=box[i])
		{
			curn->next=box[i]->next;
			curn=curbox[i];        //curn此时指向了在box中具有相同值的链表的最后一个，例如 123，								//33，783，67，56，在3开头的 元素链表中，此时cur指向了783。
		}
	}
	curn->next=NULL;
}

void printwx()
{
	for(curn=headn->next;curn!=NULL;curn=curn->next)
	{
		cout<<curn->num<<' ';
	}
	cout<<endl;
}

int main()
{
	int i,n,z=0,maxn=0;
	curn=headn=new wx;
	cin>>n;
	for(i=0;i<base;i++)
	{
		curbox[i]=box[i]=new wx;
	}
	for(i=1;i<=n;i++)
	{
		curn=curn->next=new wx;
		cin>>curn->num;
		maxn=max(maxn,curn->num);
	}
	while(maxn/base>0)
	{
		maxn/=base;
		z++;
	}
	for(i=0;i<=z;i++)
	{
		basesort(i);
	}
	printwx();
	return 0;
}
