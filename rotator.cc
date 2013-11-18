// rotator.cc	v1.0	6. Dezember 1998	by eddy

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

#include "rotator.h"

rotator::rotator(void)
	{
	a1=a2=a3=b1=b2=b3=c1=c2=c3=d1=d2=d3=0;
	skipflag = 1;
	}

rotator::rotator(const matrix& m)
	{
	skipflag = 0;
	a1 = m.a1;  b1 = m.b1;  c1 = m.c1;  d1 = m.d1;
	a2 = m.a2;  b2 = m.b2;  c2 = m.c2;  d2 = m.d2;
	a3 = m.a3;  b3 = m.b3;  c3 = m.c3;  d3 = m.d3;
	}

rotator::rotator(const vector& org,const vector& siz,dir d) 
	{
	rorg = org;
	a1=a2=a3=b1=b2=b3=c1=c2=c3=d1=d2=d3=0;
	switch(d)
		{
		case E:	skipflag = 0;
			b1 = 1; a2 =-1; c3 = 1;
			d2 = siz.x(); 
			break;
		case S:	skipflag = 0;
			a1 =-1; b2 =-1; c3 = 1; 
			d1 = siz.x(); d2 = siz.y();
			break;
		case W:	skipflag = 0;
			b1 =-1; a2 = 1; c3 = 1; 
			d1 = siz.y();
			break;
		default: skipflag = 1;
		}
	}

rotator::~rotator(void) { }

vector rotator::rotorg(const vector& vec) const
	{
	if(skipflag) return(vec);
	vector tmp(vec-rorg);
	double x = a1*tmp.x() + b1*tmp.y() + c1*tmp.z() + d1;
	double y = a2*tmp.x() + b2*tmp.y() + c2*tmp.z() + d2;
	double z = a3*tmp.x() + b3*tmp.y() + c3*tmp.z() + d3;
	tmp = vector(x,y,z) + rorg;
	return(tmp);
	}

vector rotator::rotsiz(const vector& vec) const
	{
	if(skipflag) return(vec);
	double x = a1*vec.x() + b1*vec.y() + c1*vec.z();
	double y = a2*vec.x() + b2*vec.y() + c2*vec.z();
	double z = a3*vec.x() + b3*vec.y() + c3*vec.z();
	return(vector(x,y,z));
	}

//
