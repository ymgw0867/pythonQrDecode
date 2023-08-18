from pyzbar.pyzbar import decode
from PIL import Image
#import os
import pathlib
#import cv2
import csv

path = "C:\QrDecodeSample\sampleImage"
""" filelist = []
for f in os.listdir(path):
    if os.path.isfile(os.path.join(path, f)):
        filelist.append(f)
print(filelist) """

p_path = pathlib.Path(path)

lst = []

for p in p_path.iterdir():
    sf = pathlib.PurePath(p).suffix
    if sf == ".pdf":
        continue

    print(p)


    """ image_file = cv2.imread(str(p), 0)

    # QRCodeDetectorを生成
    qrDetector = cv2.QRCodeDetector()

    if sf == ".jpg":
        # jpgファイルからQRコードを検出してデコードする
        data_jpg,bbox_jpg,rectifiedImage_jpg = qrDetector.detectAndDecode(image_file)
        
        # デコードしたデータを出力
        print(data_jpg)

    if sf == ".png":
        # pngファイルからQRコードを検出してデコードする
        data_png,bbox_png,rectifiedImage_png = qrDetector.detectAndDecode(image_file)
        
        # デコードしたデータを出力
        print(data_png)
 """
    # QRコードの読取り
    data = decode(Image.open(p))

    # コード内容を出力
    if data:
        sstr = data[0][0].decode('utf-8', 'ignore')
        print(sstr)
        if sstr:
            lst.append([sstr, p])
    #print(data[0].decode('Shift-JIS', 'ignore'))


""" # 画像ファイルの指定
image = "cap20230726165300.png"

# QRコードの読取り
data = decode(Image.open(image))

# コード内容を出力
print(data[0][0].decode('Shift-JIS', 'ignore')) """

f = open('C:\QrDecodeSample\OUT\out2.csv', 'w', newline="")
writer = csv.writer(f)
writer.writerows(lst)
f.close()
input()