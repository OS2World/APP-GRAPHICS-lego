// lego.h	v1.0	5. May 1999	by eddy

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

#ifndef _LEGO_H
#define _LEGO_H

#include "global.h"
#include "shape.h"
#include "part.h"

class Grund16x16 : public part,public ground
	{
	public: 
	Grund16x16(parameter p):part(p,16,16,0.35),ground(myorg,mysiz,mycol,myrot) { };
	};

class Grund32x32 : public part,public ground
	{
	public: 
	Grund32x32(parameter p):part(p,32,32,0.35),ground(myorg,mysiz,mycol,myrot) { };
	};

class Stein1x1 : public part,public brick
	{
	public: 
	Stein1x1(parameter p):part(p,1,1,3),brick(myorg,mysiz,mycol,myrot) { };
	};

class Stein1x2 : public part,public brick
	{
	public: 
	Stein1x2(parameter p):part(p,1,2,3),brick(myorg,mysiz,mycol,myrot) { };
	};

class Stein1x3 : public part,public brick
	{
	public: 
	Stein1x3(parameter p):part(p,1,3,3),brick(myorg,mysiz,mycol,myrot) { };
	};

class Stein1x4 : public part,public brick
	{
	public: 
	Stein1x4(parameter p):part(p,1,4,3),brick(myorg,mysiz,mycol,myrot) { };
	};

class Stein1x6 : public part,public brick
	{
	public: 
	Stein1x6(parameter p):part(p,1,6,3),brick(myorg,mysiz,mycol,myrot) { };
	};

class Stein1x8 : public part,public brick
	{
	public: 
	Stein1x8(parameter p):part(p,1,8,3),brick(myorg,mysiz,mycol,myrot) { };
	};

class Stein2x2 : public part,public brick
	{
	public: 
	Stein2x2(parameter p):part(p,2,2,3),brick(myorg,mysiz,mycol,myrot) { };
	};

class Stein2x3 : public part,public brick
	{
	public: 
	Stein2x3(parameter p):part(p,2,3,3),brick(myorg,mysiz,mycol,myrot) { };
	};

class Stein2x4 : public part,public brick
	{
	public: 
	Stein2x4(parameter p):part(p,2,4,3),brick(myorg,mysiz,mycol,myrot) { };
	};

class Stein2x6 : public part,public brick
	{
	public: 
	Stein2x6(parameter p):part(p,2,6,3),brick(myorg,mysiz,mycol,myrot) { };
	};

class Stein2x8 : public part,public brick
	{
	public: 
	Stein2x8(parameter p):part(p,2,8,3),brick(myorg,mysiz,mycol,myrot) { };
	};

class Stein2x10 : public part,public brick
	{
	public: 
	Stein2x10(parameter p):part(p,2,10,3),brick(myorg,mysiz,mycol,myrot) { };
	};

class Stein8x16 : public part,public brick
	{
	public: 
	Stein8x16(parameter p):part(p,8,16,3),brick(myorg,mysiz,mycol,myrot) { };
	};

class Stein10x20 : public part,public brick
	{
	public: 
	Stein10x20(parameter p):part(p,10,20,3),brick(myorg,mysiz,mycol,myrot) { };
	};

class Stein2x2x9 : public part,public brick
	{
	public: 
	Stein2x2x9(parameter p):part(p,2,2,9),brick(myorg,mysiz,mycol,myrot) { };
	};

class Flach1x1 : public part,public brick
	{
	public: 
	Flach1x1(parameter p):part(p,1,1,1),brick(myorg,mysiz,mycol,myrot) { };
	};

class Flach1x2 : public part,public brick
	{
	public: 
	Flach1x2(parameter p):part(p,1,2,1),brick(myorg,mysiz,mycol,myrot) { };
	};

class Flach1x4 : public part,public brick
	{
	public: 
	Flach1x4(parameter p):part(p,1,4,1),brick(myorg,mysiz,mycol,myrot) { };
	};

class Flach2x2 : public part,public brick
	{
	public: 
	Flach2x2(parameter p):part(p,2,2,1),brick(myorg,mysiz,mycol,myrot) { };
	};

class Flach2x3 : public part,public brick
	{
	public: 
	Flach2x3(parameter p):part(p,2,3,1),brick(myorg,mysiz,mycol,myrot) { };
	};

