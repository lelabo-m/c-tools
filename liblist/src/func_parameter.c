int	address_match(void *first, void *second)
{
  if (first == second)
    return (1);
  return (0);
}

void	null_free(void *elem)
{
  (void)elem;
}
