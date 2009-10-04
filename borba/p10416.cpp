#include <iostream>
#include <vector>

using namespace std;

long long int distance(int xa, int ya, int xb, int yb) {

  long long int ax = (long long int) xa, ay = (long long int) ya;
  long long int bx = (long long int) xb, by = (long long int) yb;

  return ((ax-bx)*(ax-bx)) + ((ay-by)*(ay-by));

};

bool diveq(int cima1, int baixo1, int cima2, int baixo2) {

  if (baixo2*cima1 == baixo1*cima2) {
    return true;
  } else {
    return false;
  };

};

bool eqsign(int a, int b) {
  if (((a<0) && (b<0)) || ((a>0) && (b>0))) {
    return true;
  };
  return false;
};

bool colinear(int x1,int y1, int x2, int y2, int x3, int y3) {

  if (diveq(x1-x2,y1-y2,x1-x3,y1-y3)) {
    if (eqsign(x1-x2,x1-x3)) {
      return true;
    };
  };

  return false;
};

int main() {

  int n;
  
  cin >> n;
  
  while (n--) {

    int np;

    cin >> np;

    vector<int> xval(np);
    vector<int> yval(np);

    for (int i=0;i<np;i++) {
      int x;
      int y;
      cin >> x >> y;
      xval[i] = x;
      yval[i] = y;
    };

    if (np%2) {
      bool result = true;
      for (int i=0;i<np;i++) {
	result = true;
	int init = (i+1)%np;
	int end = ((i-1) + np)%np;
	for (int k=0;k<(np/2);k++) {
	  int pointc = (init + k)%np;
	  int pointd = (((end - k)%np) + np)%np;
	  if (distance(xval[i],yval[i],xval[pointd],yval[pointd]) != 
	        distance(xval[i],yval[i],xval[pointc],yval[pointc])) {
	    result = false;
	    break;
	  };
	};
	if (!result) {
	  continue;
	};
	for (int j=0;j<(np/2);j++) {
	  int pointa = (init + j)%np;
	  int pointb = (((end - j)%np) + np)%np;
	  for (int k=0;k<(np/2);k++) {
	    int pointc = init + k;
	    int pointd = (((end - k)%np) + np)%np;
	    if (distance(xval[pointa],yval[pointa],xval[pointd],yval[pointd]) != 
		    distance(xval[pointb],yval[pointb],xval[pointc],yval[pointc])) {
	      result = false;
	      break;
	    };
	  };
	  if (!result) {
	    break;
	  };
	};
	if (result) {
	  break;
	};
      };
      if (result) {
	cout << "Yes\n";
      } else {
	cout << "No\n";
      };
    } else {
      bool result = true;
      for (int i=0;i<(np/2);i++) {
	result = true;
	int init = i;
	int end = ((i-1) + np)%np;
	for (int j=0;j<(np/2);j++) {
	  int pointa = init + j;
	  int pointb = (((end - j)%np) + np)%np;
	  for (int k=0;k<(np/2);k++) {
	    int pointc = init + k;
	    int pointd = (((end - k)%np) + np)%np;
	    if (distance(xval[pointa],yval[pointa],xval[pointd],yval[pointd]) != 
		    distance(xval[pointb],yval[pointb],xval[pointc],yval[pointc])) {
	      result = false;
	      break;
	    };
	  };
	  if (!result) {
	    break;
	  };
	};
	if (result) {
	  break;
	};
      };
      if (!(result)) {
	result = true;
	for (int i=0;i<(np/2);i++) {
	  result = true;
	  int init = (i+1)%np;
	  int end = ((i-1) + np)%np;
	  for (int k=0;k<((np-2)/2);k++) {
	    int pointc = init + k;
	    int pointd = (((end - k)%np) + np)%np;
	    if (distance(xval[i],yval[i],xval[pointd],yval[pointd]) != 
	        distance(xval[i],yval[i],xval[pointc],yval[pointc])) {
	      result = false;
	      break;
	    };
	    if (distance(xval[(np/2)+i],yval[(np/2)+i],xval[pointd],yval[pointd]) != 
	        distance(xval[(np/2)+i],yval[(np/2)+i],xval[pointc],yval[pointc])) {
	      result = false;
	      break;
	    };
	  };
	  if (!(result)) {
	    continue;
	  };
	  for (int j=0;j<((np-2)/2);j++) {
	    int pointa = init + j;
	    int pointb = (((end - j)%np) + np)%np;
	    for (int k=0;k<((np-2)/2);k++) {
	      int pointc = init + k;
	      int pointd = (((end - k)%np) + np)%np;
	      if (distance(xval[pointa],yval[pointa],xval[pointd],yval[pointd]) != 
		  distance(xval[pointb],yval[pointb],xval[pointc],yval[pointc])) {
		result = false;
		break;
	      };
	    };
	    if (!result) {
	      break;
	    };
	  };
	  if (result) {
	    break;
	  };
	};
      };
      if (result) {
	cout << "Yes\n";
      } else {
	cout << "No\n";
      };
    };

  };

  return 0;

};
