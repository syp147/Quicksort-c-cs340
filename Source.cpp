#include <iostream>
using namespace std;
int Partition(int *array, int high, int low);
void QuickSort(int *array, int high, int low);

int main()
{
	int n = 5;
	cout << "Enter the size you want array to be sorted: ";
	cin >> n;
	int array[n];
	cout << "Enter elements:\n";
	for (int i = 0; i<n; i++)
	{
		cin >> array[i];
	}
	QuickSort(array, 0, n - 1);
	cout << "QuickSorted array is: ";
	for (int i = 0; i<n; i++)
	{
		cout << array[i] << " ";
	}
	return 0;
}
int Partition(int *array, int high, int low)
{
	int pivot = array[low];
	int index = high;
	int i;
	int tmp;

	for (i = high; i<low; i++)
	{
		if (array[i] <= pivot)
		{
			tmp = array[i];
			array[i] = array[index];
			array[index] = tmp;
			index++;
		}
	}

	tmp = array[low];
	array[low] = array[index];
	array[index] = tmp;


	return index;
}
void QuickSort(int *array, int high, int low)
{
	if (high<low)
	{
		int index = Partition(array, high, low);
		QuickSort(array, high, index - 1);
		QuickSort(array, index + 1, low);
	}
}