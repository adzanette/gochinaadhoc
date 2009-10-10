#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

bool greaterRadius(double x1, double y1, double x2, double y2, double r) {

  double a = x1-x2;
  double b = y1-y2;
  if ((a*a + b*b) > (r*r)) {
    return true;
  } else {
    return false;
  };

};

double distance(int x1, int y1, int x2, int y2) {
  
  return (double) (((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2)));

};

bool getCenterCoordinates(int x1, int y1, int x2, int y2, double * x0, double * y0, double r) {

  double a = r*r;
  int distx = x2-x1;
  int disty = y2-y1;
  int disttot = distx*distx + disty*disty;
  double val = a - (((double) disttot)/4.0);
  //  cout << val << endl;
  double vals = sqrt(val);
  int diffy = y1-y2;
  int diffx = x2-x1;
  //cout << disttot << endl;
  double dist = sqrt((double) disttot);
  double valx = vals * diffy / dist;
  double valy = vals * diffx / dist;
  double x3 = ((double) (x1+x2)) / 2.0;
  double y3 = ((double) (y1+y2)) / 2.0;
  *x0 = valx + x3;
  *y0 = valy + y3;

  if (dist > r*2) {
    return false;
  } else {
    return true;
  };

};

int main() {

  int n;
  double r;

  cin >> n;

  while (n) {

    vector<int> x(n);
    vector<int> y(n);
    
    for (int i=0;i<n;i++) {
      cin >> x[i] >> y[i];
    };
    
    cin >> r;
    bool end = false;
    if (n > 1) {
    for (int i=0;i<n;i++) {
      for (int j=0;j<n;j++) {
	if (i != j) {

	    double x0,y0;
	    if (getCenterCoordinates(x[i],y[i],x[j],y[j],&x0,&y0,r)) {
	      //	      cout << i << " " <<  j << ":" << x0 << " " << y0 << endl;
	      // cout << x[i] << " " << y[i] << " " << x[j] << " " << y[j] << " " << x0 << " " << y0 << endl;
	      bool result = true;
	      for (int k=0;k<n;k++) {
		if ((k != j) && (k != i)) {
		  if (greaterRadius((double) x[k],(double) y[k],x0,y0,r)) {
		    result = false;
		    break;
		  };
		};
	      };
	      if (result) {
		end = true;
	      };
	    };
	    
	};
      };
      if (end) {
	break;
      };
    };

    } else {
      end = true;
    };

    if (end) {
      cout << "The polygon can be packed in the circle.\n";
    } else {
      cout << "There is no way of packing that polygon.\n";
    };

    cin >> n;

  };

  return 0;

};
