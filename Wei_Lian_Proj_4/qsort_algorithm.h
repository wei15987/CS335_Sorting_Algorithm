/*******************************************************************************
  Title          : test_qsort_algorithm.cc
  Author         : Wei Lian
  Created on     : April 22,2018
  Description    : Implementation to the quick sort_algorithms class
  Purpose        : 
  Usage          : 
  Build with     : C++
  Modifications  : 

*******************************************************************************/
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <chrono>
#include <algorithm>
#include <stack>
using namespace std;

//VerifyOrder(const vector<Comparable> &input, Comparator less_than) function can check if a input is in order or not
//it returns true if it is in order, returns false if not.
template <typename Comparable, typename Comparator>
bool VerifyOrder(const vector<Comparable> &input, Comparator less_than)
{
	int cter=0;
	for(int i=0;i<input.size()-1;++i)
	{
		int j=i+1;
		if(less_than(input[i],input[j]))
		{
			cter++;
		}
	}
	if(cter>=input.size()-1)
	{
		return true;
	}
	else
		return false;

}
/**
 * Return median of left, center, and right.
 * Order these and hide the pivot.
 */
template <typename Comparable, typename Comparator>
const Comparable & median3(vector<Comparable> & a, Comparable left, Comparable right,Comparator less_than)
{
	int center =(left+right)/2;

	if(less_than(a[center],a[left]))
		swap(a[left],a[center]);
	if(less_than(a[right],a[left]))
		swap(a[left],a[right]);
	if(less_than(a[right],a[center]))
		swap(a[center],a[right]);
	swap(a[center],a[right-1]);
	return a[right-1];
}
template <typename Comparable>
const Comparable & middle(vector<Comparable> & a, Comparable left, Comparable right)
{
	int middle=(left+right)/2;
	swap(a[middle],a[right-1]);
	return a[right-1];
}
template <typename Comparable>
const Comparable & first(vector<Comparable> & a, Comparable left, Comparable right)
{
	int first=left;
	swap(a[first],a[right-1]);
	return a[right-1];
}
//Simple insertion sort
template <typename Comparable, typename Comparator>
void insertion_sort(vector<Comparable> & a,Comparable left, Comparable right, Comparator less_than)
{
	for(int i=left;i<=right;i++)
	{
		Comparable temp =a[i];
		int j=i;
		while(j>0&&less_than(temp,a[j-1]))
		{
			a[j]=a[j-1];
			j--;
		}
		a[j]=temp;
	}
}
template <typename Comparable, typename Comparator>
void quicksort_median3(vector<Comparable> &a,Comparable left, Comparable right ,Comparator less_than)
{
	if(left+10 <= right)
	{

		//a[left]become the smallest,a[right]become the largest.
		const Comparable &pivot= median3(a,left,right,less_than);
		//cout<<a[right]<<endl;



		int i=left;
		int j=right-1;
		
		for(;;)
		{
			//while(a[++i]<pivot){}
			while(less_than(a[++i],pivot)){}
			while(less_than(pivot,a[--j])){}
			//while(pivot<a[--j]){}
			if(i<j)
			{
				swap(a[i],a[j]);
			}	
			else
				break;
		}
		swap(a[i],a[right-1]);
		quicksort_median3(a,left,i-1,less_than);
		quicksort_median3(a,i+1,right,less_than);
	}
	else
	{
		//cout<<"i"<<endl;
		//cout<<left<<"  "<<right<<endl;
		insertion_sort(a,left,right,less_than);

	}
}
template <typename Comparable, typename Comparator>
void quicksort_middle(vector<Comparable> &a,Comparable left, Comparable right ,Comparator less_than)
{
	if(left + 10 <=right)
	{
		
		const Comparable &pivot=middle(a,left,right);

		int i=left-1;
		int j=right-1;
		
		for(;;)
		{
			//while(a[++i]<pivot){}
			while(less_than(a[++i],pivot)){}
			while(less_than(pivot,a[--j])){}
			//while(pivot<a[--j]){}
			if(i<j)
			{
				swap(a[i],a[j]);
			}	
			else
				break;
		}
		swap(a[i],a[right-1]);
		quicksort_middle(a,left,i-1,less_than);
		quicksort_middle(a,i+1,right,less_than);
	}
	else
	{
		//cout<<"i"<<endl;
		insertion_sort(a,left,right,less_than);
	}
}
template <typename Comparable, typename Comparator>
void quicksort_first(vector<Comparable> &a,Comparable left, Comparable right ,Comparator less_than)
{
	if(left + 10 <=right)
	{
		const Comparable &pivot=first(a,left,right);

		int i=left-1;
		int j=right-1;
		
		for(;;)
		{
			//while(a[++i]<pivot){}
			while(less_than(a[++i],pivot)){}
			while(less_than(pivot,a[--j])){}
			//while(pivot<a[--j]){}
			if(i<j)
			{
				swap(a[i],a[j]);
			}	
			else
				break;
		}
		swap(a[i],a[right-1]);
		quicksort_first(a,left,i-1,less_than);
		quicksort_first(a,i+1,right,less_than);
	}
	else
	{
		//cout<<"i"<<endl;
		insertion_sort(a,left,right,less_than);
	}
}
/**
* Internal quicksort method that makes recursive calls.
* Uses median-of-three partitioning and a cutoff of 10.
* a is an array of Comparable items.
* left is the left-most index of the subarray.
* right is the right-most index of the subarray.
*/
template <typename Comparable, typename Comparator>
void quicksort_median3(vector<Comparable> &a, Comparator less_than)
{
	const auto begin = chrono::high_resolution_clock::now();
	Comparable left=0;
	Comparable right =a.size()-1;
	quicksort_median3(a,left,right,less_than);
	//sort(a.begin(),a.end(),less_than);

	const auto end = chrono::high_resolution_clock::now();
	cout <<"quicksort_median3: "<<"Runtime: "<< chrono::duration_cast<chrono::nanoseconds>(end-begin).count() << "ns" << endl;

}
/**
* Internal quicksort method that makes recursive calls.
* Uses middle partitioning and a cutoff of 10.
* a is an array of Comparable items.
* left is the left-most index of the subarray.
* right is the right-most index of the subarray.
*/
template <typename Comparable, typename Comparator>
void quicksort_middle(vector<Comparable> &a, Comparator less_than)
{
	const auto begin = chrono::high_resolution_clock::now();
	Comparable left=0;
	Comparable right =a.size()-1;
	quicksort_middle(a,left,right,less_than);
	//sort(a.begin(),a.end(),less_than);

	const auto end = chrono::high_resolution_clock::now();
	cout <<"quicksort_middle: "<<"Runtime: "<< chrono::duration_cast<chrono::nanoseconds>(end-begin).count() << "ns" << endl;

}
/**
* Internal quicksort method that makes recursive calls.
* Uses first partitioning and a cutoff of 10.
* a is an array of Comparable items.
* left is the left-most index of the subarray.
* right is the right-most index of the subarray.
*/
template <typename Comparable, typename Comparator>
void quicksort_first(vector<Comparable> &a, Comparator less_than)
{
	const auto begin = chrono::high_resolution_clock::now();
	Comparable left=0;
	Comparable right =a.size()-1;
	quicksort_first(a,left,right,less_than);
	//sort(a.begin(),a.end(),less_than);

	const auto end = chrono::high_resolution_clock::now();
	cout <<"QuickSort_first: "<<"Runtime: "<< chrono::duration_cast<chrono::nanoseconds>(end-begin).count() << "ns" << endl;

}