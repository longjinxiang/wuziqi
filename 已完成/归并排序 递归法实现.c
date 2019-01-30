#include<iostream.h>
void mergesort2(int *pData,int *Des,int left,int right)
{
int first = left;
int last  = right-1;
if(first<last)
{
int mid = (first + last)/2;
mergesort2(pData,Des,first,mid+1);
mergesort2(pData,Des,mid+1,right);
merges(pData,Des,first,mid,last);
}
}
void merges(int *pData,int *Des,int first,int mid,int last)
{
int i = first;
int j = mid + 1;
int k = first;
while(i<=mid&&j<=last)
{
if(pData[i]<pData[j])
Des[k++] = pData[i++];
else
Des[k++] = pData[j++];

}
while(i<=mid)
{
Des[k++] = pData[i++];
}
while(j<=last)
{
Des[k++] = pData[j++];
}
for(k=first;k<=last;k++)
pData[k] = Des[k];
}
