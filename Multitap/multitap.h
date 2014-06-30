#ifndef MULTITAP_H
#define MULTITAP_H

int encode_character(char letter, char* multitap_ch);
void encode(const char* plaintext, char* multitap);
void decode(std::ifstream &input, std::ofstream &output);
void decode_character(const char* ch, ostream &input, int ucase);

#endif
