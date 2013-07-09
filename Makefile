#!/bin/bash
gcccommand=/usr/bin/gcc
cginame=cgi
scriptname='cgi.c http/server.c util/tools.c'


# all lib

# fastcig
lfcgi_url=/usr/lib/



gcc -o $cginame $scriptname -L$lfcgi_url -lfcgi
