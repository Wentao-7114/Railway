#include <iostream>
#include "Dog.h"
using namespace std;


int main() {
      
      Dog mydog(2);
      int a = mydog.getAge();
      cout << a << endl;


      return 0;
}