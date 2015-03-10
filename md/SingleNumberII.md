### 总结
	
  SingleNumber的扩展，见这里http://www.cnblogs.com/daijinqiao/p/3352893.html。主要思想是说32位的整数，每个位上1出现的次数是可以区分的，每个数字如果出现3次，那么1的位数一定是3的整数倍，如果有一个数字只出现一次，那么1的个数要么是3×n + 1， 要么是3×n，前面对应数字该位=1，后面对应该位=0.

  链接里解法相当于加法器。ones是0位，twos是进位，threes相当于再进位，变化规律是（x是加数）：

	x   ones twos threes
	1    0	   0     0
	1    1     0     0 
	1  	 0     1     0 
	1 	 1     1     0 
	1 	 0     0     1

  通过这种方式减少了计算每个位出现次数的复杂度。ones处理相当于不进位加法，直接异或就行。twos是进位加法，只有ones=1 且加数也=1的时候进位，twos |= ones & A[i]， twos=1 并且有进位的时候，threes进位，threes |= (twos & ones & A[i]) 。

### 注意事项

	ones twos都=1并且进位的时候记得清零。也就是说ones twos=1的时候不是下次才进位，而是直接抵消掉，也就意味着xthrees不是第三位的进位。第一次遇到1ones = 1, 第二次twos = 1 ones = 0， 第三次twos = 1 ones =1， 然后就该清零了。

### 扩展
   
   SingleNumber相当于每个位置1个数=2×n 或 2×n+1，鉴于异或操作 = mod 2，所以可以简化一点。
   扩展可以想，对于任何所有数字出现n次，一个数字出现m次（n!= m, n,m 互质或者n > m)s的问题，都可以这么计算（count mod n = m|0)。再扩展，一个数字出现x次，一个出现y次，其他出现z次，
   
   联想到一个寻址的题目，http://coolspeed.sinaapp.com/?p=125，说远一点，这个题目相当于并发寻址，每只老鼠相当于一个并发处理机，对应一个维度，一次实验能在这个维度做一次搜索。	

   补充其他几个数字题目：

   1. 有一组数字，从1到n，中减少了一个数，顺序也被打乱，放在一个n-1的数组里

		BTW1: 有很多种方法的哦，据说O(n)的方法就不止一种： 加法和异或

		BTW2: 扩展问题，如果丢失了2个数字呢？

		BTW3: 一定要小心不要溢出，嗯，面试者有时候不会提醒你的

	2. 一个很相近的题目：1-1000放在含有1001个元素的数组中，只有唯一的一个元素值重复，其它均只出现一次。每个数组元素只能访问一次，设计一个算法，将它找出来；不用辅助存储空间，能否设计一个算法实现？

	2. 给你n个数，其中有且仅有一个数出现了奇数次，其余的数都出现了偶数次。用线性时间常数空间找出出现了奇数次的那一个数。

	3. 给你n个数，其中有且仅有两个数出现了奇数次，其余的数都出现了偶数次。用线性时间常数空间找出出现了奇数次的那两个数。
 
  补充几个位运算：

  1. 求一个数中1的个数。

   		while (v){
   			v &= (v-1);//抹掉了最后一个1
   			num++;
   		}

  2. 取掩码

     m - m &(m-1)

  3. 判断奇数偶数

    (n & 1) == 1;

  4. 是否2的幂 /对2的n次方取余

    (n & (n - 1)) == 0 
    m &   (n - 1);  

  4. 交换

      (*a) ^= (*b) ^= (*a) ^= (*b);     

      a ^= b;  
      b ^= a;  
      a ^= b;  

  5. int类型最大值/最小值/2整数倍

       (1 << 31) - 1，
       (1 << 31)
       2 << (n-1)
  
  6. 从低位到高位,取n的第m位

      (n >> (m-1)) & 1;  

  7. 从低位到高位.将n的第m位置1

       n | (1 << (m-1));

  8. 从低位到高位,将n的第m位置0

      n & ~(1 << (m-1));  

  9. if(x == a) x = b; if(x == b) x = a;
    
      x = a ^ b ^ x;  


  2. http://blog.csdn.net/zmazon/article/details/8262185

    http://blog.csdn.net/morewindows/article/details/7354571