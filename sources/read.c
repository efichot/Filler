#include "filler.h"

int read_first_line(t_data *d, char *line)
{
  if (!line)
    return (0);
  if (line[10] == '1')
  {
    d->p_char = 'O';
    return (1);
  }
  else if (line[10] == '2')
  {
    >p_char = 'X';
    return (1);
  }
  else
  	return (0);
}

int read_size(t_surface *s, char *line)
{
  char **split;

  if (!line)
    return (0);
  if (!(split = ft_strsplit(line, ' '))
    return (0);
  s->height = ft_atoi(split[1]);
  s->width = ft_atoi(split[2]);
  return (1);
}

int read_surface_size(t_surface *s)
{
  char	*line;

  line = NULL;
  if (get_next_line(0, &line))
  {
    if (!read_size(s, line))
      return (0);
  }
  if (!(s->tab = (char **)malloc(sizeof(char *) * s->height)))
    return (0);
  return (1);
}

void    read_surface(t_surface *s, int index)
{
  char	*line;
  int	i;

  line = NULL;
  i = 0;
  while (i < s->height)
  {
    get_next_line(0, &line);
    s->tab[i] = ft_strdup(&line[index]);
    ft_strdel(&line);
    i++;
  }
}

int	ft_read(void)
{
  t_data	d;
  char		*line;

  line = NULL;
  if (get_next_line(0, &line))
  {
    if(!read_first_line(&d, line))
      return (0);
  }
  while (42)
  {
    if (!read_surface_size(&(d.map)))
      return (0);
    get_next_line(0, &line);
    strdel(&line);
    read_surface(&(d.map), 4);
    if (!read_surface_size(&(d.piece)))
      return (0);
    read_surface(&(d.piece), 0);
    filler(&d);
  }
  return (1);
}
