#!/bin/bash -
#===============================================================================
#
#          FILE: rn.sh
#
#         USAGE: ./rn.sh
#
#   DESCRIPTION:
#
#       OPTIONS: ---
#  REQUIREMENTS: ---
#          BUGS: ---
#         NOTES: ---
#        AUTHOR: YOUR NAME (),
#  ORGANIZATION:
#       CREATED: 2015年02月06日 11:34
#      REVISION:  ---
#===============================================================================

set -o nounset                              # Treat unset variables as an error

echo "input your leetcode problem title: "
read title
echo "copy description to clipboard: "
read 
desc=`xclip -o -selection clipboard`

filename=`echo $title|tr -d ' '`
echo '/*' > $filename.cpp
echo " * " $desc >> $filename.cpp
echo ' */' >> $filename.cpp
echo '#include "common.h"

class Solution {
public:

}s;

' >> $filename.cpp

echo "### 总结

### 注意事项

### 扩展
">md/$filename.md
./gen.sh

vi $filename.cpp
LD_PRELOAD=~/repo/scripts/libsublime-imfix.so nohup ~/share/sublime/sublime_text md/$filename.md > /dev/null 2>&1 &
