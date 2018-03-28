#include<iostream>
#include<string>
#include<stdio.h>
#include<string.h>
#include<map>
#include<queue>
#include<math.h>
#include<algorithm>
using namespace std;
const int maxn=1e6+100;
int x,lena,lenb,maxa=-1,maxb=-1,cntc,cnta;
double y,a[maxn],b[maxn],c[maxn];
int input(int len,double *arr, int *maxx){
    for(int i=0;i<len;++i){
        scanf("%d%lf",&x,&y);
        arr[x]=y;
        *maxx=max(*maxx,x);
    }

}
void clearzoro(int &cnt,int be,double *arr){
    cnt=0;
    for(int i=be;i>=0;--i){
        if(!fabs(arr[i])<1e-8)
            fabs(arr[i])<0.05?arr[i]=0.0:cnt++;
    }
}
void output(int cnt,int be,double *arr){
    if(cnt==0) puts("0 0 0.0");
    else {
        printf("%d",cnt);
        for(int i=be;i>=0;--i){
            if(!fabs(arr[i])<1e-8) printf(" %d %.1lf",i,arr[i]);
        }
        puts("");
    }
}

int main(){

    scanf("%d",&lena);
    input(lena,a,&maxa);
    scanf("%d",&lenb);
    input(lenb,b,&maxb);
    for(int i=maxa;i>=maxb;--i){
        c[i-maxb]=a[i]/b[maxb];
        for(int j=maxb;j>=0;--j)
            a[j+i-maxb]-=b[j]*c[i-maxb];
    }
    clearzoro(cntc,maxa-maxb,c);
    clearzoro(cnta,maxb,a);
    output(cntc,maxa-maxb,c);
    output(cnta,maxb-1,a);
    return 0;
}
