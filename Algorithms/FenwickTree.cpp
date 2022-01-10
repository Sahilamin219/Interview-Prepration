#include "bits/stdc++.h"
using namespace std;
vector<int> BIT(101,0);
int N;
void update(int delta, int x){
    x+=1;
    while( x < N+1){
        BIT[x] += delta;
        x+= (x)&(-x);
    }
}
int getsum(int x){
    x+=1;
    int sum=0;
    while ( x > 0){
        sum += BIT[x];
        x -= (x)&(-x);
    }
    return sum;
}
int main() {
    vector<int> v={1,2,3,4,5,6,7,8,9,10};
    N=v.size();
    for(int i=0;i<N;i++){
        update(v[i], i);
    }
    cout<<getsum(8)<<" "<<getsum(4);
	return 0;
}
