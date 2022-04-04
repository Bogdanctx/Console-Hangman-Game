#include <iostream>
#include <ctime>
#include <random>
#include <cstring>

using namespace std;

void AddLetter(char letter, char* hidden_word, const char* word, unsigned short word_len, bool& letter_found)
{ // Here we search and add entered letter
  // If it does not exist we'll set letter_found=false and also we'll decrement lives
    letter = toupper((int)letter);
    for (unsigned short i = 1; i < word_len; i++)
    {
        if (letter == word[i])
            hidden_word[i] = letter, letter_found = true;
    }
}

bool WordFound(char* word, const char* real_word)
{ // Here we check for every letter entered if the word is completed
    for (unsigned short i = 0; word[i]; i++)
    {
        if (word[i] != real_word[i])
            return false;
    }
    return true;
}

int main()
{
    srand(time(0));
    const char* word_list[5] = { "AIRPLANE", "PROGRAMMING", "YOUTUBE", "GAME", "HANGMAN" }, // words list
        * lives_char[3] = { ":(", ":|", ":)" };
    unsigned short random_word_index = rand() % 5, // here we chose a random number to get the random word from word_list
        word_len = strlen(word_list[random_word_index]) - 1,
        lives = 2; // lives is 2 because lives_char index starts at 0
    char word[50], letter;
    bool letter_found;

    strcpy_s(word, word_list[random_word_index]); // here we copy the random word to word array
    for (unsigned short i = 1; i < word_len; i++)
    {
        if (word_list[random_word_index][i] == word[0] || word_list[random_word_index][i] == word[word_len])
        { // here we add to word[50] first letter and the last letter
            // and also we add those letters where they exists on another positions
            word[i] = word_list[random_word_index][i];
        }
        else
            word[i] = '_';
    }
    while (lives)
    {
        letter_found = false;
        cout << "Your lives: " << lives_char[lives] << " (" << lives + 1 << ")" << '\n';
        cout << word << '\n';
        cout << "Enter a letter: "; cin >> letter;
        AddLetter(letter, word, word_list[random_word_index], word_len, letter_found); // this function add a letter to word[50]

        if (!letter_found)
            lives--;
        system("cls");
        if (WordFound(word, word_list[random_word_index]))
        {
            cout << word << '\n';
            cout << "You have found the word!\n";
            system("pause");
        }
    }

    if (!lives)
    {
        cout << "You ran out of lives.\n";
        cout << "The word was: " << word_list[random_word_index] << '\n';
    }

    return 0;
}
