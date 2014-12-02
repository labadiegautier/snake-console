/*
** my_str.c for pure plaisir :p in /home/labadi_g/snake-console
**
** Made by Gautier Labadie
** Login   <labadi_g@epitech.eu>
**
** Started on  mar. déc. 02 00:08:23 14 Gautier Labadie
** Last Update mar. déc. 02 00:08:23 14 Gautier Labadie
*/

#include <unistd.h>

int		my_strlen(char *str)
{
  int		i = 0;
  while (str[i])
      ++i;
  return i;
}

int		my_puterror(char *str)
{
  if(write(2, str, my_strlen(str)) == -1)
      return -1;
  exit(EXIT_FAILURE);
}
