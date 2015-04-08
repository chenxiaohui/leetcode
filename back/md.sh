#!/bin/bash - 
#===============================================================================
#
#          FILE: gen.sh
# 
#         USAGE: ./gen.sh 
# 
#   DESCRIPTION: 
# 
#       OPTIONS: ---
#  REQUIREMENTS: ---
#          BUGS: ---
#         NOTES: ---
#        AUTHOR: YOUR NAME (), 
#  ORGANIZATION: 
#       CREATED: 2015/04/08 22:44
#      REVISION:  ---
#===============================================================================

set -o nounset                              # Treat unset variables as an error
template=" ### 总结\n\n\n\n### 注意事项\n\n\n\n### 扩展\n\n"
for i in `cat algorithm/leetcode/list.txt |awk '{print $1}'`; do
    echo -e $template > md/$i.md
done
for i in `cat algorithm/lintcode/list.txt |awk '{print $1}'`; do 
    echo -e $template > md/$i.md
done
