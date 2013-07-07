#!/bin/bash
gcccommand=/usr/bin/gcc
cginame=cgi
scriptname='cgi.c server.c tools.c'


# all lib

# fastcig
lfcgi_url=/usr/lib/



gcc -o $cginame $scriptname -L$lfcgi_url -lfcgi
