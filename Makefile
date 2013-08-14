#!/bin/bash
gcccommand=/usr/bin/gcc
cginame=cgi
mainScript='cgi.c'
httpScript='http/http.c http/request.c http/response.c http/server.c http/route.c'
utilScript='util/tools.c util/dlist.c util/hash.c util/db.c'
daoScript='dao/article.c dao/message.c'
adminScript='admin/test.c'
defaultScript='default/main.c'

# all lib
# fastcig
lfcgi_uri=/usr/lib/local/
sqlite=/usr/lib/local/

gcc -o $cginame $mainScript $httpScript $utilScript $adminScript $defaultScript $daoScript -L$lfcgi_uri -lfcgi -lsqlite3




