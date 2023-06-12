from get_web import get_web
from regex_pattern import get_info

f_list=get_web()

res=[]
for i in f_list:
    res.append(get_info(i))
