/*
** list.h for  in /home/lelabo_m/rendu/liblist-c/liblist/header
**
** Made by Marc Le Labourier
** Login   <lelabo_m@epitech.net>
**
** Started on  Mon Mar 10 13:28:55 2014 Marc Le Labourier
** Last update Tue Sep 23 13:55:41 2014 Marc Le Labourier
*/

#ifndef LIST_H_
# define LIST_H_

typedef struct s_node t_node;
typedef struct s_list t_list;

struct s_node
{
  void			*contain;
  struct s_node		*next;
  struct s_node		*prev;
};

struct s_list
{
  /*---attribute----*/
  unsigned int	_size;
  unsigned int	_index;
  t_node	*_current;
  t_node	*_head;
  t_node	*_tail;
  /*---methode-----*/
  void		(*destroy)(t_list *, void (*)(void *));
  unsigned int	(*len)(t_list *);
  unsigned int	(*is_empty)(t_list *);
  unsigned int	(*index)(t_list *);
  int		(*push_front)(t_list *, void *);
  int		(*push_back)(t_list *, void *);
  t_node	*(*pop_front)(t_list *);
  t_node	*(*pop_back)(t_list *);
  t_node	*(*begin)(t_list *);
  t_node	*(*end)(t_list *);
  t_node	*(*current)(t_list *);
  void		(*current_next)(t_list *);
  void		(*current_prev)(t_list *);
  void		*(*front)(t_list *);
  void		*(*back)(t_list *);
  void		*(*get_current)(t_list *);
  void		*(*insert_value)(t_node *, void *);
  void		*(*insert_atvalue)(t_list *, void *, unsigned int);
  int		(*insert_elem)(t_list *, t_node *, t_node *);
  int		(*insert_atelem)(t_list *, t_node *, unsigned int);
  t_node	*(*extract)(t_list *, t_node *);
  t_node	*(*extract_at)(t_list *, unsigned int);
  void		(*foreach)(t_list *, void (*)(void *), int);
  int		(*count)(t_list *, int (*)(void *));
  t_node	*(*find)(t_list *, int (*)(void *, void *), void *);
  void		(*remove)(t_list *, int (*)(void *), void (*)(void *));
  void		(*remove_if)(t_list *, int (*)(void *, void *),
			     void (*)(void *), void *);
  void		(*sort)(t_list *, int (*)(void *, void *));
};

/*----- List Function -----*/
t_list	*CreateList();
void	InitMethod(t_list *);
void	DestroyList(t_list *, void (*free_func)(void *));
/* Push Method */
int	PushFront(t_list *, void *);
int	PushBack(t_list *, void *);
/* Pop Method */
t_node	*PopFront(t_list *);
t_node	*PopBack(t_list *);
/* Size Method */
unsigned int	SizeList(t_list *);
unsigned int	IsEmptyList(t_list *);
unsigned int	IndexList(t_list *);
/* Iterator Method */
t_node	*BeginList(t_list *);
t_node	*EndList(t_list *);
t_node	*CurrentList(t_list *);
void	IncCurrentList(t_list *);
void	DecCurrentList(t_list *);
/* Access Method */
void	*GetFront(t_list *);
void	*GetBack(t_list *);
void	*GetCurrent(t_list *);
/* Insert Method */
void	*InsertContain(t_node *, void *);
void	*InsertAtContain(t_list *, void *, unsigned int);
int	InsertElem(t_list *, t_node *, t_node *);
int	InsertAtElem(t_list *, t_node *, unsigned int);
/* Extract Method */
t_node	*ExtractElem(t_list *, t_node *);
t_node	*ExtractAtElem(t_list *, unsigned int);
/* Algorithm */
void	ForEachElem(t_list *, void (*func)(void *), int);
int	CountElem(t_list *, int (*func)(void *));
t_node	*FindElem(t_list *, int (*func)(void *, void *), void *);
void	RemoveElem(t_list *, int (*func)(void *), void (*free_func)(void *));
void	RemoveElem2(t_list *, int (*func)(void *, void *),
		    void (*free_func)(void *), void *);
void	SortList(t_list *, int (*func)(void *, void *));

/*----- Node Function -----*/
t_node	*CreateNode(void *);
void	SwapNode(t_node *, t_node *);
void	DestroyNode(t_node *, void (*free_func)(void *));
void	DestroyNodeList(t_node *, void (*free_func)(void *));

/*----- Parameter Function -----*/
int	address_match(void *, void *);
void	null_free(void *);

#endif /* !LIST_H_ */
