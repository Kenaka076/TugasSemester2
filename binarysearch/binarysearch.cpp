#include <iostream>
using namespace std;


int binarySearch(int arr[], int i, int r, int x) {
  
   while (i <= r) {
     
      int m = i + (r - i) / 2;
      	if (arr[m] == x) return m;
      		if (arr[m] < x) i = m + 1;
      else r = m - 1;
   		}
   
   return -1; 
}

int main() {
   
   int arr[] = {4, 6, 8, 10, 12, 16};
   int elm = 8;

   
   int x = 6;
   int result = binarySearch(arr, 0, elm - 1, x);

   (result == -1) ? cout << "Elemen tidak ditemukan"
                  : cout << "Elemen ditemukan di indeks ke-" << result;

   return 0;
}
