/*
   ------------------------------------------------------ Maman: 22 ----------------------------------------------------------
    Eilon Alter  208500603

    This program gets input from user/file and checks for commands on complexs numbers

    The program includes the commands which are given at complex.c and utils functaions which are given at utils.c
*/

#include "complex.h"

void handelInput(Complex *comps[6]);

int main()
{
    /* Initialization */
    struct Complex A, B, C, D, E, F;
    Complex *comps[6];
    comps[0] = &A;
    comps[1] = &B;
    comps[2] = &C;
    comps[3] = &D;
    comps[4] = &E;
    comps[5] = &F;

    /* function to handle the input */
    handelInput(comps);

    return 0;
}

void handelInput(Complex *comps[6])
{
    char c;
    char lineArray[256];
    while (true)
    {
        c = getchar();
        if (c == '\n')
        {
            choseCommand(lineArray, comps);
            strcpy(lineArray, "");
        }
        else if (c == EOF)
        {
            return;
        }
        else
        {
            add(lineArray, c);
        }
    }
}