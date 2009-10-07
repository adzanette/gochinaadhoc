#include <iostream>
#include <list>
#include <vector>

using namespace std;

int dfs(int cur, vector<list<int> > &graph, vector<int> &size, vector<int> &ender, int * end) {

  if (size[cur] != 0) {
    *end = ender[cur];
    return size[cur];
  };

  int total = 0;
  int ending = cur;

  list<int>::iterator adj;
  
  for (adj=graph[cur].begin();adj!=graph[cur].end();adj++) {
    int curend;
    int curtot;
    curtot = dfs(*adj,graph,size,ender,&curend) + 1;
    if (curtot > total) {
      total = curtot;
      ending = curend;
    } else if (curtot == total) {
      if (curend < ending) {
	ending = curend;
      };
    };
  };

  size[cur] = total;
  ender[cur] = ending;

  *end = ending;
  return total;

};

int main () {

  int n;
  int i;
  
  cin >> n;

  i = 0;
  while (n) {

    int ini;
    cin >> ini;

    ini--;
    
    int a,b;
    cin >> a >> b;

    vector<list<int> > graph(n);
    vector<int> size(n,0);
    vector<int> ending(n,0);

    while (a && b) {
      a--;
      b--;

      graph[a].push_back(b);

      cin >> a >> b;
      
    };

    int final=0;
    int total=0;
    total = dfs(ini,graph,size,ending,&final);

    cout << "Case " << ++i << ": The longest path from " << ini+1 << " has length " << total << ", finishing at " << final+1 << ".\n\n";

    cin >> n;

  };

  return 0;

};
