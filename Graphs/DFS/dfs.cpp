#include <vector>
#include <list>
#include <iostream>
#define WHITE 0
#define GRAY 1
#define BLACK 2

using namespace std;
int tempo;
void print_adj(std::vector<std::list<int> > adj){
	std::list<int>::iterator it;
	int size = adj.size();
	for(int i = 0; i< size; i++){
		cout << i << ": ";
		for(it = adj[i].begin(); it != adj[i].end() ; it++){
			cout << *it << " ";
		}
		cout << "\n";
	}
}

void dfs_visit(int node, int v, std::vector<std::list<int> > adj, std::vector<int> &color, std::vector<int> &pred, 
		std::vector<int> &d, std::vector<int> &f){

	std::list<int>::iterator it;	
	color[node] = GRAY;
	tempo ++;
	d[node] = tempo;
	for(it = adj[node].begin(); it != adj[node].end() ; it++)
	{
		if(color[*it] == WHITE)
		{
			pred[*it] = node;
			dfs_visit(*it, v, adj, color, pred, d, f);
		}
	}
	color[node] = BLACK;
	tempo++;
	f[node] = tempo;
}

void dfs(int v, std::vector<std::list<int> > adj, std::vector<int> &color, std::vector<int> &pred, 
		std::vector<int> &d, std::vector<int> &f){
	
	for(int i = 0 ; i < v; i++)
	{
		color[i] = WHITE;
		pred[i] = -1;
	}
	tempo = 0;
	
	for(int i = 0 ; i < v; i++)
	{
		if(color[i] == WHITE)
			dfs_visit(i,v, adj, color, pred, d,f);
	}
}

int main(){
	int v, e;
	cin >> v >> e;
	
	std::vector<std::list<int> > adj;
	adj.resize(v);
	int o,dest;
	for(int i = 0; i < e; i++){
		cin >> o >> dest;
		adj[o].push_back(dest);
	}
	
	std::vector<int> color,pred,d,f;
	color.resize(v);
	pred.resize(v);
	d.resize(v);
	f.resize(v);
	dfs(v, adj, color, pred, d,f);
	for(int i = 0; i < v; i++){
		cout << i << ": " << d[i] << " " << f[i] << "\n";
	}	
	return 0;
		
}
