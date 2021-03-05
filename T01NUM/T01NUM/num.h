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

    /* licence counters init */
        #define DEF_BIN_OP( OP_, NAME_, INIT_VAL_ ) \
        int count##NAME_ = INIT_VAL_;
        #define DEF_LOG_OP( OP_, NAME_, INIT_VAL_ ) \
        int count##NAME_ = INIT_VAL_;
        #define DEF_UNR_OP( OP_, NAME_, INIT_VAL_ ) \
        int count##NAME_ = INIT_VAL_;

        int countAssign = 0x2;

        #include "DSL.h"

        #undef DEF_BIN_OP
        #undef DEF_LOG_OP
        #undef DEF_UNR_OP

public:  /* METHODS */

    /* value c-tor */
        Number( const num_t value ) : value_(value) {};

    /* operators defines */
        #define DEF_BIN_OP( OP_, NAME_, INIT_VAL_ )     \
        const Number operator##OP_(const Number& rv)    \
        { return value_ OP_ rv.value_; }

        #define DEF_LOG_OP( OP_, NAME_, INIT_VAL_ )     \
        Number operator##OP_(const int rv)          \
        { return value_ OP_ rv; }

        //#define DEF_UNR_OP( OP_, NAME_, INIT_VAL_ )     \
        //const Number operator##OP_() const              \
        //{ return value_ OP_; }

        #include "DSL.h"

        #undef DEF_BIN_OP
        //#undef DEF_UNR_OP
        #undef DEF_LOG_OP

    /* to get value */
        const num_t  operator!()
        { return value_; }

    /* = operator */
        const Number operator=( const Number& rv )
        { return value_ = rv.value_; }

    /* cast operators */
        operator bool()
        { return (bool)value_; }
        operator int()
        { return value_; }

};

#endif