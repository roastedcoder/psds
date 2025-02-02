#include <bits/stdc++.h>
using namespace std;

vector<bool> sieve(int n) {
  vector <bool> a(n, true);
  a[0] = false;
  a[1] = false;
  for(int i = 2; i*i<n; i++) {
    if(a[i]) {
      for(int j = i*i; j < n; j+=i) {
        a[j] = false;
      }
    }
  }
  return a;
}

int main() {
  cout << "Hello world" << endl;
  int n = 20;

  vector <bool> primes = sieve(n);

  for(int i = 0; i<n; i++) {
    cout << i << " " << primes[i] << endl;
  }
  
  cout << "Bye world" << endl;
}