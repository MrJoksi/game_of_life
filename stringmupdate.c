/***************************************************************************
 *   Copyright (C) 2023 by Elmeri Sievänen   *
 *   e2203113@edu.vamk.fi   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
/*********************************************************************

 1.  Stringm


 2.  String and file manipulation


 3.  VERSIONS
       Original:
         28.3.2023 

       Version history: None

**********************************************************************/
/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
/*-------------------------------------------------------------------*
*    GLOBAL VARIABLES AND CONSTANTS                                  *
*--------------------------------------------------------------------*/
#define MAX_LENGTH_STRING 50
#define FILENAME "stringfilu.txt"
/*-------------------------------------------------------------------*
*    FUNCTION PROTOTYPES                                             *
*--------------------------------------------------------------------*/
void display_menu(void);
char ask_command(void);
void read_string(char string[]);
void print_string(char string[]);
int count_vowels(char string[]);
int count_consonant(char string[]);
void to_lower(char string[]);
void to_upper(char string[]);
void read_file(char string[]);
void write_file(char string[]);
/*********************************************************************
*    MAIN PROGRAM                                                      *
**********************************************************************/
int main(void)
{
    char current_string[MAX_LENGTH_STRING] = "Hello world!";
    char character;
    display_menu();
    while (character != 'X')//Runs as long as "char string" isn't 'X(ascii 88)
    {
        printf("Give command:");
        character = ask_command();
        if (character == 'E')
        {
            print_string(current_string);
        }
        else if (character == 'F')
        {
            read_string(current_string);
        }
        else if(character == 'A')
        {
            int vowel_count = count_vowels(current_string);
            printf("%d\n",vowel_count);
        }
        else if(character == 'B')
        {
            int count = count_consonant(current_string);
            printf("%d\n",count);

        }
        else if(character == 'C')
        {
           to_upper(current_string);
        }
        else if(character == 'D')
        {
            to_lower(current_string);
        }
        else if(character == 'G')
        {
            read_file(current_string);
        }
        else if(character == 'H')
        {
            write_file(current_string);
        }
        else if(character == 'M')
        {
            display_menu();
        }
    } 
}
/*********************************************************************
*    FUNCTIONS                                                       *
**********************************************************************/
/*********************************************************************
 NAME:display_menu
 DESCRIPTION:displays controls and caption
	Input:none
	Output:prints description
  Used global variables:none
 REMARKS when using this function:none
*********************************************************************/
void display_menu(void)
{   printf(" __        ______        _______. _______    ____    ____  ______    __    __  .______         .___  ___.  __  .__   __.  _______      __  .__   __.      ______ \n");
    printf("|  |      /  __  \\      /       ||   ____|   \\   \\  /   / /  __  \\  |  |  |  | |   _  \\        |   \\/   | |  | |  \\ |  | |       \\    |  | |  \\ |  |     /      |\n");
    printf("|  |     |  |  |  |    |   (----`|  |__       \\   \\/   / |  |  |  | |  |  |  | |  |_)  |       |  \\  /  | |  | |   \\|  | |  .--.  |   |  | |   \\|  |    |  ,----'\n");
    printf("|  |     |  |  |  |     \\   \\    |   __|       \\_    _/  |  |  |  | |  |  |  | |      /        |  |\\/|  | |  | |  . `  | |  |  |  |   |  | |  . `  |    |  |     \n");
    printf("|  `----.|  `--'  | .----)   |   |  |____        |  |    |  `--'  | |  `--'  | |  |\\  \\----.   |  |  |  | |  | |  |\\   | |  '--'  |   |  | |  |\\   |    |  `----.\n");
    printf("|_______| \\______/  |_______/    |_______|       |__|     \\______/   \\______/  | _| `._____|   |__|  |__| |__| |__| \\__| |_______/    |__| |__| \\__|     \\______|\n");
    printf("\n\n");
    printf("A) Count the number of vowels in string\n");
    printf("B) Count the number of constants in the string\n");
    printf("C) Convert the string to uppercase\n");
    printf("D) Convert the string to lowercase\n");
    printf("E) Display the current string\n");
    printf("F) Enter another string\n");
    printf("G) Read string from file\n");
    printf("H) Write string to file\n\n");
    printf("M) Display this menu\n");
    printf("X) Exit this program\n");
}
/*********************************************************************
 NAME:print_string
 DESCRIPTION:prints out current string
	Input:string to be printed
	Output:string
  Used global variables:none
 REMARKS when using this function:none
*********************************************************************/
void print_string(char print_str[])
{
    printf("%s\n",print_str);
}
/*********************************************************************
 NAME:ask_command
 DESCRIPTION:asks user command and sends result back to main function
	Input:none
	Output:letter as log its between A-Z
  Used global variables:none
 REMARKS when using this function:function accepts low and uppercase letters.
*********************************************************************/
char ask_command(void)
{
    char str[6];
    int i;
    char ret_char;
    while (i != 1)
    {
        fgets(str,6,stdin);
        ret_char = toupper(str[0]);
        if (ret_char > 64 && ret_char < 91)
        {
            i = 1;
        }
        
    }
    return ret_char;   
}
 /*********************************************************************
 NAME:read_string
 DESCRIPTION: asks user new string.
	Input:currents string
	Output:
  Used global variables:MAX_LENGTH_STRING
 REMARKS when using this function:maximum characters to give is 50
*********************************************************************/
void read_string(char string[])
{
    printf("Give string: ");
    fgets(string,MAX_LENGTH_STRING,stdin);
}
/*********************************************************************
 NAME:count_vowels
 DESCRIPTION:counts how many wovels is in current string
	Input:current string
	Output:number of vowels in given string
  Used global variables:none
 REMARKS when using this function:none
*********************************************************************/
int count_vowels(char string[])
{
    int string_length = strlen(string);
    int vowel_amount = 0;
    for (int i = 0; i < string_length; i++)
    {
        switch (toupper(string[i]))
        {
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
        case 'Y':
            vowel_amount += 1;
            break;
        }  
    }
    return vowel_amount;
}
/*********************************************************************
 NAME:to_upper
 DESCRIPTION:makes all letters in string uppercase
	Input:current string
	Output:
  Used global variables:MAX_LENGTH_STRING
 REMARKS when using this function: Already uppercase letters stay uppercase
*********************************************************************/
void to_upper(char up_string[])
{
    char temp[MAX_LENGTH_STRING];
    for(int x = 0; x < MAX_LENGTH_STRING;x++)
    {
        up_string[x] = toupper(up_string[x]);
    }
}
/*********************************************************************
 NAME:to_lower
 DESCRIPTION:makes all letters in string lowercase
	Input:current string
	Output:
  Used global variables:MAX_LENGTH_STRING
 REMARKS when using this function:Already lowercase letters stay lowercase
*********************************************************************/
void to_lower(char low_string[])
{
   char temp[MAX_LENGTH_STRING];
    for(int x = 0; x < MAX_LENGTH_STRING;x++)
    {
        temp[x] = tolower(low_string[x]);
        low_string[x] = temp[x];
    } 
}
/*********************************************************************
 NAME:count_consonats
 DESCRIPTION:counts all consonats in current string
	Input:current string
	Output:amount of consonants
  Used global variables:none
 REMARKS when using this function:none
*********************************************************************/
int count_consonant(char string[])
{
    int string_length = strlen(string);
    int consonant_amount = 0;
    for (int i = 0; i < string_length; i++)
    {
        switch (toupper(string[i]))
        {
        case 'B':
        case 'C':
        case 'D':
        case 'F':
        case 'G':
        case 'H':
        case 'J':
        case 'K':
        case 'L':
        case 'M':
        case 'N':
        case 'P':
        case 'Q':
        case 'R':
        case 'S':
        case 'T':
        case 'V':
        case 'W':
        case 'X':
        case 'Z':
            consonant_amount += 1;
            break;
        }  
    }
    return consonant_amount;
}
/*********************************************************************
 NAME:read_file
 DESCRIPTION:makes current string to be same as text in file
	Input:current string
	Output:
  Used global variables:MAX_LENGTH_STRING
 REMARKS when using this function:if there is problem opening file
 function prints error text
*********************************************************************/
void read_file(char string[])
{
    FILE *file_pointer;
    file_pointer = fopen(FILENAME,"r");
    if (file_pointer == 0)
    {
        printf("Error in code");
    }
    else
    {
        fgets(string,MAX_LENGTH_STRING,file_pointer);
    }
    fclose(file_pointer);
}
/*********************************************************************
 NAME:write_file
 DESCRIPTION:prints current string to a file
	Input:current file
	Output:
  Used global variables:none
 REMARKS when using this function:if there is problem opening file
 function prints error text
*********************************************************************/
void write_file(char string[])
{
    FILE *file_pointer;
    file_pointer = fopen(FILENAME,"w");
    if (file_pointer == 0)
    {
        printf("Error in code");
    }
    else
    {
        fprintf(file_pointer,"%s",string);
    }
    fclose(file_pointer);
}