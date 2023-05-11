#include <iostream>
#include <fstream>

using namespace std;

struct Person
{
  char name[50];
  int age;
  char phone[24];
};

int main()
{
  Person me = {"Robert", 28, "364-2534"};
  Person book[30];
  long int x = 1239999999999;
  double fx = 34.54;
  ofstream outfile;
  outfile.open("junk.dat", ios::binary | ios::out);
  outfile.write((char*)&x, sizeof(int)); // sizeof can take a type
  outfile.write((char*)&fx, sizeof(fx)); // or it can take a variable name
  outfile.write((char*)&me, sizeof(me));
  outfile.write((char*)book, 30*sizeof(Person));
  outfile.close();
}
