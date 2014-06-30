#include <iostream>
#include <cctype>
#include <fstream>
#include "piglatin.h"

using namespace std;

int main() {
 
  cout << " Is 'a' a vowel? " << isVowel('a',0,0) <<endl;
  cout << " Is 'O' a vowel? " << isVowel('O',0,0) <<endl;
  cout << " Is 'r' a vowel? " << isVowel('r',0,0) <<endl;



  /* QUESTION 1  */

  cout << "====================== Question 1 ======================" << endl;

  int vowel;

  vowel = findFirstVowel("Passionfruit");
  cout << "The first vowel in 'Passionfruit' occurs at position " << vowel << endl <<endl;

  vowel = findFirstVowel("prune");
  cout << "The first vowel in 'prune' occurs at position " << vowel << endl <<endl;

  vowel = findFirstVowel("my");
  cout << "The first vowel in 'my' occurs at position " << vowel << endl <<endl;

  vowel = findFirstVowel("chrysanthemum");
  cout << "The first vowel in 'chrysanthemum' occurs at position " << vowel << endl <<endl;
  cout << endl;
  
  /* QUESTION 2 */ 

  cout << "====================== Question 2 ======================" << endl;

  char translated[100];

  translateWord("grape", translated);
  cout << "In Pig Latin 'grape' is '" << translated << "'." << endl <<endl;
  translateWord("orange", translated);
  cout << "In Pig Latin 'orange' is '" << translated << "'." << endl <<endl;
  translateWord("Banana", translated);
  cout << "In Pig Latin 'Banana' is '" << translated << "'." << endl<< endl;
  translateWord("Yellow", translated);
  cout << "In Pig Latin 'Yellow' is '" << translated << "'." << endl <<endl;
  cout << endl;

  /* QUESTION 3 */

  cout << "====================== Question 3 ======================" << endl;

  cout << "The file 'fruit.txt' translated into Pig Latin is:" << endl << endl;
  ifstream input;
  input.open("fruit.txt");
  translateStream(input, cout);
  input.close();
  cout << endl;

  return 0;
}
