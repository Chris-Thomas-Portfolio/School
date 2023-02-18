/*************************************************************
* Author: Chris Thomas
* Filename: Stub.cpp
* Date Created: 6/4/2022 12:23 PM
* Modifications: N/A
**************************************************************/
/*************************************************************
*
* Lab/Assignment: Lab 14 Sorts
*
* Overview: This program runs and times 8 different sorts.
*
*
* Input: Command line argument for number of values to sort.
*
*
* Output: Outputs sorted data and elapsed time of sort.
*
*
**************************************************************/
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <vector>
using std::vector;
#include <fstream>
using std::ifstream;
using std::ios;
#include <chrono>
using std::chrono::system_clock;
using std::chrono::duration_cast;
using std::chrono::microseconds;

#include "Array.h"
#include "Exception.h"

template <typename T>
void BubbleSort(T& data, int size);
template <typename T>
void FlaggedBubbleSort(T& data, int size);
template <typename T>
void SelectionSort(T& data, int size);
template <typename T>
void InsertionSort(T& data, int size);
template <typename T>
void ShellSort(T& data, int size);
template <typename T>
void MoveDown(T& data, int first, int size);
template <typename T>
void HeapSort(T& data, int size);
template <typename T>
void MergeSort(T& data, int size);
template <typename T>
void MergeSort(T& data, vector<int> &temp, int lindex, int rindex);
template <typename T>
void Merge(T& data, vector<int> &temp, int lindex, int rindex, int right_end);
template <typename T>
void QuickSort(T& data, int size);
template <typename T>
void QuickSort(T& data, int first, int last);

int main(int argc, char **argv)
{
	int size = atoi(argv[1]);			//set size variable to size set by command line
	vector<int> unsortedData(size);
	Array<int> unsortedmyData(size);
	//int unsortedCData[1000000];
	vector<int> Data(size);			//create vector for storing data
	Array<int> myData(size);
	//int data[1000000];

	vector<int> heapsort = { 10, 8, 6, 20, 4, 3, 22, 1, 0, 15, 16 };
	for (int i = 0; i < size; i++)
	{
		unsortedData[i] = rand() & 10000;	//set each element in array to a random value between 0-9999
		//unsortedmyData[i] = rand() & 10000;
		//unsortedCData[i] = rand() & 10000;
		//data[i] = unsortedCData[i];
	}
	Data = unsortedData;
	//myData = unsortedmyData;

	//BubbleSort(Data, size);			//call bubble sort function
	//BubbleSort(myData, size);			//call bubble sort function
	//BubbleSort(data, size);			//call bubble sort function
	//Data = unsortedData;
	//myData = unsortedmyData;
	//for (int i = 0; i < size; i++)
	//{
	//	data[i] = unsortedCData[i];
	//}
	//FlaggedBubbleSort(Data, size);	//call flagged bubble sort function
	//FlaggedBubbleSort(myData, size);	//call flagged bubble sort function
	//FlaggedBubbleSort(data, size);	//call flagged bubble sort function
	//Data = unsortedData;
	//myData = unsortedmyData;
	//for (int i = 0; i < size; i++)
	//{
	//	data[i] = unsortedCData[i];
	//}
	//SelectionSort(Data, size);			//call selection sort function
	//SelectionSort(myData, size);
	//SelectionSort(data, size);
	//Data = unsortedData;
	//myData = unsortedmyData;
	//for (int i = 0; i < size; i++)
	//{
	//	data[i] = unsortedCData[i];
	//}
	//InsertionSort(Data, size);		//call insertion sort function
	//InsertionSort(myData, size);		//call insertion sort function
	//InsertionSort(data, size);		//call insertion sort function
	//Data = unsortedData;
	//myData = unsortedmyData;
	//for (int i = 0; i < size; i++)
	//{
	//	data[i] = unsortedCData[i];
	//}
	//ShellSort(Data, size);			//call shell sort function
	//ShellSort(myData, size);			//call shell sort function
	//ShellSort(data, size);			//call shell sort function
	//Data = unsortedData;
	//myData = unsortedmyData;
	//for (int i = 0; i < size; i++)
	//{
	//	data[i] = unsortedCData[i];
	//}
	//HeapSort(Data, size);				//call heap sort function
	//HeapSort(myData, size);				//call heap sort function
	//HeapSort(data, size);				//call heap sort function
	//Data = unsortedData;
	//myData = unsortedmyData;
	//for (int i = 0; i < size; i++)
	//{
	//	data[i] = unsortedCData[i];
	//}
	MergeSort(Data, size);			//call merge sort fucntion
	//MergeSort(myData, size);			//call merge sort fucntion
	//MergeSort(data, size);			//call merge sort fucntion
	//QuickSort(heapsort, 11);
	return 0;	
}

