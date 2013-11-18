// room.cc  v1.0    15. April 1999  by eddy

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

#include "room.h"
#include <iostream.h>
#include <fstream.h>
#include <math.h>
#include <float.h>
//#include <values.h>

double minimum(double a,double b,double c)
    {
    double min = a;
    if(b<min) min = b;
    if(c<min) min = c;
    return(min);
    }

double minimum(double a,double b,double c,double d,double e,double f,double g,double h)
    {
    double min = a;
    if(b<min) min = b;
    if(c<min) min = c;
    if(d<min) min = d;
    if(e<min) min = e;
    if(f<min) min = f;
    if(g<min) min = g;
    if(h<min) min = h;
    return(min);
    }

double maximum(double a,double b,double c,double d,double e,double f,double g,double h)
    {
    double max = a;
    if(b>max) max = b;
    if(c>max) max = c;
    if(d>max) max = d;
    if(e>max) max = e;
    if(f>max) max = f;
    if(g>max) max = g;
    if(h>max) max = h;
    return(max);
    }

room::room(int pixel,const vector& size,double alpha,double beta)
    {
    cerr << " initialize ... \n";
    room_xsize = pixel;
    room_ysize = pixel;
    room_zsize = (int)pow(2,15)-1;
    vector room_size = size;
        alpha *= M_PI/180.0;
        beta  *= M_PI/180.0;
    const double sinalp = sin(alpha);
    const double cosalp = cos(alpha);
    const double sinbet = sin(beta);
    const double cosbet = cos(beta);
    matrix mrot;
    mrot.a1 = cosalp;
    mrot.b1 = sinalp;
    mrot.c1 = 0;
    mrot.d1 = 0;
    mrot.a2 = -sinalp*cosbet;
    mrot.b2 = cosalp*cosbet;
    mrot.c2 = 0.4*sinbet;
    mrot.d2 = 0;
    mrot.a3 = sinalp*sinbet;
    mrot.b3 = -cosalp*sinbet;
    mrot.c3 = 0.4*cosbet;
    mrot.d3 = 0;
    double mx = room_size.x();
    double my = room_size.y();
    double mz = room_size.z();
    rotator tr(mrot);
    vector va(tr.rotsiz(vector(  0, 0, 0 )));
    vector vb(tr.rotsiz(vector( mx, 0, 0 )));
    vector vc(tr.rotsiz(vector(  0,my, 0 )));
    vector vd(tr.rotsiz(vector( mx,my, 0 )));
    vector ve(tr.rotsiz(vector(  0, 0,mz )));
    vector vf(tr.rotsiz(vector( mx, 0,mz )));
    vector vg(tr.rotsiz(vector(  0,my,mz )));
    vector vh(tr.rotsiz(vector( mx,my,mz )));
    double minx = minimum(va.x(),vb.x(),vc.x(),vd.x(),ve.x(),vf.x(),vg.x(),vh.x());
    double miny = minimum(va.y(),vb.y(),vc.y(),vd.y(),ve.y(),vf.y(),vg.y(),vh.y());
    double minz = minimum(va.z(),vb.z(),vc.z(),vd.z(),ve.z(),vf.z(),vg.z(),vh.z());
    double maxx = maximum(va.x(),vb.x(),vc.x(),vd.x(),ve.x(),vf.x(),vg.x(),vh.x());
    double maxy = maximum(va.y(),vb.y(),vc.y(),vd.y(),ve.y(),vf.y(),vg.y(),vh.y());
    double maxz = maximum(va.z(),vb.z(),vc.z(),vd.z(),ve.z(),vf.z(),vg.z(),vh.z());
    double factorx = room_xsize/(maxx-minx);
    double factory = room_ysize/(maxy-miny);
    double factorz = room_zsize/(maxz-minz);
    room_scale = minimum(factorx,factory,factorz);
    mrot.a1 *= room_scale; mrot.b1 *= room_scale; mrot.c1 *= room_scale;
    mrot.a2 *= room_scale; mrot.b2 *= room_scale; mrot.c2 *= room_scale;
    mrot.a3 *= room_scale; mrot.b3 *= room_scale; mrot.c3 *= room_scale;
    mrot.d1 = 0.5-minx*room_scale;
    mrot.d2 = 0.5-miny*room_scale;
    mrot.d3 = 0.5-minz*room_scale;
    rr = rotator(mrot);
    room_xsize = (int)(room_scale*(maxx-minx)+0.5);
    room_ysize = (int)(room_scale*(maxy-miny)+0.5);
    room_zsize = (int)(room_scale*(maxz-minz)+0.5);
    room_zexpand = pow(2,15)/room_zsize;
    room_depth = new unsigned short*[room_ysize];
    for(int y=0;y<room_ysize;y++)
        {
        room_depth[y] = new unsigned short[room_xsize];
        for(int x=0;x<room_xsize;x++) room_depth[y][x] = BACKGROUND;
        }
    }

