from pyzbar.pyzbar import decode
from PIL import Image
import cv2

cap = cv2.VideoCapture(0)
font = cv2.FONT_HERSHEY_SIMPLEX
# QRCodeDetectorを生成
#detector = cv2.QRCodeDetector()

while cap.isOpened():
    ret,frame = cap.read()
    if ret == True:
        d = decode(frame)
        if d:
            frame = cv2.putText(frame, d[0].data.decode('utf-8', 'ignore'),(10,50),font,1,(0,255,255),2,cv2.LINE_AA)
            #sstr = d[0][0].data.decode('utf-8', 'ignore')
        #print[sstr]
        cv2.imshow('frame',frame)

    #    data = detector.detectAndDecode(frame)
    #    if data[0]:
    #        cv2.imshow('frame', data)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
""" while True:
    # カメラから1フレーム読み取り
    ret, frame = cap.read()

    # QRコードを認識
    data = detector.detectAndDecode(frame)

    # 読み取れたらデコードした内容をprint
    if data[0] != "":
        print(data[0])

    # ウィンドウ表示
    cv2.imshow('frame', frame)

    # Qキー押すと終了
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break """
cap.release()
#cv2.destroyAllWindows()