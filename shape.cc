// shape.cc v1.0    22. April 1999  by eddy

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

#include "shape.h"
#include <stdlib.h>
#include <math.h>
#include <float.h>

shape::shape(void) { }

shape::~shape(void) { }

void shape::draw(room&) { }

body::body(const vector& org,const vector& siz,color col,const rotator& rot)
    {
    sha_org = org;
    sha_siz = siz;
    sha_col = col;
    sha_rot = rot;
    }

void body::draw(room& r)
    {
    double x = sha_siz.x();
    double y = sha_siz.y();
    double z = sha_siz.z();
    vector a = sha_org;
    vector b = sha_org + vector(x,0,0);
    vector c = sha_org + vector(0,y,0);
    vector d = sha_org + vector(x,y,0);
    vector e = sha_org + vector(0,0,z);
    vector f = sha_org + vector(x,0,z);
    vector g = sha_org + vector(0,y,z);
    vector h = sha_org + vector(x,y,z);
    r.area(a,b,e,sha_col,sha_rot);
    r.area(a,c,e,sha_col,sha_rot);
    r.area(b,d,f,sha_col,sha_rot);
    r.area(c,d,g,sha_col,sha_rot);
    r.area(e,f,g,sha_col,sha_rot);
    r.line(a,b,OUTLINE,sha_rot);
    r.line(e,f,OUTLINE,sha_rot);
    r.line(a,e,OUTLINE,sha_rot);
    r.line(b,f,OUTLINE,sha_rot);
    r.line(a,c,OUTLINE,sha_rot);
    r.line(b,d,OUTLINE,sha_rot);
    r.line(e,g,OUTLINE,sha_rot);
    r.line(f,h,OUTLINE,sha_rot);
    r.line(c,d,OUTLINE,sha_rot);
    r.line(g,h,OUTLINE,sha_rot);
    r.line(c,g,OUTLINE,sha_rot);
    r.line(d,h,OUTLINE,sha_rot);
    }

knob::knob(const vector& org,color col,const rotator& rot)
    {
    sha_org = org;
    sha_siz = vector(0,0,0.6);
    sha_col = col;
    sha_rot = rot;
    }

knob::knob(const vector& org,const vector& d,color col,const rotator& rot)
    {
    sha_org = org;
    sha_siz = d.unit()*0.24;
    sha_col = col;
    sha_rot = rot;
    }

void knob::draw(room& r)
    {
    vector org2(sha_org+sha_siz);
    r.cyl(sha_org,sha_siz,0.3,OUTLINE,sha_rot);
    r.disc(org2,sha_siz,0.3,sha_col,sha_rot);
    }

roofbody::roofbody(const vector& org,const vector& siz,color col,const rotator& rot)
    {
    sha_org = org;
    sha_siz = siz;
    sha_col = col;
    sha_rot = rot;
    }

void roofbody::draw(room& r)
    {
    double x = sha_siz.x();
    double y = sha_siz.y();
    double z = sha_siz.z();
    vector lr(x,0,0);
    vector al = sha_org;
    vector bl = sha_org + vector(0,0,z);
    vector cl = sha_org + vector(0,y,0);
    vector dl = sha_org + vector(0,1,z);
    vector el = sha_org + vector(0,y,0.63);
    vector fl = sha_org + vector(0,0,0.63);
    vector gl = sha_org + vector(0,1,0.63);
    vector ar = al + lr;
    vector br = bl + lr;
    vector cr = cl + lr;
    vector dr = dl + lr;
    vector er = el + lr;
    vector fr = fl + lr;
    vector gr = gl + lr;
    r.area(al,bl,ar,sha_col,sha_rot);
    r.area(bl,dl,br,sha_col,sha_rot);
    r.area(dl,el,dr,sha_col,sha_rot);
    r.area(cl,el,cr,sha_col,sha_rot);
    r.area(bl,al,dl,sha_col,sha_rot);
    r.area(br,ar,dr,sha_col,sha_rot);
    r.area(er,cr,gr,sha_col,sha_rot);
    r.area(el,cl,gl,sha_col,sha_rot);
    r.triang(dl,gl,el,sha_col,sha_rot);
    r.triang(dr,gr,er,sha_col,sha_rot);
    r.line(al,ar,OUTLINE,sha_rot);
    r.line(bl,br,OUTLINE,sha_rot);
    r.line(cl,cr,OUTLINE,sha_rot);
    r.line(dl,dr,OUTLINE,sha_rot);
    r.line(el,er,OUTLINE,sha_rot);
    r.line(al,bl,OUTLINE,sha_rot);
    r.line(ar,br,OUTLINE,sha_rot);
    r.line(al,cl,OUTLINE,sha_rot);
    r.line(ar,cr,OUTLINE,sha_rot);
    r.line(br,dr,OUTLINE,sha_rot);
    r.line(bl,dl,OUTLINE,sha_rot);
    r.line(dl,el,OUTLINE,sha_rot);
    r.line(dr,er,OUTLINE,sha_rot);
    r.line(cl,el,OUTLINE,sha_rot);
    r.line(cr,er,OUTLINE,sha_rot);
    }

rooftop::rooftop(const vector& org,const vector& siz,color col,const rotator& rot)
    {
    sha_org = org;
    sha_siz = siz;
    sha_col = col;
    sha_rot = rot;
    }

