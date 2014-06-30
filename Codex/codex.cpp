#include<iostream>
#include<cctype>
#include<cstring>
#include"codex.h"

using namespace std;

/* void encode(surname, soundex){

  char first_ch = surname[0];
  soundex[0]= toupper(first_ch);

  for(i=1; i < strlen(surname); i++){

    char temp[i] = tolower(surname[i]);
    bool same = comparision(temp[i], temp[i-1]);
    if(same == false){
      encode_ch(temp[i], &soundex[.....])
    }
    else ;
  }

}
*/

// Helper function to compare characters //
/* bool comparision(char* first_ch, char* ch_before){
  cout << "The letter: " << first_ch;

  if(first_ch == ch_before){
    cout << " is the same "; 
    return true;
  }
  else {
    cout << " is different ";
   return false;
  }

  cout << "as the letter before: " << ch_before << "." << endl;
}
*/


// Helper function to encode individual characters/
void encode_ch(char letter, char &encoded){

   cout << " testing ";
}