room::~room(void)
    {
    for(int i=0;i<room_ysize;i++) delete [] room_depth[i];
    delete [] room_depth;
    }

void room::writeppm(void)
    {
    #include "colors.h"
    cerr << "output data ...\n";
    cout <<"P6 "<<room_xsize<<' '<<room_ysize<<" 255\n";
    for(int y=room_ysize-1;y>=0;y--)
        for(int x=0;x<room_xsize;x++)
            {
            color c = (color)(room_depth[y][x]&0x000F);
            cout.put(R[c]);
            cout.put(G[c]);
            cout.put(B[c]);
            }
    }

void room::writeppm(const String& filename)
    {
    #include "colors.h"
    ofstream out;
    out.open(filename);
    if(!out.good())
        {
        cerr << "Can´t open " << filename << " !\n";
        return;
        }
    cerr << "output data to " << filename << " ...\n";
    out <<"P6 "<<room_xsize<<' '<<room_ysize<<" 255\n";
    for(int y=room_ysize-1;y>=0;y--)
        for(int x=0;x<room_xsize;x++)
            {
            color c = (color)(room_depth[y][x]&0x000F);
            out.put(R[c]);
            out.put(G[c]);
            out.put(B[c]);
            }
    }

// was inline
void room::goal(void)
    {
    static const int GOALS = (int)(room_xsize*room_ysize*0.03);
    static int x = -1;
    if(x-->0) return;
    x = GOALS;
    cerr << '*';
    }

// was inline
void room::nogoal(void)
    {
    static const int GOALS = (int)(room_xsize*room_ysize*0.03);
    static int x = -1;
    if(x-->0) return;
    x = GOALS;
    cerr << '.';
    }

inline void room::putpixel(int x,int y,int z,color c)
    {
    if(x<0)            return;
    if(x>=room_xsize)  return;
    if(y<0)            return;
    if(y>=room_ysize)  return;
    if(z<0) z = 0;
    const int zmax = 65535; // 2^16-1
    if(z>zmax) z = zmax;
    if( (room_depth[y][x]/*&0xFFF0*/) >= (unsigned short)z )
        {
        nogoal();
        return;
        }
    room_depth[y][x] = (z&0xFFF0)|(c/*&0x0F*/);
    goal();
    }

void room::dodot(const vector& o,color col)
    {
    int x = (int)o.x();
    int y = (int)o.y();
    int z = (int)(room_zexpand*o.z());
    if(col==OUTLINE)
        {
        z += 64;
        putpixel(x+1,y,z,col);
        putpixel(x-1,y,z,col);
        putpixel(x,y+1,z,col);
        putpixel(x,y-1,z,col);
        }
    putpixel(x,y,z,col);
    }

void room::doline(const vector& o,const vector& p,color col)
        {
        vector v = p - o;
    int n = 1+(int)(hypot(v.x(),v.y())/room_delta);
        v *= 1.0/n;
    vector t = o;
        for(int i=0;i<=n;i++)
                {
                dodot(t,col);
                t += v;
                }
        }

void room::doarea(const vector& o,const vector& p,const vector& q,color col)
    {
    vector v = p - o;
        int n = 1+(int)(hypot(v.x(),v.y())/room_delta);
        v *= 1.0/n;
    vector t = o;
    vector s = q - o;
        for(int i=0;i<=n;i++)
                {
                doline(t,t+s,col);
                t += v;
                }
    }

