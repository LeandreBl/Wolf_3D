/*
** my.h for my.h in /home/lblanchard/CPool_Day09/include
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Thu Oct 13 09:19:01 2016 Leandre Blanchard
** Last update Mon Dec 19 20:47:55 2016 Léandre Blanchard
*/

/*
** Following prototypes :
** libmy prototypes from libmy.a
*/

void	*my_realloc(char *, int);

void	my_putchar(char);

int	my_isneg(int);

int	my_put_nbr(int);

int	my_swap(int *, int *);

int	my_putstr(char *);

int	my_strlen(char *);

int	my_getnbr(char *);

void	my_sort_int_tab(int *, int);

int	my_power_rec(int, int);

int	my_square_root(int);

int	my_is_prime(int);

int	my_find_prime(int);

char	*my_strcpy(char *, char *);

char	*my_strncpy(char *, char *, int);

char	*my_revstr(char *);

char	*my_strstr(char *, char *);

int	my_strcmp(char *, char *);

int	my_strncmp(char *, char *, int);

char	*my_strupcase(char *);

char	*my_strlowcase(char *);

char	*my_strcapitalize(char *);

int	my_str_isalpha(char *);

int	my_str_isnum(char *);

int	my_str_islower(char *);

int	my_str_isupper(char *);

int	my_str_isprintable(char *);

int	my_showstr(char *);

int	my_showmem(char *, int);

char	*my_strcat(char *, char *);

char	*my_strncat(char *, char *, int);

int	my_fact_rec(int);

int	my_find_prime_sup(int);

int	my_show_wordtab(char **);

char	*my_strdup(char *);

int	my_printf(char *, ...);
