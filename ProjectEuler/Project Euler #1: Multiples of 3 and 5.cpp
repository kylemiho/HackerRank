#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

//Find the sum of all the multiples of 3 or 5 below N.

unsigned long long returnSumMult(unsigned long long n) {
    unsigned long long temp = 0;
    
    //SLOW, O(N) SPEED
    //for (int i = 0; i < n; ++i) {
    //    if (i % 3 == 0) temp +=i;
    //   else if (i % 5 == 0) temp +=i;
    //}
    
    //MORE COMPLICATED, BUT O(1) SPEED (SLOWER FOR SMALL #s)
    // if N = 10; 3 + 6 + 9 = 3(1 + 2 + 3) = 3(N(N+1)/2)
    // if N = 12; 5 + 10 = 5(1+2) = 5(N(N+1)/2)
    // same applies for 15, except subtract with it
    //
    //Figure out how many numbers of 3/5/15 will be < n
    unsigned long long three = n/3 - ((n%3 == 0) ? 1 : 0);
    unsigned long long five = n/5 - ((n%5 == 0) ? 1 : 0);
    unsigned long long fifteen = n/15 - ((n%15 == 0) ? 1 : 0);
    //Now reapply top formula
    temp = 3*(three*(three+1))/2 + 5*(five*(five+1))/2 - (15*(fifteen*(fifteen+1))/2); 
    
    return temp;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        unsigned long long n;
        cin >> n;
        cout << returnSumMult(n) << endl;
    }
    return 0;
}
