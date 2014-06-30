#include<iostream>
#include<cctype>
#include<cstring>

using namespace std;


#include"words.h"


void reverse(const char* string1, char* string2){
  
  char add[2];
  add[1]='\0';
  
  string2[0]='\0';

  for(unsigned int n = strlen(string1); n > 0; n--){
    
    add[0]=string1[n];
    strcat(string2,add);
    add[0]='\0';
  }

  add[0]=*string1;
  strcat(string2,add);
  add[0]='\0';  

  return;
}

/*
bool compare(char* one, char* two){

  char  string1[30], string2[30], letter; 
  string1[0]='\0'; 
  string2[0]='\0';

  int index =0, currentChar=0;  


  while(*(one+currentChar) !='\0'){

    if(isalpha(*(one+currentChar))){
      *(string1+index) = '\0';
      letter = tolower(*(one+currentChar));
      *(string1+index) = letter;
      index++;
      currentChar++;
    }
    else{
      currentChar++; 
    }
  }
 
  index=0;
  currentChar=0;

  while(*(two+currentChar) !='\0'){

    if(isalpha(*(two+currentChar))){
      *(string2+index) = '\0';
      letter = tolower(*(two+currentChar));
      *(string2+index) = letter;
      index++;
      currentChar++;
    }
    else{
      currentChar++;
    }
  }

  return !strcmp(string1,string2);

}
*/

int compare(const char* one, const char* two){;
 
  if(*one=='\0' && *two=='\0'){
    return 1;
  }
 else if(ispunct(*one)&& ispunct(*two)){
    compare(one+1,two+1);
  }
 else if(ispunct(*one)){
    compare(one+1, two); 
  }
 else if(ispunct(*two)){
    compare(one, two+1);  
  }
 else if( tolower(*one) == tolower(*two) ){
    compare(one+1,two+1);   
  }
  else
    return 0; 
}


int palindrome(const char* sentence){

  char temp1[100],temp2[100],add[2];
  add[1]='\0';
  // int p=0;  
  temp2[0]='\0';
  temp1[0]='\0';
  int length=strlen(sentence);

  reduceWord(sentence,length,0,temp1);

  add[0]=sentence[0];
  strcat(temp1,add);

  reduceWord(sentence,0,length,temp2);
  
  int right = compare(temp1,temp2);

  return right; 
}

// HELPER FUNCTION //
void reduceWord( const char* sentence, int lowerlimit, int upperlimit,char* temp){

  char add[2];
  add[1]='\0';
  temp[0]='\0';


  if(lowerlimit < upperlimit){
    for(int s=lowerlimit; s < upperlimit; s++){
      if(isalpha(*(sentence+s)) ){
	add[0]=tolower(*(sentence+s));
	strcat(temp,add);
	add[0]='\0';
      }
    }
    return;
  }
  
  if(lowerlimit > upperlimit){
    for( int s=lowerlimit; s>upperlimit; s--){
      if(isalpha(*(sentence+s)) ){
	add[0]=tolower(*(sentence+s));
	strcat(temp,add);
	add[0]='\0';
      }
    }
    return;
  }
  cout << "here" <<endl;
}


int anagram(const char* string1,const char* string2){
 
  char add[2], temp1[100], temp2[100];
  add[1]='\0';
  temp1[0]='\0';
  temp2[0]='\0'; 

  int length1 = strlen(string1);
  reduceWord(string1 ,0,length1, temp1);
   
  int length2 = strlen(string2);
  reduceWord(string2 ,0,length2, temp2);
  
  int length;
  if(strlen(temp1)<strlen(temp2)){
    length = strlen(temp1);
  }
  else{
    length =strlen(temp2);
  }

  int counter=0;

  for(int s=0; s<length; s++){
    for(int p=0; p < length; p++){
      if(*(temp1+p)== *(temp2+s)){
	*(temp1+p)='\0';
	counter++;
      }    
    }
  }
  
  if(counter == length){
    return 1;
  }
  
  return 0;
}

