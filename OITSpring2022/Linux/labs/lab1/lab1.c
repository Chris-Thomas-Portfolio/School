/*******************************************************************
 * Author: Chris Thomas
 * Date: 4/3/2022
 * Assignment: Lab1
 * Discription: Read in a file and either write it to another file
 * or display it out to the console. Also be able to parse args
 * -h, -f, -o, -c.
 * *****************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
// argument parse function declaration
void parsearg(int argc, char **argv, char *read_file, char *write_file, int *lines);

int main(int argc, char **argv)
{
    //initilizing of all variables needed for program
    int hours;
    float salary;
    float gross;
    char first [50];
    char last [50];
    int lines = -1;
    char buffer [100] = "";
    char read_file [50] = "payroll.txt";
    char write_file [50] = "default";
    FILE *read;
    FILE *write;
    parsearg(argc,argv, read_file, write_file, &lines); //call the parsearg function to set up program
    read = fopen(read_file, "r");                       //set the file that we will read from
    if(strncmp(write_file, "default", sizeof(write_file)) != 0) //check if a write file was given
    {
        write = fopen(write_file, "w");                         //if one was open it for writing
        if (read != NULL && write != NULL)
        {
            if(lines == -1)                                     //check if a line limit was given
            {
                while ((fscanf(read, "%s", first)) == 1)       //if not scan and write entire file
                {
                    fprintf(write, "%-10s", first);
                    fscanf(read, "%s", last);
                    fprintf(write, "%-10s", last);
                    fscanf(read, "%d", &hours);
                    fprintf(write, "%-10d", hours);
                    fscanf(read, "%f", &salary);
                    fprintf(write, "%-10.2f", salary);
                    gross = (salary * hours);
                    fprintf(write, "%-10.2f\n", gross);
                }
                fclose(read);                                   //close both files when done
                fclose(write);
            }
            else
            {
                for(int i = 0; i < lines; i = i + 1)            //if a limit was given only write that many lines
                {
                    fscanf(read, "%s", first);
                    fprintf(write, "%-10s", first);
                    fscanf(read, "%s", last);
                    fprintf(write, "%-10s", last);
                    fscanf(read, "%d", &hours);
                    fprintf(write, "%-10d", hours);
                    fscanf(read, "%f", &salary);
                    fprintf(write, "%-10.2f", salary);
                    gross = (salary * hours);
                    fprintf(write, "%-10.2f\n", gross);
                }
                fclose(read);                                   //close both files when done
                fclose(write);
            }   
        }
        else
        {
            printf("Failed to open file");                      //display error message if file did not open
        }
    }
    else
    {
        if(read != NULL)                                        //make sure file opened properly
        {
            if(lines == -1)                                     //check for line limit
            {
                while ((fscanf(read, "%s", first)) == 1)       //if no limit read entire file and display to console
                {
                    printf("%-10s", first);
                    fscanf(read, "%s", last);
                    printf("%-10s", last);
                    fscanf(read, "%d", &hours);
                    printf("%-10d", hours);
                    fscanf(read, "%f", &salary);
                    printf("%-10.2f", salary);
                    gross = (salary * hours);
                    printf("%-10.2f\n", gross);
                }
                fclose(read);                                   //close file when done
            }
            else
            {
                for(int i = 0; i < lines; i = i + 1)            //if limit was given only read that many lines
                {                                               //and display to console
                    fscanf(read, "%s", first);
                    printf("%-10s", first);
                    fscanf(read, "%s", last);
                    printf("%-10s", last);
                    fscanf(read, "%d", &hours);
                    printf("%-10d", hours);
                    fscanf(read, "%f", &salary);
                    printf( "%-10.2f", salary);
                    gross = (salary * hours);
                    printf("%-10.2f\n", gross);
                }
                fclose(read);                                   //close file when done
            }
        }   
        else
        {
            printf("Failed to open file");                      //print error message if file did not open
        }
    }
    return 0;
}
/*******************************************************************
 * Purpose: Handle the different file manipulation arguments
 * 
 * Pre-Condition: N/A
 *
 * Post-condition: Sets the write file name, read file name, lines 
 *                  to read limit, or displays help message.
 * *****************************************************************/
#
void parsearg(int argc, char **argv, char *read_file, char *write_file, int *lines)
{
    int option;


    while ( (option=getopt(argc, argv, "f:o:c:h")) != -1)
    {
        switch (option)
        {
            //h case display the help message
            case 'h':
                printf("Help Message:\n");
                printf("-f Specify the name of file to operate on, if none selected default file name payroll.txt.\n");
                printf("-o Specify the name of the file to output\n");
                printf("-c Specify the number of records to read from the input file\n");
                printf("-h Print help message that lists the command line args\n");
                exit(1);
                break;
            //o case set the write string to the string given
            case 'o':
                {
                    strcpy(write_file, optarg);
                    break;
                }
            //f case set the read sring to the string given
            case 'f':
                {
                    strcpy(read_file, optarg);
                    break;
                }
            //c case set the value of the lines to be read/written limit
            case 'c':
                {
                    *lines = atoi(optarg);
                    break;
                }
        }
    }
}
