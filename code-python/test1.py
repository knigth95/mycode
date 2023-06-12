from urllib import request
from flask import Flask,redirect,request
from flask import render_template #渲染
 
app = Flask(__name__)
@app.route('/') #主页地址,“装饰器”
def news():
    imgs=["/static/qq.png","/static/t.jpeg","/static/sjx.jpg","/static/cai.bmp","/static/long.bmp","/static/qinfu1.bmp"]
    return render_template('kongbai.html',imgs=imgs) #把index.html文件读进来，再交给浏览器

@app.route('/del_img',methods=['POST'])
def delImg():
    print(request.form)
    name=request.form.keys()
    ## 删除文件
     
    return  redirect('/')
if __name__ == '__main__':
    app.run(host='0.0.0.0',debug=True,port=5000) #127.0.0.1 回路 自己返回自己