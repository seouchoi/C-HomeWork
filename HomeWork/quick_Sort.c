/*
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define swap(a,b) {int tmp=a; a=b; b=tmp;}


int partition(int list[], int left, int right) {
	int low = left;
	int high = right + 1;
	int pivot = list[left];
	
	
		do
		{
			do
			{
				low++;
			} while (low <= right && pivot > list[low]);
			do
			{
				high--;
			} while (high >= left && pivot < list[high]);

			if (low < high)
			{
				swap(list[low], list[high]);
			}
		} while (low < high);

		swap(list[left], list[high]);
		return high;
	
}

void quick_sort(int list[], int left, int right) {
	if (left < right) {
		int pivot = partition(list, left, right);
		quick_sort(list, left, pivot - 1);
		quick_sort(list, pivot + 1, right);
	}
}

int main(void) {
	int a;
	printf("배열의 갯수를 입력하세요 : ");
	scanf("%d", &a);
	srand(time(NULL));
	int* arr = malloc(sizeof(int) * a);
	for (int i = 0; i < a; i++)
	{
		int random = rand() % a + 1;
		arr[i] = random;
	}
	for (int j = 0; j < a; j++)
	{
		printf("%d ", arr[j]);
	}
	printf("\n");
	quick_sort(arr, 0, a - 1);
	for (int k = 0; k < a; k++)
	{
		printf("%d ", arr[k]);
	}
}
*/