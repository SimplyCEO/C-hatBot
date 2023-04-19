#include "main.h"
#include "api.h"
#include "tools.h"

#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

void getClientID(char *clientID, char *fileLocation)
{
  getFileInfo(clientID, 1, fileLocation);
}

void getBearer(char *bearer, char *fileLocation)
{
  getFileInfo(bearer, 2, fileLocation);
}

void getOAuth(char *oauth, char *fileLocation)
{
  getFileInfo(oauth, 3, fileLocation);
}
