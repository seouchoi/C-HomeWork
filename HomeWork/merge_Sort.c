/*
#include <stdio.h>

void merge(int list[], int left, int mid, int right);
void merge_sort(int list[], int left, int right);
int mergedArr[8];

int main(void) {
	int arr[12] = { 2,5,6,1,3,4,7,8,9,12,10,11 };
	int left = 0;
	int right = 11;
	merge_sort(arr, left, right);

	for (int i = 0; i < right+1; i++)
	{
		printf("%d ", arr[i]);
	}
}

void merge_sort(int list[], int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);
		merge(list, left, mid, right);
	}
}

void merge(int list[], int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int k = left;

	while (i <= mid && j <= right)
	{
		if (list[i] < list[j])
		{
			mergedArr[k++] = list[i++];
		}
		else
		{
			mergedArr[k++] = list[j++];
		}
	}
	while (i <= mid)
	{
		mergedArr[k++] = list[i++];
	}
	while (j <= right)
	{
		mergedArr[k++] = list[j++];
	}
	for (int l = left; l <= right; l++)
	{
		list[l] = mergedArr[l];
	}
}
*/