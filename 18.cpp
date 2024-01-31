#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  int a[] = {1,2,3,4,5,6,7,8,9};
  int b[9];  
  for(int i = 0; i < 9; i++) cin >> b[i];
  int res = 100;
  int s = 0;
  do{
    if (
       (a[0] + a[1] + a[2]) == 15 &&
       (a[3] + a[4] + a[5]) == 15 &&
       (a[6] + a[7] + a[8]) == 15 &&
       (a[0] + a[3] + a[6]) == 15 &&
       (a[1] + a[4] + a[7]) == 15 &&
       (a[2] + a[5] + a[8]) == 15 &&
       (a[0] + a[4] + a[8]) == 15 &&
       (a[2] + a[4] + a[6]) == 15) {
         int s = 0;
         for(int i = 0; i < 9; i++)
           s += abs(a[i] - b[i]);
         if(res > s) res = s;  
       }
  }while(next_permutation(a,a+9));
  cout << res << endl;
  return 0;
}