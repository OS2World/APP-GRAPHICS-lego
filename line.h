// line.h   v1.0    31. March 1999  by eddy

/*

    lego -- this program creates images of models made of LEGO(R)-like
    components. It is

            Copyright (C) 1999  by Edmund Nussbaum.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that you will have a lot of
    fun when using it, but WITHOUT ANY WARRANTY; without even the implied
    warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See
    the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

    Please report your experiences, suggestions or whatever related
    to this program to:

    en@mpifr-bonn.mpg.de

    or send mail to:
    Edmund Nussbaum, Richard-Wagner-Str. 59, 53115 Bonn,Germany

*/

#ifndef _LINE_H
#define _LINE_H

#include "global.h"
#include <Strng.h>
#include <iostream.h>

class line
    {
    private:
    static const int MAXLL = 128;   // Maximum line length.
    static const int MAXARGS = 9;  // Maximum number of arguments.
    int moreflag,validflag;
    int lineno;
    String linearg[MAXARGS];;
    parameter linepar;
    public:
    line(void);     // Creates line object from stdin.
    ~line(void);
    int valid(void);    // Checks if line is valid.
    int more(void);     // Checks for further lines.
    int number(void);   // Returns line number.
    String keyword(void);   // Returns keyword.
    parameter par(void);    // Returns parameter.
    String strarg(int); // Returns argument as String.
    int    intarg(int); // Returns argument as integer.
    float  fltarg(int); // Returns argument as float.
    };

#endif // _LINE_H
