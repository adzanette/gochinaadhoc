#include <iostream>
#include <vector>
using namespace std;

vector<int> bitsa(32);

void somabits(int va) {

  int i = 0;
  while (va > 0) {
    int res = va % 2;
    va=va/2;
    if (res) {
      bitsa[i] = 1 - bitsa[i];
    };
    i++;
  };

};

int main() {

  int n;

  cin >> n;

  while (n) {

    for (int i=0;i<32;i++) {
      bitsa[i] = 0;
    };

    for (int i=0;i<n;i++) {
      int val;
      cin >> val;
      somabits(val);
    };

    bool result = false;
    for (int i=0;i<32;i++) {
      if (bitsa[i]) {
	result = true;
	break;
      };
    };

    if (result) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    };

    cin >> n;

  };

  return 0;

};
