#include "http.h"

void httpInit(){
    initServer();
    initRequest();
    initResponse();
    initRoute();
}

void httpDestroy(){
    destroyRequest();
    destroyResponse();
    destroyServer();
}

