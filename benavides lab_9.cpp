// Mario Benavides
// Lab 9 - completed
// reading the contents of an existing file, 
// modifying each character in the input file into a code
// then writing the coded characters out to a second file

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


void Encrypt();


// main function
int main()
{
// calling encrypt function
    Encrypt();

    return 0;
}


// encrypt function
void Encrypt()
{
    char ch;


// open the encrypted file 
    fstream original("encryptthis.txt", ios::in);
        if (!original) // error checking
    {
    	cout << "Error: File is missing." << endl; // flush the buffer.
		cin.get(); // pause the program
	}


// write encrypted contents 
    ofstream enc("encryptedFile.txt", ios::out);
       	if (enc.fail()) // error on bit flags
	{
		cout << "Error: Reading operation has failed." << endl; // endl flush the buffer.
		cin.get(); // pause the program
	}


// writing over file data
    while(original.get(ch))
    {
        // adding ASCII 11
        ch = char(int(ch) + 11);

        // writing to output file
        enc.put(ch);
	       	if (enc.fail()) // error on bit flags
	{
		cout << "Error: Writing operation has failed." << endl; // endl flush the buffer.
		cin.get(); // pause the program
	}
    }


// closing functions
    original.close();
    enc.close();

    cout << "Data Encryption Completed." << endl; // flush the buffer.
}