void rooftop::draw(room& r)
    {
    vector x(sha_siz.x(),0,0);
    vector y(0,sha_siz.y(),0);
    vector z(0,0,sha_siz.z());
    vector z1(0,0,0.63);
    vector al(sha_org);
    vector bl(sha_org+y);
    vector cl(al+z1);
    vector dl(bl+z1);
    vector el(sha_org+y*0.5+z);
    vector ar(al+x);
    vector br(bl+x);
    vector cr(cl+x);
    vector dr(dl+x);
    vector er(el+x);
    r.area(al,bl,cl,sha_col,sha_rot);
    r.area(ar,br,cr,sha_col,sha_rot);
    r.area(al,ar,cl,sha_col,sha_rot);
    r.area(bl,br,dl,sha_col,sha_rot);
    r.area(cl,cr,el,sha_col,sha_rot);
    r.area(dl,dr,el,sha_col,sha_rot);
    r.triang(el,cl,dl,sha_col,sha_rot);
    r.triang(er,cr,dr,sha_col,sha_rot);
    r.line(al,bl,OUTLINE,sha_rot);
    r.line(ar,br,OUTLINE,sha_rot);
    r.line(al,ar,OUTLINE,sha_rot);
    r.line(bl,br,OUTLINE,sha_rot);
    r.line(cl,cr,OUTLINE,sha_rot);
    r.line(dl,dr,OUTLINE,sha_rot);
    r.line(el,er,OUTLINE,sha_rot);
    r.line(al,cl,OUTLINE,sha_rot);
    r.line(ar,cr,OUTLINE,sha_rot);
    r.line(bl,dl,OUTLINE,sha_rot);
    r.line(br,dr,OUTLINE,sha_rot);
    r.line(cl,el,OUTLINE,sha_rot);
    r.line(dl,el,OUTLINE,sha_rot);
    r.line(cr,er,OUTLINE,sha_rot);
    r.line(dr,er,OUTLINE,sha_rot);
    }

roofcornerbody::roofcornerbody(const vector& org,const vector& siz,color col,const rotator& rot)
    {
    sha_org = org;
    sha_siz = siz;
    sha_col = col;
    sha_rot = rot;
    }

void roofcornerbody::draw(room& r)
    {
    vector x0(sha_org.x(),0,0);
    vector x1(sha_org.x()+1,0,0);
    vector x2(sha_org.x()+sha_siz.x(),0,0);
    vector y0(0,sha_org.y(),0);
    vector y1(0,sha_org.y()+1,0);
    vector y2(0,sha_org.y()+sha_siz.y(),0);
    vector z0(0,0,sha_org.z());
    vector z1(0,0,sha_org.z()+0.63);
    vector z2(0,0,sha_org.z()+sha_siz.z());
    vector a(x0+y0+z0);
    vector b(x2+y0+z0);
    vector c(x2+y2+z0);
    vector d(x0+y2+z0);
    vector e(x1+y0+z1);
    vector f(x2+y0+z1);
    vector g(x2+y2+z1);
    vector h(x0+y2+z1);
    vector i(x0+y1+z1);
    vector j(x0+y0+z2);
    vector k(x1+y0+z2);
    vector l(x1+y1+z2);
    vector m(x0+y1+z2);
    vector n(x2+y1+z1);
    vector o(x1+y2+z1);
    r.area(b,a,f,sha_col,sha_rot);
    r.area(b,c,f,sha_col,sha_rot);
    r.area(c,g,d,sha_col,sha_rot);
    r.area(d,h,a,sha_col,sha_rot);
    r.area(k,j,e,sha_col,sha_rot);
    r.area(m,i,j,sha_col,sha_rot);
    r.area(j,k,m,sha_col,sha_rot);
    r.area(k,f,l,sha_col,sha_rot);
    r.area(m,l,h,sha_col,sha_rot);
    r.triang(e,f,k,sha_col,sha_rot);
    r.triang(i,h,m,sha_col,sha_rot);
    r.triang(n,l,g,sha_col,sha_rot);
    r.triang(o,l,g,sha_col,sha_rot);
    r.line(a,b,OUTLINE,sha_rot);
    r.line(b,c,OUTLINE,sha_rot);
    r.line(c,d,OUTLINE,sha_rot);
    r.line(d,a,OUTLINE,sha_rot);
    r.line(b,f,OUTLINE,sha_rot);
    r.line(c,g,OUTLINE,sha_rot);
    r.line(d,h,OUTLINE,sha_rot);
    r.line(f,g,OUTLINE,sha_rot);
    r.line(g,h,OUTLINE,sha_rot);
    r.line(a,j,OUTLINE,sha_rot);
    r.line(f,k,OUTLINE,sha_rot);
    r.line(g,l,OUTLINE,sha_rot);
    r.line(h,m,OUTLINE,sha_rot);
    r.line(j,k,OUTLINE,sha_rot);
    r.line(k,l,OUTLINE,sha_rot);
    r.line(l,m,OUTLINE,sha_rot);
    r.line(m,j,OUTLINE,sha_rot);
    }

cornerbody::cornerbody(const vector& org,const vector& siz,color col,const rotator& rot)
    {
    sha_org = org;
    sha_siz = siz;
    sha_col = col;
    sha_rot = rot;
    }

