#!/bin/bash
gcccommand=/usr/bin/gcc
cginame=cgi
mainScript='cgi.c'
httpScript='http/http.c http/request.c http/response.c http/server.c'
utilScript='util/tools.c util/dlist.c util/hash.c'

# all lib
# fastcig
lfcgi_url=/usr/lib/

gcc -o $cginame $mainScript $httpScript $utilScript -L$lfcgi_url -lfcgi




