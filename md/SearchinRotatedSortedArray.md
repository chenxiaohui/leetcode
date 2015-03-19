### 总结

  经典问题吧。不全相等的情况下，依然取中点，判断中点跟左右两个点的大小，如果>左边，那么说明在中点前段，如果小于右边，那么说明中点在右段。再判断跟target的关系
  
  1. mid > low
  	1. target < low, low = mid 
  	2. target > mid, low = mid
  	3. low < target < mid, high = mid
  2. mid < low
  	1. target > low, high = mid
  	2. target < mid, high = mid
 	3. mid < target < low,  low = mid
  3. mid = low
  	1. 返回

### 注意事项
	
1. 如果左边=右边，存在一种情况是变量全部相等。
2. 输入处理，输出预定义。

### 扩展