class Flach2x4 : public part,public brick
	{
	public: 
	Flach2x4(parameter p):part(p,2,4,1),brick(myorg,mysiz,mycol,myrot) { };
	};

class Flach2x6 : public part,public brick
	{
	public: 
	Flach2x6(parameter p):part(p,2,6,1),brick(myorg,mysiz,mycol,myrot) { };
	};

class Flach2x8 : public part,public brick
	{
	public: 
	Flach2x8(parameter p):part(p,2,8,1),brick(myorg,mysiz,mycol,myrot) { };
	};

class Flach2x10 : public part,public brick
	{
	public: 
	Flach2x10(parameter p):part(p,2,10,1),brick(myorg,mysiz,mycol,myrot) { };
	};

class Flach4x4 : public part,public brick
	{
	public: 
	Flach4x4(parameter p):part(p,4,4,1),brick(myorg,mysiz,mycol,myrot) { };
	};

class Flach4x6 : public part,public brick
	{
	public: 
	Flach4x6(parameter p):part(p,4,6,1),brick(myorg,mysiz,mycol,myrot) { };
	};

class Flach4x8 : public part,public brick
	{
	public: 
	Flach4x8(parameter p):part(p,4,8,1),brick(myorg,mysiz,mycol,myrot) { };
	};

class Flach4x10 : public part,public brick
	{
	public: 
	Flach4x10(parameter p):part(p,4,10,1),brick(myorg,mysiz,mycol,myrot) { };
	};

class Flach4x12 : public part,public brick
	{
	public: 
	Flach4x12(parameter p):part(p,4,12,1),brick(myorg,mysiz,mycol,myrot) { };
	};

class Flach6x6 : public part,public brick
	{
	public: 
	Flach6x6(parameter p):part(p,6,6,1),brick(myorg,mysiz,mycol,myrot) { };
	};

class Flach6x8 : public part,public brick
	{
	public: 
	Flach6x8(parameter p):part(p,6,8,1),brick(myorg,mysiz,mycol,myrot) { };
	};

class Flach6x10 : public part,public brick
	{
	public: 
	Flach6x10(parameter p):part(p,6,10,1),brick(myorg,mysiz,mycol,myrot) { };
	};

class Kachel1x2 : public part,public body
	{
	public: 
	Kachel1x2(parameter p):part(p,1,2,1),body(myorg,mysiz,mycol,myrot) { };
	};

class Kachel2x2 : public part,public body
	{
	public: 
	Kachel2x2(parameter p):part(p,2,2,1),body(myorg,mysiz,mycol,myrot) { };
	};

class Dach45x1 : public part,public roof
	{
	public: 
	Dach45x1(parameter p):part(p,1,2,3),roof(myorg,mysiz,mycol,myrot) { };
	};

class Dach45x2 : public part,public roof
	{
	public: 
	Dach45x2(parameter p):part(p,2,2,3),roof(myorg,mysiz,mycol,myrot) { };
	};

class Dach45x3 : public part,public roof
	{
	public: 
	Dach45x3(parameter p):part(p,3,2,3),roof(myorg,mysiz,mycol,myrot) { };
	};

class Dach45x4 : public part,public roof
	{
	public: 
	Dach45x4(parameter p):part(p,4,2,3),roof(myorg,mysiz,mycol,myrot) { };
	};

class Dach22x1 : public part,public roof
	{
	public: 
	Dach22x1(parameter p):part(p,1,3,3),roof(myorg,mysiz,mycol,myrot) { };
	};

class Dach22x2 : public part,public roof
	{
	public: 
	Dach22x2(parameter p):part(p,2,3,3),roof(myorg,mysiz,mycol,myrot) { };
	};

class Dach22x4 : public part,public roof
	{
	public: 
	Dach22x4(parameter p):part(p,4,3,3),roof(myorg,mysiz,mycol,myrot) { };
	};

class Dachspitz45x1 : public part,public rooftop
	{
	public: 
	Dachspitz45x1(parameter p):part(p,1,2,3),rooftop(myorg,mysiz,mycol,myrot) { };
	};

class Dachspitz45x2 : public part,public rooftop
	{
	public: 
	Dachspitz45x2(parameter p):part(p,2,2,3),rooftop(myorg,mysiz,mycol,myrot) { };
	};

class Dachspitz45x3 : public part,public rooftop
	{
	public: 
	Dachspitz45x3(parameter p):part(p,3,2,3),rooftop(myorg,mysiz,mycol,myrot) { };
	};