void cornerbody::draw(room& r)
    {
    vector x0(sha_org.x(),0,0);
    vector x1(sha_org.x()+1,0,0);
    vector x2(sha_org.x()+sha_siz.x(),0,0);
    vector y0(0,sha_org.y(),0);
    vector y1(0,sha_org.y()+1,0);
    vector y2(0,sha_org.y()+sha_siz.y(),0);
    vector z0(0,0,sha_org.z());
    vector z1(0,0,sha_org.z()+sha_siz.z());
    vector a(x0+y0+z0);
    vector b(x2+y0+z0);
    vector c(x2+y1+z0);
    vector d(x1+y1+z0);
    vector e(x1+y2+z0);
    vector f(x0+y2+z0);
    vector g(x0+y0+z1);
    vector h(x2+y0+z1);
    vector i(x2+y1+z1);
    vector j(x1+y1+z1);
    vector k(x1+y2+z1);
    vector l(x0+y2+z1);
    r.area(a,b,g,sha_col,sha_rot);
    r.area(a,f,g,sha_col,sha_rot);
    r.area(d,c,j,sha_col,sha_rot);
    r.area(d,e,j,sha_col,sha_rot);
    r.area(b,c,h,sha_col,sha_rot);
    r.area(f,e,l,sha_col,sha_rot);
    r.area(h,g,i,sha_col,sha_rot);
    r.area(k,j,l,sha_col,sha_rot);
    r.line(a,b,OUTLINE,sha_rot);
    r.line(b,c,OUTLINE,sha_rot);
    r.line(c,d,OUTLINE,sha_rot);
    r.line(d,e,OUTLINE,sha_rot);
    r.line(e,f,OUTLINE,sha_rot);
    r.line(f,a,OUTLINE,sha_rot);
    r.line(g,h,OUTLINE,sha_rot);
    r.line(h,i,OUTLINE,sha_rot);
    r.line(i,j,OUTLINE,sha_rot);
    r.line(j,k,OUTLINE,sha_rot);
    r.line(k,l,OUTLINE,sha_rot);
    r.line(l,g,OUTLINE,sha_rot);
    r.line(a,g,OUTLINE,sha_rot);
    r.line(b,h,OUTLINE,sha_rot);
    r.line(c,i,OUTLINE,sha_rot);
    r.line(d,j,OUTLINE,sha_rot);
    r.line(e,k,OUTLINE,sha_rot);
    r.line(f,l,OUTLINE,sha_rot);
    }

roundbody::roundbody(const vector& org,const vector& siz,color col,const rotator& rot)
    {
    sha_org = org;
    sha_siz = siz;
    sha_col = col;
    sha_rot = rot;
    }

void roundbody::draw(room& r)
    {
    vector d(0,0,1);
    vector o(sha_org+vector(0.5,0.5,0));
    double r1 = 0.4;
    double r2 = 0.5;
    r.circle(o,d,r1,OUTLINE,sha_rot);
    vector h = d*0.6;
    r.cyl(o,h,r1,sha_col,sha_rot);
    o += h;
    r.circle(o,d,r1,OUTLINE,sha_rot);
    r.circle(o,d,r2,OUTLINE,sha_rot);
    r.ring(o,d,r1,r2,sha_col,sha_rot);
    h = d*(sha_siz.z()-0.6);
    r.cyl(o,h,r2,sha_col,sha_rot);
    o += h;
    r.circle(o,d,r2,OUTLINE,sha_rot);
    r1 = 0.3;
    r.ring(o,d,r1,r2,sha_col,sha_rot);
    }

round1body::round1body(const vector& org,const vector& siz,color col,const rotator& rot)
    {
    sha_org = org;
    sha_siz = siz;
    sha_col = col;
    sha_rot = rot;
    }

void round1body::draw(room& r)
    {
    vector x0(sha_siz.x(),0,0);
    vector y0(0,sha_siz.y(),0);
    vector y1(0,sha_siz.y()-1,0);
    vector z0(0,0,sha_siz.z());
    vector z1(0,0,sha_siz.z()-2.5);
    vector al(sha_org);
    vector bl(sha_org+z0);
    vector cl(sha_org+y0);
    vector dl(sha_org+y1+z0);
    vector el(sha_org+y0+z1);
    vector fl(sha_org+y1+z1);
    vector gl(sha_org+y1);
    vector ar(al+x0);
    vector br(bl+x0);
    vector cr(cl+x0);
    vector dr(dl+x0);
    vector er(el+x0);
    vector fr(fl+x0);
    vector gr(gl+x0);
    r.area(bl,dl,br,sha_col,sha_rot);
    r.area(al,bl,ar,sha_col,sha_rot);
    r.area(al,bl,gl,sha_col,sha_rot);
    r.area(ar,br,gr,sha_col,sha_rot);
    r.area(gl,cl,fl,sha_col,sha_rot);
    r.area(gr,cr,fr,sha_col,sha_rot);
    r.area(cl,el,cr,sha_col,sha_rot);
    r.sector(fl,x0,el-fl,90,sha_col,sha_rot);
    r.sector(fr,x0,er-fr,90,sha_col,sha_rot);
    r.cylsector(fl,x0,el-fl,90,sha_col,sha_rot);
    r.line(al,cl,OUTLINE,sha_rot);
    r.line(ar,cr,OUTLINE,sha_rot);
    r.line(al,bl,OUTLINE,sha_rot);
    r.line(ar,br,OUTLINE,sha_rot);
    r.line(bl,dl,OUTLINE,sha_rot);
    r.line(br,dr,OUTLINE,sha_rot);
    r.line(al,ar,OUTLINE,sha_rot);
    r.line(bl,br,OUTLINE,sha_rot);
    r.line(cl,cr,OUTLINE,sha_rot);
    r.line(cl,el,OUTLINE,sha_rot);
    r.line(cr,er,OUTLINE,sha_rot);
    r.arc(fl,x0,el-fl,90,OUTLINE,sha_rot);
    r.arc(fr,x0,er-fr,90,OUTLINE,sha_rot);
    }

