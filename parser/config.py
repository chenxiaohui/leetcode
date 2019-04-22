#!/usr/bin/python
#coding=utf-8
#Filename:config.py
import re
seg=u"\t\t"
bar_pattern = re.compile(r'width: (\d+)%')
ip_pattern = re.compile(r'IP地址: ([\d\.]*)</b>')

def clean(text):
    """"""
    return re.sub('[\t\ \n\r]','',text)


proxy_conf = {
    'xpath': '//table/tbody/tr',
    'filepath':'/var/www/html/',
    'file_template':u"%(proxy)s\n",
}

china_conf = dict(proxy_conf, **{
    'url' : 'http://cn-proxy.com/',
    'parse_func':lambda item : {
        'ip':item[0].text,
        'port': item[1].text,
        'location':item[2].text,
        'speed': int(bar_pattern.findall(item[3].xpath(".//strong")[0].attrib['style'])[0]),
        'last_check':item[4].text
    },
    'filename':'china-proxy-list.txt',
    'file_template':u"%(ip)s:%(port)s" + seg + u"%(location)s" + seg + u"%(speed)s" + seg + u"%(last_check)s\n",
})

global_conf = dict(proxy_conf , **{
    'url' : 'http://cn-proxy.com/archives/218',
    'parse_func':lambda item : {
        'ip':item[0].text,
        'port': item[1].text,
        'location':item[3].text,
        'speed': int(item[4].text.strip(u"毫秒")),
        'last_check': item[5].text
    },
    'filename':'global-proxy-list.txt',
    'file_template':u"%(ip)s:%(port)s" + seg + u"%(location)s" + seg + u"%(speed)s" + seg + u"%(last_check)s\n",
})

ipcn_conf = dict(proxy_conf , **{
    'url' : 'http://proxy.ipcn.org/proxylist.html',
    'xpath': '//table/tbody/tr/td/pre',
    'parse_func':lambda item : {
        'ip':item[0].text,
        'port':item[0].text,
    },
    'filename':'ipcn-proxy-list.txt'
})

pachong_conf = dict(proxy_conf, **{
    'selenium':True,
    'url':'http://pachong.org/',
    'xpath': '//table[@class="tb"]/tbody/tr',
    'parse_func':lambda item : {
        'ip':item[1].text,
        'port': (lambda x: x[x.find(';')+1:]) (item[2].text_content()),
        'speed':clean(item[5].text_content())
    },
    'filename':'pachong-proxy-list.txt',
    'file_template':u"%(ip)s:%(port)s" + seg + u"%(speed)s\n",
})

kuaidaili_conf = dict(proxy_conf, **{
    'url':'http://www.kuaidaili.com/proxylist/%d',
    'variable':range(1,11),
    'parse_func':lambda item : {
        'ip':item[0].text,
        'port': item[1].text,
        'type': item[3].text,
        'location':item[5].text,
        'speed':item[6].text
    },
    'filename':'kuaidaili-proxy-list.txt',
    'file_template':u"%(ip)s:%(port)s" + seg + u"%(type)s" + seg + u"%(location)s" + seg + u"%(speed)s\n",
})

kjson_conf = dict(proxy_conf, **{
    'selenium':True,
    'url':'http://www.kjson.com/proxy/index/%d',
    'variable':range(1,12),
    'xpath':'//table/tbody/tr[@class="plist tc"]',
    'parse_func':lambda item : {
        'ip':item[0].text,
        'port': item[1].text,
        'type': item[2].text,
        'anonymous':item[3].text,
    },
    'filename':'kjson-proxy-list.txt',
    'file_template':u"%(ip)s:%(port)s" + seg + u"%(type)s" + seg + u"%(anonymous)s\n",
})

cz88_conf = dict(proxy_conf, **{
    'url':'http://www.cz88.net/proxy/',
    'xpath':'//div[@class="box694"]/ul/li[position()>1]',
    'parse_func':lambda item : {
        'ip':item[0].text,
        'port': item[1].text,
        'type': item[2].text,
        'anonymous':item[3].text,
    },
    'filename':'cz88-proxy-list.txt',
    'file_template':u"%(ip)s:%(port)s" + seg + u"%(type)s" + seg + u"%(anonymous)s\n",
})

