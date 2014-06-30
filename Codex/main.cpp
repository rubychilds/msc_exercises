#include<iostream>
#include<cstring>
#include "codex.h"

using namespace std;

int main(){

  //char surname[MAX_CHAR];
  //char output[5];

  //  cout << "This program will encode your name into soundex." << endl;
  //cout << "Please enter your surname\n";
  //cin >> surname;  

  const char* letter = "a";
  const char* letter2 = "j";
  encode_ch(letter,letter2);
 

  return 0;
}
