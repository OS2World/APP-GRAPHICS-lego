// vector.cc	v1.0	15. April 1999	by eddy

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

#include "vector.h"
#include <math.h>

vector::vector(void) { v_x = v_y = v_z = 0; }

vector::vector(double xval,double yval,double zval)
        {
        v_x = xval;
	v_y = yval;
	v_z = zval;
        }

vector::~vector(void) { }

void vector::set_x(double val) { v_x = val; }

void vector::set_y(double val) { v_y = val; }

void vector::set_z(double val) { v_z = val; }

double vector::absvalue(void) const
        {
        return( sqrt( v_x*v_x + v_y*v_y + v_z*v_z ) );
        }

//double vector::distance(const vector& vec) const
//	{
//	double xtmp = vec.v_x-v_x; xtmp *= xtmp;
//	double ytmp = vec.v_y-v_y; ytmp *= ytmp;
//	double ztmp = vec.v_z-v_z; ztmp *= ztmp;
//	return sqrt( xtmp + ytmp + ztmp );
//	}

vector vector::unit(void) const
	{
	double scale = 1.0/absvalue();
	return vector(v_x,v_y,v_z)*scale;
	}

vector vector::product(const vector& v) const
	{
	double x = v_y*v.z() - v.y()*v_z;
	double y = v_z*v.x() - v.z()*v_x;
	double z = v_x*v.y() - v.x()*v_y;
	return(vector(x,y,z));
	}

vector vector::operator + (const vector& vec) const
        {
	return( vector( v_x+vec.v_x , v_y+vec.v_y , v_z+vec.v_z ) );
        }

void vector::operator += (const vector& vec)
        {
        v_x += vec.v_x; 
	v_y += vec.v_y; 
	v_z += vec.v_z;
        }

vector vector::operator - (const vector& vec) const
        {
	return( vector( v_x-vec.v_x , v_y-vec.v_y , v_z-vec.v_z ) );
        }

void vector::operator -= (const vector& vec)
        {
        v_x -= vec.v_x;
	v_y -= vec.v_y;
	v_z -= vec.v_z;
        }

vector vector::operator * (double f) const
        {
        vector product;
        product.v_x = v_x * f;
        product.v_y = v_y * f;
        product.v_z = v_z * f;
        return( vector( v_x*f, v_y*f , v_z*f ) );
        }

void vector::operator *= (double f)
        {
        v_x *= f;
	v_y *= f;
	v_z *= f;
        }

//
