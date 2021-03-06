#include "num.h"

/* some coloring stuff */
#define _RED     "\x1b[31m"
#define _GRN     "\x1b[32m"
#define _YEL     "\x1b[33m"
#define _BLU     "\x1b[34m"
#define _MAG     "\x1b[35m"
#define _CYN     "\x1b[36m"
#define _RST     "\x1b[0m"

static size_t CALL_DEPTH_ = 8;

Number::Number( num_t value ) : value_(value)
{
    printf (_GRN "%*c CTOR(VAL) WAS CALLED - NEW ADDR : %X " "\n" _RST, CALL_DEPTH_, '>', this);
}

Number::Number( const Number& toCopy )
{
    printf(_YEL "%*c CTOR(CPY) WAS CALLED - NEW ADDR : %X " "\n" _RST, CALL_DEPTH_, '>', this);

    value_ = toCopy.value_;
}

Number::~Number()
{
    printf(_RED ">DTOR WAS CALLED - ADDR : %X " "\n" _RST, this);
}

/* bool cast operator */
    Number::operator bool()
    { return (bool)value_; }


#define BIN_OP_ACTION( OP_TYPE_ )                                           \
    printf("%*c OPERATION \"%s\" WAS MADE WITH %X AND %X" "\n" ,            \
        CALL_DEPTH_, '>', #OP_TYPE_, this, &rv);                            \
                                                                            \
    CALL_DEPTH_ += 4;                                                       \
    Number tmp = value_ OP_TYPE_ rv.value_;                                 \
    CALL_DEPTH_ -= 4;                                                       \
    return tmp


/* ariph operators */
    Number Number::operator +( const Number& rv )
    { BIN_OP_ACTION (+); }

    Number Number::operator -( const Number& rv )
    { BIN_OP_ACTION (-); }

    Number Number::operator *( const Number& rv )
    { BIN_OP_ACTION (*); }

    Number Number::operator /( const Number& rv )
    { BIN_OP_ACTION (/); }

/* logical operators */
    Number Number::operator > ( const Number& rv )
    { BIN_OP_ACTION (>); }
    Number Number::operator < ( const Number& rv )
    { BIN_OP_ACTION (<); }
    Number Number::operator >=( const Number& rv )
    { BIN_OP_ACTION (>=); }
    Number Number::operator <=( const Number& rv )
    { BIN_OP_ACTION (<=);}
    Number Number::operator ==( const Number& rv )
    { BIN_OP_ACTION (==); }
    Number Number::operator !=( const Number& rv )
    { BIN_OP_ACTION (!=); }

/* = operator */
    Number Number::operator =( const Number& rv )
    { 
        printf("%*c OPERATOR \"=\" WAS CALLED FOR %X WITH %X" "\n", 
            CALL_DEPTH_, '>', this, &rv);

        CALL_DEPTH_ += 4;
        Number tmp = value_ = rv.value_;
        CALL_DEPTH_ -= 4;

        return tmp;
    }

#undef BIN_OP_ACTION

#undef _RED
#undef _GRN
#undef _YEL
#undef _BLU
#undef _MAG
#undef _CYN
#undef _RST