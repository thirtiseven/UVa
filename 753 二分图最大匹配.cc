#include <iostream>
#include <queue> 
#include <vector> 
#include <cstring> 
#include <string>
#include <vector>
#include <map>

#define INF 0x7FFFFFFF 
#define maxn 1010 
#define unsigned int

using namespace std;
struct Edge{ 
	int c,f;
	unsigned v,flip;
	Edge(unsigned v,int c,int f,unsigned flip):v(v),c(c),f(f),flip(flip){} 
};

/*
*b:BFS使用 ，
*a:可改进量 ， 不会出现负数可改进量。
*p[v]:u到v的反向边，即v到u的边。*cur[u]:i开始搜索的位置 ，此位置前所有路已满载。*s:源点。
*t:汇点 。
*/

class Dinic{ 
private:
	bool b[maxn];
	int a[maxn];
	unsigned p[maxn],cur[maxn],d[maxn];
	vector<Edge> G[maxn];
public:
	unsigned s,t;
	void Init(unsigned n){ 
		for(int i=0;i<=n;++i)
			G[i].clear();
	}
	void AddEdge(unsigned u,unsigned v,int c){ 
		G[u].push_back(Edge(v,c,0,G[v].size())); 
		G[v].push_back(Edge(u,0,0,G[u].size()-1)); //使用无向图时将0改为c即可
	}
	bool BFS(){ 
		unsigned u,v;
		queue<unsigned> q; 
		memset(b,0,sizeof(b)); 
		q.push(s);
		d[s]=0;
		b[s]=1; 
		while(!q.empty()){
			u=q.front();
			q.pop();
			for(auto it=G[u].begin();it!=G[u].end();++it) {
				Edge &e=*it; 
				if(!b[e.v]&&e.c>e.f){
					b[e.v]=1; 
					d[e.v]=d[u]+1; 
					q.push(e.v);
				} 
			}
		}
		return b[t]; 
	}
	int DFS(unsigned u,int a){ 
		if(u==t||a==0)
			return a; 
		int flow=0,f;
		for(unsigned &i=cur[u];i<G[u].size();++i){ 
			Edge &e=G[u][i];
			if(d[u]+1==d[e.v]&&(f=DFS(e.v,min(a,e.c-e.f)))>0){ 
				a-=f;
				e.f+=f; 
				G[e.v][e.flip].f-=f; 
				flow+=f;
				if(!a) break;
			} 
		}
		return flow; 
	}
	int MaxFlow(unsigned s,unsigned t){ 
		int flow=0;
		this->s=s; 
		this->t=t; 
		while(BFS()){
			memset(cur,0,sizeof(cur));
			flow+=DFS(s,INF); 
		}
		return flow; 
	}
};


struct Chazuo{
	string name;
}v1[maxn];
struct Dianqi{
	string name, ok;
}v2[maxn];
struct Zhuanhuan{
	string from, to;
}v3[maxn];
Dinic EK;
int n, m, k;
 
void input() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> v1[i].name;
	cin >> m;
	for (int i = 0; i < m; ++i)
		cin >> v2[i].name >> v2[i].ok;
	cin >> k;
	for (int i = 0; i < k; ++i)
		cin >> v3[i].from >> v3[i].to;
}
 
void init() {
	EK.Init(n + m + k + 2);
	for(int i = 0; i < m; ++i)
		EK.AddEdge(0, 1+i, 1);
	for(int i = 0; i < n; ++i)
		EK.AddEdge(m+k+i+1, m+k+n+1, 1);
	for(int i = 0; i < m; ++i)
		for(int j = 0; j < n; ++j)
			if(v2[i].ok == v1[j].name)
				EK.AddEdge(i+1, m+k+j+1, 1);
	for(int i = 0; i < k; ++i) {
		for(int j = 0; j < m; ++j)
			if(v2[j].ok == v3[i].from)
				EK.AddEdge(1+j, m+i+1, INF);
		for (int j = 0; j < n; ++j)
			if(v3[i].to == v1[j].name)
				EK.AddEdge(1+m+i, m+k+1+j, INF);
		for (int j = 0; j < k; ++j)
			if(i != j && v3[i].to == v3[j].from)
				EK.AddEdge(m+1+i, m+1+j, INF);
	}
}

int main(int argc, char *argv[]) {  
	int T;
	std::cin >> T;
	for(int CAS = 0; CAS < T; CAS++) {
		input();
		init();
		if(CAS) {
			std::cout << '\n';
		}
		std::cout << m-EK.MaxFlow(0, m + n + k +1);
	}
	return 0;
}