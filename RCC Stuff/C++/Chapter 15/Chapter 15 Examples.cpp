/******************** Example 15.2.1 *******************/
ifstream input ( "filename.bin", ios::binary );

ofstream fout;
fout.open ( "filename.bin", ios::out | ios::binary );

ofstream data ( "c:\\data.bin", ios::out | ios::app | ios::binary );

/******************** Example 15.3.1 *******************/
struct EMP
{
    char name[30]; // Use cString not dynamic
    short int age;
};
const short int NUM_EMPLOYEES = 3;
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
    ofstream fout ( "binary.bin", ios::out | ios::binary );
    if ( fout.is_open ( ) )
    {
        fout.write ( reinterpret_cast <char *> (ray),
            sizeof ( EMP ) * NUM_EMPLOYEES );
        fout.close ( );
    }
    else
        cout << "File not opened" << endl;
}
void ReadFromFile ( EMP ray[] )
{
    ifstream fin ( "binary.bin", ios::in | ios::binary );
    if ( fin.is_open ( ) )
    {
        fin.read ( reinterpret_cast <char *>(ray),
            sizeof ( EMP ) * NUM_EMPLOYEES );
        cout << "Number of bytes read is: " << fin.gcount ( );
        fin.close ( );
    }
    else
        cout << "File not opened" << endl;
}

/******************** Example 15.4.1 *******************/
fout.write ( reinterpret_cast<char *>(&num_faculty), sizeof ( num_faculty ) );

/******************** Example 15.4.2 *******************/
// Get length of name including '\0'
str_length = strlen ( ray[i].name ) + 1;

// Write out length of name
fout.write ( reinterpret_cast<char *>(&str_length), sizeof ( str_length ) );

/******************** Example 15.4.3 *******************/
// Write out the name string (Note: we do not need a reinterpret cast here)
fout.write ( ray[i].name, str_length );

/******************** Example 15.4.4 *******************/
// Get length of department including '\0'
str_length = strlen ( ray[i].department ) + 1;

// Write out length of department
fout.write ( reinterpret_cast<char *>(&str_length), sizeof ( str_length ) );

/******************** Example 15.4.5 *******************/
// Write out the department string 
fout.write ( ray[i].department, str_length );

/******************** Example 15.4.6 *******************/
// First need to read how many elements in dynamic array and create ray
fin.read ( reinterpret_cast<char *>(&num_faculty), sizeof ( num_faculty ) );
ray = new Faculty[num_faculty];

/******************** Example 15.4.7 *******************/
// Read in the length of name and create the memory
fin.read ( reinterpret_cast<char *>(&length), sizeof ( length ) );
ray[i].name = new char[length];

// Now read in the name into the array
fin.read ( ray[i].name, length );

/******************** Example 15.4.8 *******************/
// Read in the length of department and create the memory
fin.read ( reinterpret_cast<char *>(&length), sizeof ( length ) );
ray[i].department = new char[length];

// Now read in the department into the array
fin.read ( ray[i].department, length );

/******************** Example 15.4.9******************/
// Please see the entire solution in the book's files.

/******************** Example 15.5.1******************/
ifstream fin ( "c:\\temp\\students.dat", ios::in | ios::binary );
...
fin.read ( reinterpret_cast<char *>(student_array), sizeof ( STUDENT ) * 2 );
long int pointer_position = fin.tellg ( );

/******************** Example 15.5.2******************/
fin.seekg ( sizeof ( STUDENT ) * 2 );
fin.seekg ( 10, ios::cur );

/******************** Example 15.5.3******************/
void LocateAndModifyRecord ( )
{
    EMP temp;
    // Opening the stream for both input and output
    fstream empFile ( "binary.bin", ios::in | ios::out |
        ios::binary | ios::ate );

    if ( empFile.is_open ( ) )
    {
        // Move FPM to second record from the front 
        empFile.seekp ( sizeof ( EMP ) * 1 );
        cout << "\n* Currently at postion: " << empFile.tellp ( );

        empFile.read ( reinterpret_cast <char *>(&temp),
            sizeof ( EMP ) );
        cout << "\n* The name in the second record is: " << temp.name;
        cout << "\n* The age in the second record is: " << temp.age;

        // Move FPM 0 bytes from beginning of the stream
        empFile.seekg ( 0, ios::beg );

        strcpy ( temp.name, "Jamie" );
        temp.age = 41;

        // Write updated data into current (first) position
        empFile.write ( reinterpret_cast <char *>(&temp),
            sizeof ( EMP ) );
        empFile.close ( );
    }
    else
        cout << "File not opened" << endl;
}
