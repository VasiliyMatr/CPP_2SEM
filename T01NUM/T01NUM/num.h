#include <cstdlib>
#include <cstdio>
#include <cmath>

#ifndef NUM_INCLUDED_
#define NUM_INCLUDED_

/* Joke class to learn how to work with overloaded operators */
class Number {

private: /* DATA TYPES */

    /* stor value type */
    typedef int num_t;

private: /* FIELDS */

    /* this number value */
        num_t value_ = 0;

public:  /* METHODS */

    /* Number c-tor with value */
        Number( num_t value );
    /* Copy c-tor */
        Number( const Number& toCopy );
    /* D-tor with info out */
       ~Number();

/* operators decls */
    /* cast operator - only for bool */
        operator bool();

    /* ariph operators */
        Number operator +( const Number& rv );
        Number operator -( const Number& rv );
        Number operator *( const Number& rv );
        Number operator /( const Number& rv );

    /* logical operators */
        Number operator > ( const Number& rv );
        Number operator < ( const Number& rv );
        Number operator >=( const Number& rv );
        Number operator <=( const Number& rv );
        Number operator ==( const Number& rv );
        Number operator !=( const Number& rv );

    /* = operator */
        Number operator =( const Number& rv );

};

#endif