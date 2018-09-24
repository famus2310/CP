#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define debug(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
const int MOD = 1e9 + 7;
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;
 
LL  _mergeSort(LL arr[], LL temp[], LL left, LL right);
LL merge(LL arr[], LL temp[], LL left, LL mid, LL right);
 
/* This function sorts the input array and returns the
   number of inversions in the array */
LL mergeSort(LL arr[], LL array_size)
{
    LL *temp = (LL *)malloc(sizeof(LL)*array_size);
    return _mergeSort(arr, temp, 0, array_size - 1);
}
 
/* An auxiliary recursive function that sorts the input array and
  returns the number of inversions in the array. */
LL _mergeSort(LL arr[], LL temp[], LL left, LL right)
{
  LL mid, inv_count = 0;
  if (right > left)
  {
    /* Divide the array LLo two parts and call _mergeSortAndCountInv()
       for each of the parts */
    mid = (right + left)/2;
 
    /* Inversion count will be sum of inversions in left-part, right-part
      and number of inversions in merging */
    inv_count  = _mergeSort(arr, temp, left, mid);
    inv_count += _mergeSort(arr, temp, mid+1, right);
 
    /*Merge the two parts*/
    inv_count += merge(arr, temp, left, mid+1, right);
  }
  return inv_count;
}
 
/* This funt merges two sorted arrays and returns inversion count in
   the arrays.*/
LL merge(LL arr[], LL temp[], LL left, LL mid, LL right)
{
  LL i, j, k;
  LL inv_count = 0;
 
  i = left; /* i is index for left subarray*/
  j = mid;  /* j is index for right subarray*/
  k = left; /* k is index for resultant merged subarray*/
  while ((i <= mid - 1) && (j <= right))
  {
    if (arr[i] <= arr[j])
    {
      temp[k++] = arr[i++];
    }
    else
    {
      temp[k++] = arr[j++];
 
     /*this is tricky -- see above explanation/diagram for merge()*/
      inv_count = inv_count + (mid - i);
    }
  }
 
  /* Copy the remaining elements of left subarray
   (if there are any) to temp*/
  while (i <= mid - 1)
    temp[k++] = arr[i++];
 
  /* Copy the remaining elements of right subarray
   (if there are any) to temp*/
  while (j <= right)
    temp[k++] = arr[j++];
 
  /*Copy back the merged elements to original array*/
  for (i=left; i <= right; i++)
    arr[i] = temp[i];
 
  return inv_count;
}
 
/* Driver program to test above functions */

LL arr[N];

int main() {
  LL n;
  scanf("%lld", &n);
  for (LL i = 0; i < n; i++) scanf("%lld", arr + i);
  printf("%lld\n", mergeSort(arr, n));
  return 0;
}
		