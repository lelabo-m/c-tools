#include <stdlib.h>
#include "list.h"

void	ResetCurrent(t_list *this, int side)
{
  (side == S_NORMAL) ? (this->_current = this->_head) : (this->_current = this->_back);
}