/**********************************************************************
* Purpose: Perform a bubble sort on data.
*
* Precondition:	Needs an array of data.
*
* Postcondition: Sort the data in array from smallest to largest.
*
***********************************************************************/

template<typename T>
void BubbleSort(T& data, int size)
{
	cout << "Starting Bubble Sort" << endl;
	auto start = system_clock::now();			//start timing of sort
	for (int i = 0; i < size -1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (data[j] > data[j + 1])						
			{
				int temp = data[j];				//store value in temp int
				data[j] = data[j + 1];			//set data[j] to data[j+1] value
				data[j + 1] = temp;				//data[j+1] set to temp value
			}
		}
	}
	auto end = system_clock::now();				//end timer
	auto elapsed = duration_cast<microseconds>(end - start);	//calculated time in microseconds
	for (int i = 0; i < size; i++)
	{
		cout << data[i] << endl;								//print data out in sorted order
	}
	cout << endl;
	cout << "Time in Microseconds: " << elapsed.count() << endl;	//print out elapsed time
}

/**********************************************************************
* Purpose: Perform a flagged bubble sort on data.
*
* Precondition:	Needs an array of data.
*
* Postcondition: Sort the data in array from smallest to largest.
*
***********************************************************************/

template<typename T>
void FlaggedBubbleSort(T& data, int size)
{
	cout << "Starting Flagged Bubble Sort" << endl;
	bool swapped;
	auto start = system_clock::now();		//start timer
	for (int i = 0; i < size - 1; i++)
	{
		swapped = false;
		for (int j = 0; j < size - i - 1; j++)
		{
			if (data[j] > data[j + 1])					//check to see if data needs swapped
			{
				int temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
				swapped = true;							//set flag to true
			}
		}
		if (swapped == false)							//if nothing gets swapped and stop sorting
			break;
	}
	auto end = system_clock::now();						//end timer
	auto elapsed = duration_cast<microseconds>(end - start);	//calculate time in microseconds
	for (int i = 0; i < size; i++)
	{	
		cout << data[i] << endl;								//print out sorted data
	}
	cout << endl;
	cout << "Time in Microseconds: " << elapsed.count() << endl;	//print out elapsed time for sort
}

/**********************************************************************
* Purpose: Perform a selection sort on data.
*
* Precondition:	Needs an array of data.
*
* Postcondition: Sort the data in array from smallest to largest.
*
***********************************************************************/

template<typename T>
void SelectionSort(T& data, int size)
{
	cout << "Starting Selection Sort" << endl;
	int i, j;
	int max = 0;							//index of largest number
	auto start = system_clock::now();		//start timer
	for (i = 0; i < size - 1; i++)
	{
		for (j = i + 1, max = i; j < size; j++)
		{
			if (data[j] < data[max])
			{
				max = j;							//set max to j
			}	
		}
		int temp = data[i];
		data[i] = data[max];					//swap data[i] and data[max]
		data[max] = temp;
	}

	auto end = system_clock::now();				//end timer
	auto elapsed = duration_cast<microseconds>(end - start);	//calculated time in microseconds
	for (int i = 0; i < size; i++)
	{
		cout << data[i] << endl;								//print data out in sorted order
	}
	cout << endl;
	cout << "Time in Microseconds: " << elapsed.count() << endl;	//print out elapsed time
}

