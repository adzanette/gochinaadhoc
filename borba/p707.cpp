#include <iostream>
#include <vector>
#include <list>

using namespace std;

struct rect {

  short int l;
  short int t;
  short int r;
  short int b;

};

short int w; 
short int h; 
short int t;
vector<char> state(100);
vector<int> datax(100);
vector<int> datay(100);
vector<char> perc(1000000);
vector<list<struct rect> > rectangles(100);

int calculate(int x, int y, int time) {

  if (time >= t) {
    return 1;
  };
  if (perc[(time*w*h)+(y*w)+x]) {
    return perc[(time*w*h)+(y*w)+x];
  };
  bool proc = false;
  list<struct rect>::iterator iter;
  for (iter = rectangles[time].begin();iter != rectangles[time].end();iter++) {
    if ((x <= iter->r) && (x >= iter->l) && (y <= iter->b) && (y >= iter->t)) {
      proc = true;
      break;
    };
  };
  if (proc) {
    return -1;
  };

  proc = false;
  for (int i=-1;i<=1;i++) {
    for (int j=-1;j<=1;j++) {
      if ((i==0) || (j==0)) {
	int x1 = x+i;
	int y1 = y+j;
	if ((x1 < w) && (x1 >= 0) && (y1 < h) && (y1 >= 0)) {
	  if (calculate(x1,y1,time+1) > 0) {
	    proc = true;
	  };
	};
      };
    };
  };

  if (proc) {
    if (state[time] == 0) {
      state[time] = 1;
      datax[time] = x;
      datay[time] = y;
    } else if (state[time] == 1) {
      state[time] = 2;
    };
    perc[(time*w*h)+(y*w)+x] = 1;
    return 1;
  };
  perc[(time*w*h)+(y*w)+x] = -1;
  return -1;

};

int main() {

  int at;

  cin >> w >> h >> t;

  at = 0;

  while (w || h || t) {

    short int n;

    cin >> n;

    for (int i=0;i<t;i++) {
      rectangles[i].clear();
    };

    for (int i=0; i<n; i++) {
      struct rect a;
      short int time;
      cin >> time;
      time--;
      cin >> a.l >> a.t >> a.r >> a.b;
      a.l--;
      a.t--;
      a.r--;
      a.b--;
      rectangles[time].push_back(a);
    };

    state.assign(t,0);
    perc.assign(t*w*h,0);

    bool proc = true;
    for (int i=0;i<w;i++) {
      for (int j=0;j<h;j++) {
	if (calculate(i,j,0) > 0) {
	  proc = false;
	};
      };
    };

    cout << "Robbery #" << ++at << ":\n";
    
    if (proc) {
      cout << "The robber has escaped.\n";
    } else {

      bool proc2 = true;
      for (int i=0;i<t;i++) {
	if (state[i] == 1) {
	  cout << "Time step " << i+1 << ": The robber has been at " << datax[i]+1 << "," << datay[i]+1 << ".\n";
	  proc2 = false;
	};
      };
      
      if (proc2) {
	cout << "Nothing known.\n";
      };

    };
    
    cout << "\n";

    cin >> w >> h >> t;

  };

  return 0;

};
