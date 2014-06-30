#include<iostream>
#include<cctype>
#include<cstring>
#include<fstream>
#include<cstdlib>
#include"braille.h"

using namespace std;

int encode_character(char ch, char* braille){
  
  braille[0]='\0';
  int lookup_val =0;

  char add[2];
  add[1]='\0';

  const char* table[] = {"0.....", "00....", "0..0..", "0..00.", "0...0.", "00.0..", "00.00.", "00..0.", ".0.0..", ".0.00.", "0.0...", "000...","0.00..","0.000.", "0.0.0.","0000..","00000.","000.0.",".000..", "0.000.",".0000.","0.0..0","000..0",".0.000","0.00.0","0.0000","0.0.00"};

  const char* punc_table[] = {"0..00.","0.....", "00....",".0..0.","00.0..","00..0.","00.00." };
 
  if(ispunct(ch)){

    int n;                                                                                                        

    switch(ch){
    case '.': n = 0;
      break;
    case ',': n = 1;
      break;
    case ';': n = 2;
      break;
    case '-': n = 3;
      break;
    case '!': n = 4;
      break;
    case '?': n = 5;
      break;
    case '(':
    case ')': n = 6;
      break;
    default:
      break;
    }
  
    for(int s = 0; punc_table[n][s]; s++){
      add[0] = punc_table[n][s];
      strcat(braille, add);
    } 
  
    return strlen(braille);
  }
    
  else if(isdigit(ch)){                                                                                               
    char* digit = "..0000";                                                                                        
    strcat(braille,digit);

     lookup_val = ch - 48 -1;     
    
    for(int s = 0; table[lookup_val][s]; s++){
      add[0] = table[lookup_val][s];
      strcat(braille,add); 
    }
    return strlen(braille);
  }    

  else if(isalpha(ch)){
    int length;    

    char temp[10], temp2[10];
    temp2[0]= '\0';
    temp[0] = '\0';

    if(isupper(ch)){
      char* upper = "....0.";
      strcat(temp, upper);
      length = strlen(temp);
      ch = tolower(ch);
    }
    else if(islower(ch)){
      length = 0;
    }

    lookup_val = ch - 'a';
    for(int s = 0; table[lookup_val][s]; s++){
      add[0] = table[lookup_val][s];
      strcat(temp2,add);
    }  
    strcat(braille, temp);
    strcat(braille,temp2);
    return strlen(temp2)+length;
  }

  strcpy(braille,"");
   
 return strlen(braille);
}

/* MUCH SHORTER WAY */
void encode(const char* plaintext, char* braille){

  if(*plaintext == '\0'){
    *braille = '\0';
    return;
  }

  int offset = encode_character(*plaintext, braille);
  encode(plaintext+1,braille+offset);
}

/*
void encode(char* braille){
  
  char plaintext2[20], add[2];
  add[1] ='\0'; 
  plaintext2[0]='\0';
  
  char letter = plaintext[0];

  if(*plaintext=='\0'){
    *braille = '\0';
    return; 
  }  
    
  int size = encode_character(letter,braille); 
    
    for(unsigned int s = 1; s < strlen(plaintext); s++){
      add[0]='0';     
      add[0] = plaintext[s];
      strcat(plaintext2, add);
    }
     encode(plaintext2, braille+size);
}
*/

void print_braille(const char* plaintext, ostream& output){

  char temp[512];

  encode(plaintext, temp);
 
  // print top row
  for(unsigned int c=0; c < strlen(temp); c += 3){
    output << temp[c];
  }
  cout << endl;

  // print second row
  for(unsigned int c=1; c < strlen(temp); c += 3){
    output << temp[c];
  }
  cout << endl;

  // print third row
  for(unsigned int c=2; c < strlen(temp); c += 3){
    output << temp[c];
  }
  cout << endl;

  // print text underneath 
  for(unsigned int c=0; c < strlen(plaintext); c++){

    if(isupper(plaintext[c]) || isdigit(plaintext[c])){
      output << "   "; // if upper case or a digit, place 2 spaces
      output << plaintext[c];
    }
    else{
      output << " ";
      output << plaintext[c];
    }
  }
  cout << endl;
}
  


/*
void print_braille(const char* plaintext, ostream& output){

  char braille[512];
  braille[0]='\0';
  char currentChar = *plaintext;
  int index = 0;
  int charIndex = 0;
  encode(plaintext, braille);

  
  int counter = 0;
  char temp[14];
  temp[0]='\0';
 
  for(int n=0; n < 3; n++){
    
    while(currentChar != '\0'){
      output << braille[index+n];
      output << braille[index + n + 3];
      output << " ";
      currentChar = *(plaintext + charIndex);
      charIndex++;
      index += 6;
    }
    output << endl;
    currentChar = *plaintext; // dereferece of plaintext gives first character 
    index = 0;
    charIndex = 0;
  }
  while(currentChar != '\0'){
    if(isupper(currentChar) || isdigit(currentChar)){
      output<< "   ";
    }
    output << currentChar;
    output << "  ";
    charIndex++;
    currentChar = *(plaintext + charIndex);
  }
}


/*
void print_braille(const char* plaintext, ostream& output){

  int n = 0;
  char braille[512];
  char currentChar = *plaintext;
  int charIndex = 0;
  char index = 0;
  encode(plaintext,braille);

  while(currentChar !='\0'){
    
    if(isupper(currentChar) || isdigit(currentChar)){
      output<< "   ";
      output<< currentChar;
    }      
    else {

      for(int n=0; n < 3; n++){
	output<< braille[index+n] << braille[index+n+3];
	output<< "  "; 
      }
      index += 6;
      n++;   
    } 
    
    currentChar = *(plaintext+charIndex);
  }
  output<< endl;
  index =0;
  charIndex =0;
} */
