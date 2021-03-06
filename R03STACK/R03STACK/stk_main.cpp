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
        auto stkError = AbstractStack::err_t::OK_;

        /* stacks with diff dbg modes */
            Stack<int> test;
            Stack<int> testOFF   (AbstractStack::dbgMode_t::DBG_OFF_);
            Stack<double> testCAN   (AbstractStack::dbgMode_t::DBG_CAN_);
            Stack<int> testFULL  (AbstractStack::dbgMode_t::DBG_FULL_);

            /* hash test */
        for (int i = 0; i < cycles; i++)
            testFULL.push (i, &stkError);

        testFULL.dump (false);

        for (int i = 0; i < cycles; i++)
            testFULL.pop (&stkError);

            /* canary test */
        for (int i = 0; i < cycles; i++)
            testCAN.push (i, &stkError);

        testCAN.dump(false);

        for (int i = 0; i < cycles; i++)
            testCAN.pop (&stkError);

            /* only standart errors check */
        for (int i = 0; i < cycles; i++)
            testOFF.push (i, &stkError);

        testOFF.dump(false);

        for (int i = 0; i < cycles; i++)
            testOFF.pop (&stkError);

            /* fastest var */
        for (int i = 0; i < cycles; i++)
            test.push (i);

        test.dump(false);

        for (int i = 0; i < cycles; i++)
            test.pop ();

    /* ******************************* */

    return 0;
}