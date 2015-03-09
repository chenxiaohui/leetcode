### 总结

  栈的问题，基本思路。

### 注意事项

  1. 犯了一个真心蛋疼的错误：

  	    for(unsigned int i = 0; i < s.size(); i++){
            if(chars.empty() || chars.top() != s[i]){
                chars.push(s[i]);
            }else{
                chars.pop();
            }
        }

   2. c++stack的取栈顶函数是top，不是peek。size()类型是unsigned int。stack不能用可以用vector的push_back，pop_back
   3. 一些特殊情况的处理。比如非合法字符是不是要判断?先右括号再左括号是不是有问题？

### 扩展

  判断出栈序列。http://blog.csdn.net/gstc110/article/details/7583655
  卡特兰数。http://baike.baidu.com/view/2499752.htm
  