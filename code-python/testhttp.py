from flask import Flask,render_template,request
app =Flask(__name__)
@app.route('/')
def Hello_world():
    data=['a','b','c']
    return render_template('hello.html',data=data)
@app.route('/result',methods=['POST'])
def result():
    if request.method=='POST':
        first=request.form['first']
        print(first)
        second=request.form['second']
        sum=first+second
        return render_template('hello.html',first=first,second=second,sum=sum)
        
def show():
    return '<p>font color="red">红色4</font></p>'
if __name__=='_main_':
    app.run(host='0.0.0.0',port="5002",debug=True);