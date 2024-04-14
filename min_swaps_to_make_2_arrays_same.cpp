// C++ program to make an array same to another 
// using minimum number of swap 
/*
Given two arrays that have the same values but in a different order and having no duplicate elements in it, we need to make a second array the same as a first array using the minimum number of swaps. 

Examples:  

    Input  : arrA[] = {3, 6, 4, 8}, 
             arrB[] = {4, 6, 8, 3}
    Output : 2
    Explanation: we can make arrB to same as arrA in 2 swaps which are shown below, swap 4 with 8,
    arrB = {8, 6, 4, 3} swap 8 with 3,   arrB = {3, 6, 4, 8}

This problem can be solved by modifying the array B. We save the index of array A elements in array B i.e. if ith element of array A is at jth position in array B, then we will make arrB[i] = j 
For above given example, modified array B will be, arrB = {3, 1, 0, 2}. This modified array represents the distribution of array A element in array B and our goal is to sort this modified array 
in a minimum number of swaps because after sorting only array B element will be aligned with array A elements. 
*/
#include <bits/stdc++.h> 
using namespace std; 

// Function returns the minimum number of swaps 
// required to sort the array 
// This method is taken from below post 
// https://www.geeksforgeeks.org/minimum-number-swaps-required-sort-array/ 
int minSwapsToSort(int arr[], int n) 
{ 
	// Create an array of pairs where first 
	// element is array element and second element 
	// is position of first element 
	pair<int, int> arrPos[n]; 
	for (int i = 0; i < n; i++) 
	{ 
		arrPos[i].first = arr[i]; 
		arrPos[i].second = i; 
	} 

	// Sort the array by array element values to 
	// get right position of every element as second 
	// element of pair. 
	sort(arrPos, arrPos + n); 

	// To keep track of visited elements. Initialize 
	// all elements as not visited or false. 
	vector<bool> vis(n, false); 

	// Initialize result 
	int ans = 0; 

	// Traverse array elements 
	for (int i = 0; i < n; i++) 
	{ 
		// already swapped and corrected or 
		// already present at correct pos 
		if (vis[i] || arrPos[i].second == i) 
			continue; 

		// find out the number of node in 
		// this cycle and add in ans 
		int cycle_size = 0; 
		int j = i; 
		while (!vis[j]) 
		{ 
			vis[j] = 1; 

			// move to next node 
			j = arrPos[j].second; 
			cycle_size++; 
		} 

		// Update answer by adding current cycle. 
		ans += (cycle_size - 1); 
	} 

	// Return result 
	return ans; 
} 

// method returns minimum number of swap to make 
// array B same as array A 
int minSwapToMakeArraySame(int a[], int b[], int n) 
{ 
	// map to store position of elements in array B 
	// we basically store element to index mapping. 
	map<int, int> mp; 
	for (int i = 0; i < n; i++) 
		mp[b[i]] = i; 

	// now we're storing position of array A elements 
	// in array B. 
	for (int i = 0; i < n; i++) 
		b[i] = mp[a[i]]; 

	/* We can uncomment this section to print modified 
	b array 
	for (int i = 0; i < N; i++) 
		cout << b[i] << " "; 
	cout << endl; */

	// returning minimum swap for sorting in modified 
	// array B as final answer 
	return minSwapsToSort(b, n); 
} 

// Driver code to test above methods 
int main() 
{ 
	int a[] = {3, 6, 4, 8}; 
	int b[] = {4, 6, 8, 3}; 

	int n = sizeof(a) / sizeof(int); 
	cout << minSwapToMakeArraySame(a, b, n); 
	return 0; 
} 
