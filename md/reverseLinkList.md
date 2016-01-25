### 总结

  主要是遍历一个链表的前后位置存储。

  	LinkList r = NULL;
  	LinkList p = head;
  	while (p != NULL) {
	  	r = p;
	  	p = p->next;
	  	/* your code */
  	}

### 注意事项
	
	两种思路，一种结果。可以用dummy node但是需要释放node

### 扩展
	
	逆转一个环

