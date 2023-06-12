# -*- coding: UTF-8 -*-
# 音乐

import requests
import re
import time
import pandas as pd
from lxml import etree


def wangyiyunHot():
    (true, false, null) = ('true', 'false', 'null')
    url = 'https://music.163.com/discover/toplist?id=3778678'
    headers = {
        'user-agent':
        'Mozilla/5.0(WindowsNT10.0;Win64;x64)AppleWebKit/537.36(KHTML,likeGecko)Chrome/91.0.4472.124Safari/537.36'
    }
    page = requests.get(url=url, headers=headers).content.decode('utf-8')
    ex = '<textarea id="song-list-pre-data" style="display:none;">(.*?)</textarea>'
    pattern = re.compile(ex)
    ls = eval(pattern.findall(page, re.S)[0])
    resLs = []
    for li in ls:
        dic = {
            'rank':
            str(ls.index(li) + 1),
            'name':
            li['name'],
            'singer':
            '/'.join([i['name'] for i in li['artists']]),
            'length':
            str(int(li['duration'] / 1000)),
            'songUrl':
            'https://music.163.com/song?id=' + str(li['id']),
            'singerUrl':
            '/'.join([
                'https://music.163.com/artist?id=' + str(i['id'])
                for i in li['artists']
            ])
        }
        try:
            resLs.append(dic)
            print(dic)
        except Exception as e:
            print(str(e))
    data = time.strftime('%Y-%m-%d', time.localtime())
    pf = pd.DataFrame(resLs)
    path = pd.ExcelWriter(f'./音乐/网易云音乐热歌榜 {data}.xlsx')
    pf.to_excel(path, encoding='utf-8', index=False)
    path.save()


def wangyiyunOri():
    (true, false, null) = ('true', 'false', 'null')
    url = 'https://music.163.com/discover/toplist?id=2884035'
    headers = {
        'user-agent':
        'Mozilla/5.0(WindowsNT10.0;Win64;x64)AppleWebKit/537.36(KHTML,likeGecko)Chrome/91.0.4472.124Safari/537.36'
    }
    page = requests.get(url=url, headers=headers).content.decode('utf-8')
    ex = '<textarea id="song-list-pre-data" style="display:none;">(.*?)</textarea>'
    pattern = re.compile(ex)
    ls = eval(pattern.findall(page, re.S)[0])
    resLs = []
    for li in ls:
        dic = {
            'rank':
            str(ls.index(li) + 1),
            'name':
            li['name'],
            'singer':
            '/'.join([i['name'] for i in li['artists']]),
            'length':
            str(int(li['duration'] / 1000)),
            'songUrl':
            'https://music.163.com/song?id=' + str(li['id']),
            'singerUrl':
            '/'.join([
                'https://music.163.com/artist?id=' + str(i['id'])
                for i in li['artists']
            ])
        }
        try:
            resLs.append(dic)
            print(dic)
        except Exception as e:
            print(str(e))
    data = time.strftime('%Y-%m-%d', time.localtime())
    pf = pd.DataFrame(resLs)
    path = pd.ExcelWriter(f'./音乐/网易云音乐原创榜 {data}.xlsx')
    pf.to_excel(path, encoding='utf-8', index=False)
    path.save()


