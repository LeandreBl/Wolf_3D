/*
** print.c for wolf3d in /home/leandre/C_graphical_prog/Wolf3d/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Mon Jan  9 14:41:42 2017 Léandre Blanchard
** Last update Tue Jan 10 14:29:22 2017 Léandre Blanchard
*/

#include "include/wolf.h"

void		menu_lines()
{
  wolf_name();
  mvprintw(LINES / 2 - 11, COLS / 2 - 15,
	   "Select a file to open in Wolf_3D");
  mvprintw(LINES / 2 - 12, COLS / 2 - 8, "Press [X] to quit");
  mvprintw(LINES / 2 - 13, COLS / 2 - 14,
	   "Press [E] to enter editor Mode");
  mvprintw(LINES / 2 - 10, COLS / 2 - 13, "Press [O] ingame for options");
  mvprintw(LINES - 1, COLS - 35, "Wolf_3D made by LEANDRE BLANCHARD");
}

void		wolf_name()
{
  attron(COLOR_PAIR(4) | A_BOLD);
  mvprintw(LINES / 2 - 20, COLS / 2 - 34, L1_);
  mvprintw(LINES / 2 - 19, COLS / 2 - 34, L2_);
  mvprintw(LINES / 2 - 18, COLS / 2 - 34, L3_);
  mvprintw(LINES / 2 - 17, COLS / 2 - 34, L4_);
  mvprintw(LINES / 2 - 16, COLS / 2 - 34, L5_);
  mvprintw(LINES / 2 - 15, COLS / 2 - 34, L6_);
  attron(COLOR_PAIR(5) | A_BOLD);
}
