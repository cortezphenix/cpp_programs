//Shape Shifter, Cortez Phenix- Program to Print Shapes, With the Use of Multiple Variables

#include <iostream>
#include <string>
using namespace std;

int main ()
{
  string strLine;
  strLine = "   *\n   *\n";
  string strTriangle;
  strTriangle = "*******\n *   * \n  * * \n   *   ";
  string strRectangle;
  strRectangle = "\n*******\n*     *\n*     *\n*******";

  cout << "Line:\n";
  cout << strLine;
  cout << "Triangle:\n";
  cout << strTriangle;
  cout << "\nRectangle:";
  cout <<strRectangle;
  cout << "\nFunnel:\n";
  cout <<strTriangle;
  cout <<"\n";
  cout <<strLine;
  cout << "Popsicle:";
  cout <<strRectangle;
  cout << "\n";
  cout <<strLine;
  cout << "Down Arrow:\n";
  cout <<strLine;
  cout <<strTriangle;
  return 0;
}
