#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define DEFAULT_SCALE 35

char message[] = "Enjoy this beautiful day.";

int main(int argc, char **argv) {
  double radians;
  double sine;
  int degree = 0;
  int scale = DEFAULT_SCALE;
  if (argc > 1) {
    int parsed_arg = atoi(argv[1]);
    if (parsed_arg > 0) {
      scale = parsed_arg;
    }
  }
  while (1) {
    radians = degree * M_PI / 180; /* convert degrees to radians */
    sine = scale * sin(radians);
    fprintf(stdout,
            "{\"message\":\"%s\",\"scale\":%i,\"radians\":%f,\"sine\":%f }\n",
            message, scale, radians, sine);

    if (sine > 0) {
      usleep(sine * 10000);
    }

    fflush(stdout);
    ++degree;
  }

  return 0;
}
