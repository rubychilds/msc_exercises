#include<iostream>
#include<cctype>
#include<fstream>
#include<cstring>
#include<iomanip>

using namespace std;

#include"piglatin.h"

// FUNCTION ISVOWEL //
// returns true if ch is a vowel and false otherwise //
bool isVowel(const char ch, int position, int length){

  // if not alpha, return fasle //
  if(!isalpha(ch)){
    return -1;
  }
  // tabel to use as lookup //
  const char* table[]={"a","e","i","o","u", "y"};
  const char* currentChar = *table;

  // loop which compares table with character given and if in table returns true //
  for(int n=0; n < 6; n++){
    // using tolower ensures a capital can be passed in and checked //
    if(*currentChar == tolower(ch)){;
	return true;
      }
    currentChar = *(table+n+1);
  }
  // if not in table returns true //
  return false;
}

// FUNCTION FINDFIRSTVOWEL //
// finds the first vowel and returns an int being the position that vowel is at //
int findFirstVowel(const char* string){
  // if first char is a digit, returns -1 //
  if(isdigit(*string) || ispunct(*string)){
    return -1;
  }
  
  int length = strlen(string);
  int index =0;
  // current looks at first item of string //
  char current = *string; 
  
  // while the current character is not a sentinel character loops //
  while(current != '\0'){
    // points current at a position in string which increments //
    current = *(string+index);
    // if isVowel returns true then we return the position the vowel appears in. This returns the first instance of a vowel //
    if(isVowel(current, index ,length)){
      return index+1;
    } 
    // increments index, so current will poitn to next instance in string //
    index++;  
  }
}

void translateWord(const char* word, char* translated){

  char add[2], temp[2];
  add[1]='\0';
  temp[1]='\0';

  //FLAGS //
  int ucase = 0, yflag = 0,fpunct = 0, lpunct =0;
  // length of WORD //
  int length = strlen(word);
  // CALCULATES POSITION //                         
  int position = findFirstVowel(word);  

// ensures Translate is EMPTY //
  translated[0] = '\0';  

  // if begins or ends with PUNCTUATION flags this //
  if(ispunct(*word)){
    fpunct++;
    add[0]=word[0];
    strcat(translated,add);
    position = findFirstVowel(word+1);
   
    position++;
    if(isupper(*(word+1))){
      ucase++;
    }
 }
  // If begins with UPPERCASE, flags this for translation //
  if(isupper(*word)){
    ucase = 1;
  }
  if(ispunct(*(word+length+1))){
    // IF END OF WORD IS A PUNC, THEN CHANGE MAX AND ADD TO END OF WORD //  
    lpunct++;  
    temp[0]=word[length];
}
 // if word begins with a Y or y//
  if(*word=='Y' || *word == 'y'){
    position = findFirstVowel(word+1);
    // changes Y flag //
    yflag++;
    position++;
 }  
  // if Y is not the first character and the word starts with a vowel //
  if(position == 1 && yflag != 1){
    strcat(translated,word);
    strcat(translated,"way");
    return;
  }
  // if position is negative - DIGIT or NO VOWELS exit in word//
  if(position < 0 && yflag !=1){
    if(isdigit(*word)){
      strcat(translated,word);
      return;
    }
    strcat(translated,word);
    strcat(translated,"ay");
  }

  // ALL OTHER SITUATIONS //
  else {
    for(unsigned int n = position - 1 ; n < length; n++ ){   
      add[0]='\0';
      add[0]= tolower(word[n]);
      strcat(translated,add);  
      }
    
    for( int s = 0+fpunct; s < position-1; s++){    
      add[0]='\0';
      add[0] = tolower(word[s]);
      strcat(translated, add);       
    }
    strcat(translated,"ay"); 
    // if ucase is raised then ensures translated is formatted correctly //
    if(ucase != 0){
      *(translated+fpunct)=toupper(*(translated+fpunct));
    }
    return;
  }
}
  

/*
void translateWord(const char* word, char* translated){

  int fpunct=0,fycase =0, lpunct=0, position, ucase=0;
  char lpunc[1], add[2];
  *translated='\0';
  add[1]='\0';
  
  int length = strlen(word);
  
  // first letter //
  if(isupper(*word)){
    ucase++;
  }
  if(ispunct(*word)){
    fpunct++;
    position = findFirstVowel(word+1);
    add[0] = word[0];
    strcat(translated,add);
    add[0]='\0';
    *word = *(word+1);
  }
  if(ispunct(*(word+length))){
    lpunct++;
    lpunc[1] = *(word+length);
    length--;
  }
  if(*word == 'Y'|| *word == 'y'){
    fycase++;
    position = findFirstVowel(word+1);
    *word = *(word+1);
  }  
  else{
    position = findFirstVowel(word);
  }
  if(position = 1 && fycase != 1){
    strcat(translated, word);
    strcat(translated,"way");
    return;
  }
  
  if(position < 0 || (position = length && word[length]== "y") ){
    strcat(translated, word);
    strcat(translated,"ay");
    return;
  }
  
  for(int n = position-1; n < length; n++){
    add[0]= tolower(word[n]);
    strcat(translated,add);
    add[0]='\0';
  }
  if(fycase==1){
    strcat(translated,"y");
  }
  for(int s = 0; s < position-1; s++){
    add[0] = tolower(word[s]);
    strcat(translated, add);
    add[0]='\0';
  }
  if(lpunct != 0){
    strcat(translated,lpunc);
  }
  
  if(ucase == 1){
    *translated = toupper(*translated);
  }
  return;
}
*/

// TRANSLATES - INCLUDES FORMATTING //
void translateStream(istream &input, ostream &output){
  int index = 0;
  char current[100], translated[128]; // current word and piglatin translation

  // write out any bits that don't form a word
  char ch;
  // read in a character
  input.get(ch);
  while (input && !isalnum(ch)) { // For punction, spaces etc. just outputs it //
    output << ch;
    input.get(ch);
  }
  //  if no input return //
  if (!input)
    return;

  // grab the next word
  current[index++] = ch;      
  input.get(ch);
  while (input && isalnum(ch)) { // whilst it reads characters or numbers //
    current[index++] = ch;      // saves in current which increaments
    input.get(ch);
  }
  current[index++] = '\0'; // adds sentinel character

  // translate it
  translateWord(current, translated); 

  output << translated; // outputs translated

  if (!input)
    return;

  // better put back the (non-alpha) character we just read
  input.putback(ch);
  // as we haven't put back the characters itself, it will continue from the next non-alpha //
  translateStream(input, output);
}

/*
// TRANSLATES STREAM  - DOES NOT INC. FORMATTING //
void translateStream(ifstream& inputStream, ostream& outputStream){
  
  char word[64], translated[70];
  translated[0]='\0';
  word[0]='\0';
  int p=0;

  if(inputStream.eof()){
    return;
  }

  while(!inputStream.eof()){
    // inputStream.unsetf(ios_base::skipws); 
    inputStream>> word;       
      // inputStream >> noskipws >> word;
    translateWord(word,translated);
    outputStream<< translated;
    outputStream<< " ";
    translateStream(inputStream,outputStream);
  }               
}
*/
