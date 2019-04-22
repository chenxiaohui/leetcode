#!/usr/bin/python
#coding=utf-8
#Filename:driver.py
import io
import PyRSS2Gen
from time import strptime
from time import mktime
import datetime

def to_redis():
    """"""
    pass

def to_file(item_list, conf):
    """"""
    try:
        if conf.has_key('file_template'):
            lines = [conf['file_template'] % item for item in item_list]
            filetype = conf['filetype'] if conf.has_key('filetype') else '.txt'
            filename = conf['filename'] if conf.has_key('filename') else conf['title'] + filetype
            with io.open(conf['filepath'] + filename, 'w', encoding='utf-8') as fp:
                fp.writelines(lines)
    except Exception , e:
        raise e

def to_screen(item_list, conf):
    """"""
    try:
        if conf.has_key('file_template'):
            lines = [conf['file_template'] % item for item in item_list]
            if conf.has_key('title'):
                print "[%s]" %conf['title']
            for line in lines:
                print line.encode('utf8'),
    except Exception , e:
        raise e

def to_rss(item_list, conf):
    """"""
    try:
        rss = PyRSS2Gen.RSS2(
            title = conf['title'],
            link =  conf['url'],
            description = conf['description'] if conf.has_key('description') else '',
            lastBuildDate = datetime.datetime.now(),
            items = [
                PyRSS2Gen.RSSItem(
                    title = item['title'] if item.has_key('title') else conf['title'],
                    link = item['url'] if item.has_key('url') else conf['url'],
                    description = conf['file_template'] % item,
                    guid = PyRSS2Gen.Guid(conf['file_template'] % item),
                    pubDate = datetime.datetime.now()
                    )  for item in item_list
            ])
        rssname = conf['filename'] if conf.has_key('filename') else conf['title'] + '.xml'
        rss.write_xml(open(conf['filepath'] + rssname, "w"))
    except Exception , e:
        raise e

def to_img(item_list, conf):
    try:
        if len(item_list) >= 1:
            item = item_list[0]
            filetype = conf['filetype'] if conf.has_key('filetype') else '.gif'
            filename = conf['filename'] if conf.has_key('filename') else conf['title'] + filetype
            with io.open(conf['filepath'] + filename, 'wb') as fp:
                fp.write(item['html'])
    except Exception:
        raise

def parse_time(time_string):
    """"""
    time_string = time_string.strip()
    dt = datetime.datetime.now()
    if time_string:
        idx = time_string.find("-")
        if idx > -1:
            idx = time_string.find("-", idx + 1)
            if idx > -1:
                pass
            else:
                time_string = "%d-%s" %(dt.year, time_string)
        else:
            time_string = "%d-%d-%d %s" %(dt.year , dt.month , dt.day, time_string)
    return strptime(time_string, '%Y-%m-%d %H:%M')

#  if __name__ == '__main__':
    #  print parse_time("03-10 10:25")
    #  print parse_time("2014-10-28 19:03")
    #  print parse_time("19:03")
    #  print type(datetime.datetime(2003, 9, 6, 21, 49))
