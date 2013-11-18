// room.h   v1.0    15. April 1999  by eddy

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

#ifndef _ROOM_H
#define _ROOM_H

#include "vector.h"
#include "rotator.h"
#include "global.h"
#include <Strng.h>

class room
    {
    friend class signature;

    private:
    int room_xsize;
    int room_ysize;
    int room_zsize;
    vector room_size;
    unsigned short** room_depth;
    rotator rr;
    static const double room_delta = 0.7;
    double room_scale;
    double room_zexpand;
    vector rotate(const vector&);
    /*inline*/ void goal(void);
    /*inline*/ void nogoal(void);
    inline void putpixel(int x,int y,int z,color c);
    void dodot(const vector&,color);
    void doline(const vector&,const vector&,color);
    void doarea(const vector&,const vector&,const vector&,color);
    void doarc(const vector&,vector,const vector&,double,color);
    void docircle(const vector& o,const vector& d,double radius,color col);
    void dodisc(const vector& o,const vector& d,double radius,color col);
    void doring(const vector& o,const vector& d,double r1,double r2,color col);
    void dosector(const vector& o,const vector& d,vector r,double angel,color col);
    void docylsector(const vector& o,const vector& h,const vector& r,double angel,color col);
    void docyl(const vector& o,vector d,double radius,color col);
    void dotriang(const vector& o,const vector& p,const vector& q,color col);

    public:
    room(int pixel,const vector& size,double alpha,double beta);
    ~room(void);
//  void dot(const vector&,color,const rotator&);
    void line(const vector& o,const vector& p,color col,const rotator&);
    void area(const vector& o,const vector& p,const vector& q,color col,const rotator&);
    void arc(const vector& o,const vector& d,const vector& r,double angel,color col,const rotator&);
    void circle(const vector& o,const vector& d,double radius,color col,const rotator&);
    void disc(const vector& o,const vector& d,double radius,color col,const rotator&);
    void ring(const vector& o,const vector& d,double r1,double r2,color col,const rotator&);
    void sector(const vector& o,const vector& d,const vector& r,double angel,color col,const rotator&);
    void cylsector(const vector& o,const vector& h,const vector& r,double angel,color col,const rotator&);
    void cyl(const vector& o,const vector& d,double radius,color col,const rotator&);
    void triang(const vector& o,const vector& p,const vector& q,color col,const rotator&);
    void writeppm(void);
    void writeppm(const String &);
    };

#endif // _ROOM_H
