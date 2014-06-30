#ifndef BRAILLE_H
#define BRAILLE_H


int encode_character(char ch, char* braille);
void encode(const char* plaintext, char* braille);
void print_braille(const char* plaintext, std::ostream& output);

#endif
