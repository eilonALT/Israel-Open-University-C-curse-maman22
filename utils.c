/*
   ------------------------------------------------------ Maman: 22 ----------------------------------------------------------
    Eilon Alter  208500603

    This program gets input from user/file and checks for commands on complexs numbers

    The program includes the commands which are given at complex.c and utils functaions which are given at utils.c
*/
#include "complex.h"
/*---------------------------------an util func that match the right command and handel bad commands-------------------------------------*/
void choseCommand(char lineArray[256], Complex *comps[6])
{
    Complex *complexOne;
    Complex *compTwo;
    Complex tempResultComp;

    double num;
    double num2;
    char *command;
    char *arg;
    char *arg2;

    if (emptyLine(lineArray))
    {
        return;
    }
    printf("%s\n", lineArray);
    if (strstr(lineArray, ",,"))
    {
        printf("multiple commas\n\n");
        return;
    }
    command = strtok(lineArray, " ");
    if (strchr(command, ','))
    {
        printf("Illegal comma\n\n");
        return;
    }
    if (strcmp(command, "add_comp") == 0)
    {
        arg = getArgument(true, true);
        arg2 = getArgument(true, true);
        if (arg && arg2)
        {
            complexOne = choseComplex(arg, comps);
            compTwo = choseComplex(arg2, comps);
            if (complexOne && compTwo)
            {
                if (getArgument(false, false))
                {
                    add_comp(complexOne, compTwo);
                }
            }
            else
            {
                printf("Undefined complex\n\n");
            }
        }
    }
    else if (strcmp(command, "sub_comp") == 0)
    {
        arg = getArgument(true, true);
        arg2 = getArgument(true, true);
        if (arg && arg2)
        {
            complexOne = choseComplex(arg, comps);
            compTwo = choseComplex(arg2, comps);
            if (complexOne && compTwo)
            {
                if (getArgument(false, false))
                {
                    sub_comp(complexOne, compTwo);
                }
            }
            else
            {
                printf("Undefined complex\n\n");
            }
        }
    }
    else if (strcmp(command, "mult_comp_real") == 0)
    {
        arg = getArgument(true, true);
        if (arg)
        {
            complexOne = choseComplex(arg, comps);
            if (complexOne)
            {
                arg = getArgument(true, true);
                if (!arg)
                {
                    return;
                }
                num = atof(arg);
                if (num == 0 && strcmp("0", arg) != 0)
                {
                    printf("parameter is not a number\n\n");
                    return;
                }
                if (getArgument(false, false))
                {
                    tempResultComp = mult_comp_real(complexOne, num);
                    print_comp(&tempResultComp);
                }
            }
            else
            {
                printf("Undefined complex \n\n");
            }
        }
    }
    else if (strcmp(command, "mult_comp_img") == 0)
    {
        arg = getArgument(true, true);
        if (arg)
        {
            complexOne = choseComplex(arg, comps);
            if (complexOne)
            {
                arg = getArgument(true, true);
                if (!arg)
                {
                    return;
                }
                num = atof(arg);
                if (num == 0 && strcmp("0", arg) != 0)
                {
                    printf("parameter is not a number\n\n");
                    return;
                }
                if (getArgument(false, false))
                {
                    tempResultComp = mult_comp_img(complexOne, num);
                    print_comp(&tempResultComp);
                }
            }
            else
            {
                printf("Undefined complex\n\n");
            }
        }
    }
    else if (strcmp(command, "mult_comp_comp") == 0)
    {
        arg = getArgument(true, true);
        arg2 = getArgument(true, true);
        if (arg && arg2)
        {
            complexOne = choseComplex(arg, comps);
            compTwo = choseComplex(arg2, comps);
            if (complexOne && compTwo)
            {
                if (getArgument(false, false))
                {
                    mult_comp_comp(complexOne, compTwo);
                }
            }
            else
            {
                printf("Undefined complex\n\n");
            }
        }
    }
    else if (strcmp(command, "abs_comp") == 0)
    {
        arg = getArgument(true, true);
        if (arg)
        {
            complexOne = choseComplex(arg, comps);
            if (complexOne)
            {
                if (getArgument(false, false))
                {
                    abs_comp(complexOne);
                }
            }
            else
            {
                printf("Undefined complex\n\n");
            }
        }
    }
    else if (strcmp(command, "read_comp") == 0)
    {
        arg = getArgument(true, true);
        if (arg)
        {
            complexOne = choseComplex(arg, comps);
            if (complexOne)
            {
                arg = getArgument(true, true);
                if (!arg)
                {
                    return;
                }
                num = atof(arg);
                if (num == 0 && strcmp("0", arg) != 0)
                {
                    printf("parameter is not a number\n\n");
                    return;
                }
                arg2 = getArgument(true, true);
                if (!arg2)
                {
                    return;
                }
                num2 = atof(arg2);
                if (num2 == 0 && strcmp("0", arg2) != 0)
                {
                    printf("parameter is not a number\n\n");
                    return;
                }
                if (getArgument(false, false))
                {
                    read_comp(num, num2, complexOne);
                }
            }
            else
            {
                printf("Undefined complex\n\n");
            }
        }
    }
    else if (strcmp(command, "print_comp") == 0)
    {
        arg = getArgument(true, true);
        if (arg)
        {
            complexOne = choseComplex(arg, comps);
            if (complexOne)
            {
                if (getArgument(false, false))
                {
                    print_comp(complexOne);
                }
            }
            else
            {
                printf("Undefined complex\n\n");
            }
        }
    }
    else if (strcmp(command, "stop") == 0)
    {
        if (getArgument(false, false))
        {
            exit(0);
        }
    }
    else
    {
        printf("Undefined command name\n\n");
        return;
    }
    printf("\n");
}
/*---------------------------------an util func that match the right complex-------------------------------------*/
Complex *choseComplex(char *comp, Complex *comps[6])
{
    if (comp == NULL)
    {
        return NULL;
    }

    switch (*comp)
    {
    case 'A':
        return comps[0];
        break;

    case 'B':
        return comps[1];
        break;

    case 'C':
        return comps[2];
        break;

    case 'D':
        return comps[3];
        break;

    case 'E':
        return comps[4];
        break;

    case 'F':
        return comps[5];
        break;

    default:
        return NULL;
    }
}
/*---------------------------------an util func that check if the line empty-------------------------------------*/
bool emptyLine(char arr[])
{
    char c;
    int index;
    for (index = 0; index < strlen(arr); index++)
    {
        c = arr[index];
        if (c != ' ' && c != '\n' && c != '\t')
        {
            return false;
        }
    }
    return true;
}