round2body::round2body(const vector& org,const vector& siz,color col,const rotator& rot)
    {
    sha_org = org;
    sha_siz = siz;
    sha_col = col;
    sha_rot = rot;
    }

void round2body::draw(room& r)
    {
    vector x0(sha_siz.x(),0,0);
    vector x1(-sha_siz.x(),0,0);
    vector y0(0,sha_siz.y(),0);
    vector y1(0,1,0);
    vector y2(0,sha_siz.y()-1,0);
    vector z0(0,0,sha_siz.z());
    vector z1(0,0,sha_siz.z()-2.5);
    vector al(sha_org);
    vector bl(sha_org+y1+z0);
    vector cl(sha_org+y0);
    vector dl(sha_org+y2+z0);
    vector el(sha_org+y0+z1);
    vector fl(sha_org+y2+z1);
    vector gl(sha_org+y1+z1);
    vector hl(sha_org+z1);
    vector ar(al+x0);
    vector br(bl+x0);
    vector cr(cl+x0);
    vector dr(dl+x0);
    vector er(el+x0);
    vector fr(fl+x0);
    vector gr(gl+x0);
    vector hr(hl+x0);
    r.area(bl,dl,br,sha_col,sha_rot);
    r.area(al,hl,ar,sha_col,sha_rot);
    r.area(gl,fl,bl,sha_col,sha_rot);
    r.area(gr,fr,br,sha_col,sha_rot);
    r.area(al,cl,hl,sha_col,sha_rot);
    r.area(ar,cr,hr,sha_col,sha_rot);
    r.area(cl,el,cr,sha_col,sha_rot);
    r.sector(gl,x1,hl-gl,90,sha_col,sha_rot);
    r.sector(gr,x1,hr-gr,90,sha_col,sha_rot);
    r.sector(fl,x0,el-fl,90,sha_col,sha_rot);
    r.sector(fr,x0,er-fr,90,sha_col,sha_rot);
    r.cylsector(gr,x1,hr-gr,90,sha_col,sha_rot);
    r.cylsector(fl,x0,el-fl,90,sha_col,sha_rot);
    r.line(al,cl,OUTLINE,sha_rot);
    r.line(ar,cr,OUTLINE,sha_rot);
    r.line(al,hl,OUTLINE,sha_rot);
    r.line(ar,hr,OUTLINE,sha_rot);
    r.line(bl,dl,OUTLINE,sha_rot);
    r.line(br,dr,OUTLINE,sha_rot);
    r.line(al,ar,OUTLINE,sha_rot);
    r.line(cl,cr,OUTLINE,sha_rot);
    r.line(cl,el,OUTLINE,sha_rot);
    r.line(cr,er,OUTLINE,sha_rot);
    r.arc(gl,x1,hl-gl,90,OUTLINE,sha_rot);
    r.arc(gr,x1,hr-gr,90,OUTLINE,sha_rot);
    r.arc(fl,x0,el-fl,90,OUTLINE,sha_rot);
    r.arc(fr,x0,er-fr,90,OUTLINE,sha_rot);
    }

round3::round3(const vector& org,const vector& siz,color col,const rotator& rot)
    {
    sha_org = org;
    sha_siz = siz;
    sha_col = col;
    sha_rot = rot;
    }

