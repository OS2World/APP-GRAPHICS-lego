// shape.h	v1.0	12. April 1999	by eddy

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

#ifndef _SHAPE_H
#define _SHAPE_H

#include "vector.h"
#include "rotator.h"
#include "room.h"
#include "global.h"

class shape			// generic object
	{
	protected:
	vector  sha_org;	// origin
	vector  sha_siz;	// size
	color   sha_col;	// main color
	rotator sha_rot;	// rotation
	public:
	shape(void);
	virtual ~shape(void);
	virtual void draw(room&);
	};

class body : public shape	// box with outlines
	{
	public:
	body(const vector& org,const vector& siz,color col,const rotator& rot);
	void draw(room&);
	};

class knob : public shape	
	{
	public:
	knob(const vector& org,color col,const rotator& rot);
	knob(const vector& org,const vector& d,color col,const rotator& rot);
	void draw(room&);
	};

class roofbody : public shape
	{
	public:
	roofbody(const vector& org,const vector& siz,color col,const rotator& rot);
	void draw(room&);
	};

class roofcornerbody : public shape
	{
	public:
	roofcornerbody(const vector& org,const vector& siz,color col,const rotator& rot);
	void draw(room&);
	};

class cornerbody : public shape
	{
	public:
	cornerbody(const vector& org,const vector& siz,color col,const rotator& rot);
	void draw(room&);
	};

class roundbody : public shape
	{
	public:
	roundbody(const vector& org,const vector& siz,color col,const rotator& rot);
	void draw(room&);
	};

class round1body : public shape
	{
	public:
	round1body(const vector& org,const vector& siz,color col,const rotator& rot);
	void draw(room&);
	};

class round2body : public shape
	{
	public:
	round2body(const vector& org,const vector& siz,color col,const rotator& rot);
	void draw(room&);
	};

class navepin1 : public shape	
	{
	public:
	navepin1(const vector& org,const vector& d,color col,const rotator& rot);
	void draw(room&);
	};

class felloebody : public shape	
	{
	public:
	felloebody(const vector& org,const vector& d,color col,const rotator& rot);
	void draw(room&);
	};

class tire : public shape	
	{
	public:
	tire(const vector& org,const vector& d,color col,const rotator& rot);
	void draw(room&);
	};

/////////////////////////////////////////////////////////////

class group : public shape		// group of objects
	{
	protected:
	dir grp_dir;
	shape** grp_shape;
	public:
	group(void);
	~group(void);
	void draw(room&);
	};
	
////////////////////////////////////////////////////////////

class brick : public group
	{
	private:
	shape* bri_shape[202];
	public:
	brick(const vector& org,const vector& siz,color col,const rotator& rot);
	};

class ground : public group
	{
	private:
	shape* gro_shape[1026];
	public:
	ground(const vector& org,const vector& siz,color col,const rotator& rot);
	};

class roof : public group
	{
	private:
	shape* roof_shape[6];
	public:
	roof(const vector& org,const vector& siz,color col,const rotator& rot);
	};

class roofcorner : public group
	{
	private:
	shape* roofcorner_shape[3];
	public:
	roofcorner(const vector& org,const vector& siz,color col,const rotator& rot);
	};

class rooftop : public shape
	{
	public:
	rooftop(const vector& org,const vector& siz,color col,const rotator& rot);
	void draw(room& r);
	};

class corner : public group
	{
	private:
	shape* corner_shape[5];
	public:
	corner(const vector& org,const vector& siz,color col,const rotator& rot);
	};

class round : public group
	{
	private:
	shape* round_shape[3];
	public:
	round(const vector& org,const vector& siz,color col,const rotator& rot);
	};

class round1 : public group
	{
	private:
	shape* round1_shape[6];
	public:
	round1(const vector& org,const vector& siz,color col,const rotator& rot);
	};

class round2 : public group
	{
	private:
	shape* round2_shape[6];
	public:
	round2(const vector& org,const vector& siz,color col,const rotator& rot);
	};

class round3 : public shape
	{
	public:
	round3(const vector& org,const vector& siz,color col,const rotator& rot);
	void draw(room& r);
	};

class axisvertical : public group
	{
	private:
	shape* axv_shape[3];
	public:
	axisvertical(const vector& org,const vector& siz,color col,const rotator& rot);
	};
	
class axisone : public group
	{
	private:
	shape* ax1_shape[3];
	public:
	axisone(const vector& org,const vector& siz,color col,const rotator& rot);
	};
	
class axistwo : public group
	{
	private:
	shape* ax2_shape[4];
	public:
	axistwo(const vector& org,const vector& siz,color col,const rotator& rot);
	};
	
class axisfour : public group
	{
	private:
	shape* ax4_shape[6];
	public:
	axisfour(const vector& org,const vector& siz,color col,const rotator& rot);
	};
	
class felloe : public group
	{
	private:
	shape* felloe_shape[6];
	public:
	felloe(const vector& org,const vector& siz,color col,const rotator& rot);
	};

class wheel : public group
	{
	private:
	shape* wheel_shape[3];
	public:
	wheel(const vector& org,const vector& siz,color col,const rotator& rot);
	};

class test : public group
	{
	private:
	shape* test_shape[99];
	public:
	test(const vector& org,const vector& siz,color col,const rotator& rot);
	};

#endif // _SHAPE_H
