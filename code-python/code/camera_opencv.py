import cv2
import time

from imutils import paths
import face_recognition
import argparse
import pickle
import os


def getImage(imgQueue):
    camera = cv2.VideoCapture(0)
    ret,img = camera.read()
    backGround = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    fileNames =['007.jpg','face.jpg']
    personNames = ['zzm','yzb']
    
    encodings_ref = []
    for fileName in fileNames:
        image = cv2.imread(fileName)
        rgb = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
        # detect the (x, y)-coordinates of the bounding boxes
        # corresponding to each face in the input image
        boxes = face_recognition.face_locations(rgb)
        # compute the facial embedding for the face
        encodings = face_recognition.face_encodings(rgb, boxes)
        encodings_ref.append(encodings)
    k=0
    cnt=0
    while(True):
        # 读取图片
        read_start = time.time()
        ret,img = camera.read()
        read_end = time.time()
        change = False
        if(not ret):
            continue
        # 移动目标检测
        gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
        diff = cv2.absdiff(backGround,gray)
        diff = cv2.threshold(diff,50,255,cv2.THRESH_BINARY)[1]
        diff = cv2.dilate(diff,cv2.getStructuringElement(cv2.MORPH_ELLIPSE,(9,4)),iterations=2)
        contours,hierarchy = cv2.findContours(diff,cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_SIMPLE)
        show_img = img.copy()
        for c in contours:
            if(cv2.contourArea(c)<1500):
                continue
            change = True
            (x,y,w,h) = cv2.boundingRect(c)
            cv2.rectangle(show_img,(x,y),(x+w,y+h),(0,255,0),2)
        if(change==False):
            backGround = gray
        move_detection_end = time.time()

        # 人脸检测
        
        if(change==True):
            rgb1 = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
            # detect the (x, y)-coordinates of the bounding boxes
            # corresponding to each face in the input image
            boxes1 = face_recognition.face_locations(rgb1)
            # compute the facial embedding for the face
            encodings1 = face_recognition.face_encodings(rgb1, boxes1)
            
            for i in encodings1:
                matches = face_recognition.compare_faces(i,
                        encodings_ref)
                if(matches):
                    k=cnt
                    cv2.putText(show_img, personNames[k], (x+20, y), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2)
                #print(i)
                    print(personNames[k])
                else:
                    cv2.putText(show_img, 'Unknown', (x+20, y), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2)
                    cnt=cnt+1
            #matches2 = face_recognition.compare_faces(encodings[0],encodings_ref)
            #print(matches[i])
        
        
        # 显示信息
        cv2.putText(show_img, 'shape:%s*%s'%(img.shape[0],img.shape[1]), (20, 20), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2)
        cv2.putText(show_img, 'move:%sms'%(round((move_detection_end-read_end)*1000,3)), (20, 50), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2)

        # 将图片编码为web所用格式
        frame = cv2.imencode('.jpg',show_img)[1].tobytes()     
        yield(b'--frame\r\n'
                b'Content-Type: image/jpeg\r\n\r\n'+frame+b'\r\n')
        #判断
        