void round3::draw(room& r)
    {
    vector x0(sha_org.x(),0,0);
    vector xd(sha_siz.x(),0,0);
    vector y0(0,sha_org.y(),0);
    vector y1(y0+vector(0,1,0));
    vector y2(y0+vector(0,2,0));
    vector y3(y0+vector(0,3,0));
    vector y4(y0+vector(0,4,0));
    vector z0(0,0,sha_org.z());
    vector z1(z0+vector(0,0,0.5));
    vector z2(z0+vector(0,0,3));
    vector z3(z0+vector(0,0,3.5));
    vector al(x0+y0+z0);
    vector bl(x0+y1+z2);
    vector cl(x0+y4+z0);
    vector dl(x0+y3+z2);
    vector el(x0+y4+z1);
    vector fl(x0+y3+z1);
    vector gl(x0+y1+z1);
    vector hl(x0+y0+z1);
    vector il(x0+y3+z3);
    vector jl(x0+y1+z3);
    vector kl(x0+y2+z3);
    vector ar(al+xd);
    vector br(bl+xd);
    vector cr(cl+xd);
    vector dr(dl+xd);
    vector er(el+xd);
    vector fr(fl+xd);
    vector gr(gl+xd);
    vector hr(hl+xd);
    vector ir(il+xd);
    vector jr(jl+xd);
    vector kr(kl+xd);
    r.area(dl,il,dr,sha_col,sha_rot);
    r.area(bl,jl,br,sha_col,sha_rot);
    r.area(al,hl,ar,sha_col,sha_rot);
    r.area(gl,fl,jl,sha_col,sha_rot);
    r.area(gr,fr,jr,sha_col,sha_rot);
    r.area(al,cl,hl,sha_col,sha_rot);
    r.area(ar,cr,hr,sha_col,sha_rot);
    r.area(cl,el,cr,sha_col,sha_rot);
    r.sector(gl,xd,bl-gl,90,sha_col,sha_rot);
    r.sector(gr,xd,br-gr,90,sha_col,sha_rot);
    r.sector(fl,xd,el-fl,90,sha_col,sha_rot);
    r.sector(fr,xd,er-fr,90,sha_col,sha_rot);
    r.sector(kl,xd,il-kl,180,sha_col,sha_rot);
    r.sector(kr,xd,ir-kr,180,sha_col,sha_rot);
    r.cylsector(gl,xd,br-gr,90,sha_col,sha_rot);
    r.cylsector(fl,xd,el-fl,90,sha_col,sha_rot);
    r.cylsector(kl,xd,il-kl,180,sha_col,sha_rot);
    r.line(dl,il,OUTLINE,sha_rot);
    r.line(dr,ir,OUTLINE,sha_rot);
    r.line(bl,jl,OUTLINE,sha_rot);
    r.line(br,jr,OUTLINE,sha_rot);
    r.line(al,cl,OUTLINE,sha_rot);
    r.line(ar,cr,OUTLINE,sha_rot);
    r.line(al,hl,OUTLINE,sha_rot);
    r.line(ar,hr,OUTLINE,sha_rot);
    r.line(bl,br,OUTLINE,sha_rot);
    r.line(dl,dr,OUTLINE,sha_rot);
    r.line(al,ar,OUTLINE,sha_rot);
    r.line(cl,cr,OUTLINE,sha_rot);
    r.line(cl,el,OUTLINE,sha_rot);
    r.line(cr,er,OUTLINE,sha_rot);
    r.arc(kl,xd,il-kl,180,OUTLINE,sha_rot);
    r.arc(kr,xd,ir-kr,180,OUTLINE,sha_rot);
    r.arc(gl,xd,bl-gl,90,OUTLINE,sha_rot);
    r.arc(gr,xd,br-gr,90,OUTLINE,sha_rot);
    r.arc(fl,xd,el-fl,90,OUTLINE,sha_rot);
    r.arc(fr,xd,er-fr,90,OUTLINE,sha_rot);
    }

navepin1::navepin1(const vector& org,const vector& d,color col,const rotator& rot)
    {
    sha_org = org;
    sha_siz = d;
    sha_col = col;
    sha_rot = rot;
    }

void navepin1::draw(room& r)
    {
    vector org(sha_org);
//  r.circle(org,sha_siz,0.37,OUTLINE,sha_rot);
    r.cyl(org,sha_siz*0.1,0.37,OUTLINE,sha_rot);
    org += sha_siz*0.1;
//  r.circle(org,sha_siz,0.37,OUTLINE,sha_rot);
    r.ring(org,sha_siz,0.3,0.37,sha_col,sha_rot);
//  r.circle(org,sha_siz,0.3,OUTLINE,sha_rot);
    r.cyl(org,sha_siz*0.9,0.3,OUTLINE,sha_rot);
    org = sha_org + sha_siz;
//  r.circle(org,sha_siz,0.3,OUTLINE,sha_rot);
    r.ring(org,sha_siz,0.15,0.3,sha_col,sha_rot);
    r.disc(org,sha_siz,0.15,OUTLINE,sha_rot);
    }

felloebody::felloebody(const vector& org,const vector& d,color col,const rotator& rot)
    {
    sha_org = org;
    sha_siz = d;
    sha_col = col;
    sha_rot = rot;
    }

void felloebody::draw(room& r)
    {
    vector org(sha_org);
//  r.circle(org,sha_siz,0.38,OUTLINE,sha_rot);
    r.circle(org,sha_siz,0.50,OUTLINE,sha_rot);
    r.ring(org,sha_siz,0.38,0.50,sha_col,sha_rot);
//  r.circle(org,sha_siz,0.74,OUTLINE,sha_rot);
    r.circle(org,sha_siz,1.05,OUTLINE,sha_rot);
    r.ring(org,sha_siz,0.74,1.05,sha_col,sha_rot);
    r.cyl(org,sha_siz*0.1,0.38,OUTLINE,sha_rot);
    r.cyl(org,sha_siz*0.9,0.50,sha_col,sha_rot);
    r.cyl(org,sha_siz*0.9,0.74,OUTLINE,sha_rot);
    r.cyl(org,sha_siz*0.2,1.05,sha_col,sha_rot);
    org += sha_siz*0.1;
//  r.circle(org,sha_siz,0.38,OUTLINE,sha_rot);
    r.ring(org,sha_siz,0.3,0.38,sha_col,sha_rot);
//  r.circle(org,sha_siz,0.3,OUTLINE,sha_rot);
    r.cyl(org,sha_siz*0.8,0.3,OUTLINE,sha_rot);
    org += sha_siz*0.1;
    r.circle(org,sha_siz,1.05,OUTLINE,sha_rot);
    r.ring(org,sha_siz,0.9,1.05,sha_col,sha_rot);
    r.circle(org,sha_siz,0.9,OUTLINE,sha_rot);
    r.cyl(org,sha_siz*0.6,0.9,sha_col,sha_rot);
    org += sha_siz*0.6;
    r.ring(org,sha_siz,0.9,1.05,sha_col,sha_rot);
    r.circle(org,sha_siz,1.05,OUTLINE,sha_rot);
    r.cyl(org,sha_siz*0.2,1.05,sha_col,sha_rot);
    r.circle(org,sha_siz,0.9,OUTLINE,sha_rot);
    org += sha_siz*0.1;
//  r.circle(org,sha_siz,0.3,OUTLINE,sha_rot);
    r.ring(org,sha_siz,0.3,0.38,sha_col,sha_rot);
//  r.circle(org,sha_siz,0.38,OUTLINE,sha_rot);
    r.cyl(org,sha_siz*0.1,0.38,OUTLINE,sha_rot);
    r.circle(org,sha_siz,0.5,OUTLINE,sha_rot);
//  r.circle(org,sha_siz,0.74,OUTLINE,sha_rot);
    r.ring(org,sha_siz,0.5,0.74,sha_col,sha_rot);
    org = sha_org+sha_siz;
    r.circle(org,sha_siz,1.05,OUTLINE,sha_rot);
    r.ring(org,sha_siz,0.38,1.05,sha_col,sha_rot);
//  r.circle(org,sha_siz,0.38,OUTLINE,sha_rot);
    }

