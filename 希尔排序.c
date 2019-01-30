void shellsort(int *pData,int left,int right)
{
	int i,j,gap;
	int temp;
	for(gap=right/2;gap>0;gap/=2)
	{
		for(i=gap;i<right;i++)
		{
			temp = pData[i];
			for(j=i-gap;(j>=0)&&pData[j]>temp;j-=gap)
			{
				pData[j+gap] = pData[j];
			}
			pData[j+gap] = temp;
		}
	}
}
