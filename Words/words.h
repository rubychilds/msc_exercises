#ifndef WORDS_H
#define WORDS_H

void reverse(const char* string1, char* string2);

int compare(const char* one, const char* two);

int palindrome(const char* sentence);

int anagram(const char* string1, const char* string2);

void reduceWord( const char* sentence, int lowerlimit, int upperlimit,char* temp);


#endif
