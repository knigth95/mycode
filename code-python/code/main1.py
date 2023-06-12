import cv2
 
# 调用模型库文件
face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')
# 打开内置摄像头
cap = cv2.VideoCapture(0,cv2.CAP_DSHOW)
#这个地方的cv2.CAP_DSHOW是当cv2.VideoCapture(0)出错误再加，一般来说可以不要
while True:
    # 读取视频图像
    _, frame = cap.read()
    # 灰度处理
    gray = cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)
    # 设定人脸识别参数
    faces = face_cascade.detectMultiScale(gray, scaleFactor=1.3, minNeighbors=3,minSize=(5, 5),maxSize=(500,500),)
 
    faceNum = len(faces)
    print("检测到的人脸数量为: %s人" % faceNum)
 
    if len(faces) > 0:
        for faceRect in faces:
            x, y, w, h = faceRect
            # 在人脸周围绘制矩形
            cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 255, 0), 3)
    # 显示图像
    cv2.imshow('img', frame)
    #  按esc键推出
    if cv2.waitKey(1) & 0xff == 27:
        break
cv2.destroyAllWindows()
cap.release()