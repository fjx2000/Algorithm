/**********************************************************************************************************************************
This file is used to calculate the shortest path between two points, in this case the two points is heathrow and london.


**********************************************************************************************************************************/

#include <iostream>
#include <memory>
#include <cstdint>

/*  if use <cstdint>, then complile has to use option -std=c++0x or -std=gun++0x.
    if use "stdint.h" or "inttypes.h",which is part of C standand header files, no need to add extra compile ioptions

/usr/include/c++/4.3/c++0x_warning.h:36:2: error: #error This file requires compiler and library support for the upcoming ISO C++ standard, C++0x. This support is currently experimental, and must be enabled with the -std=c++0x or -std=gnu++0x compiler options.

*/

using namespace std;

typedef struct path
{
  uint16_t left;
  uint16_t right;
  uint16_t x;
} Path;

void shortestPath(Path*, uint16_t&, uint16_t&);

int main()
{
  //Path pathFromHeathrow[4] = {{50,10,30},{5,90,20},{40,2,25},{10,8,0}};  // shortest path is 75

  Path pathFromHeathrow[4] = {{10,20,5},{25,30,70},{15,75,25},{15,100,0}};
  uint16_t shortLeft =0, shortRight = 0;

  shortestPath(pathFromHeathrow, shortLeft, shortRight);

  cout<<"shortest left is : "<<shortLeft<<endl;

  cout<<"shortest right is: "<<shortRight<<endl;

  return 1;
}

void shortestPath(Path* path, uint16_t& accLeft, uint16_t& accRight)
{
  if(accLeft + path->left <= accRight + path->right + path->x)
  {
    accLeft = accLeft + path->left;
    cout<<"If accLeft is : "<<accLeft<<endl;
  }
  else
  {
    accLeft = accRight + path->right + path->x;
    cout<<"Else accLeft is : "<<accLeft<<endl;
  }


  /* accLeft already updated in previous code, so, here no like code above, no need to add path->left */
  if(accRight + path->right <= accLeft + path->x)
  {
    accRight = accRight + path->right;
    cout<<"If accRight is : "<<accRight<<endl;
  }
  else
  {
    accRight = accLeft + path->x;
    cout<<"Else accRight is : "<<accRight<<endl;
  }

  if(path->x > 0)
  {
    shortestPath(++path, accLeft, accRight);
  }
}





/************************************************************************************************************************************

esekilxxen2768: ~/test_c/algorithm  > g++ -std=c++11 heathrow_to_london.cc 
esekilxxen2768: ~/test_c/algorithm  > ./a.out
If accLeft is : 10
Else accRight is : 15
If accLeft is : 35
If accRight is : 45
If accLeft is : 50
Else accRight is : 75
If accLeft is : 65
Else accRight is : 65
shortest left is : 65
shortest right is: 65
esekilxxen2768: ~/test_c/algorithm  > 

*************************************************************************************************************************************/
