#!/bin/bash - 
#===============================================================================
#
#          FILE: stock.sh
# 
#         USAGE: ./stock.sh 
# 
#   DESCRIPTION: 
# 
#       OPTIONS: ---
#  REQUIREMENTS: ---
#          BUGS: ---
#         NOTES: ---
#        AUTHOR: YOUR NAME (), 
#  ORGANIZATION: 
#       CREATED: 02/23/2018 08:54
#      REVISION:  ---
#===============================================================================

set -o nounset                              # Treat unset variables as an error
cd /root/projects/parser
stock() {
    name=$1
    title=$2
    python parser.py --stock=${name} --img --day
    python parser.py --stock=${name} --print |tee ${name}.txt
    convert *.gif -append ${name}.gif
    #mpack -s "`date +%Y-%m-%d`日K曲线" ${name}.gif 243505859@qq.com
    cat ${name}.txt | mailx -s "`date +%Y-%m-%d`${title}日K曲线" -a ${name}.gif 243505859@qq.com 
    git clean -fd
}
stock sz a股
stock us 美股
stock hk 港股
