// lego.cc	v1.0	5. May 1999	by eddy

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

#include "lego.h"
#include "line.h"
#include "vector.h"
#include "shape.h"
#include "room.h"
#include "signatur.h"
#include <iostream.h>
#include <unistd.h>
#include <stdlib.h>
#include <String.h>
#include <strstream.h>
#include <iomanip.h>

void usage(String argv0)
	{
	cerr << "Usage:\n";
	cerr << argv0 << " [hs] < input.lego > output.ppm \n";
	cerr << "option -help	this help screen \n";
	cerr << "option -seq 	create sequence of output files, \n";
	cerr << " 		one image for each processed brick. \n";
	cerr << " 		take care of your storage capacity! \n";
	exit(1);
	}

int main(int argc, char* argv[])
    {
    cerr << "\n***   l e g o   ***   by eddy   ***   May 1999   ***\n";
    room* rp;
    int imgcount = 0;
    if(argc>1) 
	{
	String arg;
	for(int i=1;i<argc;i++) arg += argv[i];
	if(arg.contains('h')) usage(argv[0]);
	if(arg.contains('s')) imgcount = 1;
	}
    srandom(getpid());
    while(1)
	{
	line l;
	if(!l.more())
	    {
	    cerr<<"\nError: No Raum or Room statement found !\n";
	    exit(2);
	    }
	if(!l.valid()) continue;
	if(l.keyword()!="Raum" && l.keyword()!="Room") continue;
	vector rsize(l.fltarg(2),l.fltarg(3),l.fltarg(4));
	rp = new room(l.intarg(1),rsize,l.fltarg(5),l.fltarg(6));
	break;
	}
    room& r = *rp;
//    signature sig("1999");
//    sig.draw(r);
    if(imgcount) r.writeppm("img0000.ppm");
    float xorg = 0, yorg = 0, zorg = 0;
    while(1)
	{
	line l;
	if(l.valid())
	    {
	    String w(l.keyword());
	    if(w=="Nullpunkt") 
		{
		xorg = l.fltarg(1);
		yorg = l.fltarg(2);
		zorg = l.fltarg(3);
		cerr << endl;
		continue;
		}
	    else if(w=="Signatur")
		{
		cerr << "Keyword Signature is not supported yet :-(";
		cerr << endl;
		continue;
		}
	    else if(w=="End") break;
	    parameter p = l.par();
	    p.x += xorg;
	    p.y += yorg;
	    p.z += zorg;
	    if     (w=="Stein1x1")       {Stein1x1       s(p); s.draw(r);}
	    else if(w=="Stein1x2")       {Stein1x2       s(p); s.draw(r);}
	    else if(w=="Stein1x3")       {Stein1x3       s(p); s.draw(r);}
	    else if(w=="Stein1x4")       {Stein1x4       s(p); s.draw(r);}
	    else if(w=="Stein1x6")       {Stein1x6       s(p); s.draw(r);}
	    else if(w=="Stein1x8")       {Stein1x8       s(p); s.draw(r);}
	    else if(w=="Stein2x2")       {Stein2x2       s(p); s.draw(r);}
	    else if(w=="Stein2x3")       {Stein2x3       s(p); s.draw(r);}
	    else if(w=="Stein2x4")       {Stein2x4       s(p); s.draw(r);}
	    else if(w=="Stein2x6")       {Stein2x6       s(p); s.draw(r);}
	    else if(w=="Stein2x8")       {Stein2x8       s(p); s.draw(r);}
	    else if(w=="Stein2x10")      {Stein2x10      s(p); s.draw(r);}
	    else if(w=="Stein8x16")      {Stein8x16      s(p); s.draw(r);}
	    else if(w=="Stein10x20")     {Stein10x20     s(p); s.draw(r);}
	    else if(w=="Stein2x2x9")     {Stein2x2x9     s(p); s.draw(r);}
	    else if(w=="Flach1x1")       {Flach1x1       s(p); s.draw(r);}
	    else if(w=="Flach1x2")       {Flach1x2       s(p); s.draw(r);}
	    else if(w=="Flach1x4")       {Flach1x4       s(p); s.draw(r);}
	    else if(w=="Flach2x2")       {Flach2x2       s(p); s.draw(r);}
	    else if(w=="Flach2x3")       {Flach2x3       s(p); s.draw(r);}
	    else if(w=="Flach2x4")       {Flach2x4       s(p); s.draw(r);}
	    else if(w=="Flach2x6")       {Flach2x6       s(p); s.draw(r);}
	    else if(w=="Flach2x8")       {Flach2x8       s(p); s.draw(r);}
	    else if(w=="Flach2x10")      {Flach2x10      s(p); s.draw(r);}
	    else if(w=="Flach4x4")       {Flach4x4       s(p); s.draw(r);}
	    else if(w=="Flach4x6")       {Flach4x6       s(p); s.draw(r);}
	    else if(w=="Flach4x8")       {Flach4x8       s(p); s.draw(r);}
	    else if(w=="Flach4x10")      {Flach4x10      s(p); s.draw(r);}
	    else if(w=="Flach4x12")      {Flach4x12      s(p); s.draw(r);}
	    else if(w=="Flach6x6")       {Flach6x6       s(p); s.draw(r);}
	    else if(w=="Flach6x8")       {Flach6x8       s(p); s.draw(r);}
	    else if(w=="Flach6x10")      {Flach6x10      s(p); s.draw(r);}
	    else if(w=="Kachel1x2")      {Kachel1x2      s(p); s.draw(r);}
	    else if(w=="Kachel2x2")      {Kachel2x2      s(p); s.draw(r);}
	    else if(w=="Grund16x16")     {Grund16x16     s(p); s.draw(r);}
	    else if(w=="Grund32x32")     {Grund32x32     s(p); s.draw(r);}
	    else if(w=="Dach45x1")       {Dach45x1       s(p); s.draw(r);}
	    else if(w=="Dach45x2")       {Dach45x2       s(p); s.draw(r);}
	    else if(w=="Dach45x3")       {Dach45x3       s(p); s.draw(r);}
	    else if(w=="Dach45x4")       {Dach45x4       s(p); s.draw(r);}
	    else if(w=="Dach22x1")       {Dach22x1       s(p); s.draw(r);}
	    else if(w=="Dach22x2")       {Dach22x2       s(p); s.draw(r);}
	    else if(w=="Dach22x4")       {Dach22x4       s(p); s.draw(r);}
	    else if(w=="Dachspitz45x1")  {Dachspitz45x1  s(p); s.draw(r);}
	    else if(w=="Dachspitz45x2")  {Dachspitz45x2  s(p); s.draw(r);}
	    else if(w=="Dachspitz45x3")  {Dachspitz45x3  s(p); s.draw(r);}
	    else if(w=="Dachspitz45x4")  {Dachspitz45x4  s(p); s.draw(r);}
	    else if(w=="Dachspitz22x2")  {Dachspitz22x2  s(p); s.draw(r);}
	    else if(w=="Dachspitz22x4")  {Dachspitz22x4  s(p); s.draw(r);}
	    else if(w=="Dacheck22")      {Dacheck22      s(p); s.draw(r);}
	    else if(w=="Ecke")           {Ecke           s(p); s.draw(r);}
	    else if(w=="Eckeflach")      {Eckeflach      s(p); s.draw(r);}
	    else if(w=="Rundflach")      {Rundflach      s(p); s.draw(r);}
	    else if(w=="Rundhoch")       {Rundhoch       s(p); s.draw(r);}
	    else if(w=="Rund1")          {Rund1          s(p); s.draw(r);}
	    else if(w=="Rund2")          {Rund2          s(p); s.draw(r);}
	    else if(w=="Rund3")          {Rund3          s(p); s.draw(r);}
	    else if(w=="Achsevertflach") {Achsevertflach s(p); s.draw(r);}
	    else if(w=="Achseverthoch")  {Achseverthoch  s(p); s.draw(r);}
	    else if(w=="Achseeins2x1")   {Achseeins2x1   s(p); s.draw(r);}
	    else if(w=="Achseeins2x2")   {Achseeins2x2   s(p); s.draw(r);}
	    else if(w=="Achsezwei2x2")   {Achsezwei2x2   s(p); s.draw(r);}
	    else if(w=="Achsezwei2x4")   {Achsezwei2x4   s(p); s.draw(r);}
	    else if(w=="Achsevier")      {Achsevier      s(p); s.draw(r);}
	    else if(w=="Felge")          {Felge          s(p); s.draw(r);}
	    else if(w=="Reifen")         {Reifen         s(p); s.draw(r);}
	    else if(w=="Rad")            {Rad            s(p); s.draw(r);}
	    else if(w=="Test")           {Test           s(p); s.draw(r);}
	    else cerr<<"Warning: Line "<<l.number()<<": Bad keyword.\n";
	    if(imgcount)
		{
		ostrstream ostr;
		ostr<<"img"<<setfill('0')<<setw(4)<<imgcount++<<".ppm"<<ends;
		r.writeppm(ostr.str());
		ostr.freeze(0);
		}
	    }
	if(!l.more()) break;
	}
    r.writeppm();
    delete rp;
    return(0);
    }

//