cz88_other_conf = dict(cz88_conf, **{
    'url':'http://www.cz88.net/proxy/http_%d.shtml',
    'xpath':'//div[@class="box694"]/ul/li[position()>1]',
    'variable':range(2,11),
    'parse_func':lambda item : {
        'ip':item[0].text,
        'port': item[1].text,
        'type': item[2].text,
        'anonymous':item[3].text,
    },
    'filename':'cz88-other-proxy-list.txt',
    'file_template':u"%(ip)s:%(port)s" + seg + u"%(type)s" + seg + u"%(anonymous)s\n",
})

weather_conf = {
    'url':'http://www.weather.com.cn/weather/%d.shtml',
    'xpath':'//ul[@class="t clearfix"]/li',
    'filepath':'/var/www/html/',
    'parse_func':lambda item : {
        'date':item[0].text,
        'weather': item[3].text,
        'temperature':clean(item[4].text_content()),
        'wind':clean(item[5].text_content()),
    },
    'filetype':'.html',
    'file_template':u"%(date)s" + seg + u"%(weather)s" + seg + u"%(temperature)s" + seg + u"%(wind)s\n",
    'variable':{101120501:'yantai',
                101121201:'dongying',
                101120601:'weifang',
                101090713:'huanghua',
                101030100:'tianjin',
                101010100:'beijing'
               },
}

weather15d_conf = dict(weather_conf, **{
    'url':'http://www.weather.com.cn/weather15d/%d.shtml',
    'xpath':'//ul[@class="t clearfix"]/li',
    'parse_func':lambda item : {
        'date':item[0].text,
        'weather': item[3].text,
        'temperature': clean(item[5].text),
        'wind':clean(item[6].text),
    },
})

stock_conf = {
    'filepath':'./',
    'file_template':u"%(url)s" + u"\n",
}

sz_stock = dict(stock_conf, **{
    'variable':{
        'sh600977':'中国电影',
        'sh000001':'上证指数',
        'sz300144':'宋城演艺',
        'sz002714':'牧原股份',
        'sz002920':'德赛西威',
        'sz002739':'万达电影',
        'sz002905':'金逸影视',
        'sh603103':'横店影视',
        'sz002555':'三七互娱',
        'sz300017':'网宿科技',
        'sz002624':'完美世界',
        'sz002035':'华帝股份',
        'sz300528':'幸福蓝海',
        'sh600715':'文投控股',
        'sz000869':'张 裕Ａ',
        'sz300251':'光线传媒',
        'sz002230':'科大讯飞',
    },
})

us_stock = dict(stock_conf, **{
    'variable':{
        'ryb':'红黄蓝',
        'tal':'好未来',
        'snap':'Snap',
        'msft':'微软',
        'cyou':'畅游',
        'wuba':'58同城',
        'ppdf':'拍拍贷',
        'edu':'新东方',
        'jmei':'聚美优品',
        'vips':'唯品会',
        'hmi':'华米',
        'sina':'新浪',
        'cmcm':'猎豹移动',
        'bita':'易车网',
        'baba':'阿里巴巴',
        'amd':'AMD',
        'intc':'英特尔',
        'nflx':'奈飞',
        'twtr':'推特',
        'wb':'微博',
        'jd':'京东',
        'ehic':'一嗨租车',
        'nvda':'英伟达',
        'momo':'陌陌',
        'vnet':'世纪互联',
        'tour':'途牛',
        'goog':'谷歌',
        'bidu':'百度',
        'qd':'趣店',
        'fb':'Facebook',
        'ccih':'蓝汛',
        'sogo':'搜狗',
        'ebay':'eBay',
        'amzn':'亚马逊',
        'sohu':'搜狐',
        'xnet':'迅雷',
        'ctrp':'携程网',
        'aapl':'苹果',
        'tsm':'台积电',
        'yy':'欢聚时代',
    },
})

hk_stock = dict(stock_conf, **{
    'variable':{
'00700':'腾讯控股',
'01816':'中广核电力',
'01958':'北京汽车',
'02689':'玖龙纸业',
'00696':'中国民航信息网络',
'00175':'吉利汽车',
'00699':'神州租车',
'00169':'万达酒店发展',
'00710':'京东方精电',
               }
})

