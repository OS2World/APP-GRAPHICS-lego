// colors.h	v1.0	21. March 1999	by eddy

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

char R[COLORS];
char G[COLORS];
char B[COLORS];
R[TRANSPARENT] =   0; G[TRANSPARENT] =   0; B[TRANSPARENT] =   0;
R[BLACK      ] =  80; G[BLACK      ] =  80; B[BLACK      ] =  80;
R[RED        ] = 255; G[RED        ] =  60; B[RED        ] =  50;
R[YELLOW     ] = 250; G[YELLOW     ] = 230; B[YELLOW     ] =   0;
R[GREEN      ] =  30; G[GREEN      ] = 200; B[GREEN      ] =  50;
R[LIGHTGREEN ] = 130; G[LIGHTGREEN ] = 210; B[LIGHTGREEN ] = 110;
R[BLUE       ] = 100; G[BLUE       ] = 120; B[BLUE       ] = 255;
R[GREY       ] = 170; G[GREY       ] = 170; B[GREY       ] = 170;
R[WHITE      ] = 250; G[WHITE      ] = 250; B[WHITE      ] = 250;
R[OUTLINE    ] =   0; G[OUTLINE    ] =   0; B[OUTLINE    ] =   0;
R[BACKGROUND ] = 255; G[BACKGROUND ] = 255; B[BACKGROUND ] = 255;

//