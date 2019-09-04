#include <stdio.h>

void swap(int *first, int *second){
	int temp = *first;
	*first = *second;
	*second = temp;
}

int partition(int arr[], int begin, int end){
	int pivot = arr[end];
	int i = begin-1;

	for (int j = 0; j < end-1; ++j)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[end]);
	return (i+1);
}

void quick_sort(int arr[], int begin, int end){
	if (begin < end)
	{
		int p = partition(arr, begin, end);

		quick_sort(arr, begin, p-1);
		quick_sort(arr, p+1, end);
	}
}

int main()
{
	/* code */
	return 0;
}