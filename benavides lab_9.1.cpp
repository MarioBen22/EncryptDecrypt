// Mario Benavides
// Lab 9.1 - completed
// program that decrypts the file produced by the program in Prog. 1.  
// read the contents of the coded file, 
// restore the information to its original state and write it to another file.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


void Decrypt();


// main function
int main()
{
// calling decrypt function
    Decrypt();

    return 0;
}


// decrypt function
void Decrypt()
{
    char ch;


// open the encrypted file 
    fstream enc("encryptedFile.txt", ios::in);
        if (!enc) // error checking
	{
    	cout << "Error: File is missing." << endl; // endl flush the buffer.
		cin.get(); // pause the program
	}


// write decrypted contents 
    fstream dec("decryptedFile.txt", ios::out); 
       	if (dec.fail()) // error on bit flags
	{
		cout << "Error: Creating file has failed." << endl; // endl flush the buffer.
		cin.get(); // pause the program
	}


// writing over file data
    while(enc.get(ch))
    {
        // subtracting ASCII 11
        ch = char(int(ch) - 11);

        // writing to output file
        dec.put(ch);
        	if (dec.fail()) // error on bit flags
	{
		cout << "Error: Writing operation has failed." << endl; // endl flush the buffer.
		cin.get(); // pause the program
	}
    }


// closing files
    dec.close();
    enc.close();

    cout << "Data Decryption Completed." << endl; // flush the buffer.
}
