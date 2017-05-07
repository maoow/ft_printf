# ft_printf
command ft_printf as 42 project.
# __________________________________________________________________


##  Name
    ft_printf - formatted write

##  Synopsys
    #include "ft_printf.h"
    ft_printf(const char *format, ...);
  
##  Description
     The function ft_printf() write output to stdout, the standard output stream;
       
##  Format of the format string
      The format string is a character string, beginning and ending in its
       initial shift state, if any.  The format string is composed of zero
       or more directives: ordinary characters (not %), which are copied
       unchanged to the output stream; and conversion specifications, each
       of which results in fetching zero or more subsequent arguments.  Each
       conversion specification is introduced by the character %, and ends
       with a conversion specifier.  In between there may be (in this order)
       zero or more flags, an optional minimum field width, an optional
       precision and an optional length modifier.
       
##        Flag characters
       The character % is followed by zero or more of the following flags:

###       \#
The value should be converted to an "alternate form".  For o
              conversions, the first character of the output string is made
              zero (by prefixing a 0 if it was not zero already).  For x and
              X conversions, a nonzero result has the string "0x" (or "0X"
              for X conversions) prepended to it.  For a, A, e, E, f, F, g,
              and G conversions, the result will always contain a decimal
              point, even if no digits follow it (normally, a decimal point
              appears in the results of those conversions only if a digit
              follows).  For g and G conversions, trailing zeros are not
              removed from the result as they would otherwise be.  For other
              conversions, the result is undefined.

###       0
 The value should be zero padded.  For d, i, o, u, x, X, a, A,
              e, E, f, F, g, and G conversions, the converted value is
              padded on the left with zeros rather than blanks.  If the 0
              and - flags both appear, the 0 flag is ignored.  If a
              precision is given with a numeric conversion (d, i, o, u, x,
              and X), the 0 flag is ignored.  For other conversions, the
              behavior is undefined.

###       -
 The converted value is to be left adjusted on the field
              boundary.  (The default is right justification.)  The
              converted value is padded on the right with blanks, rather
              than on the left with blanks or zeros.  A - overrides a 0 if
              both are given.

###       ' '
(a space) A blank should be left before a positive number (or
              empty string) produced by a signed conversion.

###       +
A sign (+ or -) should always be placed before a number
              produced by a signed conversion.  By default, a sign is used
              only for negative numbers.  A + overrides a space if both are
              used.

### Field width
An optional decimal digit string (with nonzero first digit)
       specifying a minimum field width.  If the converted value has fewer
       characters than the field width, it will be padded with spaces on the
       left (or right, if the left-adjustment flag has been given).  Instead
       of a decimal digit string one may write "*" or "*m$" (for some
       decimal integer m) to specify that the field width is given in the
       next argument, or in the m-th argument, respectively, which must be
       of type int.  A negative field width is taken as a '-' flag followed
       by a positive field width.  In no case does a nonexistent or small
       field width cause truncation of a field; if the result of a
       conversion is wider than the field width, the field is expanded to
       contain the conversion result.

###    Precision
An optional precision, in the form of a period ('.')  followed by an
       optional decimal digit string.  Instead of a decimal digit string one
       may write "*" or "*m$" (for some decimal integer m) to specify that
       the precision is given in the next argument, or in the m-th argument,
       respectively, which must be of type int.  If the precision is given
       as just '.', the precision is taken to be zero.  A negative precision
       is taken as if the precision were omitted.  This gives the minimum
       number of digits to appear for d, i, o, u, x, and X conversions, the
       number of digits to appear after the radix character for a, A, e, E,
       f, and F conversions, the maximum number of significant digits for g
       and G conversions, or the maximum number of characters to be printed
       from a string for s and S conversions.

###   Length modifier
 Here, "integer conversion" stands for d, i, o, u, x, or X conversion.

####       hh
A following integer conversion corresponds to a signed char or
              unsigned char argument, or a following n conversion
              corresponds to a pointer to a signed char argument.

####       h
A following integer conversion corresponds to a short int or
              unsigned short int argument, or a following n conversion
              corresponds to a pointer to a short int argument.

####       l
A following integer conversion corresponds to a long int
              or unsigned long int argument, or a following n conversion
              corresponds to a pointer to a long int argument, or a
              following c conversion corresponds to a wint_t argument, or a
              following s conversion corresponds to a pointer to wchar_t
              argument.

####       ll
(ell-ell).  A following integer conversion corresponds to a
              long long int or unsigned long long int argument, or a
              following n conversion corresponds to a pointer to a long long
              int argument.
              
####       z
A following integer conversion corresponds to a size_t or
              ssize_t argument, or a following n conversion corresponds to a
              pointer to a size_t argument.
              
###  Conversion specifiers
A character that specifies the type of conversion to be applied.  The
       conversion specifiers and their meanings are:

####       d, i
The int argument is converted to signed decimal notation.  The
              precision, if any, gives the minimum number of digits that
              must appear; if the converted value requires fewer digits, it
              is padded on the left with zeros.  The default precision is 1.
              When 0 is printed with an explicit precision 0, the output is
              empty.

####       o, u, x, X
 The unsigned int argument is converted to unsigned octal (o),
              unsigned decimal (u), or unsigned hexadecimal (x and X)
              notation.  The letters abcdef are used for x conversions; the
              letters ABCDEF are used for X conversions.  The precision, if
              any, gives the minimum number of digits that must appear; if
              the converted value requires fewer digits, it is padded on the
              left with zeros.  The default precision is 1.  When 0 is
              printed with an explicit precision 0, the output is empty.

    
####       c
If no l modifier is present, the int argument is converted to
              an unsigned char, and the resulting character is written.  If
              an l modifier is present, the wint_t (wide character) argument
              is converted to a multibyte sequence by a call to the
              wcrtomb(3) function, with a conversion state starting in the
              initial state, and the resulting multibyte string is written.

####       s
If no l modifier is present: the const char * argument is
              expected to be a pointer to an array of character type
              (pointer to a string).  Characters from the array are written
              up to (but not including) a terminating null byte ('\0'); if a
              precision is specified, no more than the number specified are
              written.  If a precision is given, no null byte need be
              present; if the precision is not specified, or is greater than
              the size of the array, the array must contain a terminating
              null byte.
              If an l modifier is present: the const wchar_t * argument is
              expected to be a pointer to an array of wide characters.  Wide
              characters from the array are converted to multibyte
              characters (each by a call to the wcrtomb(3) function, with a
              conversion state starting in the initial state before the
              first wide character), up to and including a terminating null
              wide character.  The resulting multibyte characters are
              written up to (but not including) the terminating null byte.
              If a precision is specified, no more bytes than the number
              specified are written, but no partial multibyte characters are
              written.  Note that the precision determines the number of
              bytes written, not the number of wide characters or screen
              positions.  The array must contain a terminating null wide
              character, unless a precision is given and it is so small that
              the number of bytes written exceeds it before the end of the
              array is reached.

  ####     C      
Synonym for lc.

####       S     
Synonym for ls.

####       p      
The void * pointer argument is printed in hexadecimal (as if
              by %#x or %#lx).

####       n      
The number of characters written so far is stored into the
              integer pointed to by the corresponding argument.  That
              argument shall be an int *, or variant whose size matches the
              (optionally) supplied integer length modifier.  No argument is
              converted. 
       
####       % 
A '%' is written.  No argument is converted.  The complete
              conversion specification is '%%'.
              
              
## RETURN VALUE
return the number of characters printed
              