void room::doarc(const vector& o,vector a,const vector& b,double angel,color col)
    {
        a  = a.unit();
    double arc = M_PI*angel/180.0;
    double rad = b.absvalue();
    int n = 1+(int)(rad*arc/room_delta);
    double darc = arc/n;
        double axby = a.x()*b.y();
        double axbz = a.x()*b.z();
        double aybx = a.y()*b.x();
        double aybz = a.y()*b.z();
        double azbx = a.z()*b.x();
        double azby = a.z()*b.y();
        double sx = aybz-azby;
        double sy = azbx-axbz;
        double sz = axby-aybx;
        double factor = sx*aybz + sy*azbx + sz*axby;
        factor += (azby-aybz)*azby;
        factor += (axbz-azbx)*axbz;
        factor += (aybx-axby)*aybx;
        factor = rad*rad/factor;
        sx *= factor;
        sy *= factor;
        sz *= factor;
        double cx = sy*a.z()-sz*a.y();
        double cy = sz*a.x()-sx*a.z();
        double cz = sx*a.y()-sy*a.x();
    arc = 0;
    for(int i=0;i<=n;i++)
            {
                double vsin = sin(arc);
                double vcos = cos(arc);
                vector v(sx*vsin+cx*vcos,sy*vsin+cy*vcos,sz*vsin+cz*vcos);
        dodot(v+o,col);
        arc += darc;
        }
    }

void room::docircle(const vector& o,const vector& d,double radius,color col)
    {
    vector r(d.product(vector(-d.y(),d.z(),-d.x())));
    r *= radius/r.absvalue();
    doarc(o,d,r,360,col);
    }

void room::dodisc(const vector& o,const vector& d,double radius,color col)
    {
    vector r(d.product(vector(-d.y(),d.z(),-d.x())));
    r = r.unit()*radius;
        int n = 1+(int)(radius/room_delta);
        r *= 1.0/n;
    vector t;
        for(int i=0;i<=n;i++)
                {
                doarc(o,d,t,360,col);
                t += r;
                }
    }

void room::doring(const vector& o,const vector& d,double r1,double r2,color col)
    {
    vector r(d.product(vector(-d.y(),d.z(),-d.x())));
    vector runit(r.unit());
    r = runit*(r2-r1);
        int n = 1+(int)((r2-r1)/room_delta);
        r *= 1.0/n;
    vector t(runit*r1);
        for(int i=0;i<=n;i++)
                {
                doarc(o,d,t,360,col);
                t += r;
                }
    }

void room::dosector(const vector& o,const vector& d,vector r,double angel,color col)
    {
        int n = 1+(int)(hypot(r.x(),r.y())/room_delta);
        r *= 1.0/n;
    vector t;
        for(int i=0;i<=n;i++)
                {
                doarc(o,d,t,angel,col);
                t += r;
                }
    }

void room::docylsector(const vector& o,const vector& h,const vector& r,double angel,color col)
    {
        vector a(h.unit());
    double arc = M_PI*angel/180.0;
    double rad = r.absvalue();
    int n = 1+(int)(rad*arc/room_delta);
    double darc = arc/n;
        double axby = a.x()*r.y();
        double axbz = a.x()*r.z();
        double aybx = a.y()*r.x();
        double aybz = a.y()*r.z();
        double azbx = a.z()*r.x();
        double azby = a.z()*r.y();
        double sx = aybz-azby;
        double sy = azbx-axbz;
        double sz = axby-aybx;
        double factor = sx*aybz + sy*azbx + sz*axby;
        factor += (azby-aybz)*azby;
        factor += (axbz-azbx)*axbz;
        factor += (aybx-axby)*aybx;
        factor = rad*rad/factor;
        sx *= factor;
        sy *= factor;
        sz *= factor;
        double cx = sy*a.z()-sz*a.y();
        double cy = sz*a.x()-sx*a.z();
        double cz = sx*a.y()-sy*a.x();
    arc = 0;
    for(int i=0;i<=n;i++)
            {
                double vsin = sin(arc);
                double vcos = cos(arc);
                vector v(sx*vsin+cx*vcos,sy*vsin+cy*vcos,sz*vsin+cz*vcos);
        v += o;
        doline(v,v+h,col);
        arc += darc;
        }
    }

