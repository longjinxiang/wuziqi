# include <stdio.h>
main()
{
  int a[10],i,j,k,t,n=10;
  printf("Please input 10 numbers:");
  for(i=0;i<10;i++)
    scanf("%d",&a[i]);
  for(i=0;i<n-1;i++)   	/*外循环控制趟数，n个数选n-1趟*/
  {
    k=i;            	/*假设当前趟的第一个数为最值,记在k中 */
    for(j=i+1;j<n;j++) 	/*从下一个数到最后一个数之间找最值*/
      if(a[k]<a[j])    	/*若其后有比最值更大的*/
        k=j;        	/*则将其下标记在k中*/
    if(k!=i)       		/*若k不为最初的i值，说明在其后找到比其更大的数*/
    {  t=a[k];  a[k]=a[i];  a[i]=t;  }	/*则交换最值和当前序列的第一个数*/
  }
  printf("The sorted numbers: ");
  for(i=0;i<10;i++)
    printf("%d   ",a[i]);
  printf("\n");
}


/*void selectsort(int *pData,int left,int right)
{
	int i,j,temp;
	int tb;
	for(i=left;i<right-1;i++)
	{
		temp = i;
		for(j=i+1;j<right;j++)
		{
			if(pData[j]<pData[temp])
			{
				temp = j;
			}
		}
		if(i != temp )
		{
			tb = pData[temp];
			pData[temp] = pData[i];
			pData[i] = tb;
		}
	}
}
*/
