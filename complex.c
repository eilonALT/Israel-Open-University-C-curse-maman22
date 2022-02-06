/*
   ------------------------------------------------------ Maman: 22 ----------------------------------------------------------
    Eilon Alter  208500603

    This program gets input from user/file and checks for commands on complexs numbers

    The program includes the commands which are given at complex.c and utils functaions which are given at utils.c
*/
#include "complex.h"

void read_comp(double real, double imaginary, Complex *comp)
{
    comp->real = real;
    comp->imaginary = imaginary;
    print_comp(comp);
}

void print_comp(Complex *comp)
{
    printf("%.2f", comp->real);
    if (comp->imaginary >= 0)
        printf(" + (%.2f)i\n", comp->imaginary);
    else
        printf(" - (%.2f)i\n", -comp->imaginary);
}

void add_comp(Complex *compOne, Complex *compTwo)
{
    Complex respond;
    respond.real = compOne->real + compTwo->real;
    respond.imaginary = compOne->imaginary + compTwo->imaginary;
    print_comp(&respond);
}

void sub_comp(Complex *compOne, Complex *compTwo)
{
    Complex respond;
    respond.real = compOne->real - compTwo->real;
    respond.imaginary = compOne->imaginary - compTwo->imaginary;
    print_comp(&respond);
}

Complex mult_comp_real(Complex *comp, double number)
{
    Complex respond;
    respond.real = comp->real * number;
    respond.imaginary = comp->imaginary * number;
    return respond;
}

Complex mult_comp_img(Complex *comp, double number)
{
    Complex respond;
    respond.real = comp->imaginary * (-1) * number;
    respond.imaginary = comp->real * number;
    return respond;
}

void mult_comp_comp(Complex *compOne, Complex *compTwo)
{
    Complex respond1;
    Complex respond2;
    respond1 = mult_comp_real(compOne, compTwo->real);
    respond2 = mult_comp_img(compOne, compTwo->imaginary);
    add_comp(&respond1, &respond2);
}

void abs_comp(Complex *comp)
{
    double respond = sqrt(comp->real * comp->real + comp->imaginary * comp->imaginary);
    printf("%.2f\n", respond);
}