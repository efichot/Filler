#ifndef FILLER_H
#define FILLER_H

# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"
# include <stdio.h> //for perror()

typedef struct s_surface
{
  int height;
  int width;
  char **tab;
}              t_surface;

typedef struct s_data
{
  t_surface *map;
  t_surface *piece;
  char p_char;
}             t_data;

#endif