class Dachspitz45x4 : public part,public rooftop
	{
	public: 
	Dachspitz45x4(parameter p):part(p,4,2,3),rooftop(myorg,mysiz,mycol,myrot) { };
	};

class Dachspitz22x2 : public part,public rooftop
	{
	public: 
	Dachspitz22x2(parameter p):part(p,2,2,1.8),rooftop(myorg,mysiz,mycol,myrot) { };
	};

class Dachspitz22x4 : public part,public rooftop
	{
	public: 
	Dachspitz22x4(parameter p):part(p,4,2,1.8),rooftop(myorg,mysiz,mycol,myrot) { };
	};

class Dacheck22 : public part,public roofcorner
	{
	public: 
	Dacheck22(parameter p):part(p,3,3,3),roofcorner(myorg,mysiz,mycol,myrot) { };
	};

class Ecke : public part,public corner
	{
	public: 
	Ecke(parameter p):part(p,2,2,3),corner(myorg,mysiz,mycol,myrot) { };
	};

class Eckeflach : public part,public corner
	{
	public: 
	Eckeflach(parameter p):part(p,2,2,1),corner(myorg,mysiz,mycol,myrot) { };
	};

class Rundflach : public part,public round
	{
	public: 
	Rundflach(parameter p):part(p,1,1,1),round(myorg,mysiz,mycol,myrot) { };
	};

class Rundhoch : public part,public round
	{
	public: 
	Rundhoch(parameter p):part(p,1,1,3),round(myorg,mysiz,mycol,myrot) { };
	};

class Rund1 : public part,public round1
	{
	public: 
	Rund1(parameter p):part(p,2,3,3),round1(myorg,mysiz,mycol,myrot) { };
	};

class Rund2 : public part,public round2
	{
	public: 
	Rund2(parameter p):part(p,2,4,6),round2(myorg,mysiz,mycol,myrot) { };
	};

class Rund3 : public part,public round3
	{
	public: 
	Rund3(parameter p):part(p,2,4,6),round3(myorg,mysiz,mycol,myrot) { };
	};

class Achsevertflach : public part,public axisvertical
	{
	public: 
	Achsevertflach(parameter p):part(p,2,2,1),axisvertical(myorg,mysiz,mycol,myrot) { };
	};
	
class Achseverthoch : public part,public axisvertical
	{
	public: 
	Achseverthoch(parameter p):part(p,2,2,3),axisvertical(myorg,mysiz,mycol,myrot) { };
	};
	
class Achseeins2x1 : public part,public axisone
	{
	public: 
	Achseeins2x1(parameter p):part(p,2,1,3),axisone(myorg,mysiz,mycol,myrot) { };
	};
	
class Achseeins2x2 : public part,public axisone
	{
	public: 
	Achseeins2x2(parameter p):part(p,2,2,3),axisone(myorg,mysiz,mycol,myrot) { };
	};
	
class Achsezwei2x2 : public part,public axistwo
	{
	public: 
	Achsezwei2x2(parameter p):part(p,2,2,3),axistwo(myorg,mysiz,mycol,myrot) { };
	};
	
class Achsezwei2x4 : public part,public axistwo
	{
	public: 
	Achsezwei2x4(parameter p):part(p,2,4,3),axistwo(myorg,mysiz,mycol,myrot) { };
	};
	
class Achsevier : public part,public axisfour
	{
	public: 
	Achsevier(parameter p):part(p,10,4,3),axisfour(myorg,mysiz,mycol,myrot) { };
	};
	
class Felge : public part,public felloe
	{
	public: 
	Felge(parameter p):part(p,0,0,0),felloe(myorg,vector(0,1,0),mycol,myrot) { };
	};
	
class Reifen : public part,public tire
	{
	public: 
	Reifen(parameter p):part(p,0,0,0),tire(myorg,vector(0,1,0),mycol,myrot) { };
	};
	
class Rad : public part,public wheel
	{
	public: 
	Rad(parameter p):part(p,0,0,0),wheel(myorg,vector(0,1,0),mycol,myrot) { };
	};
	
/////////////////////////////////////////////////////////////////////

class Test : public part,public test
	{
	public: 
	Test(parameter p):part(p,2,2,3),test(myorg,mysiz,mycol,myrot) { };
	};
	
#endif // _LEGO_H
