# atcoder
コンテストごとにディレクトリ  
ディレクトリ名はコンテストページ開いた時のurlと同じ名前、agc028みたいな  
問題ごとにプログラムファイル  
ファイル名は問題ページのurlに準拠、agc028_aならa.ccみたいに_のうしろ  
コミットメッセージは問題ページのurlに準拠、agc028_aみたいな

atcoder problems  
https://kenkoooo.com/atcoder/?user=iwannatto&rivals=&kind=category  
を見るとACがわかりやすい

memo.txt  
（コンテスト中は自由な空間）  
一番上にコンテストリンク・解説リンクを貼る
ACした問題には問題リンクとタイトルと解説を入れる  
反省は残しておくなら下に分離  
改行をいちいち入れるのが面倒なのと基本いっぱい続けて書くことより、.mdではなく.txtを採用

取り組む問題のレベルに関しては  
https://twitter.com/chokudai/status/986561875344158720  
に従う、今は水色なので  
https://kenkoooo.com/atcoder/?user=iwannatto&rivals=&kind=list  
でonly ratedで400~500検索して出てくる問題を上から順にやる  

## TODO

AC済みの既出問題に解説を入れたい  
problemsの上からやっていくことにする  
今の進捗：agc028まで終了  

libraryディレクトリが埋もれているのでrename  

Makefileとかテスト駆動とかもあとでやるかも  
テストケースの自動取得（多分有志のライブラリがある）  
テスト  
をMakefileで自動化する  
ディレクトリ生成の際に↑をやるMakefileを自動生成する  
