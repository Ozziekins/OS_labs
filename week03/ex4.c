#include <stdio.h>

/* first auxiliary function which will be used in the quick sort */
void swap(int *first, int *second){
	int temp = *first;
	*first = *second;
	*second = temp;
}

/* second auxiliary function which will be used in the quick sort */
/* it reorders the array so that all elements with values less than the pivot come before the pivot,
while all elements with values greater than the pivot come after it(equal values can go either way).*/
int partition(int arr[], int begin, int end){
	int pivot = arr[end];
	int i = begin-1;

	for (int j = begin; j <= end-1; ++j)
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

/* implementation of quick sort algorithm */
void quick_sort(int arr[], int begin, int end){
	if (begin < end)
	{
		int p = partition(arr, begin, end);

		/* recursion */
		quick_sort(arr, begin, p-1);
		quick_sort(arr, p+1, end);
	}
}

int main()
{
	/* code */
	return 0;
}
