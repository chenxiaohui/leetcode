### 总结
  经典二分。模板：

    public int binarySearch(int[] array, int target){
      int ret = -1;
      if (array.length > 0){
        int low = 0;
        int high = array.length - 1;
        int mid = 0;
        while (low + 1 < high){
          mid = low + (high - low)/2;
          if (array[mid] == target){
            high = mid;
          }else if (array[mid] < target){
            low = mid;
          }else {
            high = mid;
          }
        }
        if (array[low] == target){
          ret = low;
        }else if (array[high] == target) {
          ret = high;
        }
      }
      return ret;
    }


### 注意事项
  1. 输入判断
  2. start + 1 < end :  保证start 和end刚好在分界的地方
  3. = : end = mid，继续查找，而不是找到一个就返回
  3. < > ： low = mid, high = mid， 保证不略过一个边界。比如 x|target...这种
  3. 判断：if A[low] == target A[high] == target， 存在这种情况 target(low) target(high)... 返回low，否则返回high 
 
### 扩展

  1. lower bound。 2. upper bound 3. find range 4. 返回最后一个找到结果

