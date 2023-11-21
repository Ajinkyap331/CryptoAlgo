import cv2
from numpy import random

demo = cv2.imread('image.jpg')

r, c, t = demo.shape

key = random.randint(256, size=(r, c, t))

enc = demo ^ key
cv2.imwrite('enc.jpg', enc)

dec = enc ^ key
cv2.imwrite('dec.jpg', dec)
