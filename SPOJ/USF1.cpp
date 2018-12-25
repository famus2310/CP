#include<bits/stdc++.h> 
  
using namespace std; 
  
#define MAX 100005
  
// prime[] for storing smallest prime divisor of element 
// count[] for storing the number of times a particular 
// divisor occurs in a subsequence 
int prime[MAX], countdiv[MAX], arr[MAX], n; 
  
// Simple sieve to find smallest prime factors of numbers 
// smaller than MAX 
void SieveOfEratosthenes() 
{ 
    for (int i = 2; i * i <= MAX; ++i) 
    { 
        if (!prime[i]) 
            for (int j = i * 2; j <= MAX; j += i) 
                prime[j] = i; 
    } 
  
    // Prime number will have same divisor 
    for (int i = 1; i < MAX; ++i) 
        if (!prime[i]) 
            prime[i] = i; 
} 
  
// Returns length of the largest subsequence 
// with GCD more than 1. 
int largestGCDSubsequence() 
{ 
    int ans = 0; 
    for (int i=0; i < n; ++i) 
    { 
        int element = arr[i]; 
  
        // Fetch total unique prime divisor of element 
        while (element > 1) 
        { 
            int div = prime[element]; 
  
            // Increment count[] of Every unique divisor 
            // we get till now 
            ++countdiv[div]; 
  
            // Find maximum frequency of divisor 
            ans = max(ans, countdiv[div]); 
  
            while (element % div==0) 
                element /= div; 
        } 
    } 
  
    return ans; 
} 
  
// Driver code 
int main() 
{ 
    // Pre-compute smallest divisor of all numbers 
    SieveOfEratosthenes(); 
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << largestGCDSubsequence() << endl; 
    }
    return 0; 
} 