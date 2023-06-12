import cv2

faceCascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')
img = cv2.imread('007.jpg')

#img = cv2.flip(img, -1)
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
faces = faceCascade.detectMultiScale(
    gray,     
    scaleFactor=1.2,
    minNeighbors=5,     
    minSize=(20, 20)
)
print(faces)
face = faces[0]
[x,y,w,h] = face
cv2.rectangle(img,(x,y),(x+w,y+h),(0,255,0),2)
#cv2.imwrite('face_detect.jpg',img)
cv2.imwrite('007.jpg',img)