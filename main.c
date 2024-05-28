/*-------------------------------------------
Program 1: TwentyFour
Course: CS 211, Spring 2023, UIC
System: Replit
Author: Reem Allam
------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

void intro() { //displays instructions to user
  printf("Welcome to the game of TwentyFour. \n");
  printf("Use each of the four numbers shown below exactly once, \n");
  printf("combining them somehow with the basic mathematical operators (+,-,*,/) \n");
  printf("to yield the value twenty-four.\n\n");
}

//from lab 2, to run arguments on the command line
void arguments(int argc,char *argv[],int *easymode, int *debug){
if (argc == 0){ // No arguments at all
  intro(); //displays intro again
  } 
else{
  while ((argc -= 2) > 0) {  
    if (argv[1][0] != '-') 
      intro();
switch (argv[1][1]) { 
      case 'e':
*easymode = atoi(argv[2]);
  break;
    case 'd':
      *debug = atoi(argv[2]);
       break;
    default:
        perror("Incorrect parameter");
} 
argv += 2; //advances to next two command line options
   } 
  }
}

// hardmode contains 3188 solutions, those should display in command line
void hardmode(double solutions[3188][4], char dispoperations[3188][3]){
  double i, j, n, x;
  char operations[4] = {'+','-','*','/'};
  char op1, op2, op3;
  double result1;
  double result2;
  double finalres;

  int count = 0;

  //this portion loops through all the operations user could use
  for (i = 1; i < 10; i++){
    for (j = 1; j < 10; j++) {
     for (n = 1; n < 10; n++){
      for (x = 1; x < 10; x++){
       for(int m = 0; m < 4; m++){
         
         if(operations[m]=='+'){
            result1 = i + j;
            op1 = '+';
             }
         
         if(operations[m]=='-'){
            result1 = i - j;
            op1 = '-';
              }
         
          if(operations[m]=='*'){
            result1 = i*j;
            op1 = '*';
             }
         
          if(operations[m]=='/'){
            result1 = i/j;
            op1 = '/';
              }
         
            for(int f = 0; f< 4; f++){
              if(operations[f]=='+'){
                result2 = result1 + n;
                op2 = '+';
                    }
              
              if(operations[f]=='-'){
                result2 = result1 - n;
                op2 = '-';
                    }
              
             if(operations[f]=='*'){
                result2= result1 *n;
                op2 = '*';
                    }
              
              if(operations[f]=='/'){
                result2 = result1/n;
                op2 = '/';
                    }
              // does math equation usser inputs and displays its value
                for(int z = 0; z<4; z++){
                  
                    if(operations[z]=='+'){
                       finalres = result2 + x;
                       op3 = '+';
                        }
                  
                    if(operations[z]=='-'){
                      finalres= result2 - x;
                      op3 = '-';
                        }
                  
                    if(operations[z]=='*'){
                      finalres= result2 *x;
                      op3 = '*';
                        }
                  
                    if(operations[z]=='/'){
                      finalres = result2 / x;
                      op3 = '/';
                        }

                  //makes sure result is rounded down
if ((finalres - 24.0) < 0.001 && (finalres - 24.0) >= 0){ //rounds solution down
          solutions[count][0] = i;
          solutions[count][1]= j;
          solutions[count][2]= n;
          solutions[count][3] = x;
  
          dispoperations[count][0] = op1;
          dispoperations[count][1] = op2;
          dispoperations[count][2] = op3;
          count++;
                        }
                       }
                     }
                    }
                  }
                 }
               }
             }
  }
// if hardmode is selected, run 3188 solution options
 void selecthard(double solutions[3188][4]){
   double hardarray[4];
   bool done = false;
   while (done != true){
   int random = (rand() % 3188);
     printf("The numbers to use are: ");

     for(int i = 0; i<4; i++){
       hardarray[i] = solutions[random][i]; 
     }
     for(int j = 0; j < 4; j++){
       if(j != 3){
         printf("%d, ",
           (int) hardarray[j]);
       }
       else{
         printf("%d",(int) hardarray[j]);
       }
     }
  printf(".\n");
  printf("Enter the three operators to be used, in order (+,-,*, or /): ");
     
 int num = hardarray[0], num1 = hardarray[1], num2 = hardarray[2], num3 = hardarray[3];
  int result, result2, result3;
  char op1, op2, op3;
  char array[10];
  scanf("%s" , array);
  strlen(array);
  op1 = array[0];
  op2 = array[1];
  op3 = array[2];

     //if user uses more or less operations than allowed display error
      if(strlen(array)>3 || strlen(array)<3){
          printf("Error! The number of operators is incorrect. Please try again.\n\n");
          continue;
        }
     
     //if incorrect operations are used, display error for op1,2,3
if(op1 != '+' && op1 != '-' && op1 != '*' && op1 != '/'){
    printf("Error! Invalid operator entered. Please try again.\n\n");
    continue;
  }
     
  if(op2 != '+' && op2 != '-' && op2 != '*' && op2 != '/'){
    printf("Error! Invalid operator entered. Please try again.\n\n");
    continue;
  }
     
  if(op3 != '+' && op3 != '-' && op3 != '*' && op3 != '/'){
    printf("Error! Invalid operator entered. Please try again.\n\n");
    continue;
  }
//performs the math equation user inputs and displays its result for operation 1
    if (op1 == '+'){
result = num + num1;
    printf("%d + %d = %d.\n", num, num1, result);
    }
else if (op1 == '-'){
result = num - num1;
    printf("%d - %d = %d.\n", num, num1, result);
    }
else if (op1 == '*'){
result = num * num1;
    printf("%d * %d = %d.\n", num, num1, result);
    }
else if (op1 == '/'){
result = num / num1;
    printf("%d / %d = %d.\n", num, num1, result);
    }
//value is stored in result
result2=result;

//performs math equation user inputs and displays its result for operation 2
    if (op2 == '+'){
result = result + num2;
    printf("%d + %d = %d.\n", result2, num2, result);
    }
else if (op2 == '-'){
result = result - num2;
    printf("%d - %d = %d.\n", result2, num2, result);
    }
else if (op2 == '*'){
result = result * num2;
    printf("%d * %d = %d.\n", result2, num2, result);
    }
else if (op2 == '/'){
result = result / num2;
    printf("%d / %d = %d.\n", result2, num2, result);
    }
     //answer is stored
result3=result;
     
    //performs math equation user inputs and displays its result for operation 3
    if (op3 == '+'){
result = result + num3;
    printf("%d + %d = %d.\n", result3, num3, result);
    }
else if (op3 == '-'){
result = result - num3;
    printf("%d - %d = %d.\n", result3, num3, result);
    }
else if (op3 == '*'){
result = result * num3;
    printf("%d * %d = %d.\n", result3, num3, result);
    }
else if (op3 == '/'){
result = result / num3;
    printf("%d / %d = %d.\n", result3, num3, result);
    }

    
    //when user solves game or loses this displays
    if(result == 24){
      printf("Well done! You are a math genius.\n\n");
      }
    else {
      printf("Sorry. Your solution did not evaluate to 24.\n\n");
      }
    
    //gives user option to play again
    printf("Would you like to play again? Enter N for no and any other character for yes.\n");
    
    scanf("%s",array);
    if(array[0] == 'N'){
      printf("Thanks for playing!");
      done = true;
    }
    else{
      continue;
    }
     
   }
 }

// displays all the solutions to the game when on
void debugmode(double solutions[3188][4], char dispoperations[3188][3]){
  for(int x = 0; x < 3188; x++){
    printf("%d. ", x+1);
  
  for(int j = 0; j<4; j++){
            if(j==0){
                printf("%d", (int) solutions[x][j]);
            }
            if(j==1){
                printf("%c%d", dispoperations[x][0], (int) solutions[x][j]);
            }
            if(j==2){
                printf("%c%d", dispoperations[x][1], (int) solutions[x][j]);
            }
            if(j==3){
                printf("%c%d", dispoperations[x][2], (int) solutions[x][j]);
            }
        }
        printf("\n");
    }
  }

//10 puzzles are used to play when easy mode is on
void easymode(int easyarray[4]){
  
  bool finish = false;
  while (finish != true){
    
  printf("The numbers to use are: ");
  int numarray[10][4] = 
  {{3, 9, 4, 1},
  {8, 5, 8, 1},
  {6, 1, 5, 1},
  {2, 8, 7, 8},
  {5, 2, 9, 2},
  {2, 6, 8, 4},
  {5, 5, 4, 3},
  {6, 6, 2, 6},
  {8, 4, 2, 6},
  {6, 2, 8, 1}};

    //picks random array frrom those 10 options
  int random = (rand() % 10);
  
  //picks random row from numarray and copies it to easysolutions
  for(int i = 0; i< 4; i++){ 
    easyarray[i] = numarray[random][i];
  }

  for (int j = 0; j<4;j++){
    if(j != 3){
      printf("%d, ", easyarray[j]);
      }
  else {
    printf("%d",easyarray[j]);
    }
    }
  printf(".\n");
  printf("Enter the three operators to be used, in order (+,-,*, or /): ");

  int num = easyarray[0], num1 = easyarray[1], num2 = easyarray[2], num3 = easyarray[3];
  int result, result2, result3;
  char op1, op2, op3;
  char array[10];
  scanf("%s" , array);
  strlen(array);
  op1 = array[0];
  op2 = array[1];
  op3 = array[2];

     //if user uses more or less operations than allowed display error
      if(strlen(array)>3 || strlen(array)<3){
          printf("Error! The number of operators is incorrect. Please try again.\n");
          continue;
        }

     //if incorrect operations are used, display error
if(op1 != '+' && op1 != '-' && op1 != '/' && op1 != '*'){
    printf("Error! Invalid operator entered. Please try again.\n\n");
    continue;

  }
  if(op2 != '+' && op2 != '-' && op2 != '/' && op2 != '*'){
    printf("Error! Invalid operator entered. Please try again.\n\n");
    continue;

  }
  if(op3 != '+' && op3 != '-' && op3 != '/' && op3 != '*'){
    printf("Error! Invalid operator entered. Please try again.\n\n");
    continue;

  }
//performs the math equation user inputs and displays its result for operation 1
    if (op1 == '+'){
result = num + num1;
    printf("%d + %d = %d.\n", num, num1, result);
    }
else if (op1 == '-'){
result = num - num1;
    printf("%d - %d = %d.\n", num, num1, result);
    }
else if (op1 == '*'){
result = num * num1;
    printf("%d * %d = %d.\n", num, num1, result);
    }
else if (op1 == '/'){
result = num / num1;
    printf("%d / %d = %d.\n", num, num1, result);
    }

result2=result;
//performs the math equation user inputs and displays its result for operation 2
    if (op2 == '+'){
result = result + num2;
    printf("%d + %d = %d.\n", result2, num2, result);
    }
else if (op2 == '-'){
result = result - num2;
    printf("%d - %d = %d.\n", result2, num2, result);
    }
else if (op2 == '*'){
result = result * num2;
    printf("%d * %d = %d.\n", result2, num2, result);
    }
else if (op2 == '/'){
result = result / num2;
    printf("%d / %d = %d.\n", result2, num2, result);
    }
result3=result;
    //performs the math equation user inputs and displays its result for operation 3
    if (op3 == '+'){
result = result + num3;
    printf("%d + %d = %d.\n", result3, num3, result);
    }
else if (op3 == '-'){
result = result - num3;
    printf("%d - %d = %d.\n", result3, num3, result);
    }
else if (op3 == '*'){
result = result * num3;
    printf("%d * %d = %d.\n", result3, num3, result);
    }
else if (op3 == '/'){
result = result / num3;
    printf("%d / %d = %d.\n", result3, num3, result);
    }

    
    //when user solves game or loses this displays
    if(result == 24){
      printf("Well done! You are a math genius.\n\n");
      }
    else {
      printf("Sorry. Your solution did not evaluate to 24.\n\n");
      }
    
    //gives user option to play again
    printf("Would you like to play again? Enter N for no and any other character for yes.\n");
    
    scanf("%s",array);
    if(array[0] == 'N'){
      printf("Thanks for playing!");
      finish = true;
    }
    else{
      continue;
    }
    }
  }
    

int main(int argc, char* argv[]) {
  intro(); //calls intro
  int easy = 1; //easy mode is set to true
  int debug = 0; // debug is set to false
  arguments(argc, argv, &easy, &debug); // calls command line arguments
  int easyarray[4]; //array of 4 random numbers in the 10 easy mode array options
  double hardarray[3188][4]; //4 random numbers in the 3188 solution options
  char dispoperations[3188][3]; //displays 3188 solution options
  hardmode(hardarray,dispoperations); // calls hardmode function

	srand(1);	// Initialize random number generator.

  //cases to run if easy or debug are true or false
	if(debug==1){ 
    debugmode(hardarray,dispoperations);
    }
  if(easy==1){
    easymode(easyarray);
  }
  if(easy==0){
      selecthard(hardarray);
  }

	return 0;
}