tire::tire(const vector& org,const vector& d,color col,const rotator& rot)
    {
    sha_org = org;
    sha_siz = d;
    sha_col = col;
    sha_rot = rot;
    }

void tire::draw(room& r)
    {
    const double R1 = 1.05;
    const double R2 = 1.22;
    const double R3 = 1.53;
    const double SF = R2/R3;
    const int NIPS = 2*22;
    const double W = 2.0*M_PI/(int)NIPS;
    vector org(sha_org);
//  r.circle(org,sha_siz,R1,OUTLINE,sha_rot);
    r.ring(org,sha_siz,R1,R2,sha_col,sha_rot);
    r.cyl(org,sha_siz,R1,OUTLINE,sha_rot);
    r.cyl(org,sha_siz,R2,sha_col,sha_rot);
    org += sha_siz;
//  r.circle(org,sha_siz,R1,OUTLINE,sha_rot);
    r.ring(org,sha_siz,R1,R2,sha_col,sha_rot);
    org = sha_org + sha_siz*0.5;
    r.circle(org,sha_siz,R2,OUTLINE,sha_rot);
    r.circle(org,sha_siz,R3,OUTLINE,sha_rot);
    r.ring(org,sha_siz,R2,R3,sha_col,sha_rot);
    vector vz(sha_siz*0.5);
    vector v0(0,0,2.5*R3);
    vector v2(v0*SF);
    for(int i=1;i<=NIPS;i++)
        {
        vector v1(R3*sin(W*i),0,R3*2.5*cos(W*i));
        vector v3(v1*SF);
        r.line(org+v1-vz,org+v1+vz,OUTLINE,sha_rot);
        r.line(org+v3-vz,org+v3+vz,OUTLINE,sha_rot);
        r.line(org+v0+vz,org+v1+vz,OUTLINE,sha_rot);
        r.line(org+v1+vz,org+v3+vz,OUTLINE,sha_rot);
        r.line(org+v0+vz,org+v2+vz,OUTLINE,sha_rot);
        r.line(org+v2-vz,org+v3-vz,OUTLINE,sha_rot);
        r.line(org+v1,org+v3,OUTLINE,sha_rot);
        r.area(org+v1,org+v1+vz,org+v0,sha_col,sha_rot);
        r.area(org+v1,org+v1+vz,org+v3,sha_col,sha_rot);
        r.area(org+v0,org+v0+vz,org+v2,sha_col,sha_rot);
        r.triang(org+vz+v1,org+vz+v0,org+vz+v2,sha_col,sha_rot);
        r.triang(org+vz+v1,org+vz+v2,org+vz+v3,sha_col,sha_rot);
        v0 = v1;
        v2 = v3;
        vz *= -1;
        }
    }

//////////////////////////////////////////////////////////////////////////////

group::group(void) { }

group::~group(void)
    {
    int i=0;
    while(grp_shape[i]!=NULL)
        delete grp_shape[i++];
    }

void group::draw(room& r)
    {
    int i=0;
    while(grp_shape[i]!=NULL)
        {
        grp_shape[i++]->draw(r);
        }
    }

//////////////////////////////////////////////////////////////////////////////

brick::brick(const vector& org,const vector& siz,color col,const rotator& rot)
    {
    grp_shape = bri_shape;
    sha_org   = org;
    sha_siz   = siz;
    sha_col   = col;
    sha_rot   = rot;
    int i=0;
    bri_shape[i++] = new body(sha_org,sha_siz,sha_col,sha_rot);
    vector ocyl(sha_org+vector(0.5,0.5,sha_siz.z()));
    vector xcyl(1,0,0);
    vector ycyl(0,1,0);
    for(int xx=0;xx<sha_siz.x();xx++) for(int yy=0;yy<sha_siz.y();yy++)
        {
        vector o((xcyl*xx)+(ycyl*yy)+ocyl);
        bri_shape[i++] = new knob(o,sha_col,sha_rot);
        }
    bri_shape[i] = NULL;
    }

