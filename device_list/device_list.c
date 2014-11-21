#include <stdio.h>
#include <string.h>

#include <OpenAL/al.h>
#include <OpenAL/alc.h>

void printDeviceList(const char *list);

int main(int argc, char *argv[])
{
  printf("Available playback devices:\n");
  printDeviceList(alcGetString(NULL, ALC_DEVICE_SPECIFIER));

  printf("Available capture devices:\n");
  printDeviceList(alcGetString(NULL, ALC_CAPTURE_DEVICE_SPECIFIER));

  return 0;
}

void printDeviceList(const char *list)
{
  if(!list || *list == '\0')
      printf("Device Not Found.\n");
  else{
    do {
      printf("  %s\n", list);
      list += strlen(list) + 1;
    } while(*list != '\0');
  }
}

