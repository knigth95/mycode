from flask import Flask,render_template, request,Response
from multiprocessing import Process,Manager
from camera_opencv import getImage
import cv2
app = Flask(__name__)

@app.route('/')
def index():
    data = {'fps':20}
    return render_template('index.html',data=data)

@app.route('/video_feed')
def video_feed():
    return Response(getImage(None),mimetype='multipart/x-mixed-replace;boundary=frame')
    
if __name__ == '__main__':

    app.run(host="0.0.0.0",port="5002",threaded=True,debug=True)