ground::ground(const vector& org,const vector& siz,color col,const rotator& rot)
    {
    grp_shape = gro_shape;
    sha_org = org-vector(0,0,siz.z());
    sha_siz = siz;
    sha_col = col;
    sha_rot = rot;
    int i=0;
    gro_shape[i++] = new body(sha_org,sha_siz,sha_col,sha_rot);
    vector ocyl(sha_org+vector(0.5,0.5,sha_siz.z()));
    vector xcyl(1,0,0);
    vector ycyl(0,1,0);
    int x = (int)sha_siz.x();
    int y = (int)sha_siz.y();
    for(int xx=0;xx<x;xx++) for(int yy=0;yy<y;yy++)
        {
        vector o((xcyl*xx)+(ycyl*yy)+ocyl);
        gro_shape[i++] = new knob(o,sha_col,sha_rot);
        }
    gro_shape[i] = NULL;
    }

roof::roof(const vector& org,const vector& siz,color col,const rotator& rot)
    {
    grp_shape = roof_shape;
    sha_org = org;
    sha_siz = siz;
    sha_col = col;
    sha_rot = rot;
    int i=0;
    roof_shape[i++] = new roofbody(sha_org,sha_siz,sha_col,sha_rot);
    vector ocyl(sha_org+vector(0.5,0.5,sha_siz.z()));
    vector xcyl(1,0,0);
    int x = (int)sha_siz.x();
    for(int xx=0;xx<x;xx++)
        {
        vector o((xcyl*xx)+ocyl);
        roof_shape[i++] = new knob(o,sha_col,sha_rot);
        }
    roof_shape[i] = NULL;
    }

roofcorner::roofcorner(const vector& org,const vector& siz,color col,const rotator& rot)
    {
    grp_shape = roofcorner_shape;
    sha_org = org;
    sha_siz = siz;
    sha_col = col;
    sha_rot = rot;
    int i=0;
    roofcorner_shape[i++] = new roofcornerbody(sha_org,sha_siz,sha_col,sha_rot);
    vector o(sha_org+vector(0.5,0.5,sha_siz.z()));
    roofcorner_shape[i++] = new knob(o,sha_col,sha_rot);
    roofcorner_shape[i] = NULL;
    }

corner::corner(const vector& org,const vector& siz,color col,const rotator& rot)
    {
    grp_shape = corner_shape;
    sha_org = org;
    sha_siz = siz;
    sha_col = col;
    sha_rot = rot;
    int i=0;
    corner_shape[i++] = new cornerbody(sha_org,sha_siz,sha_col,sha_rot);
    vector o0(sha_org+vector(0.5,0.5,sha_siz.z()));
    vector o1(o0+vector(1,0,0));
    vector o2(o0+vector(0,1,0));
    corner_shape[i++] = new knob(o0,sha_col,sha_rot);
    corner_shape[i++] = new knob(o1,sha_col,sha_rot);
    corner_shape[i++] = new knob(o2,sha_col,sha_rot);
    corner_shape[i] = NULL;
    }

round::round(const vector& org,const vector& siz,color col,const rotator& rot)
    {
    grp_shape = round_shape;
    sha_org = org;
    sha_siz = siz;
    sha_col = col;
    sha_rot = rot;
    int i=0;
    round_shape[i++] = new roundbody(sha_org,sha_siz,sha_col,sha_rot);
    vector ocyl(sha_org+vector(0.5,0.5,sha_siz.z()));
    round_shape[i++] = new knob(ocyl,sha_col,sha_rot);
    round_shape[i] = NULL;
    }

round1::round1(const vector& org,const vector& siz,color col,const rotator& rot)
    {
    grp_shape = round1_shape;
    sha_org = org;
    sha_siz = siz;
    sha_col = col;
    sha_rot = rot;
    int i=0;
    round1_shape[i++] = new round1body(sha_org,sha_siz,sha_col,sha_rot);
    vector ocyl(sha_org+vector(0.5,0.5,sha_siz.z()));
    vector xcyl(1,0,0);
    vector ycyl(0,1,0);
    int x = (int)sha_siz.x();
    int y = (int)sha_siz.y();
    for(int yy=0;yy<y-1;yy++) for(int xx=0;xx<x;xx++)
        {
        vector o(xcyl*xx+ycyl*yy+ocyl);
        round1_shape[i++] = new knob(o,sha_col,sha_rot);
        }
    round1_shape[i] = NULL;
    }

round2::round2(const vector& org,const vector& siz,color col,const rotator& rot)
    {
    grp_shape = round2_shape;
    sha_org = org;
    sha_siz = siz;
    sha_col = col;
    sha_rot = rot;
    int i=0;
    round2_shape[i++] = new round2body(sha_org,sha_siz,sha_col,sha_rot);
    vector ocyl(sha_org+vector(0.5,0.5,sha_siz.z()));
    vector xcyl(1,0,0);
    vector ycyl(0,1,0);
    int x = (int)sha_siz.x();
    int y = (int)sha_siz.y();
    for(int yy=1;yy<y-1;yy++) for(int xx=0;xx<x;xx++)
        {
        vector o(xcyl*xx+ycyl*yy+ocyl);
        round2_shape[i++] = new knob(o,sha_col,sha_rot);
        }
    round2_shape[i] = NULL;
    }

axisvertical::axisvertical(const vector& org,const vector& siz,color col,const rotator& rot)
    {
    grp_shape = axv_shape;
    sha_org   = org;;
    sha_siz   = siz;
    sha_col   = col;
    sha_rot   = rot;
    int i=0;
    axv_shape[i++] = new body(sha_org,sha_siz,sha_col,sha_rot);
    vector norg = sha_org+vector(0.5*sha_siz.x(),0.5*sha_siz.y(),sha_siz.z());
    vector ndir(0,0,2.5);
    axv_shape[i++] = new navepin1(norg,ndir,sha_col,sha_rot);
    axv_shape[i] = NULL;
    }

