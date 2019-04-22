#!/usr/bin/python
#coding=utf-8
#Filename:parser.py
import datetime
from urllib2 import urlopen
import lxml.html.soupparser as soupparser
from driver import to_file


def parse(url, conf):
    """
    parse html and get proxy list
    """
    try:
        result = []
        html = urlopen(url)
        dom = soupparser.fromstring(html)
        print conf['xpath']
        items = dom.xpath(conf['xpath'])
        for item in items:
            try:
                sub_list = item.getchildren()
                if sub_list:
                    result.append(conf['parse_func'](sub_list))
            except Exception , e:
                print str(e)
        return result
    except Exception , e:
        raise e

def refresh(conf):
    """
    refresh and update proxy list
    """
    try:
        if 'variable' in conf.keys():
            proxy_list = []
            for variable in conf['variable'] :
                proxy_list.extend(parse(conf['url'] % variable, conf))
        else:
            proxy_list = parse(conf['url'], conf)

        print proxy_list
        #  to_file(proxy_list, conf)
    except Exception , e:
        raise e

import re
# ======================== 中文检测 ==========================
def findChinese(text):
    if isinstance(text, unicode):
        return ''
    text = text.decode('utf8')
    res = re.findall(u"[\u4e00-\u9fa5]",text)
    # \u4e00-\u9fa5是中文常用字段
    return res

def myAlign(un_align_str, length=0, addin=' '):
    assert isinstance(length, int)        # 输入长度是否为整数
    if length <= len(un_align_str):       # 小于输入长度返回原字符
        return un_align_str
    strlen = len(un_align_str)
    chn = findChinese(un_align_str)
    numchn = len(chn)
    numsp = length - strlen + numchn      # 填充半角字符的的个数
    str = addin * numsp                   # 生成填充字符串

    return un_align_str + str                            # 返回填充的字符串

#  def myAlign(string, length=0):
    #  if length == 0:
        #  return string
    #  slen = len(string)
    #  re = string
    #  if isinstance(string, str):
        #  placeholder = ' '
    #  else:
        #  placeholder = u'　'
    #  while slen < length:
        #  re += placeholder
        #  slen += 1
    #  return re

s1 = '我是一个长句子，是的很长的句子。'
s2 = '我是短句子AAAA'

if __name__ == "__main__":
    a,b =myAlign(s1,32),myAlign(s2,32)
    print "%s :%s " %(a, b)
    print "%s :%s " %(b, a)
