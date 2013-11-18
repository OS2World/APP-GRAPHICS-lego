// vector.h	v1.0	15. April 1999	by eddy

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

#ifndef _VECTOR_H
#define _VECTOR_H

struct matrix
	{
	double a1,a2,a3,b1,b2,b3,c1,c2,c3,d1,d2,d3;
	};

class vector
	{
	private:
	double v_x,v_y,v_z;
	public:
	vector(void);			// Null vector.
	vector(double,double,double);	// Initialized vector.
	~vector(void);
	inline double x(){ return(v_x); };	// Get x
	inline double y(){ return(v_y); };	// Get y
	inline double z(){ return(v_z); };	// Get z
	void set_x(double);		// Set x
	void set_y(double);		// Set y
	void set_z(double);		// Set z
	double absvalue(void) const;
//	double distance(const vector&) const;
	vector unit(void) const;
	vector product(const vector&) const;
	vector operator + (const vector&) const;
	void operator += (const vector&);
	vector operator - (const vector&) const;
	void operator -= (const vector&);
	vector operator * (double) const;
	void operator *= (double);
	};
	
#endif // _VECTOR_H                                                                                                                
