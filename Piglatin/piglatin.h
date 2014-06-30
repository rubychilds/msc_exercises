#ifndef PIGLATIN_H
#define PIGLATIN_H

int findFirstVowel(const char* string);
bool isVowel(const char ch, int position, int length);

void translateWord(const char* word, char* translated);

void translateStream(std::istream& inputStream,std::ostream& outputStream);
int getWord(char* string);

#endif
