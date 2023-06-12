# -*- coding: utf-8 -*-
# 摄像头头像识别
import face_recognition
import cv2
import ft2
from PIL import Image, ImageDraw, ImageFont
import numpy as np

cam = cv2.VideoCapture(0)
# 本地图像
kxs_image = face_recognition.load_image_file("kxs.jpg")
kxs_face_encoding = face_recognition.face_encodings(kxs_image)[0]

# 本地图像二
wsp_image = face_recognition.load_image_file("wsp.jpg")
wsp_face_encoding = face_recognition.face_encodings(wsp_image)[0]

# 本地图片三2
pr_image = face_recognition.load_image_file("pr.jpg")
pr_face_encoding = face_recognition.face_encodings(pr_image)[0]

# Create arrays of known face encodings and their names
# 脸部特征数据的集合
known_face_encodings = [
    kxs_face_encoding,
    wsp_face_encoding,
    pr_face_encoding
]

# 人物名称的集合
"""""
known_face_names = [
    "kxs",
    "wsp",
    "panrui"
]
"""""
known_face_names = [
    "匡",
    "王",
    "潘"
]
face_locations = []
face_encodings = []
face_names = []
process_this_frame = True


while(cam.isOpened()):
    # 读取摄像头画面
    ret, frame = cam.read()
    if not ret:
        #等同于 if ret is not none
        break
    sucess, img = cam.read()
    k = cv2.waitKey(1)
    if k == 27:
        # 通过esc键退出摄像
        cv2.destroyAllWindows()
        break
    elif k == ord("s"):
        # 通过s键保存图片，并退出。
        num = 1
        cv2.imwrite("image%s.jpg" % num, img)
        num+=1;
        print("ok")
        #cv2.destroyAllWindows()
        break
    # 改变摄像头图像的大小，图像小，所做的计算就少
    small_frame = cv2.resize(frame, (0, 0), fx=0.33, fy=0.33)

    # opencv的图像是BGR格式的，而我们需要是的RGB格式的，因此需要进行一个转换。
    rgb_small_frame = small_frame[:, :, ::-1]

    # Only process every other frame of video to save time
    if process_this_frame:
        # 根据encoding来判断是不是同一个人，是就输出true，不是为flase
        face_locations = face_recognition.face_locations(rgb_small_frame)
        face_encodings = face_recognition.face_encodings(rgb_small_frame, face_locations)

        face_names = []
        for face_encoding in face_encodings:
            # 默认为unknown
            matches = face_recognition.compare_faces(known_face_encodings, face_encoding,tolerance=0.48)
            #阈值太低容易造成无法成功识别人脸，太高容易造成人脸识别混淆 默认阈值tolerance为0.6
            #print(matches)
            name = "Unknown"

            # if match[0]:
            #     name = "michong"
            # If a match was found in known_face_encodings, just use the first one.
            if True in matches:
                first_match_index = matches.index(True)
                name = known_face_names[first_match_index]

            face_names.append(name)

    process_this_frame = not process_this_frame

    # 将捕捉到的人脸显示出来
    for (top, right, bottom, left), name in zip(face_locations, face_names):
        # Scale back up face locations since the frame we detected in was scaled to 1/4 size
        #由于我们检测到的帧被缩放到1/4大小，所以要缩小面位置
        top *= 3
        right *= 3
        bottom *= 3
        left *= 3

        cv2.rectangle(frame, (left, top), (right, bottom), (0, 0, 255), 3)
        print(name)
        ft = ft2.put_chinese_text('msyh.ttf')
        #引入ft2中的字体
        #加上标签
        xpos=left+10
        ypos=bottom
        frame = ft.draw_text(frame,xpos,ypos,name, 20, (255, 255, 255))
       


    cv2.imshow('monitor', frame)
    if cv2.waitKey(1) & 0xFF == 27:
        break

cam.release()
cv2.destroyAllWindows()

