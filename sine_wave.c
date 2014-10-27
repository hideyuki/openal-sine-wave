#include <OpenAL/al.h>
#include <OpenAL/alc.h>
#include <math.h>
#include <stdio.h>
#include <limits.h>

#define SECOND 1
#define SAMPLING_HZ 44100
#define BUFFER_LENGTH (SECOND * SAMPLING_HZ)
#define SOUND_HZ 14706

int main(){
  ALCdevice *device;
  ALCcontext *context;
  ALshort data[BUFFER_LENGTH*2];
  ALuint buffer, source;
  int i;

  device = alcOpenDevice(NULL);
  context = alcCreateContext(device, NULL);
  alcMakeContextCurrent(context);
  alGenBuffers(1, &buffer);

  for (i = 0; i < BUFFER_LENGTH; ++i) {
      data[i*2] = sin(2 * M_PI * SOUND_HZ * i / BUFFER_LENGTH) * SHRT_MAX;
      data[i*2+1] = -1 * sin(2 * M_PI * SOUND_HZ * i / BUFFER_LENGTH) * SHRT_MAX;
  }

  alBufferData(buffer, AL_FORMAT_STEREO16, data, sizeof(data), BUFFER_LENGTH*2);
  alGenSources(1, &source);
  alSourcei(source, AL_BUFFER, buffer);
  alSourcei(source, AL_LOOPING, AL_TRUE);
  alSourcePlay(source);

  printf("Press Enter key to exit.");
  getchar();

  alSourceStop(source);
  alDeleteSources(1, &source);
  alDeleteBuffers(1, &buffer);
  alcMakeContextCurrent(NULL);
  alcDestroyContext(context);
  alcCloseDevice(device);

  return 0;
}

