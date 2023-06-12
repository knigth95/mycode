from imutils import paths
import face_recognition
import argparse
import pickle
import cv2
import os


fileNames =['','']
personNames = ['','']

encodings_ref = []
for fileName in fileNames:
    image = cv2.imread(fileName)
    rgb = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
    # detect the (x, y)-coordinates of the bounding boxes
    # corresponding to each face in the input image
    boxes = face_recognition.face_locations(rgb)
    # compute the facial embedding for the face
    encodings = face_recognition.face_encodings(rgb, boxes)
    encodings_ref.append(encodings[0])

image1 = cv2.imread('007.jpg')
rgb1 = cv2.cvtColor(image1, cv2.COLOR_BGR2RGB)
# detect the (x, y)-coordinates of the bounding boxes
# corresponding to each face in the input image
boxes1 = face_recognition.face_locations(rgb1)
# compute the facial embedding for the face
encodings1 = face_recognition.face_encodings(rgb, boxes1)

for e in encodings1:
    matches = face_recognition.compare_faces(e,
			encodings_ref)
#cv2.putText(show_img, "zzm", (20, 80), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2)
print(matches)
# loop over the encodings
#for encoding in encodings:
    # add each encoding + name to our set of known names and
    # encodings
    #knownEncodings.append(encoding)
    #knownNames.append(name)