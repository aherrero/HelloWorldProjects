// derived classes
#include <iostream>
using namespace std;

class Polygon {
  protected:
    int width, height;
    
    
  public:
    Polygon();
    static int staticVarInst;
    void set_values (int a, int b){ width=a; height=b;}
    

 };

int Polygon::staticVarInst = 1;

Polygon::Polygon()
{
  width = 0;height = 0;
}

class Rectangle: public Polygon {

  public:
    int area () { return width * height; }

 };

class Triangle: public Polygon {

  public:
    int area (){ return width * height / 2; }

  };


  
int main () {
  Rectangle rect;
  Triangle trgl;
  rect.set_values (4,5);


  trgl.staticVarInst = 2;
  //trgl.set_values (2,3);

  cout << rect.area() << '\n';
  cout << trgl.area() << '\n';

  cout<<rect.staticVarInst<<endl;



  return 0;
}
