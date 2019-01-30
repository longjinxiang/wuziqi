void HeapAdjust(int array[], int i, int nLength)
{
	int nchild;
	int ntemp;
	while(i>=0)
	{
		nchild = 2 * i + 1;
		ntemp = array[i];
		if (array[nchild]<ntemp)
		{
			ntemp = array[nchild];
			array[nchild] = array[i];
			array[i] = ntemp;
		}
		if (nchild < nLength - 1)
		{
			nchild++;
			if (array[nchild]<ntemp)
			{
				ntemp = array[nchild];
				array[nchild] = array[i];
				array[i] = ntemp;
			}
		}
		i--;
	}

}

// ¶ÑÅÅĞòËã·¨
void HeapSort(int array[],int length)
{
	int i,temp;
	for (int nL = length; nL>0;nL--)
	{
		i = nL/2 - 1;
		HeapAdjust(array,i,nL);
		temp = array[0];
		array[0] = array[nL-1];
		array[nL-1] = temp;
	}
}
