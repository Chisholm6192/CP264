/*
--------------------------------------------------
File:    myrecord.c, 
About:   public test driver
Author:  Ryan Chisholm, 169027577, chis7577@mylaurier.ca
Version: 2024-02-07
--------------------------------------------------
*/ 
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "myrecord.h"
#include "mysort.h"

GRADE grade(float score){
  GRADE letter = {"F"};
  if (score >= 90) strcpy(letter.letter_grade, "A+"); //if grade greater than 90, letter grade is A+

  else{
    char let[14][5] = {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D+", "D", "D-", "F"}; //array of letter grades
    int num[] = {100, 90, 85, 80, 77, 73, 70, 67, 63, 60, 57, 53, 50, 0}; //array of numeric grades

    int i = 1;
    while (i < 14 && !(score < num[i-1] && score >= num[i])){ //find correct location of score in number array
      i++;
    }
    strcpy(letter.letter_grade, let[i-1]); //set letter grade to matching index, (i-1 because the index's are misaligned by one index between the two arrays)
  }
  
  return letter;  
}

STATS process_data(RECORD *dataset, int count) {    
  STATS stats = {count, 0.0, 0.0, 0.0};
  float mean, median, stddev; //variables for mean, median and standard deviation
  float total = 0.0;

  for (int i = 0; i < count; i++){
    total += dataset[i].score; //add to sum

    if((count - i) == (count / 2)){ //if count is even, and middle is reached, median equals avg of the two middle values
      median = (dataset[i-1].score + dataset[i].score) /2 ;
    }
    else if((count - i) == (count / 2) + 1){ //if count is odd, and middle is reached, median equals middle value
      median = dataset[i].score;
    }
  }
  mean = total / count;

  for (int j = 0; j < count; j++){ //calculate standard deviation
    stddev += pow(dataset[j].score - mean, 2);
  }

  stddev = sqrt(stddev / count);

  //assign to values of STATS
  stats.mean = mean;
  stats.median = median;
  stats.stddev = stddev;

  return stats;
}

int import_data(FILE *fp, RECORD *dataset) {
  char delimeters[] = ",\n\r";
  char line[100];
  int i = 0;
  char *token = NULL;

  while(fgets(line, sizeof(line), fp) != NULL){ //keep reading until end of file is reached
    token = (char *) strtok(line, delimeters); //seperate name and score using tokens
    strcpy(dataset[i].name, token);

    token = (char *) strtok(NULL, delimeters);
    sscanf(token, "%f", &dataset[i].score);
    i++;
  }
  return i;
}

int report_data(FILE *fp, RECORD *dataset, int count) {
  for (int i = 0; i < count; i++){ //traverse dataset
    fprintf(fp, "%s,%.1f,%s\n", dataset[i].name, dataset[i].score, grade(dataset[i].score).letter_grade);
    //write to file in specified format
  }
}