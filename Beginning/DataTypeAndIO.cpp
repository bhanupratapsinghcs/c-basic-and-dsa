#include <iostream>
using namespace std;
int main()
{
    //  varialbe initializtion & primitive Data Type

    bool boolean;             // size -> 1 byte       => range from true to false
    char character;           // size -> 1 byte       => range from -128 to 127
    signed char chr;          // size -> 1 byte       => range from -128 to 127
    unsigned char unschr;     // size -> 1 byte       => range from 0 to 255
    short int sint;           // size -> 2 byte       => range from -32768 to 32767
    unsigned short int usint; // size -> 2 byte       => range from 0 to 65,535
    unsigned int unint;       // size -> 4 byte       => range from 0 to 4,294,967,295
    int integer;              // size -> 4 byte       => range from -2147483648 to 2147483647
    long int lint;            // size -> 4 byte       => range from -2,147,483,648 to 2,147,483,647
    long long int llint;      // size -> 8 byte       => range from -(2^63) to (2^63)-1
    float flt;                // size -> 4 byte
    double dble;              // size -> 8 byte
    long double ldble;        // size -> 16 byte
    string str;               // size -> 32 byte
    wchar_t w = L'n';         // size -> 2-4 byte

    // for wchar_t :- to support international character
    // => Just like the type for character constants is char, the type for wide character is wchar_t.
    // => This data type occupies 2 or 4 bytes depending on the compiler being used.
    // => Mostly the wchar_t datatype is used when international languages like Japanese are used

    // long long double lldble -> not possible
    // long long long int lllint -> not possible;

    //   variable declaration:-

    boolean = false;
    chr = -123;
    unschr = 4;
    character = 'A';
    integer = 2147483648;
    dble = 45.33877383;
    flt = 4.23F;
    str = "String";

    // input:-

    //  single number or character input

    cin >> integer >> dble;

    // scanf("Enter Variable Valee of float: %f", &flt); // Can't use String in scanf
    scanf("%f", &flt);

    // string input
    // to get input with getline after cin use following code below
    getline(cin >> ws, str);

    //  output:-

    //  sizeof method:-

    cout << sizeof(wchar_t);

    // variable call

    //Some C++ data types, their format specifiers, and their most common bit widths are as follows:

    // Int ("%d"): 32 Bit integer
    // Long ("%ld"): 64 bit integer
    // Char ("%c"): Character type
    // Float ("%f"): 32 bit real value
    // Double ("%lf"): 64 bit real value

    printf("PrintF integer: %d \n", integer);
    printf("PrintF Float: %f\n", flt);

    cout << "boolean: " << boolean << endl;
    cout << "char: " << character << endl;
    cout << "signed char: " << chr << endl;
    cout << "unsigned char: " << unschr << endl;
    cout << "integer: " << integer << endl;
    cout << "double: " << dble << endl;
    cout << "float: " << flt << endl;
    cout << "String: " << str << endl;

    return 0;

} // namespace std