/**********************************************************************
* Purpose: Perform a insertion sort on data.
*
* Precondition:	Needs an array of data.
*
* Postcondition: Sort the data in array from smallest to largest.
*
***********************************************************************/

template<typename T>
void InsertionSort(T& data, int size)
{
	cout << "Starting Insertion Sort" << endl;
	int temp, j;
	auto start = system_clock::now();		//start timer
	for (int i = 1; i < size; i++)
	{
		temp = data[i];							//set temp to data at i
		for(j = i; j > 0 && temp < data[j-1]; j--)
		{
			data[j] = data[j - 1];				//set data[j] to data[j-1]
		}
		data[j] = temp;
	}
	auto end = system_clock::now();				//end timer
	auto elapsed = duration_cast<microseconds>(end - start);	//calculated time in microseconds
	for (int i = 0; i < size; i++)
	{
		cout << data[i] << endl;								//print data out in sorted order
	}
	cout << endl;
	cout << "Time in Microseconds: " << elapsed.count() << endl;	//print out elapsed time
}

/**********************************************************************
* Purpose: Perform a shell sort on data.
*
* Precondition:	Needs an array of data.
*
* Postcondition: Sort the data in array from smallest to largest.
*
***********************************************************************/

template<typename T>
void ShellSort(T& data, int size)
{
	cout << "Starting Shell Sort" << endl;
	int h = 0;	

	auto start = system_clock::now();		//start timer

	for (int i = 0; h < size / 3; i++)					//setup array of increments
	{
		h = (3 * h) + 1;
	}

	while(h > 0)
	{
		for (int i = h; i < size; i++)
		{
			auto temp = data[i];
			int k = i;

			while (k > h - 1 && data[k - h] >= temp)	//swap data to right spot
			{
				data[k] = data[k - h];
				k = k - h;
			}
			data[k] = temp;
		}
		h = (h - 1) / 3;
	}
	auto end = system_clock::now();				//end timer
	auto elapsed = duration_cast<microseconds>(end - start);	//calculated time in microseconds
	for (int i = 0; i < size; i++)
	{
		cout << data[i] << endl;								//print data out in sorted order
	}
	cout << endl;
	cout << "Time in Microseconds: " << elapsed.count() << endl;	//print out elapsed time
}

/**********************************************************************
* Purpose: Perform a shell sort on data.
*
* Precondition:	Needs an array of data.
*
* Postcondition: Sort the data in array from smallest to largest.
*
***********************************************************************/

template<typename T>
void HeapSort(T& data, int size)
{
	cout << "Starting Heap Sort" << endl;
	int first = (size/2) - 1;
	int temp;

	auto start = system_clock::now();		//start timer

	for (int i = first; i >= 0; i--)		//setup max heap
	{
		MoveDown(data, i, size - 1);
	}

	for (int i = size - 1; i > 0; i--)		//swap first and last element then recall MoveDown
	{
		temp = data[0];
		data[0] = data[i];
		data[i] = temp;
		MoveDown(data, 0, i - 1);
	}
	auto end = system_clock::now();								//end timer
	auto elapsed = duration_cast<microseconds>(end - start);	//calculated time in microseconds
	for (int i = 0; i < size; i++)
	{
		cout << data[i] << endl;								//print data out in sorted order
	}
	cout << endl;
	cout << "Time in Microseconds: " << elapsed.count() << endl;	//print out elapsed time
}

