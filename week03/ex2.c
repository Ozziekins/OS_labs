#include <stdio.h>

/* auxiliary function for the bubble sort */
void swap(int *first, int *second){
	int temp = *first;
	*first = *second;
	*second = temp;
}

/* my function bubble_sort() which accepts an array of integers and sorts it in place using Bubble sort algorithm */
void bubble_sort(int arr[], int n){
	for (int i = 0; i < n-1; ++i)
	{
		for (int j = 0; j < n-i-1; ++j)
		{
			if (arr[j] > arr[j+1])
			{
				swap(&arr[j], &arr[j+1]);
			}
		}
	}
}

int main()
{
	/* code */
	return 0;
}