stock_data_conf = {
    'file_template':u"%(t_open)s" + seg + u"%(y_close)s" + seg + u"%(current)s" + seg + u"%(t_max)s"  + seg + u"%(t_min)s\n",
}

sz_stock_conf = dict(sz_stock, **dict(stock_data_conf, **{
    'url':'http://hq.sinajs.cn/list=%s',
    'regex':re.compile(r'var.*="(.*?),(.*?),(.*?),(.*?),(.*?),(.*?),.*"'),
    'parse_func':lambda item : {
        't_open':item[1],
        'y_close':item[2],
        'current':item[3],
        't_max':item[4],
        't_min':item[5],
    },
}))

hk_stock_conf = dict(hk_stock, **dict(stock_data_conf,** {
    'url':'http://hq.sinajs.cn/list=hk%s',
    'regex':re.compile(r'var.*="(.*?),(.*?),(.*?),(.*?),(.*?),(.*?),(.*?),.*"'),
    'parse_func':lambda item : {
        't_open':item[2],
        'y_close':item[3],
        'current':item[6],
        't_max':item[4],
        't_min':item[5],
    },
}))

us_stock_conf = dict(us_stock, **dict(stock_data_conf,** {
    'url':'http://hq.sinajs.cn/list=gb_%s',
    'regex':re.compile(r'var.*="(.*?),(.*?),(.*?),(.*?),(.*?),(.*?),(.*?),(.*?),.*,(.*?),(.*?)"'),
    'parse_func':lambda item : {
        't_open':item[5],
        'y_close':item[8],
        'current':item[1],
        't_max':item[6],
        't_min':item[7],
    },
}))

sz_stock_k_day_conf = dict(sz_stock, **{
    'url':'http://image.sinajs.cn/newchart/daily/n/%s.gif',
})

hk_stock_k_day_conf = dict(hk_stock, **{
    'url':'http://image.sinajs.cn/newchart/hk_stock/daily/%s.gif',
})

us_stock_k_day_conf = dict(us_stock, **{
    'url':'http://image.sinajs.cn/newchartv5/usstock/daily/%s.gif',
})


sz_stock_time_conf = dict(sz_stock, **{
    'url':'http://image.sinajs.cn/newchart/min/n/%s.gif',
})

hk_stock_time_conf = dict(hk_stock, **{
    'url':'http://image.sinajs.cn/newchart/hk_stock/min/%s.gif',
})

us_stock_time_conf = dict(us_stock, **{
    'url':'http://image.sinajs.cn/newchartv5/usstock/min/%s.gif',
})

if __name__ == '__main__':
    #  stock='var hq_str_gb_amzn="亚马逊,1386.2300,3.48,2018-02-13 09:20:06,46.6300,1364.6700,1393.8100,1344.0100,1498.0000,828.5500,6738944,9006763,662583975978,4.90,282.90,0.00,0.00,0.00,0.00,477975499,61.00,1386.7700,0.04,0.54,Feb 12 08:00PM EST,Feb 12 04:00PM EST,1339.6000,102712.00"; '
    #  stock='var hq_str_sz002555="���߻���,20.530,20.540,19.890,21.050,19.770,19.890,19.900,8274236,168087463.870,20700,19.890,4500,19.880,3100,19.860,11700,19.850,100,19.840,108700,19.900,2000,19.910,1000,19.920,1100,19.940,1700,19.950,2018-02-13,15:05:03,00"; '
    stock=' var hq_str_hk00696="TRAVELSKY TECH,�й�����Ϣ����,23.600,22.550,23.850,23.150,23.400,0.850,3.769,23.400,23.450,55628582,2362662,32.276,0.949,28.000,16.720,2018/02/13,16:09";'
    stockInfo = stock.split(',')
    if stockInfo[0]:
        temp  = stockInfo[0].split('str_')[-1].replace('"','').split('=')
        code = temp[0]
        name = temp[1]
        print code,name
        #  print name
    st_type =  stockInfo[0].split(' ')[1]
    #  for i,v in enumerate(stockInfo):
        #  print i,v
