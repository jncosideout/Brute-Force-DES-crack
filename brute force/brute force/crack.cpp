
#include <stdio.h>
#include "DES.h"
#include <iostream>
#include<fstream>
using namespace std;
//typedef int bool;
#define true 1
#define false 0


//Loading data from a text file
//data[]: an array to read the data into
//length: length of data you want to read from the file 
//For simplicity, the ciphertext file contains ONLY 32 characters
void loadFile(unsigned char data[], int length)
{
 FILE* file = fopen("CipherFile1.txt", "r");
 if (file)
 {
  int i;
  for (i = 0; i < length; i++)
   data[i] = fgetc(file);
  fclose(file);
 }
 else
 {
  printf("Cannot open the file\n");
  exit(1);
 }
}
void printText(unsigned char hash[], int length, uchar key[])
{
 int i;
 for (i = 0; i < length; i++)
 printf("%c", hash[i]);
 printf("\n");
}
void keyI(long long, uchar[]);
int main()
{
     uchar key[8],        //You need to get that key using brute force attack                             
  plainTextBlock[8],
  cipherTextBlock[8],
  schedule[16][6];
     uint state[2];

 //Start your work.................
 int l = 8;
 ofstream results, results1, results2, results3, results4;
 results.open("decrypted text.txt");
 results1.open("decrypted text1.txt");
 results2.open("decrypted text2.txt");
 results3.open("decrypted text3.txt");
 results4.open("decrypted text4.txt");


 for (int k = 0; k<8; k++)
  key[k] = 0;

 long long Counter;
 Counter = 1000;// 281474976710656; //initialized to the X byte of keys


 loadFile(cipherTextBlock, l);
 // printText(cipherTextBlock, l);


 results << "piece 3 of cipher, byte 2 1st 5000" << endl;
  do
  {
   
    keyI(Counter, key);
    key_schedule(key, schedule, DECRYPT);
    des_crypt(cipherTextBlock, plainTextBlock, schedule);
	
    results << Counter << endl;
    for (int i = 0; i < l; i++)
      results << plainTextBlock[i];

	results << endl<< endl;
	for (int i = 0; i < l; i++)
	{if (plainTextBlock[i] == 'e'|| plainTextBlock[i] == 't'|| plainTextBlock[i] == 'a'|| plainTextBlock[i] == 'o'|| plainTextBlock[i] == 'i'|| plainTextBlock[i] == 'n')
		results << "found etaoin \n\n";
	}
    Counter++;
   } while (Counter < 5256); //  all possible keys in byte 2 between start and +5000

  Counter = 5256;

  results1 << "piece 3 of cipher, byte 2 2nd 5000" << endl;
  do
  {
   
    keyI(Counter, key);
    key_schedule(key, schedule, DECRYPT);
    des_crypt(cipherTextBlock, plainTextBlock, schedule);
	
    results1 << Counter << endl;
    for (int i = 0; i < l; i++)
      results1 << plainTextBlock[i];
    results1 << endl<< endl;
	for (int i = 0; i < l; i++)
	{if (plainTextBlock[i] == 'e'|| plainTextBlock[i] == 't'|| plainTextBlock[i] == 'a'|| plainTextBlock[i] == 'o'|| plainTextBlock[i] == 'i'|| plainTextBlock[i] == 'n')
	results1 << "found etaoin \n\n";}
	
    Counter++;
   } while (Counter < 10256); //  all possible keys in byte 2 between 5256  and +5000

  Counter = 10256;

	  	results2 << "piece 3 of cipher, byte 2 4th 5000" << endl;
  do
  {
   
    keyI(Counter, key);
    key_schedule(key, schedule, DECRYPT);
    des_crypt(cipherTextBlock, plainTextBlock, schedule);

    results2 << Counter << endl;
    for (int i = 0; i < l; i++)
      results2 << plainTextBlock[i];

    results2 << endl<< endl;
	for (int i = 0; i < l; i++)
	{if (plainTextBlock[i] == 'e'|| plainTextBlock[i] == 't'|| plainTextBlock[i] == 'a'|| plainTextBlock[i] == 'o'|| plainTextBlock[i] == 'i'|| plainTextBlock[i] == 'n')
	results2 << "found etaoin \n\n";}
		
    Counter++;
   } while (Counter < 15256); // all possible keys in byte 2 between 10256 and +5000

  Counter = 15256;

	  results3 << "piece 3 of cipher, byte 2 5th 5000" << endl;
  do
  {
   
    keyI(Counter, key);
    key_schedule(key, schedule, DECRYPT);
    des_crypt(cipherTextBlock, plainTextBlock, schedule);
	
    results3 << Counter << endl;
    for (int i = 0; i < l; i++)
      results3 << plainTextBlock[i];
	
    results3 << endl<< endl;
	
	for (int i = 0; i < l; i++)
		{if (plainTextBlock[i] == 'e'|| plainTextBlock[i] == 't'|| plainTextBlock[i] == 'a'|| plainTextBlock[i] == 'o'|| plainTextBlock[i] == 'i'|| plainTextBlock[i] == 'n')
		results3 << "found etaoin \n\n";}
		
    Counter++;
   } while (Counter < 20256); // all possible keys in byte 2 between 15256 and +5000


  Counter = 72057594037932935;
 results4 << "piece 3 of cipher, byte 8 2nd 5000" << endl;
  do
  {
   
    keyI(Counter, key);
    key_schedule(key, schedule, DECRYPT);
    des_crypt(cipherTextBlock, plainTextBlock, schedule);
	
    results4 << Counter << endl;
    for (int i = 0; i < l; i++)
      results4 << plainTextBlock[i];

    results4 << endl<< endl;
	for (int i = 0; i < l; i++)
	{if (plainTextBlock[i] == 'e'|| plainTextBlock[i] == 't'|| plainTextBlock[i] == 'a'|| plainTextBlock[i] == 'o'|| plainTextBlock[i] == 'i'|| plainTextBlock[i] == 'n')
	results4 << "found etaoin \n\n";}
	
    Counter++;
   } while (Counter < 72057594037937935); // all possible keys in byte 2 between 20256 and +5000

 

 getchar();
 return 0;
}
void keyI(long long counter, uchar key[])
{
 char g, h, i, j, k, l, m, n;

 if (counter < 256) //first 8 bits
 {
  n = static_cast<char>((counter & 0x00000000000000ff));
  key[0] = n;
 }
 else if (255 < counter && counter < 65536) //2nd 8 bits
 {
  m = static_cast<char>((counter & 0x000000000000ff00) );
  n = static_cast<char>((counter & 0x00000000000000ff));
  key[1] = m;
  key[0] = n;
 }
 else if (65535 < counter && counter< 16777216) //3rd 8 bits
 {
  l = static_cast<char>((counter & 0x0000000000ff0000) );
  m = static_cast<char>((counter & 0x000000000000ff00) );
  n = static_cast<char>((counter & 0x00000000000000ff));
  key[2] = l;
  key[1] = m;
  key[0] = n;
 }
 else if (16777215 < counter && counter < 4294967296) // 4th 8 bits
 {
  k = static_cast<char>((counter & 0x00000000ff000000) );
  l = static_cast<char>((counter & 0x0000000000ff0000) );
  m = static_cast<char>((counter & 0x000000000000ff00) );
  n = static_cast<char>((counter & 0x00000000000000ff));

  key[3] = k;
  key[2] = l;
  key[1] = m;
  key[0] = n;
 }
 else if (4294967295 < counter && counter < 1099511627776) // 5th 8 bits
 {
  j = static_cast<char>((counter & 0x000000ff00000000) );
  k = static_cast<char>((counter & 0x00000000ff000000) );
  l = static_cast<char>((counter & 0x0000000000ff0000) );
  m = static_cast<char>((counter & 0x000000000000ff00) );
  n = static_cast<char>((counter & 0x00000000000000ff));
  key[4] = j;
  key[3] = k;
  key[2] = l;
  key[1] = m;
  key[0] = n;
 }
 else if (1099511627775 < counter && counter < 281474976710656) // 6th 8 bits
 {
  i = static_cast<char>((counter & 0x0000ff0000000000) );
  j = static_cast<char>((counter & 0x000000ff00000000) );
  k = static_cast<char>((counter & 0x00000000ff000000) );
  l = static_cast<char>((counter & 0x0000000000ff0000) );
  m = static_cast<char>((counter & 0x000000000000ff00) );
  n = static_cast<char>((counter & 0x00000000000000ff));
  key[5] = i;
  key[4] = j;
  key[3] = k;
  key[2] = l;
  key[1] = m;
  key[0] = n;
 }
 else if (281474976710655 < counter && counter < 72057594037927936) // 7th 8 bits
 {
  h = static_cast<char>((counter & 0x00ff000000000000) );
  i = static_cast<char>((counter & 0x0000ff0000000000) );
  j = static_cast<char>((counter & 0x000000ff00000000) );
  k = static_cast<char>((counter & 0x00000000ff000000) );
  l = static_cast<char>((counter & 0x0000000000ff0000) );
  m = static_cast<char>((counter & 0x000000000000ff00) );
  n = static_cast<char>((counter & 0x00000000000000ff));
  key[6] = h;
  key[5] = i;
  key[4] = j;
  key[3] = k;
  key[2] = l;
  key[1] = m;
  key[0] = n;
 }
 else if (72057594037927935 < counter && counter < 9223372036854775808) // 8th 8 bits
 {
  g = static_cast<char>((counter & 0xff00000000000000) );
  h = static_cast<char>((counter & 0x00ff000000000000) );
  i = static_cast<char>((counter & 0x0000ff0000000000) );
  j = static_cast<char>((counter & 0x000000ff00000000) );
  k = static_cast<char>((counter & 0x00000000ff000000) );
  l = static_cast<char>((counter & 0x0000000000ff0000) );
  m = static_cast<char>((counter & 0x000000000000ff00) );
  n = static_cast<char>((counter & 0x00000000000000ff));
  key[7] = g;
  key[6] = h;
  key[5] = i;
  key[4] = j;
  key[3] = k;
  key[2] = l;
  key[1] = m;
  key[0] = n;
 }
 else
  cout << "error" << endl;

}