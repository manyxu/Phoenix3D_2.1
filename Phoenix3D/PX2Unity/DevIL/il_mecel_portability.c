#if defined (QNX) || defined(__INTEGRITY)
#include <wchar.h>
int wcsncasecmp(const wchar_t *s1, const wchar_t *s2, size_t n) 
{
    while (n--) 
    {
        wint_t c1 = towlower(*s1);
        wint_t c2 = towlower(*s2);
        wint_t diff = c1 - c2;

        if (diff != 0) 
        {
            return diff;
        }
        if (!c1) 
        {
            return 0;
        }
        ++s1;
        ++s2;
    }
    return 0;
}

/** 
 *
 * The wcscasecmp() function is the wide-character equivalent of the
 * strcasecmp(3) function. It compares the wide-character string pointed to by
 * s1 and the wide-character string pointed to by s2, ignoring case differences
 * (towupper(3), towlower(3)).
 *
 * @note this functions isn't safe if the strings isn't null terminated.
 *
 * @param s1 first string
 * @param s2 second string
 * @return The wcscasecmp() function returns zero if the wide-character strings
 *         at s1 and s2 are equal except for case distinctions. It returns a
 *         positive integer if s1 is greater than s2, ignoring case. It returns
 *         a negative integer if s1 is smaller than s2, ignoring case.
 */
int wcscasecmp(const wchar_t *s1, const wchar_t *s2) 
{
    do {
        wint_t c1 = towlower(*s1);
        wint_t c2 = towlower(*s2);
        wint_t diff = c1 - c2;
        if (diff != 0) 
        {
            return diff;
        }
        if (!c1) 
        {
            return 0;
        }
        ++s1;
        ++s2;
    } while(1);
}

#endif

#ifndef _WIN32
#ifdef UNICODE
#include <stdio.h>
#include <wchar.h>
#include <limits.h>

#define UNICODE_CHARS (sizeof(wchar_t) >= 4 ? 0x110000 : 0xFFFE)

size_t wchar2utf8(const wchar_t *srcStr, size_t inputSize, char *dstStr, size_t destSize )
{
    size_t i;
    unsigned char *s = (unsigned char *) dstStr;
    unsigned char *t = s;

    for (i = 0; (i < inputSize) && ((t-s) < destSize); i++)
    {
        wchar_t wc = srcStr[i];
        if (wc <= 0x7F)
        {           /* 7 sig bits */
            *t++ = wc;
        }
        else if (wc <= 0x7FF)
        {           /* 11 sig bits */
            *t++ = 0xC0 | (unsigned char) (wc >> 6);    /* upper 5 bits */
            *t++ = 0x80 | (unsigned char) (wc & 0x3F);  /* lower 6 bits */
        }
        else if (wc <= 0xFFFF)
        {           /* 16 sig bits */
            *t++ = 0xE0 | (unsigned char) (wc >> 12);   /* upper 4 bits */
            *t++ = 0x80 | (unsigned char) ((wc >> 6) & 0x3F);   /* next 6 bits */
            *t++ = 0x80 | (unsigned char) (wc & 0x3F);  /* lowest 6 bits */
        }
        else if (wc < UNICODE_CHARS)
        {           /* 21 sig bits */
            *t++ = 0xF0 | (unsigned char) ((wc >> 18) & 0x07);  /* upper 3 bits */
            *t++ = 0x80 | (unsigned char) ((wc >> 12) & 0x3F);  /* next 6 bits */
            *t++ = 0x80 | (unsigned char) ((wc >> 6) & 0x3F);   /* next 6 bits */
            *t++ = 0x80 | (unsigned char) (wc & 0x3F);  /* lowest 6 bits */
        }
    }
    *t = 0;

    return (t - s);
}

FILE *_wfopen( 
        const wchar_t *filename,
        const wchar_t *mode 
        )
{
    char namebuffer[PATH_MAX];
    char modebuffer[PATH_MAX];
    wchar2utf8(filename, wcslen(filename), namebuffer, sizeof(namebuffer));
    wchar2utf8(filename, wcslen(filename), modebuffer, sizeof(modebuffer));
    return fopen(namebuffer, modebuffer);
}
#endif // UNICODE
#endif // _WIN32
