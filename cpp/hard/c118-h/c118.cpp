// Challenge 118 Hard - Alphabetizing Cipher
// Compiled with GCC
// Written by charles.0x4f@gmail.com
// Github: https://github.com/charles-0x4f

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<string> dictionary;
vector<char> alphabet;
vector<char> prometheus;

string translate(int wordNumber, const vector<char> &key) {
	string temp, cipher = "";

	temp = dictionary[wordNumber];

	for(int x = 0; x < temp.size(); x++) {
		int y;
		vector<char>::iterator it;
		it = find(alphabet.begin(), alphabet.end(), temp[x]);
		y = distance(alphabet.begin(), it);
		cipher += key.at(y);
	}

	return cipher;
}

bool alphabetical(string word) {
	char height;

	height = word[0];

	for(int x = 1; x < word.size(); x++) {
		if(word[x] > height) {
			height = word[x];
			continue;
		}
		else {
			return false;
		}
	}

	return true;
}

int calculateScore(const vector<char> &key) {
	int count = 0;

	for(int x = 0; x < dictionary.size(); x++) {
		if(alphabetical(translate(x, key)) == true) {
			count++;
		}
	}

	return count;
}

void newHighScore(int score) {
	cout << "New high score: " << score << " : ";

	for(int x = 0; x < prometheus.size(); x++) {
		cout << prometheus[x];
	}

	cout << "\n";
}

int main()
{
	ifstream dict;
	dict.open("dictionary.txt");

	// Read file into dictionary vector
	while(!dict.eof()) {
		string temp;
		// silly windows
		getline(dict, temp, '\r');
		if(temp[0] == '\n') {
			temp.erase(0, 1);
		}
		dictionary.push_back(temp);
	}

	// Fill original alphabet
	for(int x = 'a'; x <= 'z'; x++) {
		alphabet.push_back(x);
	}

	// I like this line
	prometheus = alphabet;

	// Start with base score for future comparisons
	int highscore = calculateScore(prometheus);
	newHighScore(highscore);

	// Do genetic stuff
	srand(time(NULL));
	do {
		int score1, score2;
		vector<char> offspring1 = prometheus, offspring2 = prometheus;

		// Retrospect: NEEDS MORE COMMENTS
		for(int x = 0; x < (offspring1.size() / 2); x++) {
			int chance = rand() % 101;

			if(chance < 45) {
				chance = rand() % (offspring1.size() / 2);
				swap(offspring1[x], offspring1[chance]);
			}
		}
		
		score1 = calculateScore(offspring1);

		for(int x = (offspring2.size() / 2); x < offspring2.size();
				x++) {
			int chance = rand() % 101;

			if(chance < 45) {
				chance = rand() % (offspring2.size() / 2);
				swap(offspring2[x], offspring2[chance]);
			}
		}

		score2 = calculateScore(offspring2);

		if(score2 > score1) {
			score1 = score2;
			offspring1 = offspring2;
		}

		if(score1 > highscore) {
			highscore = score1;
			prometheus = offspring1;
			newHighScore(highscore);
		}
	} while(true);

	return 0;
}


