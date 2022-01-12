#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>
#include <ctype.h>

char rot(char c, int shift)
{
  if (c >= 'a' && c <= 'z')
  {
    c = 'a' + (((c - 'a') + shift) % 26);
    if (c < 'a')
      c += 26;
  }
  else if (c >= 'A' && c <= 'Z')
  {
    c = 'A' + (((c - 'A') + shift) % 26);
    if (c < 'A')
      c += 26;
  }
  return c;
}

int main(int argc, char **argv)
{
  int opt, i, j;
  char c;
  int k = 0;
  opterr = 0;

  char tmp[100];
  int shift;

  FILE *in = NULL;
  FILE *out = NULL;

  while ((opt = getopt(argc, argv, "O:F:")) != -1)
  {
    if (opt == 'O' && optarg != NULL)
    { /*Output*/
      out = fopen(optarg, "w");
    }
    else if (opt == 'F' && optarg != NULL)
    { /*Input*/
      if ((in = fopen(optarg, "r")) == NULL)
      {
        fprintf(stderr, "Error - Could not open file %s\n", argv[optind]);
        exit(0);
      }
    }
    else if (opt == '?' && isdigit(optopt))
    {
      tmp[strlen(tmp)] = optopt; /*Super scuffed way of getting negative shift*/
    }
    else if (opt == '?')
    {
      printf("Unknown option '-%c'\n", optopt);
    }
  }

  if (strlen(tmp) == 0)
  { /*If shift isn't negative and already defined, get it from other args*/
    for (i = optind; i < argc; i++)
    {
      for (j = 0; j < strlen(argv[i]); j++)
      {
        if (isdigit(argv[i][j]))
          k++;
      }
      if (k == strlen(argv[i]))
      {
        strcpy(tmp, argv[i]);
        break;
      }
    }
  }

  if (!strlen(tmp))
  { /*If no shift, shift=13*/
    shift = 13;
  }
  else
  {
    shift = atoi(tmp);
    shift *= -1;
  }

  if (abs(shift) > 25)
  { /*Ensuring shift is between -26 & 26*/
    fprintf(stderr, "Shift (%d) too large/small\n", shift);
    exit(0);
  }

  /*COPY_TEXT function*/
  if (in == NULL && out == NULL)
  { /*stdin->stdout*/
    printf("Input: ");
    fgets(tmp, 100, stdin);
    for (i = 0; i < strlen(tmp); i++)
      tmp[i] = rot(tmp[i], shift);
    printf("Output: %s", tmp);
  }
  else if (in == NULL && out != NULL)
  { /*stdin -> file*/
    printf("Input: ");
    fgets(tmp, 100, stdin);
    for (i = 0; i < strlen(tmp); i++)
      fputc(rot(tmp[i], shift), out);
  }
  else if (in != NULL && out == NULL)
  { /*file -> stdout*/
    while ((c = fgetc(in)) != EOF)
      printf("%c", rot(c, shift));
  }
  else if (in != NULL && out != NULL)
  {
    while ((c = fgetc(in)) != EOF) /*file -> file*/
      fputc(rot(c, shift), out);
  }

  if (in != NULL)
    fclose(in);
  if (out != NULL)
    fclose(out);

  return 0;
}
