/*
    code style formats:

    CONSTANT_OR_DEFINE_FORMAT_
    ClassOrStructFormat         (with methods)
    dataTypeFormat_t            (only data)
    varFormat
    methodFormat
    classFieldsFormat_

*/

#include "local_utils.h"

/* all project dbg off/on (to use less memory in release) */
#define PRJ_STK_DBG_ON_ true

#include "stack.h"

int main()
{

    /* just some speed and debug tests */

        /* num of cycles */
        const size_t cycles = 8192;

        /* for error out */
        Stack::err_t    stkError = Stack::err_t::OK_;

        /* stacks with diff dbg modes */
            Stack test;
            Stack testOFF   (Stack::dbgMode_t::DBG_OFF_);
            Stack testCAN   (Stack::dbgMode_t::DBG_CAN_);
            Stack testFULL  (Stack::dbgMode_t::DBG_FULL_);

            /* hash test */
        for (int i = 0; i < cycles; i++)
            testFULL.push (i, &stkError);
        for (int i = 0; i < cycles; i++)
            testFULL.pop (&stkError);

            /* canary test */
        for (int i = 0; i < cycles; i++)
            testCAN.push (i, &stkError);
        for (int i = 0; i < cycles; i++)
            testCAN.pop (&stkError);

            /* only standart errors check */
        for (int i = 0; i < cycles; i++)
            testOFF.push (i, &stkError);
        for (int i = 0; i < cycles; i++)
            testOFF.pop (&stkError);

            /* fastest var */
        for (int i = 0; i < cycles; i++)
            test.push (i);
        for (int i = 0; i < cycles; i++)
            test.pop ();

    /* ******************************* */

    return 0;
}