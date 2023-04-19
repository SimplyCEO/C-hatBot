#ifndef API_HEADER_FILE
#define API_HEADER_FILE

void getClientID(char *clientID, char *fileLocation);
void getBearer(char *bearer, char *fileLocation);
void getOAuth(char *oauth, char *fileLocation);

enum FileTypes
{
  NONE = 0,
  CLIENT_ID = 1,
  BEARER_TOKEN = 2,
  OAUTH_TOKEN = 3
};

struct FileSettings
{
  struct Key
  {
    char client[48], bearer[48], oauth[48];
  } key;
  enum FileTypes type;
};

#endif
