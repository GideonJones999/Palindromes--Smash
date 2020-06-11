#include <iostream>
#include <iomanip>
#include <string>
//Sounds
#include <Windows.h>
#include <MMSystem.h>
//Randoms 
#include <random>
#include <cstdlib>
#include <ctime>
//Dynamic Arrays
#include <vector>
// Sleep Function
#include <time.h>

using namespace std;
bool TestPalindrome(string);
string SmashGames(vector<string>);
int RandomNumber(int, int);
void Sleep(int);

int RandomNumber(int max, int min) {
	return (rand() % (max - min) + min);
}

int main() {
	//Palindromes
	string test = "";
	cout << "Enter a string to check for a palindrome:  " << endl;
	cin >> test;
	if (TestPalindrome(test))
		cout << test << " is a palindrome!" << endl;
	else if (TestPalindrome(test) == false)
		cout << test << " is not a palindrome." << endl;

	//Smash
	cout << "Let's play..." << endl;
	cout << "SMASH BROS.!!!!" << endl;
	vector<string> fighters = { "Mario", "Luigi", "Donkey Kong", "Link", "Ness", "Samus", "Yoshi", "Captain Falcon", "Kirby", "Fox", "Jiggly Puff", "Pikachu" };
	cout << SmashGames(fighters) << " is the Winner! Congratulations! " << endl;
	system("PAUSE");
	return 0;
}

bool TestPalindrome(string test) {
	if (test.length() <= 1)
		return true;
	else if (test[0] == test[test.length() - 1])
		return true && TestPalindrome(test.substr(1, test.length() - 2));
	else
		return false;
}
string SmashGames(vector<string> fighters) {
	if (fighters.size() == 1)
		return fighters[0];
	int SMASHED = RandomNumber(fighters.size(), 0);
	cout << fighters[SMASHED] << " got SMASHED!!" << endl;
	fighters.erase(fighters.begin() + SMASHED);
	Sleep(250);
	return SmashGames(fighters);
}

void Sleep(int milliSec) {
	clock_t goal = milliSec + clock(); // clock() is system clock
	while (goal > clock()); // acts as sleep function
}