template<typename T>
void MergeSort(T& data, int size)
{
	cout << "Starting Merge Sort" << endl;

	auto start = system_clock::now();		//start timer
	
	vector<int> temp(size);

	MergeSort(data, temp, 0, size - 1);

	auto end = system_clock::now();								//end timer
	auto elapsed = duration_cast<microseconds>(end - start);	//calculated time in microseconds
	for (int i = 0; i < size; i++)
	{
		cout << data[i] << endl;								//print data out in sorted order
	}
	cout << endl;
	cout << "Time in Microseconds: " << elapsed.count() << endl;	//print out elapsed time
}

template<typename T>
void MergeSort(T& data, vector<int> &temp, int lindex, int rindex)
{
	int mid;
	if (lindex < rindex)									
	{
		mid = (lindex + rindex) / 2;						//find middle point of array
		MergeSort(data, temp, lindex, mid);					//call 4 arg merge sort for left side
		MergeSort(data, temp, mid + 1, rindex);				//call 4 arg merge sort for right side
		Merge(data, temp, lindex, mid + 1, rindex);			//call merge to merge the two halves
	}
}

template<typename T>
void Merge(T& data, vector<int> &temp, int lindex, int rindex, int right_end)
{
	int left = lindex;								//set left to starting point of left array
	int right = rindex;								//set right to starting point of right array
	int left_end = rindex - 1;						//find the end of point of left array
	int temp_pos = lindex;							//set temp_pos to start of left array
	int num_elements = right_end - lindex + 1;		//calculate the size of the whole array

	while (left <= left_end && right <= right_end)	//do this while not at end of either left or right array
	{
		if (data[left] <= data[right])				
		{
			temp[temp_pos] = data[left];			//if data in the left array is < data in right put the left data into 
			temp_pos++;
			left++;
		}
		else
		{
			temp[temp_pos] = data[right];
			temp_pos++;
			right++;
		}
	}

	while (left <= left_end)
	{
		temp[temp_pos] = data[left];
		temp_pos++;
		left++;
	}

	while (right <= right_end)
	{
		temp[temp_pos] = data[right];
		temp_pos++;
		right++;
	}
	
	for (int i = 0; i < num_elements; i++)
	{
		data[right_end] = temp[right_end];
		right_end--;
	}
}

template<typename T>
void QuickSort(T& data, int size)
{
	int max = 0;
	int	temp;
	if (size >= 2)
	{
		for (int i = 1, max = 0; i < size; i++)
		{
			if (data[max] < data[i])
			{
				max = i;
			}
		}
		temp = data[size - 1];
		data[size - 1] = data[max];
		data[max] = temp;
		QuickSort(data, 0, size - 2);
	}
}

template<typename T>
void QuickSort(T& data, int first, int last)
{
	int temp;
	int small = first + 1;
	int large = last;
	int pivot = data[first];

	while (small <= large)
	{
		while (data[small] < pivot)
		{
			small = small + 1;
		}

		while (data[large] > pivot)
		{
			large = large - 1;
		}

		if (small < large)
		{
			temp = data[small];
			data[small] = data[large];
			data[large] = data[small];
		}
		else
		{
			small = small + 1;
		}
	}
	temp = data[large];
	data[large] = data[small];
	data[small] = temp;

	if (first < large - 1)
	{
		QuickSort(data, first, large - 1);
	}
	if (last > large + 1)
	{
		QuickSort(data, large + 1, last);
	}
}

template<typename T>
void MoveDown(T& data, int first, int size)
{
	int largest = first * 2 + 1;									//set largest
	int temp;														//temp for storing ints for swaps

	while (largest <= size)
	{
		if (largest < size && data[largest] < data[largest + 1])
		{
			largest++;												//if largest is small than size and data at largest
		}															//is less than right child increment largest

		if (data[first] < data[largest])							//if data at first is less than right child swap them
		{
			temp = data[first];
			data[first] = data[largest];
			data[largest] = temp;
			first = largest;
			largest = first * 2 + 1;
		}
		else
		{
			largest = size + 1;										//else we are done and exit while loop
		}
	}
}
