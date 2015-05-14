### 总结
  
  简单的思路就是SortedArray的合并，但是只比较和计数。

### 注意事项

  1. 需要状态的可以置last current, 每次修改current前先保存current.
  2. double的一定要/2.0，即使接收返回值的变量是double

### 扩展

  1. 中位数
  2. topn
