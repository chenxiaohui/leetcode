#!/bin/bash - 
#===============================================================================
#
#          FILE: up.sh
# 
#         USAGE: ./up.sh 
# 
#   DESCRIPTION: 
# 
#       OPTIONS: ---
#  REQUIREMENTS: ---
#          BUGS: ---
#         NOTES: ---
#        AUTHOR: YOUR NAME (), 
#  ORGANIZATION: 
#       CREATED: 2015年02月06日 11:15
#      REVISION:  ---
#===============================================================================

set -o nounset                              # Treat unset variables as an error

make clean
make -C ex clean
git add .
git cam "modify `date +%Y%m%d`"
git push origin
