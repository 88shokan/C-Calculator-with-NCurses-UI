/*
Billy Phan
 Calculator in C With UI
*/

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

int main(){
   initscr(); 
   start_color();

   init_pair(1, COLOR_CYAN, COLOR_BLUE); 
   init_pair(2, COLOR_WHITE, COLOR_BLUE);
   init_pair(3, COLOR_GREEN, COLOR_BLUE);
   init_pair(4, COLOR_RED, COLOR_WHITE);


   //Calculator UI

   //Title
    attron(COLOR_PAIR(1));
    mvprintw(1, 10, "+---------------------------+");
    mvprintw(2, 10, "  Calculator By Billy Phan   ");
    mvprintw(3, 10, "+---------------------------+");
    attroff(COLOR_PAIR(1));


   char operator;
   double num1;
   double num2;
   double result;
   attron(COLOR_PAIR(2));
   mvprintw(5, 10, "Enter an operator (+ - * /): ");
   scanw(" %c", &operator);
   

   mvprintw(7, 10, "Enter number 1: ");
   scanw("%lf", &num1);

   mvprintw(9, 10, "Enter number 2: ");
   scanw("%lf", &num2);
   attroff(COLOR_PAIR(2));
   switch(operator){
      case '+':
         result = num1 + num2;
         attron(COLOR_PAIR(3));
         mvprintw(12, 10, "Result: %.2lf", result);
         attroff(COLOR_PAIR(3));
         break;
      case '-':
         result = num1 - num2;
         attron(COLOR_PAIR(3));
         mvprintw(12, 10, "Result: %.2lf", result);
         attroff(COLOR_PAIR(3));
         break;
      case '*':
         result = num1 * num2;
         attron(COLOR_PAIR(3));
         mvprintw(12, 10, "Result: %.2lf", result);
         attroff(COLOR_PAIR(3));
         break;
      case '/':
         if (num2 != 0){
            result = num1 / num2;
            attron(COLOR_PAIR(3));
            mvprintw(12, 10, "Result: %.2lf", result);
            attroff(COLOR_PAIR(3));
         }
         else{
            attron(COLOR_PAIR(4));
            mvprintw(12, 10, "Error: Division by zero is not allowed.");
            attroff(COLOR_PAIR(4));
         }
         break;
      default:
        attron(COLOR_PAIR(4));
        mvprintw(12, 10, "%c is not valid", operator);
        attroff(COLOR_PAIR(4));
   }

   refresh();
   getch();
   endwin();          
   return 0;
}