def qqHot():
    url = 'https://y.qq.com/n/ryqq/toplist/26'
    headers = {
        'user-agent':
        'Mozilla/5.0(WindowsNT10.0;Win64;x64)AppleWebKit/537.36(KHTML,likeGecko)Chrome/91.0.4472.124Safari/537.36'
    }
    page = requests.get(url=url, headers=headers).content.decode('utf-8')
    tree = etree.HTML(page)
    resLs = []
    for li in tree.xpath('//ul[@class="songlist__list"]/li'):
        dic = {
            'rank':
            li.xpath('.//div[contains(@class,"songlist__number")]/text()')[0],
            'name':
            li.xpath('.//span[@class="songlist__songname_txt"]/a/@title')[0],
            'singer':
            '/'.join(li.xpath('.//div[@class="songlist__artist"]/a/text()')),
            'length':
            li.xpath('.//div[@class="songlist__time"]/text()')[0],
            'songUrl':
            'https://y.qq.com' + li.xpath(
                './/span[@class="songlist__songname_txt"]/a[last()]/@href')[0],
            'singerUrl':
            '/'.join(
                'https://y.qq.com' + i
                for i in li.xpath('.//div[@class="songlist__artist"]/a/@href'))
        }
        try:
            resLs.append(dic)
            print(dic)
        except Exception as e:
            print(str(e))
    data = time.strftime('%Y-%m-%d', time.localtime())
    pf = pd.DataFrame(resLs)
    path = pd.ExcelWriter(f'./音乐/QQ音乐热歌榜 {data}.xlsx')
    pf.to_excel(path, encoding='utf-8', index=False)
    path.save()
    with open(f'./音乐/QQ音乐热歌榜 {data}.html', 'w', encoding='utf-8') as f:
        f.write(page)


def qqOri():
    url = 'https://y.qq.com/n/ryqq/toplist/52'
    headers = {
        'user-agent':
        'Mozilla/5.0(WindowsNT10.0;Win64;x64)AppleWebKit/537.36(KHTML,likeGecko)Chrome/91.0.4472.124Safari/537.36'
    }
    page = requests.get(url=url, headers=headers).content.decode('utf-8')
    tree = etree.HTML(page)
    resLs = []
    for li in tree.xpath('//ul[@class="songlist__list"]/li'):
        dic = {
            'rank':
            li.xpath('.//div[contains(@class,"songlist__number")]/text()')[0],
            'name':
            li.xpath('.//span[@class="songlist__songname_txt"]/a/@title')[0],
            'singer':
            '/'.join(li.xpath('.//div[@class="songlist__artist"]/a/text()')),
            'length':
            li.xpath('.//div[@class="songlist__time"]/text()')[0],
            'songUrl':
            'https://y.qq.com' + li.xpath(
                './/span[@class="songlist__songname_txt"]/a[last()]/@href')[0],
            'singerUrl':
            '/'.join(
                'https://y.qq.com' + i
                for i in li.xpath('.//div[@class="songlist__artist"]/a/@href'))
        }
        try:
            resLs.append(dic)
            print(dic)
        except Exception as e:
            print(str(e))
    data = time.strftime('%Y-%m-%d', time.localtime())
    pf = pd.DataFrame(resLs)
    path = pd.ExcelWriter(f'./音乐/QQ音乐原创榜 {data}.xlsx')
    pf.to_excel(path, encoding='utf-8', index=False)
    path.save()
    with open(f'./音乐/QQ音乐原创榜 {data}.html', 'w', encoding='utf-8') as f:
        f.write(page)


def kugouOri():
    url = 'https://www.kugou.com/yy/rank/home/1-30972.html'
    headers = {
        'user-agent':
        'Mozilla/5.0(WindowsNT10.0;Win64;x64)AppleWebKit/537.36(KHTML,likeGecko)Chrome/91.0.4472.124Safari/537.36'
    }
    page = requests.get(url=url, headers=headers).content.decode('utf-8')
    tree = etree.HTML(page)
    resLs = []
    for li in tree.xpath('//div[@class="pc_temp_songlist "]/ul/li'):
        dic = {
            'rank':
            ''.join(li.xpath('.//span[@class="pc_temp_num"]//text()')).strip(),
            'singer':
            li.xpath('.//a[@class="pc_temp_songname"]/text()')[0].split(' - ')
            [0].strip(),
            'length':
            li.xpath('.//span[@class="pc_temp_time"]/text()')[0].strip(),
            'songUrl':
            li.xpath('.//a[@class="pc_temp_songname"]/@href')[0]
        }
        try:
            dic['name'] = li.xpath('.//a[@class="pc_temp_songname"]/text()'
                                   )[0].split(' - ')[1].strip()
        except IndexError:
            dic['name'] = ''
        try:
            resLs.append(dic)
            print(dic)
        except Exception as e:
            print(str(e))
    data = time.strftime('%Y-%m-%d', time.localtime())
    pf = pd.DataFrame(resLs)
    path = pd.ExcelWriter(f'./音乐/酷狗音乐原创榜 {data}.xlsx')
    pf.to_excel(path, encoding='utf-8', index=False)
    path.save()
    with open(f'./音乐/酷狗音乐原创榜 {data}.html', 'w', encoding='utf-8') as f:
        f.write(page)


