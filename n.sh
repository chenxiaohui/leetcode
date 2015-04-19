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
[ -f /usr/bin/pbpaste ] && copycmd='pbpaste'
[ -f /usr/bin/xclip ] && copycmd='xclip -o selection clipboard'
echo "copy or type your problem title: "
read title
[ -z "$title "] && title=`$copycmd`
echo "copy or type description:"
read desc
[ -z "$desc "] && desc=`$copycmd`

cppfilename=others/`echo $title|tr -d ' '`.cpp
echo '/*' > $cppfilename
echo " * " $desc >> $cppfilename
echo ' */' >> $cppfilename
echo '#include "common.h"

class Solution {
public:

};
Solution s;
' >> $cppfilename

mdfilename=md/`echo $title|tr -d ' '`.md
echo "### 总结



### 注意事项



### 扩展


">$mdfilename
./gen.sh

sublime $mdfilename
vi $cppfilename
