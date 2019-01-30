/****************************/
/*author:²»´ÇÔ¶*/
/****************************/
#include <malloc.h>
#include <stdlib.h>
void mergesort(int*a,int length){
    int step;
    int*p,*q,*t;
    int i,j,k,len1,len2;
    int*temp;
        step=1;
    p=a;
    q=(int*)malloc(sizeof(int)*length);
    temp=q;
    while(step<length){
        i=0;
        j=i+step;
        k=i;
        len1=i+step<length?i+step:length;
        len2=j+step<length?j+step:length;
        while(i<length){
            while(i<len1&&j<len2){
                q[k++]=p[i]<p[j]?p[i++]:p[j++];
            }
            while(i<len1){
                q[k++]=p[i++];
            }
            while(j<len2){
                q[k++]=p[j++];
            }
            i=j;
            j=i+step;
            k=i;
            len1=i+step<length?i+step:length;
            len2=j+step<length?j+step:length;
        }
        step*=2;
        t=p;
        p=q;
        q=t;
    }

    if(a!=p){
        memcpy(a,p,sizeof(int)*length);
    }

    free(temp);
}
void main(void){
int arrary[]={9,6,1,3,8,4,2,0,5,7};
mergesort(arrary,10);
}
