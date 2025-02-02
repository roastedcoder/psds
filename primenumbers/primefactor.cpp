#include <bits/stdc++.h>
using namespace std;

vector <vector<int> > sieveFactors(int n) {
  vector <int> sp(n);
  vector< vector<int> > factors(n);
  for(int i = 0; i<n; i++) sp[i] = i;

  for(int i = 2; i*i < n; i++) {
    if(sp[i] == i) {
      for(int j = i*i; j<n; j+=i) {
        sp[j] = i;
      }
    }
  }

  for(int i = 2; i<n; i++) {
    int curr = i;
    while(curr > 1) {
      int currF = sp[curr];
      factors[i].push_back(currF);
      while(curr%currF == 0) curr /= currF;
    }
  }

  return factors;
}

int main() {
  cout << "Hello world" << endl;
  int n = 20;

  vector <vector<int> > a = sieveFactors(n);
  for(int i = 0; i<n; i++) {
    cout << i<<": ";
    for(auto y: a[i]) cout << y << ", ";
    cout << endl;
  }
  
  cout << "Bye world" << endl;
}