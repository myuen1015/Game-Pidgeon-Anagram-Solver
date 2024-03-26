/* This is the anagrams solver mainly used for the popular Imessage game Anagrams
	Given a 6 letter string this program is able to solve any 6 letter string effectly.
	This program uses an unordered map, string manipulation, permutatios and look ups.  
	if you want to change the word size you can change it in the driver 

	To use just imput the letters you see such as for (int length = 3; length <= 6; length++) you can change 6 to however long you need it to be. 

	abcdef
*/
#include<iostream>
#include<fstream>
#include<unordered_map>
#include<algorithm>
using namespace std; 

unordered_map<string, int> dict; 

void read_dictionary()
{
	ifstream dictionary("words_alpha.txt");  
	string word; 
	if (dictionary.is_open())
	{
		while (dictionary >> word)
		{
			dict.insert(make_pair(word, 0));  //allows to store words from the txt to a unordered map
		}
		dictionary.close(); 
	}
}
void findwords(string str, int length)
{
	string words = str.substr(0, length); 
	sort(words.begin(), words.end()); // will make it into shortest -> longest order 
	do
	{
		if (dict.count(words)) //if the word is found in the unordered map it will print out the word. 
		{
			cout << words << endl;
		}
	}
	while (next_permutation(words.begin(), words.end()));  // continues brute forcing possible combinations. 
	// this works by generating all the possible values in a sorted order. 
	// it will keep updating the value of words until it reaches the end of its combinations. 
}
int main()
{
	read_dictionary(); 
	string word; 
	cout << "give a 6 letter string such as abcdef" << endl; 
	cin >> word; 
	for (int length = 3; length <= 6; length++) // prints words between 3 letters to 6 letters 
	{
		for (int i = 0; i <= word.size()-length; i++) // without the -length the loop would not work idk why :crying: i think cus if it doesn't it will break the subset 
		{
			findwords(word.substr(i), length); 
		}
	}
	return 0; 
}
