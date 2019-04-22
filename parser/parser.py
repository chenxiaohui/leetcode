#!/usr/bin/python
#coding=utf-8
#Filename:parser.py
import datetime,getopt,sys,pprint
from urllib2 import urlopen
import lxml.html.soupparser as soupparser
from driver import to_file, to_screen, to_rss, to_img
from config import weather15d_conf, weather_conf
from config import sz_stock_k_day_conf, hk_stock_k_day_conf, us_stock_k_day_conf
from config import sz_stock_time_conf, hk_stock_time_conf, us_stock_time_conf
from config import sz_stock_conf, hk_stock_conf, us_stock_conf
from pyvirtualdisplay import Display
from selenium import webdriver


def parse(urls, conf):
    """
    parse html and get proxy list
    """
    result = []
    if 'selenium' in conf.keys() and conf['selenium']:
        browser = None
        display = None
        try:
            display = Display(visible=0, size=(1024, 768))
            display.start()
            browser = webdriver.Firefox()
            browser.set_page_load_timeout(3)
            for url in urls:
                try:
                    browser.get(url)
                except Exception , e:
                    print str(e)
                html = browser.page_source
                if html:
                    result.extend(dom_parse(html, url, conf))
        except Exception , e:
            print str(e)
        finally:
            if browser:
                browser.quit()
            if display:
                display.stop()
    else:
        for url in urls:
            try:
                page = urlopen(url)
                html = page.read()
            except Exception , e:
                print str(e)
            if html:
                result.extend(dom_parse(html, url, conf))
    return result


def dom_parse(html, url, conf):
    """"""
    if not html:
        return None
    try:
        result = []
        if conf.has_key('xpath'):
            dom =  soupparser.fromstring(html)
            items = dom.xpath(conf['xpath'])

            for item in items:
                try:
                    sub_list = item.getchildren()
                    if sub_list:
                        result.append(dict(conf['parse_func'](sub_list), **{'url':url, 'html':html}))
                except Exception , e:
                    print str(e)
        elif conf.has_key("regex"):
            items = conf['regex'].findall(html)
            for item in items:
                try:
                    if item:
                        result.append(dict(conf['parse_func'](item),  **{'url':url, 'html':html}))
                except Exception , e:
                    print str(e)
        else:
            result = [{'url':url, 'html':html}]
        return result
    except Exception , e:
        print str(e)

def to_driver(item_list, conf, output = []):
    """"""
    if 'file' in output:
        to_file(item_list, conf)
    if 'print' in output:
        to_screen(item_list, conf)
    if 'rss' in output:
        to_rss(item_list, conf)
    if 'img' in output:
        to_img(item_list, conf)

def refresh(conf, output = [], filt=None):
    """
    refresh and update proxy list
    """
    try:
        template = conf['url']
        if 'variable' in conf.keys():
            if type(conf['variable']) == dict:
                for variable, title in conf['variable'].items():
                    conf['title'] = title
                    if filt and title==filt or not filt:
                        item_list = parse([template % variable], conf)
                        to_driver(item_list, conf, output)
                return
            elif type(conf['variable']) == list:
                item_list = parse([template % variable for variable in conf['variable']], conf)
            else:
                item_list = parse([template % conf['variable']], conf)
        else:
            item_list = parse([template], conf)

        to_driver(item_list, conf, output)
    except Exception , e:
        raise e

def refresh_list(conf_list, output = [], filt=None):
    """
    refresh conf list
    """
    for conf in conf_list:
        refresh(conf, output, filt)

def help():
    print './parser.py --weather [--15d] [--print] [--xml] [--img] [--file]'
    print './parser.py --stock [--print] [--xml] [--img] [--file]'

if __name__ == "__main__" :
    opts, args = getopt.getopt(sys.argv[1:], 'vh', [
            'conf=', 'weather=', '15d', 'stock=', 'print', 'file', 'rss', 'img', 'day', 'time',])

    opts = dict(opts)

    fn = 'config.py'
    if '--conf' in opts:
        fn = opts['--conf']

    #  print("conf :" + fn)
    verbose = False
    if  '-v' in opts:
        verbose = True
    if  '-h' in opts:
        help()
        sys.exit()
    filt=None

    if  '--weather' in opts:
        conf_list = [weather15d_conf] if '--15d' in opts else [weather_conf]
        if opts['--weather'] != 'all':
            filt = opts['--weather']

    if  '--stock' in opts:
        stock = opts['--stock']
        if stock == 'all':
            if '--day' in opts:
                conf_list = [sz_stock_k_day_conf, hk_stock_k_day_conf, us_stock_k_day_conf]
            elif '--time' in opts:
                conf_list = [sz_stock_time_conf, hk_stock_time_conf, us_stock_time_conf]
            else:
                conf_list = [sz_stock_conf, hk_stock_conf, us_stock_conf]
        elif stock == 'sz':
            if '--day' in opts:
                conf_list = [sz_stock_k_day_conf]
            elif '--time' in opts:
                conf_list = [sz_stock_time_conf]
            else:
                conf_list = [sz_stock_conf]
        elif stock == 'hk':
            if '--day' in opts:
                conf_list = [hk_stock_k_day_conf]
            elif '--time' in opts:
                conf_list = [hk_stock_time_conf]
            else:
                conf_list = [hk_stock_conf]
        elif stock == 'us':
            if '--day' in opts:
                conf_list = [us_stock_k_day_conf]
            elif '--time' in opts:
                conf_list = [us_stock_time_conf]
            else:
                conf_list = [us_stock_conf]
        else :
            if '--day' in opts:
                conf_list = [sz_stock_k_day_conf, hk_stock_k_day_conf, us_stock_k_day_conf]
            elif '--time' in opts:
                conf_list = [sz_stock_time_conf, hk_stock_time_conf, us_stock_time_conf]
            else:
                conf_list = [sz_stock_conf, hk_stock_conf, us_stock_conf]
            filt= opts['--stock']

    output = []
    if '--print' in opts:
        output.append('print')
    if '--file' in opts:
        output.append('file')
    if '--rss' in opts:
        output.append('rss')
    if '--img' in opts:
        output.append('img')

    if verbose:
        pprint.pprint(conf_list)

    refresh_list(conf_list, output, filt)

    if verbose:
        print "refresh succeed. time: " + str(datetime.datetime.now())
