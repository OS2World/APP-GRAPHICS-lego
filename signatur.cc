// signatur.cc	v1.0	7. April 1999	by eddy

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

#include "signatur.h"

signature::signature(const String& str)
	{
	sig_text = str;
	sig_cirdir = vector(0,0,1);
	sig_unit = sig_xchars = sig_ychars = 0;
	sig_ychars = split(sig_text,sig_line,MAXLINES,'\n');
	int i = 0;
	while(sig_line[i]!="")
		{
		int l = sig_line[i].length();
		if(l>sig_xchars) sig_xchars = l;
		i++;
		}
	}

signature::~signature(void) { }

void signature::draw(room& r)
	{
	cerr << "Signature " << sig_text << "   ";
	sig_room = &r;
	sig_unit = r.room_xsize>r.room_ysize ? r.room_xsize : r.room_ysize;
	sig_unit *= sig_scale;
	vector yorg(r.room_xsize,0,r.room_zsize);
	yorg += vector(-(3*sig_xchars+1)*sig_unit,6*sig_unit,0);
	vector xorg(yorg);
	sig_xunit = vector(sig_unit,0,0);
	sig_yunit = vector(0,sig_unit,0);
	for(int y=sig_ychars-1;y>=0;y--)
		{
		for(unsigned x=0;x<sig_line[y].length();x++)
			{
			setchar(xorg,sig_line[y][x]);
			xorg += sig_xunit*3;
			}
		yorg += sig_yunit*6; xorg = yorg;
		}
	cerr << endl;
	}

void signature::setchar(vector pos,char c)
	{
	vector& o = pos;
	vector& d = sig_cirdir;
	vector& x = sig_xunit;
	vector& y = sig_yunit;
	float&  u = sig_unit;
	room&   r = *sig_room;
	switch(c)
		{
		case ' ': break;
		case 'd': r.docircle(o,d,u,OUTLINE);
			  r.doline(o+x-y,o+x+y*3,OUTLINE);
			  break;
		case 'e': r.doarc(o,d,x,270,OUTLINE);
			  r.doline(o-x,o+x,OUTLINE);
			  r.doline(o-y,o+x-y,OUTLINE);
			  break;
		case 'y': r.doline(o-y,o-x+y,OUTLINE);
			  r.doline(o+x+y,o-x*0.5-y*2,OUTLINE);
			  break;
		case '+': r.doline(o-x+y,o+x+y,OUTLINE);
			  r.doline(o,o+y*2,OUTLINE);
			  break;
		case '-': r.doline(o-x+y,o+x+y,OUTLINE);
			  break;
		case '°': r.docircle(o+y*2.5,d,0.5*u,OUTLINE);
			  break;
		case '/': r.doline(o-x-y,o+x+y*3,OUTLINE);
			  break;
		case '0': r.doarc(o+y*2,d,x,180,OUTLINE);
			  r.doarc(o,d,x*-1,180,OUTLINE);
			  r.doline(o-x,o-x+y*2,OUTLINE);
			  r.doline(o+x,o+x+y*2,OUTLINE);
			  break;
		case '1': r.doline(o-x-y,o+x-y,OUTLINE);
			  r.doline(o-y,o+y*3,OUTLINE);
			  r.doline(o+y*3,o-x+y,OUTLINE);
			  break;
		case '2': r.doarc(o+y*2,d,x,180,OUTLINE);
			  r.doline(o-x-y,o+x+y*2,OUTLINE);
			  r.doline(o-x-y,o+x-y,OUTLINE);
			  break;
		case '3': r.doarc(o+y*2,d,y*-1,270,OUTLINE);
			  r.doarc(o,d,x*-1,270,OUTLINE);
			  break;
		case '4': r.doline(o+x*0.25+y*3,o-x,OUTLINE);
			  r.doline(o-x,o+x,OUTLINE);
			  r.doline(o+x*0.25+y,o+x*0.25-y,OUTLINE);
			  break;
		case '5': r.doarc(o,d,x*-1,270,OUTLINE);
			  r.doline(o+y,o-x+y,OUTLINE);
			  r.doline(o-x+y,o-x+y*3,OUTLINE);
			  r.doline(o-x+y*3,o+x+y*3,OUTLINE);
			  break;
		case '6': r.docircle(o,d,u,OUTLINE);
			  r.doarc(o+y*2,d,x,180,OUTLINE);
			  r.doline(o-x,o-x+y*2,OUTLINE);
			  break;
		case '7': r.doline(o-x-y,o+x+y*3,OUTLINE);
			  r.doline(o-x+y*3,o+x+y*3,OUTLINE);
			  r.doline(o-x+y*3,o-x+y*2.5,OUTLINE);
			  r.doline(o-x*0.5+y,o+x*0.5+y,OUTLINE);
			  break;
		case '8': r.docircle(o+y*2,d,u,OUTLINE);
			  r.docircle(o,d,u,OUTLINE);
			  break;
		case '9': r.docircle(o+y*2,d,u,OUTLINE);
			  r.doarc(o,d,x*-1,180,OUTLINE);
			  r.doline(o+x,o+x+y*2,OUTLINE);
			  break;
		default : r.doline(o-x-y*2,o+x+y*3,RED);
			  r.doline(o-x+y*3,o+x-y*2,RED);
		}
	}

void signature::drawcorner(room& r)
	{
	sig_room = &r;
	vector o(0,0,r.room_zsize);
	vector x(r.room_xsize-1,0,r.room_zsize-1);
	vector y(0,r.room_ysize-1,r.room_zsize-1);
	r.doline(o,x,OUTLINE);
	r.doline(x,x+y,OUTLINE);
	r.doline(x+y,y,OUTLINE);
	r.doline(y,o,OUTLINE);
	}

//
