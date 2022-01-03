#include <iostream>

#include "AdjMatrix.h"
using namespace std;


int main() {
      AdjMatrix myMatrix(200);
      myMatrix.changeDistance(2, 2, 2002);
      double dis = myMatrix.distanceBetween(2, 2);
      cout << dis;
      


      return 0;
}