/*---------------------------------an util func to add a char into given array-------------------------------------*/
void add(char *char_array, char c)
{
    int len = strlen(char_array);
    char_array[len] = c;
    char_array[len + 1] = '\0';
}

char *lcut(char *s)
{
    while (isspace(*s))
        s++;
    return s;
}

char *rcut(char *s)
{
    char *back = s + strlen(s);
    while (isspace(*--back))
        ;
    *(back + 1) = '\0';
    return s;
}
/*---------------------------------an util func that seperate arguments-------------------------------------*/
char *cut(char *s)
{
    return rcut(lcut(s));
}
/*---------------------------------an util func that gets the arguments needed for a command-------------------------------------*/
char *getArgument(bool shouldHaveText, bool shouldComma)
{
    char *temp = "temp";
    char *arg = strtok(NULL, ",");
    if (arg == NULL)
    {
        if (shouldHaveText)
        {
            printf("Missing parameter\n\n");
            return NULL;
        }
        else
        {
            return temp;
        }
    }
    else if (!shouldHaveText)
    {
        printf("Extraneous text after end of command\n");
        return NULL;
    }
    arg = cut(arg);
    if (strchr(arg, ' '))
    {
        if (shouldComma)
        {
            printf("Missing comma\n\n");
            return NULL;
        }
        else
        {
            printf("Extraneous text after end of command\n");
            return NULL;
        }
    }
    return arg;
}