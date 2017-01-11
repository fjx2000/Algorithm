/*********************************************************************************************************************************
This file to generate a exhaustive binary string, but it has some problems now, it list all the combination with 2  '1', which is not 
correct, correction need TBD.
*********************************************************************************************************************************/

#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <stdint.h>
#include <cstring>

using namespace std;

class bin_gen
{
public:
  //bin_gen(uint8_t digit_width) : digit_width(digit_width) {};
  static void cal_max_value(uint8_t);
  static void gen_save_bin_seq(uint8_t);
  static void print_bin_seq();
private:
  static uint8_t digit_width;
  static uint32_t max_value;
  static vector<string> bin_str;
};

uint8_t bin_gen::digit_width =  0;
uint32_t bin_gen::max_value = 0;
vector<string> bin_gen::bin_str;

int main()
{

  cout<<"please input the width of the binary sequence :" <<endl;
  int digit_width;
  cin>>digit_width;
  while(digit_width<1 || digit_width>10)
  {
    cout<<"the width is out of range, please re-enter :"<<endl;
    cin>>digit_width;
  }
  bin_gen::cal_max_value(digit_width);
  bin_gen::gen_save_bin_seq(digit_width);
  bin_gen::print_bin_seq();

}

void bin_gen::cal_max_value(uint8_t width)
{

  max_value = width > 1 ? pow(2, width-1) + pow(2, width -2) : 1;

}

void bin_gen::gen_save_bin_seq(uint8_t width)
{
  char bin[width];
  for(int i=0; i < width; i++)
  {
    for(int j=0; j < width && j!= i; j++)
    {
      memset(bin, '0', sizeof(bin));
      bin[i] = '1';
      bin[j] = '1';
      bin_str.push_back(string(bin));
    }
  }
}

void bin_gen::print_bin_seq()
{
  for(auto bin : bin_str)
  {
    cout<<bin.c_str()<<endl;
  }
}


/***********************************************************************************************************************************
Test Result:
esekilxxen2768: ~/test_c/algorithm  > g++ -std=c++11 generate_bin_seq.cc
esekilxxen2768: ~/test_c/algorithm  > ./a.out
please input the width of the binary sequence :
6
110000@
101000@
011000@
100100@
010100@
001100@
100010@
010010@
001010@
000110@
100001@
010001@
001001@
000101@
000011@

***********************************************************************************************************************************/
