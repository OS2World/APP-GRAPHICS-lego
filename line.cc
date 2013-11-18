// line.cc	v1.0	4. March 1999	by eddy

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

#include "line.h"
#include <strstream.h>

static int lno = 0;	// Line number.

line::line(void)
	{
	linepar.x = linepar.y = linepar.z = 0;
	linepar.c = WHITE;
	linepar.d = N;
	moreflag = validflag = 1;
	lineno = ++lno;
	for(int i=0;i<MAXARGS;i++) linearg[i] = "";
	char tmp[MAXLL];
	cin.getline(tmp,MAXLL);
	if( !cin.eof() && cin.fail() )
		{
		cerr << "Warning: Line " << lineno << ": Line is too long.\n";
		cin.clear();
		int c;
		do c = cin.get(); while( (c!='\n')&&!cin.eof() );
		}
	if(cin.eof()) moreflag = 0;
	split(tmp,linearg,MAXARGS,RXwhite);
	if(linearg[0]=="")
		{
		for(int i=0;i<MAXARGS-1;i++) linearg[i] = linearg[i+1];
		linearg[MAXARGS-1] = "";
		}
	if(linearg[0]=="")          validflag = 0;
	else if(linearg[0][0]=='#') validflag = 0;
	else
		{
		for(int i=0;i<MAXARGS;i++) cerr << linearg[i] << ' '; 
//		cerr << '\t';
		}
	}

line::~line(void) { }

int line::valid(void)  { return validflag;  }

int line::more(void)   { return moreflag;   }

int line::number(void) { return lineno;     }

String line::keyword(void)    
	{ 
	return capitalize( downcase( linearg[0] ) ); 
	}

parameter line::par(void)     
	{
	if(!validflag) return linepar;
	char dirchar = '\0';
	istrstream xo(       linearg[1]);
	istrstream yo(       linearg[2]);
	istrstream zo(       linearg[3]);
	String colstr(upcase(linearg[4]));
	if(linearg[5]!="") dirchar = linearg[5][0];
	xo >> linepar.x;
	yo >> linepar.y;
	zo >> linepar.z;
	if(     colstr=="TRANSPARENT") linepar.c = TRANSPARENT;
	else if(colstr==      "BLACK") linepar.c = BLACK;
	else if(colstr==    "SCHWARZ") linepar.c = BLACK;
	else if(colstr==        "RED") linepar.c = RED;
	else if(colstr==        "ROT") linepar.c = RED;
	else if(colstr==     "YELLOW") linepar.c = YELLOW;
	else if(colstr==       "GELB") linepar.c = YELLOW;
	else if(colstr==      "GREEN") linepar.c = GREEN;
	else if(colstr==      "GRUEN") linepar.c = GREEN;
	else if(colstr== "LIGHTGREEN") linepar.c = LIGHTGREEN;
	else if(colstr==  "HELLGRUEN") linepar.c = LIGHTGREEN;
	else if(colstr==       "BLUE") linepar.c = BLUE;
	else if(colstr==       "BLAU") linepar.c = BLUE;
	else if(colstr==       "GREY") linepar.c = GREY;
	else if(colstr==       "GRAU") linepar.c = GREY;
	else if(colstr==      "WHITE") linepar.c = WHITE;
	else if(colstr==      "WEISS") linepar.c = WHITE;
	else cerr << "Warning: Line " << lineno << ": Bad color.\n";
	switch(dirchar)
		{
		case '\0':
		case 'n' :
		case 'N' : linepar.d = N; break;
		case 's' :
		case 'S' : linepar.d = S; break;
		case 'w' :
		case 'W' : linepar.d = W; break;
		case 'o' :
		case 'O' :
		case 'e' :
		case 'E' : linepar.d = E; break;
		default  : cerr<<"Warning: Line "<<lineno<<": Bad direction.\n";
		}
	return(linepar);
	}

String line::strarg(int i) { return linearg[i]; }

int line::intarg(int i)
	{
	istrstream istr(linearg[i]);
	int val;
	istr >> val;
	return val;
	}

float line::fltarg(int i)
	{
	istrstream istr(linearg[i]);
	float val;
	istr >> val;
	return val;
	}

//