def kugouTop():
    url = 'https://www.kugou.com/yy/rank/home/1-8888.html'
    headers = {
        'user-agent':
        'Mozilla/5.0(WindowsNT10.0;Win64;x64)AppleWebKit/537.36(KHTML,likeGecko)Chrome/91.0.4472.124Safari/537.36'
    }
    page = requests.get(url=url, headers=headers).content.decode('utf-8')
    tree = etree.HTML(page)
    resLs = []
    for li in tree.xpath('//div[@class="pc_temp_songlist "]/ul/li'):
        dic = {
            'rank':
            ''.join(li.xpath('.//span[@class="pc_temp_num"]//text()')).strip(),
            'singer':
            li.xpath('.//a[@class="pc_temp_songname"]/text()')[0].split(' - ')
            [0].strip(),
            'length':
            li.xpath('.//span[@class="pc_temp_time"]/text()')[0].strip(),
            'songUrl':
            li.xpath('.//a[@class="pc_temp_songname"]/@href')[0]
        }
        try:
            dic['name'] = li.xpath('.//a[@class="pc_temp_songname"]/text()'
                                   )[0].split(' - ')[1].strip()
        except IndexError:
            dic['name'] = ''
        try:
            resLs.append(dic)
            print(dic)
        except Exception as e:
            print(str(e))
    data = time.strftime('%Y-%m-%d', time.localtime())
    pf = pd.DataFrame(resLs)
    path = pd.ExcelWriter(f'./音乐/酷狗音乐TOP500 {data}.xlsx')
    pf.to_excel(path, encoding='utf-8', index=False)
    path.save()
    with open(f'./音乐/酷狗音乐TOP500 {data}.html', 'w', encoding='utf-8') as f:
        f.write(page)


def kuwoHot():
    rank = 1
    resLs = []
    for pn in range(10):
        url = f'http://www.kuwo.cn/api/www/bang/bang/musicList?bangId=16&pn={pn + 1}&rn=30&httpsStatus=1'
        headers = {
            'cookie':
            '_ga=GA1.2.440685833.1626022431; _gid=GA1.2.817459333.1626022431; Hm_lvt_cdb524f42f0ce19b169a8071123a4797=1626022431; Hm_lpvt_cdb524f42f0ce19b169a8071123a4797=1626022510; kw_token=MT9IB65OZK',
            'csrf':
            'MT9IB65OZK',
            'user-agent':
            'Mozilla/5.0(WindowsNT10.0;Win64;x64)AppleWebKit/537.36(KHTML,likeGecko)Chrome/91.0.4472.124Safari/537.36'
        }
        res = requests.get(url=url, headers=headers).json()
        for li in res['data']['musicList']:
            dic = {
                'rank':
                str(rank),
                'name':
                li['name'],
                'singer':
                li['artist'],
                'length':
                str(li['duration']),
                'songUrl':
                'http://www.kuwo.cn/play_detail/' + str(li['rid']),
                'singerUrl':
                'http://www.kuwo.cn/singer_detail/' + str(li['artistid'])
            }
            try:
                resLs.append(dic)
                print(dic)
            except Exception as e:
                print(str(e))
            rank += 1
        time.sleep(2)
    data = time.strftime('%Y-%m-%d', time.localtime())
    pf = pd.DataFrame(resLs)
    path = pd.ExcelWriter(f'./音乐/酷我音乐热歌榜 {data}.xlsx')
    pf.to_excel(path, encoding='utf-8', index=False)
    path.save()


