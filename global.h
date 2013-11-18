// global.h	v1.0	15. April 1999	by eddy

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

#ifndef _GLOBAL_H
#define _GLOBAL_H

typedef char color;

const color TRANSPARENT =  0;	// never
const color BLACK       =  1;	// define
const color RED         =  2;	// more
const color YELLOW      =  3;	// than
const color GREEN       =  4;	// 15
const color LIGHTGREEN  =  5;	// colors.
const color BLUE        =  6;
const color GREY        =  7;
const color WHITE       =  8;
const color OUTLINE	=  9;
const color BACKGROUND	= 10;
const int   COLORS	= 11;	// No. of colors.


typedef char dir;	// Alignment of brick.

const dir N = 'N';	// Default direction, north.
const dir E = 'E';	// -90° rotated, east. 
const dir W = 'W';	//  90° rotated, west.
const dir S = 'S';	// 180° rotated, south.


struct parameter
	{
	float x;
	float y;
	float z;
	color c;
	dir d;
	};

#endif // _GLOBAL_H
