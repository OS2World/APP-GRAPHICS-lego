// rotator.h	v1.0	5. February 1999	by eddy

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

#ifndef _ROTATOR_H
#define _ROTATOR_H

#include "global.h"
#include "vector.h"

class rotator
	{
	private:
	int skipflag;
	double a1,a2,a3,b1,b2,b3,c1,c2,c3,d1,d2,d3;
	vector rorg;
	public:
	rotator(void);
	rotator(const matrix&);
	rotator(const vector& org,const vector& siz,dir d);
	~rotator(void);
	vector rotorg(const vector&) const;	// Rotate absolute vectors.
	vector rotsiz(const vector&) const;	// Rotate relative vectors.
	};
	
const rotator NOROT;

#endif // _ROTATOR_H                                                                                                                