def miguHot():
    (true, false, null) = ('true', 'false', 'null')
    url = 'https://music.migu.cn/v3/music/top/jianjiao_hotsong'
    headers = {
        'user-agent':
        'Mozilla/5.0(WindowsNT10.0;Win64;x64)AppleWebKit/537.36(KHTML,likeGecko)Chrome/91.0.4472.124Safari/537.36'
    }
    page = requests.get(url=url, headers=headers).content.decode('utf-8')
    ex = 'var listData = (.*?)</script>'
    pattern = re.compile(ex)
    json = eval(pattern.findall(page, re.S)[0])
    resLs = []
    ls = json['songs']['items']
    for li in ls:
        dic = {
            'rank':
            str(ls.index(li) + 1),
            'name':
            li['name'],
            'singer':
            '/'.join([i['name'] for i in li['singers']]),
            'length':
            li['duration'],
            'songUrl':
            'https://music.migu.cn/v3/music/song/' + li['copyrightId'],
            'singerUrl':
            '/'.join([
                'https://music.migu.cn/v3/music/artist/' + i['id']
                for i in li['singers']
            ])
        }
        try:
            resLs.append(dic)
            print(dic)
        except Exception as e:
            print(str(e))
    data = time.strftime('%Y-%m-%d', time.localtime())
    pf = pd.DataFrame(resLs)
    path = pd.ExcelWriter(f'./音乐/咪咕音乐热歌榜 {data}.xlsx')
    pf.to_excel(path, encoding='utf-8', index=False)
    path.save()
    with open(f'./音乐/咪咕音乐热歌榜 {data}.html', 'w', encoding='utf-8') as f:
        f.write(page)


def miguOri():
    (true, false, null) = ('true', 'false', 'null')
    url = 'https://music.migu.cn/v3/music/top/jianjiao_original'
    headers = {
        'user-agent':
        'Mozilla/5.0(WindowsNT10.0;Win64;x64)AppleWebKit/537.36(KHTML,likeGecko)Chrome/91.0.4472.124Safari/537.36'
    }
    page = requests.get(url=url, headers=headers).content.decode('utf-8')
    ex = 'var listData = (.*?)</script>'
    pattern = re.compile(ex)
    json = eval(pattern.findall(page, re.S)[0])
    resLs = []
    ls = json['songs']['items']
    for li in ls:
        dic = {
            'rank':
            str(ls.index(li) + 1),
            'name':
            li['name'],
            'singer':
            '/'.join([i['name'] for i in li['singers']]),
            'length':
            li['duration'],
            'songUrl':
            'https://music.migu.cn/v3/music/song/' + li['copyrightId'],
            'singerUrl':
            '/'.join([
                'https://music.migu.cn/v3/music/artist/' + i['id']
                for i in li['singers']
            ])
        }
        try:
            resLs.append(dic)
            print(dic)
        except Exception as e:
            print(str(e))
    data = time.strftime('%Y-%m-%d', time.localtime())
    pf = pd.DataFrame(resLs)
    path = pd.ExcelWriter(f'./音乐/咪咕音乐原创榜 {data}.xlsx')
    pf.to_excel(path, encoding='utf-8', index=False)
    path.save()
    with open(f'./音乐/咪咕音乐原创榜 {data}.html', 'w', encoding='utf-8') as f:
        f.write(page)


def main():
    wangyiyunHot()
    wangyiyunOri()
    qqHot()
    qqOri()
    kugouOri()
    kugouTop()
    kuwoHot()
    miguHot()
    miguOri()


if __name__ == '__main__':
    main()
