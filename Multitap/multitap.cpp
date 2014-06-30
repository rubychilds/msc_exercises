#include<iostream>
#include<cctype>
#include<cstring>
#include<fstream>

#include "multitap.h"


int encode_character(char ch, char* multitap){

  if(isdigit(ch)){
    multitap[0]='*';
    multitap[1]=ch;
    multitap[2]='\0';

    return 2;
  }

  const char *table[]={" ",".,!?","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

  // make ch lower case to allow comparision to table //
  char target = tolower(ch);

  char add[2];
  // add a sentinel character at the end //
  add[1]='\0';

  for(int n=0; n <10; n++){
    // allows to be empty //
    strcpy(multitap, "");
    for(int s=0; table[n][s]; s++){
      add[0]= '0' + n;
      strcat(multitap, add);      
// if we find the correct character, return the column it is found in //
      if(target == table[n][s]){
	return (s+1);
      }
    }
  }
  strcpy(multitap,"_");
  return 1;
}


void encode(const char *plaintext, char *multitap){

  // flag for uppercase  - 1 if upper//
  int upper_case=0;
  char temp[40];
  int output = 0;

  for(unsigned int i =0; i < strlen(plaintext); i++){

    // checks if character is upper and what case is set to, if they are different will print out a # to indicate change //
    if((isupper(plaintext[i])&& !upper_case) || (islower(plaintext[i])&& upper_case)){
      multitap[output++]='#';
      // changes flag for case //
      upper_case != upper_case;
    }

    int size = encode_character(plaintext[i], temp);

    // PAUSE //
    if(output && multitap[output-1] == temp[0])
      //if current multitap -1 is same as temp, then add a pause //
      multitap[output++]='|';
    // at end adds a sentinel character //
    multitap[output]='\0';
    // copies temp word to multitap string using strcat //
    strcat(multitap, temp); 
    // increases total output by the size used in encode //
    output += size;
  }
}

ostream decode(ifstream &input, ostream &output){



  return;
}

void decode_character(const char* ch, ostream &input, int ucase){

  if(!ch[0])
    return;

  if(ch[0]=='*'){
    input << ch[1];
    return;
  }

  








}




/* int encode_character(char ch,char* multitap){

  const char *table[] = {" ", ".,! ?", "abc", "def","ghi","jkl","mno", "pqrs","tuv","wxyz" };


  // identifies if it is a digit and if so, allows the first to be a * then the digit itself, then adds sentinel character //
  if(isdigit(ch)){
    multitap[0]= '*';
    multitap[1]= ch;
    multitap[2]= '\0';
    // must have a return to exit. Returns 2 as we have pressed * and the digit //
    return 2;
  }

  // creates new array with size 2'
  char add[2];

  // allows second entry to be a sentinel character //
  add[1]='\0';

  // ensures ch is in lower case //
  char target = tolower(ch);

  // goes through each 10 phone digits  which are in rows //
  for(int n=0; n < 10 ; n++){
   // copies the first one to be empty //
   strcpy(multitap, "");
    
   // now for add[0] makes it be the number it goes along by, i.e. the digit which will be pressed //
    for(int s = 0; table[n][s]; s++){
      // finds appropriate row //
      add[0] = '0'+ n;
      // adds the contents of add to the remaining of multitap - UPDATES//
      strcat(multitap,add);
      // if finds the target, then returns its column, i.e. if it is at 1,2,3,4 hence so we know how many times to repeat it //
      if(target == table[n][s]){
	// returns the columns, adding 1 as we begin at 0, for the number of times we press that digit //
	return (s+1); 
      }
    }
  }
  return 1;
}
