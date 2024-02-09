/**
 * -------------------------------------
 * @file  myword.c
 * 
 * -------------------------------------
 * @author Ryan Chisholm, 169027577, chis7577@mylaurier.ca
 *
 * @version 02-03-2024
 *
 * ------------------------------------- */

#include <stdio.h>
#include <string.h>
#include "myword.h"

#define MAX_LINE_LEN 1000
#define MAX_WORDS 1000

// You can copy here the functions in mysttring.c if you want to use them in the
// following functions. You can also add other auxiliary functions here. 

/*
 * Define enumeration type BOOLEAN with value FASLE = 0 and TRUE 1.
 */
typedef enum boolean {
    false, 
    true
} BOOLEAN;

/*
 * Define structure type WORD consists of char word[20] to store a word, int count to hold frequency of the word.
 */
typedef struct word {
    char word[20];
    int count;
} WORD;


/*
 * Define structure type WORDSTATS consisting of int line_count, int word_count, and int keyword_count to represent
 * to represent the number of lines, number of all words, and the number of different non-common-word in text data.
 */
typedef struct wordstats {
    int line_count;
    int word_count;
    int keyword_count;
} WORDSTATS;


/*
 * Load word data from file, and insert words a directory represented by char array.
 * 
 * @param  FILE *fp -   file pointer to an opened text file
 * @param *dictionary - char pointer to a char array where dictionary words are stored. 
 *                      It's up to your design on how to store words in the char array.
 * @return - the number of words added into the dictionary.   
 */
int create_dictionary(FILE *fp, char *dictionnary) {
    int count = 0;

    // Read each line from the file
    char line[1000];
    while (fgets(line, sizeof(line), fp) != NULL) {

        // Remove newline character from the end of the line
        line[strcspn(line, "\n")] = '\0';

        // Copy the word into the dictionary
        strcpy(dictionnary, line);

        // Move the pointer to the next available position in the dictionary
        dictionnary += strlen(line) + 1; // +1 to leave space for null terminator

        count++;
    }

    return count;
}


/*
 * Determine if a given word is contained in the given dictionary.  
 * 
 * @param *dictionary -  char pointer to a char array of given dictionary.
 * @param *word  -  pointer to a given word.  
 *                     
 * @return - TRUE if the word is in the dictionary, FALSE otherwise.   
 */
BOOLEAN contain_word(char *dictionary, char *word) {
    char *val = strstr(dictionary, word);

    if ((int)(val) == 0) { return false; }
    else { return true; }
}

/*
 * Process text data from a file for word statistic information of line count, word count, keyword count, and frequency of keyword.   
 * 
 * @param *fp -  FILE pointer of input text data file. .
 * @param *words  -  WORD array for keywords and their frequencies.
 * @param *dictionary  -  stop-word/common-word dictionary.    
 *                     
 * @return - WORDSTATS value of processed word stats information.   
 */
WORDSTATS process_words(FILE *fp, WORD *words, char *dictionary) {
    WORDSTATS stats = {0, 0, 0};

    char line[1000];
    while (fgets(line, sizeof(line), fp) != NULL) {
        stats.line_count++;

        char *token = strtok(line, " ");
        while (token != NULL) {
            stats.word_count++;

            // Check if the token is not in the dictionary (non-common word)
            if (!contain_word(dictionary, token)) {
                // Check if the token is already in the words array
                int index = -1;
                for (int i = 0; i < stats.keyword_count; i++) {
                    if (strcmp(words[i].word, token) == 0) {
                        index = i;
                        break;
                    }
                }

                // Update frequency in the words array
                if (index != -1) {
                    words[index].count++;
                } else {
                    // Add new keyword to the words array
                    if (stats.keyword_count < 1000) {
                        strcpy(words[stats.keyword_count].word, token);
                        words[stats.keyword_count].count = 1;
                        stats.keyword_count++;
                    } else {
                        fprintf(stderr, "Too many keywords. Increase MAX_WORDS.\n");
                        exit(EXIT_FAILURE);
                    }
                }
            }

            token = strtok(NULL, " ");
        }
    }

    return stats;
}