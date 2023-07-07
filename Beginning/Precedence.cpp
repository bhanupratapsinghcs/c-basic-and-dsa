#include <iostream>
using namespace std;
int fe(int n)
{
    cout << n << endl;
    return n;
}
// look at this for more information -> https://www.ibm.com/docs/en/zos/2.4.0?topic=operators-operator-precedence-associativity
// -> https://www.ibm.com/docs/en/zos/2.4.0?topic=SSLTBW_2.4.0/com.ibm.zos.v2r4.cbclx01/exampl_of_exprs_and_precedence.htm
int main()
{
    // Postfix	        () [] -> . ++ - -	                Left to right
    // Unary            + - ! ~ ++ - - (type)* & sizeof	    Right to left
    // Multiplicative	* / %	                            Left to right
    // Additive	         + -	                            Left to right
    // Shift	        << >>	                            Left to right
    // Relational	    < <= > >=	                        Left to right
    // Equality	         == !=/td>	                        Right to left
    // Bitwise AND	    &	                                Left to right
    // Bitwise XOR	    ^	                                Left to right
    // Bitwise OR	    |	                                Right to left
    // Logical AND	    &&	                                Left to right
    // Logical OR	    ||	                                Left to right
    // Conditional	    ?:	                                Right to left
    // Assignment	    = += -= *= /= %=>>= <<= &= ^= |=	Right to left
    // Comma	        ,	                                Left to right

    int a = 1, b = 2, c = 4;
    //int e = 1 = 2 = 3;        //not possible lvalue required as left operand of assignment
    //int e + 1 = 12;           // 1=12 not possible

    int d = a = b;               // right to left associativity
    int dd = a = b = 2;          // value of rightest willassign to leftest
                                 // (d=(a=b)) ->Evaluated as a=b then d=a
    d = a -= b += c;             // (d = (a -= (b += c)))
    cout << a << b << d << endl; //-4 6 -4

    c = 3, 6, 7;                         // Comma has the least precedence among alloperators
                                         // Evaluated as (c = 3), 6, 7
    cout << c << endl;                   // 3
    int f = (4) * (5) / (2) + (6) / (3); // 4.->((2.->(1.->(4) * (5)) / (2)) + 3.->((6) / (3)))
    cout << f << endl;

    cout << c++ + c++ + ++c << endl; // evaluated as c->3->4->6 =>cout->3+4+6=>13
    // c = c++ + c++ + ++c;
    cout << "a: " << a << " b: " << b << " c: " << c << endl;
    cout << a - b - +c << endl; // ((a-b)-(+c))
    cout << a++ << ++b << --c << endl;
    cout << a << b << c << endl;
    a = 6 / 5 * 4 / 2; // ((6/5)*4)/2
    cout << a << endl;
}