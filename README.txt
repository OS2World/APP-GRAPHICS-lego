README.txt	v1.0	6. May 1999	by eddy

lego is a tool to create images of models made of LEGO(R)-like bricks. 
It simply uses stdin and stdout streams. A text compilation builds up 
the graphical image. At end of programs runtime the image is issued in 
portabel pixmap format.

The input describes a virtual room in size and angel of view. It also 
describes objects inside of the room concerning origin, color and 
alignment. See example.lego and examples.

Usage:   lego < textsource > pixmap

Example: 
         lego < example.lego > example.ppm

The program was developed for Linux and may be ported to other operation
systems. It uses GNU libg++ class library. 

Get sources from: 

        ftp://ftp.mpifr-bonn.mpg.de/pub/incoming/en/lego1v0.tar.gz

If they disappeared from this location get it from:

        ftp://ftp.speckle.mpifr-bonn.mpg.de/pub/taoi/en/lego1v0.tar.gz

To install the program you have to unzip and untar lego1v0.tar.gz. Change 
directory to ./lego1v0 and type "make lego". An executable binary file named 
lego will arise. If you are using egcs there will be some linker warnings. 
I didn't have time yet to avoid them.

Author:	Edmund Nussbaum <en@mpifr-bonn.mpg.de> ;-)
