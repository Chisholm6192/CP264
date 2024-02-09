/**
 * -------------------------------------
 * @file  mystring.c
 * 
 * -------------------------------------
 * @author Ryan Chisholm, 169027577, chis7577@mylaurier.ca
 *
 * @version 02-03-2024
 *
 * ------------------------------------- */
#include "mystring.h"


/**
 * Count the number words of given simple string. A word starts with an English charactor end with a charactor of space, tab, comma, or period.  
 *
 * @param s - char pointer to a str
 * @return - return the number of words. 
 */
int str_words(char *s) {
    int count = 0;
    char *p = s;

    while (*p) { //traverse string
        if (isalpha(*p)){ //if a letter is found, continue until the end of the word is reached
            while (isalpha(*p)){
                p++;
            }
            //once the end of the word is reached, add to count
            count++;
        }
        p++;
    }
    return count;
}

/**
 * Change every upper case English letter to its lower case of string passed by s
 *
 * @param s - char pointer to a str
 * @return - return the number of actual flips.   
 */
int str_lower(char *s) {
    char *p = s;

    while (*p){ //traverse string
        if(isupper(*p) == 1){ //if uppercase character is found
            *p = tolower(*p); //convert to lowercase
        }
        p++;
    }
}

/**
 * Remove unnecessary space characters in a simple string passed by `s`
 *
 * @param s - char pointer to a str
 */
void str_trim(char *s) {
    char *p = s;
    char *dp = s;

    while (*p){ //traverse string
        if (*p != ' ' || (p > s && *(p-1) != ' ')){ //if character is not a space, or char is a space, but previous is not
            *dp = *p; 
            dp++;
        }
        p++;
    }

    if (*(p-1) != ' '){
        *dp = '\n';
    }
    else {
        *(dp-1) = '\0';
    }
}