void room::docyl(const vector& o,vector d,double radius,color col)
    {
    vector r(d.product(vector(-d.y(),d.z(),-d.x())));
    r = r.unit()*radius;
    docylsector(o,d,r,360,col);
    }

void room::dotriang(const vector& o,const vector& p,const vector& q,color col)
    {
    vector v = p - o;
        int n = 1+(int)(hypot(v.x(),v.y())/room_delta);
    double recn = 1.0/n;
        v *= recn;
    vector t = o;
    vector s = (q-o)*recn;
        for(int i=0;i<=n;i++)
                {
                doline(t,t+s*(n-i),col);
                t += v;
                }
    }

//void room::dot(const vector& o,color col,const rotator& rot)
//  {
//  if(!col) return;
//  dodot(rr.rotorg(rot.rotorg(o)),col);
//  }

void room::line(const vector& o,const vector& p,color col,const rotator& rot)
        {
    if(!col) return;
    doline(rr.rotorg(rot.rotorg(o)),rr.rotorg(rot.rotorg(p)),col);
        }

void room::area(const vector& o,const vector& p,const vector& q,color col,const rotator& rot)
    {
    if(!col) return;
    doarea(rr.rotorg(rot.rotorg(o)),rr.rotorg(rot.rotorg(p)),rr.rotorg(rot.rotorg(q)),col);
    }

void room::arc(const vector& o,const vector& d,const vector& r,double angel,color col,const rotator& rot)
    {
    if(!col) return;
    doarc(rr.rotorg(rot.rotorg(o)),rr.rotsiz(rot.rotsiz(d)),rr.rotsiz(rot.rotsiz(r)),angel,col);
    }

void room::circle(const vector& o,const vector& d,double radius,color col,const rotator& rot)
    {
    if(!col) return;
    docircle(rr.rotorg(rot.rotorg(o)),rr.rotsiz(rot.rotsiz(d)),room_scale*radius,col);
    }

void room::disc(const vector& o,const vector& d,double radius,color col,const rotator& rot)
    {
    if(!col) return;
    dodisc(rr.rotorg(rot.rotorg(o)),rr.rotsiz(rot.rotsiz(d)),room_scale*radius,col);
    }

void room::ring(const vector& o,const vector& d,double r1,double r2,color col,const rotator& rot)
    {
    if(!col) return;
    doring(rr.rotorg(rot.rotorg(o)),rr.rotsiz(rot.rotsiz(d)),room_scale*r1,room_scale*r2,col);
    }

void room::sector(const vector& o,const vector& d,const vector& r,double angel,color col,const rotator& rot)
    {
    if(!col) return;
    dosector(rr.rotorg(rot.rotorg(o)),rr.rotsiz(rot.rotsiz(d)),rr.rotsiz(rot.rotsiz(r)),angel,col);
    }

void room::cylsector(const vector& o,const vector& h,const vector& r,double angel,color col,const rotator& rot)
    {
    if(!col) return;
    docylsector(rr.rotorg(rot.rotorg(o)),rr.rotsiz(rot.rotsiz(h)),rr.rotsiz(rot.rotsiz(r)),angel,col);
    }

void room::cyl(const vector& o,const vector& d,double radius,color col,const rotator& rot)
    {
    if(!col) return;
    docyl(rr.rotorg(rot.rotorg(o)),rr.rotsiz(rot.rotsiz(d)),room_scale*radius,col);
    }

void room::triang(const vector& o,const vector& p,const vector& q,color col,const rotator& rot)
    {
    if(!col) return;
    dotriang(rr.rotorg(rot.rotorg(o)),rr.rotorg(rot.rotorg(p)),rr.rotorg(rot.rotorg(q)),col);
    }

//
