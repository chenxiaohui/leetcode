/*
size=3, capacity=4[null, 21->9->null, 14->null, null]The hash function is:int hashcode(int key, int capacity) {    return key % capacity;}here we have three numbers, 9, 14 and 21, where 21 and 9 share the same position as they all have the same hashcode 1 (21 % 4 = 9 % 4 = 1). We store them in the hash table by linked list.rehashing this hash table, double the capacity, you will get:size=3, capacity=8index:           0    1    2     3      4    5     6    7hash table: [null, 9, null, null, null, 21, 14, null]Given the original hash table, return the new hash table after rehashing .
Note
For negative integer in hash table, the position can be calculated as follow:In C++/Java, if you directly calculate -4 % 3 you will get -1. You can use function: a % b = (a % b + b) % b to make it is a non negative integer.In Python, you can directly use -1 % 3, you will get 2 automatically.

Example
Given [null, 21->9->null, 14->null, null], return [null, 9->null, null, null, null, 21->null, 14->null, null]

*/

#include "common.h"

class Solution {
public:

};
Solution s;

TEST(Rehashing, normal) {
}
