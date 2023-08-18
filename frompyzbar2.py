from pyzbar.pyzbar import decode
from PIL import Image
from tkinter import messagebox
import cv2
import numpy as np
import csv
import datetime

cap = cv2.VideoCapture(1)
font = cv2.FONT_HERSHEY_SIMPLEX
# QRCodeDetectorを生成
#detector = cv2.QRCodeDetector()
wstr = ""
lst = []

initial_time = datetime.datetime.now()
time_cnt = 30        # sec 初期値
time_interval = 60  # sec 定期実行の時間間隔

while cap.isOpened():
    #現在時間 sec
    current_time = (datetime.datetime.now() - initial_time).total_seconds()
    # time_interval毎に実行する
    if current_time >= time_cnt:
        # メッセージボックス（はい・いいえ） 
        ret = messagebox.askyesno('確認', 'ウィンドウを閉じますか？')
        if ret == True:
           cv2.waitKey(1)
           break
        # 次回、定期実行する時刻 time_cntを更新
        time_cnt += time_interval

    ret,frame = cap.read()
    if ret == True:
        d = decode(frame)
        if d:
            #print(d)
            sstr = d[0][0].decode('utf-8', 'ignore')
            #frame = cv2.putText(frame, sstr,(10,50),font,1,(0,255,255),2,cv2.LINE_AA)
            if wstr != sstr:
                print(sstr)
                wstr = sstr
                lst.append([sstr, ""])

                # メッセージボックス（はい・いいえ） 
                ret = messagebox.askyesno('認識しました', wstr + '\n\n' + 'ウィンドウを閉じますか？')
                if ret == True:
                    cv2.waitKey(1)
                    break
                # 次回、定期実行する時刻 time_cntを更新
                time_cnt = (datetime.datetime.now() - initial_time).total_seconds() + time_interval

        cv2.imshow('Scan the QR Code',np.array(frame)) 

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
        break 
"""
cap.release()
#print(lst)
f = open('C:\QrDecodeSample\OUT\out3.csv', 'w', newline="")
writer = csv.writer(f)
writer.writerows(lst)
f.close()
cv2.destroyAllWindows()