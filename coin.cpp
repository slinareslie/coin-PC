#include <bits/stdc++.h>

using namespace std;

vector<float> c;
vector<float> ready(100,0);
vector<float> listo(100,0);

float solve(float);

int main(){
    float n;
    cin>>n;

    for(float i=0;i<n ;i++){
        float aux;
        cin>>aux;
        c.push_back(aux);
    }

    float x;
    cin>>x;

    cout<<solve(x)<<"\n";

    return 0;
}


float solve(float x){

    if (x==0) {
        return 0;
    }
    else if (x<0) {
        return INFINITY;
    }
    if(ready[x]==1){
        return listo[x]-1;
    }

    float best=INFINITY;

    for(auto j :c){

        best=min(best, solve(x-j)+1);
        listo[x-j]=best;
        ready[x-j]=1;
        
    }
    return best;
}