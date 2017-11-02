#include <cstdio>
#include <iostream>
#define INF 110
using namespace std;
int d[101][101];
void Floyd(){
	for(int k=1;k<=100;k++)
		for(int i=1;i<=100;++i)
			for(int j=1;j<=100;++j){
				if(d[i][k]<INF&&d[k][j]<INF)
					d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
}
int main(){
	int cas=1;
	int x,y;
	while(scanf("%d%d",&x,&y)==2&&(x!=0||y!=0)){
		for(int i=1;i<=100;++i)
			for(int j=1;j<=100;++j){
				if(i==j)d[i][j]=0;
				else d[i][j]=INF;
			}
		do{
			d[x][y]=1;
		}while(scanf("%d%d",&x,&y)==2&&(x!=0||y!=0));
		Floyd();
		double ans=0;
		int num=0;
		for(int i=1;i<=100;++i)
			for(int j=1;j<=100;++j){
				if(i!=j&&d[i][j]<INF){
					num++;
					ans+=d[i][j];
				}
			}
		printf("Case %d: average length between pages = %.3lf clicks\n",cas++,ans/num);
	}
	return 0;
}
