/*
   ------------------------------------------------------ Maman: 22 ----------------------------------------------------------
    Eilon Alter  208500603

    This program gets input from user/file and checks for commands on complexs numbers

    The program includes the commands which are given at complex.c and utils functaions which are given at utils.c
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

typedef struct Complex
{
   double real;
   double imaginary;
} Complex;

/*--------------------------------------------- Complex Functions -----------------------------------------------*/
void read_comp(double real, double imaginary, Complex *comp);
void print_comp(Complex *comp);
void add_comp(Complex *comp1, Complex *comp2);
void sub_comp(Complex *comp1, Complex *comp2);
Complex mult_comp_real(Complex *comp, double number);
Complex mult_comp_img(Complex *comp, double number);
void mult_comp_comp(Complex *a, Complex *b);
void abs_comp(Complex *a);

/*------------------------------------------------------ utilis ---------------------------------------------------- */
void add(char *char_array, char c);
bool emptyLine(char arr[]);
char *cut(char *s);
Complex *choseComplex(char *comp, Complex *comps[6]);
char *getArgument(bool shouldHaveText, bool shouldComma);
void choseCommand(char lineArray[256], Complex *comps[6]);
