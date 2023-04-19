#include "main.h"
#include "api.h"
#include "tools.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curl/curl.h>

int main(int argc, char *argv[])
{
  CURL *curl = curl_easy_init();
  char *twitchAPI = "https://api.twitch.tv/helix/channels?broadcaster_id=145909736";
  const char *fileLocation = "c-hatbot.conf";
  struct FileSettings settings;
  struct TwitchHeaders headers;
  struct curl_slist *list = NULL;

  if(!setupFileLocation(fileLocation))
  {
    printf("ERROR: Configuration file does not exist.\n");
    return 1;
  }

  getClientID(settings.key.client, fileLocation);
  getBearer(settings.key.bearer, fileLocation);
  getOAuth(settings.key.oauth, fileLocation);

  sprintf(headers.client, "Client-Id: %s", settings.key.client);
  sprintf(headers.bearer, "Authorization: Bearer %s", settings.key.bearer);

  printf("ClientID: %s\nBearer Token: %s\nOAuth Token: %s\n", settings.key.client, settings.key.bearer, settings.key.oauth);

  if(!curl)
  {
    printf("Initialisation error.\n");
    return 1;
  }

  curl_easy_setopt(curl, CURLOPT_URL, twitchAPI);

  list = curl_slist_append(list, headers.client);
  list = curl_slist_append(list, headers.bearer);

  curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);

  CURLcode result = curl_easy_perform(curl);

  if(result != CURLE_OK)
  {
    printf("curl_easy_perform() failed: %s\n", curl_easy_strerror(result));
    return 1;
  }

  curl_easy_cleanup(curl);
  
  return 0;
}
