# EAT.PY (c) 2024 EN
# ETP ASSET TRANSFORMER
# CONVERT .PNG to .ETP 1.0
# THIS FILE IS UNDER THE MIT LICENSE
# https://github.com/CardboardDog/ETP/blob/main/LICENSE

import sys
from PIL import Image

png = Image.open(sys.argv[1])
pixels = list(png.getdata())

if png.size[0] > 255 or png.size[1]> 255:
    print("error: image is too big")
    sys.exit(-1)

out = open(sys.argv[2],"wb")
data = ['e','t','p',chr(0x10),chr(png.size[0]),chr(png.size[1])]

data = [ord(i) for i in data]

for pixel in range(0,png.size[0]*png.size[1]):
    data.extend(list(pixels[pixel]))

out.write(bytes(data))
out.close()