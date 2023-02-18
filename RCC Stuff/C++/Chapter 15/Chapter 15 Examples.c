/******************** Example 15.6.1 *******************/
FILE * input;
FILE * fout;
FILE * data;
input = fopen ( "filename.dat", "rb" );
fout = fopen ( "filename.dat", "w+b" );
data = fopen ( "c:\\data.dat", "ab" );

/******************** Example 15.6.2 *******************/
typedef struct
{
    char name[30];
    short int age;
} EMP;
#define NUM_EMPLOYEES 3
...
int main ( )
{
    EMP ray[NUM_EMPLOYEES];
    FillArrayFromKeyboard ( ray );
    WriteToFile ( ray );
    ReadFromFile ( ray );
    PrintArray ( ray );
    return 0;
}
void WriteToFile ( EMP ray[] )
{
    FILE * fout;
    fout = fopen ( "binary.bin", "wb" );
    if ( fout != NULL )
    {
        fwrite ( ray, sizeof ( EMP ), NUM_EMPLOYEES, fout );
        fclose ( fout );
    }
    else
        printf ( "File not opened\n" );
}
void ReadFromFile ( EMP ray[] )
{
    size_t num_items = 0;
    FILE * fin;
    fin = fopen ( "binary.bin", "rb" );
    if ( fin != NULL )
    {
        num_items = fread ( ray, sizeof ( EMP ), NUM_EMPLOYEES, fin );
        fclose ( fin );
        printf ( "Number of bytes read is: %d", num_items );
    }
    else
        printf ( "File not opened\n" );
}
/******************** Example 15.6.3 *******************/
void LocateAndModifyRecord ( )
{
    EMP temp;
    // Opening the stream for both input and output
    FILE * empFile = fopen ( "binary.bin", "r+b" );
    if ( empFile != NULL )
    {
        // Move to the beginning of the file
        rewind ( empFile );

        // Move FPM to second record from the front 
        fseek ( empFile, sizeof ( EMP ), SEEK_SET );
        printf ( "\n* Currently at postion: %ld", ftell ( empFile ) );

        fread ( &temp, sizeof ( EMP ), 1, empFile );
        printf ( "\n* The name in the second record is: %s", temp.name );
        printf ( "\n* The age in the second record is: %d", temp.age );

        // Move FPM 0 bytes from beginning of the stream
        fseek ( empFile, 0, SEEK_SET );

        strcpy ( temp.name, "Jamie" );
        temp.age = 41;

        // Write updated data into current (first) position
        fwrite ( &temp, sizeof ( EMP ), 1, empFile );
        fclose ( empFile );
    }
    else
        printf ( "File not opened" );
}
