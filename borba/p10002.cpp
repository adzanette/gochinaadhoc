#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

struct ponto {
  long long int x;
  long long int y;
};

bool por_x(struct ponto a, struct ponto b) {
  
  if (a.x != b.x) {
    return a.x < b.x;
  } else {
    return a.y < b.y;
  };

};

long long int area(long long int x0, long long int x1, long long int x2, long long int y0, long long int y1, long long int y2) {

  return x0*y1 + x1*y2 + x2*y0 - x1*y0 - x2*y1 - x0*y2;

};

void ccw(list<struct ponto> & pontosConvexos, struct ponto & val) {

  list<struct ponto>::reverse_iterator vas;

  while (pontosConvexos.size() >= 2) {
    long long int x1;
    long long int x2;
    long long int y1;
    long long int y2;
    vas = pontosConvexos.rbegin();
    x1 = vas->x;
    y1 = vas->y;
    vas++;
    x2 = vas->x;
    y2 = vas->y;
    if (area(x1,x2,val.x,y1,y2,val.y) <= 0) {
      pontosConvexos.pop_back();
    } else {
      break;
    };
  };

  pontosConvexos.push_back(val);

};

void convexHull(vector<struct ponto> & pontos,list<struct ponto> & pontosConvexosSai) {

  list<struct ponto> pontosConvexos;

  vector<struct ponto>::iterator vas;

  vas = pontos.begin();
  pontosConvexos.push_back(*vas);
  vas++;
  pontosConvexos.push_back(*vas);

  for (vas++;vas!=pontos.end();vas++) {
    ccw(pontosConvexos,*vas);
  };

  list<struct ponto> pontosConvexos2;

  vector<struct ponto>::reverse_iterator vas_tras;

  vas_tras = pontos.rbegin();
  pontosConvexos2.push_back(*vas_tras);
  vas_tras++;
  pontosConvexos2.push_back(*vas_tras);

  for (vas_tras++;vas_tras!=pontos.rend();vas_tras++) {
    ccw(pontosConvexos2,*vas_tras);
  };

  pontosConvexos2.pop_front();
  pontosConvexos2.pop_back();
  
  pontosConvexosSai.splice(pontosConvexosSai.end(),pontosConvexos);
  pontosConvexosSai.splice(pontosConvexosSai.end(),pontosConvexos2);  

};

void getCentroid(list<struct ponto> & pontosConvexos, double & centroidX, double & centroidY) {

  list<struct ponto>::iterator vas,vas_next;
  long long int cimax=0;
  long long int cimay=0;
  long long int baixo=0;

  int size = pontosConvexos.size();
  int i = 0;
  vas_next = pontosConvexos.begin();
  vas_next++;
  for (vas=pontosConvexos.begin();vas!=pontosConvexos.end();vas++) {
    long long int xi = vas->x;
    long long int yi = vas->y;
    long long int xim;
    long long int yim;
    if (vas_next!=pontosConvexos.end()) {
      xim = (vas_next)->x;
      yim = (vas_next)->y;
    } else {
      xim = (pontosConvexos.begin())->x;
      yim = (pontosConvexos.begin())->y;
    };
    long long int a1;
    a1 = xi*yim - xim*yi;
    cimax += a1*(xi+xim);
    cimay += a1*(yi+yim);
    baixo += a1;
    i++;
    vas_next++;
  };

  baixo *= 3;
  centroidX = ((double) cimax) / ((double) baixo);
  centroidY = ((double) cimay) / ((double) baixo);

};

int main() {

  int n;
  cin >> n;
  while (n >= 3) {

    vector<struct ponto> pontos(n);

    for (int i=0;i<n;i++) {
      cin >> pontos[i].x >> pontos[i].y;
    };
     
    sort(pontos.begin(),pontos.end(),por_x);
    
    list<struct ponto> pontosConvexos;
    convexHull(pontos,pontosConvexos);

    double centroidX;
    double centroidY;
    getCentroid(pontosConvexos,centroidX,centroidY);

    if ((centroidX < 0.001) && (centroidX > -0.001)) {
      centroidX = 0.0001;
    };
    if ((centroidY < 0.001) && (centroidY > -0.001)) {
      centroidY = 0.0001;
    };
    
    cout << setprecision (3) << fixed << centroidX << " " << centroidY << endl;

    cin >> n;
  };

  return 0;

};
