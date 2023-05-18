/*
#include <stdio.h>

int main(void) {
	int arr[7] = { 4,3,1,7,2,5,6 };
	int i = 0;
	int minIdx;
	while (i < 6)
	{
		int min = arr[i];
		for (int j = i+1; j < 7; j++)
		{
			if (min > arr[j])
			{
				min = arr[j];
				minIdx = j;
			}
		}
		arr[minIdx] = arr[i];
		arr[i] = min;
		i++;
	}
	for (int k = 0; k < 7; k++)
	{
		printf("%d ", arr[k]);
	}
}
*/