axisone::axisone(const vector& org,const vector& siz,color col,const rotator& rot)
    {
    grp_shape = ax1_shape;
    sha_org   = org;;
    sha_siz   = siz;
    sha_col   = col;
    sha_rot   = rot;
    int i=0;
    ax1_shape[i++] = new brick(sha_org,sha_siz,sha_col,sha_rot);
    vector norg = sha_org+vector(0.5*sha_siz.x(),sha_siz.y(),2);
    vector ndir(0,1,0);
    ax1_shape[i++] = new navepin1(norg,ndir,sha_col,sha_rot);
    ax1_shape[i] = NULL;
    }

axistwo::axistwo(const vector& org,const vector& siz,color col,const rotator& rot)
    {
    grp_shape = ax2_shape;
    sha_org   = org;;
    sha_siz   = siz;
    sha_col   = col;
    sha_rot   = rot;
    int i=0;
    ax2_shape[i++] = new brick(sha_org,sha_siz,sha_col,sha_rot);
    vector norg = sha_org+vector(0.5*sha_siz.x(),0,2);
    vector ndir(0,-1,0);
    ax2_shape[i++] = new navepin1(norg,ndir,sha_col,sha_rot);
    norg += vector(0,sha_siz.y(),0);
    ndir = vector(0,1,0);
    ax2_shape[i++] = new navepin1(norg,ndir,sha_col,sha_rot);
    ax2_shape[i] = NULL;
    }

axisfour::axisfour(const vector& org,const vector& siz,color col,const rotator& rot)
    {
    grp_shape = ax4_shape;
    sha_org   = org;;
    sha_siz   = siz;
    sha_col   = col;
    sha_rot   = rot;
    int i=0;
    ax4_shape[i++] = new brick(sha_org,sha_siz,sha_col,sha_rot);
    double x1 = sha_org.x() + 2;
    double x2 = sha_org.x() + sha_siz.x() - 2;
    double y1 = sha_org.y();
    double y2 = sha_org.y() + sha_siz.y();
    double z  = sha_org.z() + 2;
    vector ndir(0,-1,0);
    vector norg(x1,y1,z);
    ax4_shape[i++] = new navepin1(norg,ndir,sha_col,sha_rot);
    norg = vector(x2,y1,z);
    ax4_shape[i++] = new navepin1(norg,ndir,sha_col,sha_rot);
    ndir = vector(0,1,0);
    norg = vector(x1,y2,z);
    ax4_shape[i++] = new navepin1(norg,ndir,sha_col,sha_rot);
    norg = vector(x2,y2,z);
    ax4_shape[i++] = new navepin1(norg,ndir,sha_col,sha_rot);
    ax4_shape[i] = NULL;
    }

felloe::felloe(const vector& org,const vector& siz,color col,const rotator& rot)
    {
    double angel = M_PI_2*(double)random()/(double)RAND_MAX;
    grp_shape = felloe_shape;
    sha_org   = org;;
    sha_siz   = siz;
    sha_col   = col;
    sha_rot   = rot;
    int i=0;
    felloe_shape[i++] = new felloebody(sha_org,sha_siz,sha_col,sha_rot);
    vector ndir(0,1,0);
    double sina = sin(angel)*M_SQRT1_2;
    double cosa = cos(angel)*M_SQRT1_2;
    vector norg = sha_org+vector(0,1,0);
    vector norg1 = norg + vector( sina,0, cosa*2.5);
    vector norg2 = norg + vector( cosa,0,-sina*2.5);
    vector norg3 = norg + vector(-sina,0,-cosa*2.5);
    vector norg4 = norg + vector(-cosa,0, sina*2.5);
    felloe_shape[i++] = new knob(norg1,ndir,sha_col,sha_rot);
    felloe_shape[i++] = new knob(norg2,ndir,sha_col,sha_rot);
    felloe_shape[i++] = new knob(norg3,ndir,sha_col,sha_rot);
    felloe_shape[i++] = new knob(norg4,ndir,sha_col,sha_rot);
    felloe_shape[i] = NULL;
    }

wheel::wheel(const vector& org,const vector& siz,color col,const rotator& rot)
    {
    grp_shape = wheel_shape;
    sha_org   = org;;
    sha_siz   = siz;
    sha_col   = col;
    sha_rot   = rot;
    int i=0;
    wheel_shape[i++] = new felloe(sha_org,sha_siz,sha_col,sha_rot);
    wheel_shape[i++] = new tire(sha_org,sha_siz,BLACK,sha_rot);
    wheel_shape[i] = NULL;
    }

test::test(const vector& org,const vector& siz,color col,const rotator& rot)
    {
    grp_shape = test_shape;
    sha_org   = org;;
    sha_siz   = siz;
    sha_col   = col;
    sha_rot   = rot;
    int i=0;
    test_shape[i++] = new brick(sha_org,sha_siz,sha_col,sha_rot);
    vector norg = sha_org + vector(0.5*sha_siz.x(),sha_siz.y(),2);
    vector ndir(0,1,0);
    test_shape[i++] = new felloebody(norg,ndir,RED,sha_rot);
    test_shape[i] = NULL;
    }

//
