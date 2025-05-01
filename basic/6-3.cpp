#include <iostream>
 using namespace std;
 
 int main() {
     int size1, size2;
 
     // Read sizes
     cout << "Enter the size of first sorted array: ";
     cin >> size1;
     cout << "Enter the size of second sorted array: ";
     cin >> size2;
 
     // Dynamic allocation for input arrays
     int* arr1 = new int[size1];
     int* arr2 = new int[size2];
 
     // Input elements of first array
     cout << "Enter elements of first sorted array:\n";
     for (int i = 0; i < size1; i++)
     {
         cin >> arr1[i];
     }
 
     // Input elements of second array
     cout << "Enter elements of second sorted array:\n";
     for (int i = 0; i < size2; i++) {
         cin >> arr2[i];
     }
 
     // Allocate memory for merged array
     int mergedSize = size1 + size2;
     int* mergedArr = new int[mergedSize];
 
     // Merge logic using for loop
     int i = 0, j = 0;
     for (int k = 0; k < mergedSize; k++)
     {
         if (i < size1 && (j >= size2 || arr1[i] <= arr2[j]))
          {
             mergedArr[k] = arr1[i++];
         } else {
             mergedArr[k] = arr2[j++];
         }
     }
 
     // Output the merged array
     cout << "Merged sorted array:\n";
     for (int i = 0; i < mergedSize; i++) {
         cout << mergedArr[i] << " ";
     }
     cout << endl;
 
     // Free dynamically allocated memory
     delete[] arr1;
     delete[] arr2;
     delete[] mergedArr;
 
     return 0;
 }