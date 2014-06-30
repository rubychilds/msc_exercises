#include<iostream>
#include<cctype>
#include<cstring>

using namespace std;

#include"string.h"

bool is_prefix(const char* string1, const char* string2, int position){

  if(string1[position] == '\0' )
    return true;
  else if(string1[position] == string2[position]){
    return 
      is_prefix(string1, string2, position + 1);
  }
  else 
    return false;
}

int substring_position(const char* string1, const char* string2){

  // ensures that something has been passed through //
  if(strlen(string1)== 0 && strlen(string2)==0){
    return 0;
  }

  else { // now goes through wwhole sentence as passed in by string2 //
    for(unsigned int s = 0; s < strlen(string2); s++){
      // check if it is true. Pass into is_prefix the thing we want. We check each position of string2 against initial character of 1. We always start this at ZERO // 
      if(is_prefix(string1,string2+s, 0)){
	return s;
      }
    }
  }
  return -1;
}


