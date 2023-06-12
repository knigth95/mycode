import requests
import time
import os

url="https://www.saikr.com/vs/computer/0/0?page="
def get_time():
    return time.strftime('%Y-%m-%d',time.localtime())

def get_web():
    web_path='./web'
    folder=os.path.exists(web_path)
    file_list=[]
    if not folder:
        os.makedirs(web_path)

    t=get_time()
    for i in range(1,10):
        try:
            res=requests.get(url=(url+str(i)))
        except:
            continue
        
        file=f'{web_path}/{t}-{str(i)}.html'
        with open(file,'w') as f:
            f.write(res.text)
        print(res.status_code)
        file_list.append(file)
        time.sleep(1)

    return file_list

print(get_web())
