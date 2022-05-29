#include <iostream>
#include <cmath>
#include <algorithm>
typedef long long LL;
using namespace std;
const int maxn=20;
int n;
int listt[maxn];
int inp[maxn];

int min=1e5+5;

struct item{
    int time_com;
    int time_hig;
    int time;
};

item t[maxn];

void assignment()
{
    t[1].time_com=5;
    t[2].time_com=45;
    t[3].time_com=45;
    t[4].time_com=30;
    t[5].time_com=10;
    t[6].time_com=5;
    t[7].time_com=5;
    t[8].time_com=45;
    t[9].time_com=45;
    t[10].time_com=5;
    t[11].time_com=45;
    t[12].time_com=45;
    t[13].time_com=15;
    t[14].time_com=60;
    t[15].time_com=15;
    t[16].time_com=15;
    t[17].time_com=10;
    t[18].time_com=10;
    t[19].time_com=10;
    
    t[1].time_hig=30;
    t[2].time_hig=75;
    t[3].time_hig=75;
    t[4].time_hig=60;
    t[5].time_hig=45;
    t[6].time_hig=30;
    t[7].time_hig=30;
    t[8].time_hig=120;
    t[9].time_hig=100;
    t[10].time_hig=30;
    t[11].time_hig=75;
    t[12].time_hig=120;
    t[13].time_hig=75;
    t[14].time_hig=180;
    t[15].time_hig=90;
    t[16].time_hig=30;
    t[17].time_hig=60;
    t[18].time_hig=45;
    t[19].time_hig=45;
    
    t[1].time=10;
    t[2].time=10;
    t[3].time=4;
    t[4].time=3;
    t[5].time=3;
    t[6].time=1;
    t[7].time=3;
    t[8].time=2;
    t[9].time=1;
    t[10].time=1;
    t[11].time=4;
    t[12].time=10;
    t[13].time=15;
    t[14].time=5;
    t[15].time=10;
    t[16].time=15;
    t[17].time=1;
    t[18].time=4;
    t[19].time=5;
    
    return;
}

int calculation()
{
    int cur=0;
    for(int i=0;i<n;i++)
    {
        if((cur>=0&&cur<=90)||(cur>=240&&cur<=300)||(cur>=540&&cur<=630)||(cur>=720&&cur<=810))
        {
            cur+=t[listt[i]].time_com;
            cur+=t[listt[i]].time;
        }
        else if((cur>90&&cur<240)||(cur>300&&cur<540)||(cur>630&&cur<720))
        {
            cur+=t[listt[i]].time_hig;
            cur+=t[listt[i]].time;
        }
    }
    return cur;
}

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
void perm(int list[],int low,int high){
    if(low==high){
        for(int i=0;i<=low;i++)
            listt[i]=list[i];

        for(int i=0;i<n;i++)
            cout<<listt[i];
        cout<<" "<<calculation();

        cout<<endl;
    }else{
        for(int i=low;i<=high;i++){
            swap(list[i],list[low]);
            perm(list,low+1,high);
            swap(list[i],list[low]);
        }
    }
}


LL jiecheng(int a)
{
    LL ans=1;
    while (a>1) {
        ans*=a;
        a--;
    }
    return ans;
}

int main()
{
    assignment();
    cin>>n;
    for(int i=0;i<=n-1;i++)
    {
        cin>>inp[i];
    }
    perm(inp, 0, n-1);
    
    return 0;
}
