/*
** menu.c for pure plaisir :p in /home/labadi_g/snake-console/src
**
** Made by Gautier Labadie
** Login   <labadi_g@epitech.eu>
**
** Started on  lun. déc. 01 23:38:18 14 Gautier Labadie
** Last Update lun. déc. 01 23:38:18 14 Gautier Labadie
*/

#include <menu.h>
#include <ncurses.h>
#include <stdlib.h>
#include "menu.h"

char		*choices[]={
    "Play",
    "Help",
    "Highscores",
    "Exit",
};

void 		menu()
{
  ITEM		**items;
  int		c, n_choices, i;
  MENU		*menu;

  //init_ncurses
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);

  //preparing menu
  n_choices = ARRAY_SIZE(choices);
  if (!(items = (ITEM **)calloc(n_choices + 1, sizeof(items))))
    return NULL;
  i = 0;
  while (i < n_choices)
      if (!(items[i] = new_item(choices[i], choices[i])))
          return NULL;
  items[n_choices] = NULL;

  //creating menu
  if (!(menu = new_menu((ITEM **)items)))
      return NULL;
  if (mvprintw(LINES - 2, "Press F1 to exit game!\n") == ERR)
      return (my_puterror("mvprintw which annonce the key for exit game failed!\n"));
  if (post_menu(menu) != E_OK)
      return (my_puterror("Post menu failed!\n"));
  refresh();

  //navigation menu
  while ((c = getch()) != KEY_F(1))
  {
      switch(c)
      {
        case KEY_DOWN:
          menu_driver(menu, REQ_KEY_DOWN);
          break;
        case KEY_UP:
          menu_driver(menu, REQ_KEY_UP);
          break;
      }
  }
  free_item(items[0]);
  free_item(items[1]);
  free_menu(menu);
  endwin();
}
