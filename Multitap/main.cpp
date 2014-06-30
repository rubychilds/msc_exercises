#include<iostream>
#include<fstream>

using namespace std;

#include"multitap.h"

int main(){

  // size id the number returned from encoding the letter //
  int size;
  char multitap[512];

  multitap[0]='\0';

  cout << "Question 1" << endl <<endl;

  size = encode_character('c', multitap);
  cout << "The character 'c' encoded in multitap is '" << multitap << " ' (" << size << " keystrokes)" << endl;

  size = encode_character('5', multitap);
  cout << "The character '5' encoded in multitap is '" << multitap << " ' (" << size << " keystrokes)" << endl;

  size = encode_character('Q', multitap);
  cout << "The character 'Q' encoded in multitap is '" << multitap << " ' (" << size << " keystrokes)" << endl;

  size = encode_character(' ', multitap);
  cout << "The character ' ' encoded in multitap is '" << multitap << " ' (" << size << " keystrokes)" << endl;

  size = encode_character(',', multitap);
  cout << "The character ',' encoded in multitap is '" << multitap << " ' (" << size << " keystrokes)" << endl;

  cout << endl;
  multitap[0] = '\0';

  cout << "Question 2" <<endl;

  encode("imperial", multitap);
  cout << "The string 'imperial' in multitap is: '" << multitap <<  "'. " << endl;

  encode("cab", multitap);
  cout << "The string 'cab' in multitap is: '" << multitap <<  "'. " << endl;

  encode("Meet Anna at 8pm", multitap);
  cout << "The string 'Meet Anna at 8pm' in multitap is: '" << multitap <<  "'. " << endl;




  return 0;



}
