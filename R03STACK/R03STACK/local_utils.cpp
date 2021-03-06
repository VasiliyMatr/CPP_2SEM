
bool isBadPtr( const void* ptr )
{
    MEMORY_BASIC_INFORMATION mbi = {0};
    if (::VirtualQuery (ptr, &mbi, sizeof (mbi)))
    {
        DWORD mask = (PAGE_READONLY     | PAGE_READWRITE            | PAGE_WRITECOPY | 
                        PAGE_EXECUTE_READ | PAGE_EXECUTE_READWRITE    | PAGE_EXECUTE_WRITECOPY);

        bool bad = !(mbi.Protect & mask);
        /* check the page is not a guard page */
        if (mbi.Protect & (PAGE_GUARD | PAGE_NOACCESS))
            bad = true;

        return bad;
    }

    return true;
}

hash_t hashF( const void* toHash, const size_t numOfBytes )
{
    if (toHash == nullptr)
    {
        /* Bad ptr to hashable sequence. */
        CRIT_ERROR_OUT_ ("BAD toHash ptr!");
        return rand ();
    }

    if (numOfBytes == 0)
    {
        /* Zero sequence size */
        CRIT_ERROR_OUT_ ("0 size of hashable value!");
        return rand ();
    }

    /* Hashing stuff */

        const size_t byte_move = sizeof (hash_t) - 1;
        int hash = HASH_INIT_;

        for (size_t i = 0; i < numOfBytes; i++)
        {
            hash = (-hash * *((char* )toHash + i) + hash >> byte_move ^ hash << 1) + hash - i;
        }
    /* ************* */

    return hash;
}

int getPoison( int* )
{
    return 0xF00DF00D;
}

double getPoison( double* )
{
    return NAN;
}