// signatur.h	v1.0	29. April 1999	by eddy

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

#ifndef _SIGNATUR_H
#define _SIGNATUR_H

#include <String.h>
#include "global.h"
#include "room.h"
#include "vector.h"

class signature
	{
	private:
	static const float sig_scale = 0.004;	// size of signatur.
	static const int MAXLINES = 5;
	String sig_line[MAXLINES+1];
	int sig_xchars,sig_ychars;
	float  sig_unit;
	String sig_text;
	vector sig_cirdir;
	vector sig_xunit;
	vector sig_yunit;
	room*  sig_room;
	void setchar(vector pos,char c);
	public:
	signature(const String&);
	~signature(void);
	void draw(room&);
	void drawcorner(room&);
	};
	
#endif // _SIGNATUR_H                                                                                                                
