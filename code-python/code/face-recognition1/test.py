# encoding:utf-8
import cv2


face_cascade = cv2.CascadeClassifier('haarcascade_files/haarcascade_frontalface_default.xml')
eye_cascade = cv2.CascadeClassifier('haarcascade_files/haarcascade_eye.xml')

# 读取图像
img = cv2.imread('west.jpeg')
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)  # 转为灰度图


# 检测脸部
faces = face_cascade.detectMultiScale(gray,
                            scaleFactor=1.1,
                            minNeighbors=5,
                            minSize=(30, 30),
                            flags=cv2.CASCADE_SCALE_IMAGE)
print('Detected ', len(faces), " face")


# 标记位置
for (x, y, w, h) in faces:
    img = cv2.rectangle(img, (x, y), (x + w, y + h), (255, 0, 0), 1)
    # cv2.circle(img, (int((x + x + w) / 2), int((y + y + h) / 2)), int(w / 2), (0, 255, 0), 1)
    roi_gray = gray[y: y + h, x: x + w]
    roi_color = img[y: y + h, x: x + w]

    eyes = eye_cascade.detectMultiScale(roi_gray)
    for (ex, ey, ew, eh) in eyes:
        cv2.rectangle(roi_color, (ex, ey), (ex + ew, ey + eh), (0, 255, 0), 1)


label = 'Result: Detected ' + str(len(faces)) +" faces !"
cv2.putText(img, label, (10, 20),
            cv2.FONT_HERSHEY_SCRIPT_COMPLEX,
            0.8, (0, 0, 0), 1)

# 显示图像
cv2.imshow('img', img)
cv2.waitKey(0)
cv2.destroyAllWindows()