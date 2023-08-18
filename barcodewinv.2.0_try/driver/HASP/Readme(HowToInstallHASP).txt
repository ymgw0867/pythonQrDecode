	How to HASP Driver Update/Install

　このファイルはHASPドライバをアップデートする方法、もしくは
HASPドライバをインストールする方法について記しています。

１．PCの電源を切りHASPをPCから取り外します。

２．PCを起動し、できる限り他のアプリケーションが実行されていない状態にします。

３．HASPドライバがインストールされている場合は、このフォルダのremove.batを実行します。

４．このフォルダのinstall.batを実行します。

５．デバイスドライバのインストールが開始され、「Please Wait...」が表示されます
　　(数分かかる場合があります)。
６．インストールが完了すると、「The operation was completed successfully」
　　のメッセージが表示されます。

７．HASPを取り付けます。

補足
　・インストールが成功したかどうかを確認するには、このフォルダのshowinfor.batを
    実行してください。インストールされた状態が表示されます。
　・インストールがうまく成功しない場合は、一度アンインストールを実行し、その後
    インストールを試みて下さい。アンインストールにはこのフォルダのremove.batを
    実行します。

　・HASPデバイスドライバのインストール時の障害については下記URLをご覧ください。
　　　参考URL
       http://support.safenet-inc.jp/srm/information/faq/faq.html

    ドライバインストール中にブルースクリーン(BSOD)となる場合、
    セーフモードでログオンして、このフォルダ内の haspdinst_DisableAksfridge.bat
    を実行して aksfridge.sys を無効化します。
    ＯＳを再起動して正常動作を確認してください。

  ・HASPデバイスドライバをインストールすると、Admin Control Center（ACC）という
    ライセンス管理コンソール画面でライセンス状況を確認することが出来ます。
    このフォルダの Admin Control Center（ショートカット）からアクセス可能です。
　　　参考URL
       http://www.aladdin.co.jp/down/haspSRM_trouble.html#01
