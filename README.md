与えられたマップの中で、1番大きな正方形を描くプログラム。  
  
------------------------  
例　test_correctフォルダ内のbsq1.txtで説明する。  

書式は以下  
  
6.oI  
`....o..`  
`.......`    
`o.....o`  
`......o`  
`.......`  
`.....o.`  
  
6はマップ全体が6行であることを指す。  
.は正方形を置ける箇所。  
oは正方形を置けない箇所。いわば障害物である。  
Iは変換する文字。  
  
`....o..`  
`.......`  
`o.....o`  
`......o`  
`.......`  
`.....o.`  
はマップである。  
  
  
出力結果はこのようになる  
`....o..`  
`.IIII..`  
`.IIII..`  
`oIIII.o`  
`.IIII.o`  
`.IIII..`  
`.....o.`  
  
Iが縦・横4つ並んでいる箇所が、最大の正方形である(表示の関係上、長方形に見えてしまうが数えると確かに縦横の数は一致している)。  
  
下の数字の並びは、マップのそれぞれの箇所においておくことのできる正方形の、  
縦・横最大の大きさである。  
  
` 1 1 1 1 0 1 1`  
` 1 2 2 2 1 1 2`  
` 0 1 2 3 2 2 0`  
` 1 1 2 3 3 3 0`  
` 1 2 2 3 4 4 1`  
` 1 2 3 3 4 0 1`  
  
oが置かれている箇所は何も置けないので0である。  
  
  
もう1つ、成功例を挙げる。  
  
bsq10.txt   
  
`10AB `  
`AAAAAAAAAAAAA`  
`AAAAAAAAAAAAA`  
`AABAAAAAAABAA`  
`AAAAAAAAAAAAA`  
`BAAAAAAAABAAA`  
`AAAAAAAAAAAAA`  
`AAAAAABAAAAAA`  
`AAAAAAAAAAAAA`  
`BBAAAAAAAAAAA`  
`AAAAAAAAAAAAA`  
  
  
書式の文字が足りないように見えるが、実は半角スペースを入れてある。  
つまり空白で埋めるということを意味するため、最初の書式は正しい。  
まとめると書式は、10行のマップであり、Aは置ける箇所、Bは障害物、そして空白で正方形を描く、という意味になる。  
  
  
実行結果  
  
`./bsq test_correct/bsq10.txt`  
` 1 1 1 1 1 1 1 1 1 1 1 1 1`  
` 1 2 2 2 2 2 2 2 2 2 2 2 2`  
` 1 2 0 1 2 3 3 3 3 3 0 1 2`  
` 1 2 1 1 2 3 4 4 4 4 1 1 2`  
` 0 1 2 2 2 3 4 5 5 0 1 2 2`  
` 1 1 2 3 3 3 4 5 6 1 1 2 3`  
` 1 2 2 3 4 4 0 1 2 2 2 2 3`  
` 1 2 3 3 4 5 1 1 2 3 3 3 3`  
` 0 0 1 2 3 4 2 2 2 3 4 4 4`  
` 1 1 1 2 3 4 3 3 3 3 4 5 5`  
  
`AAA`&emsp &emsp `AAAA`  
`AAA                 AAAA`  
`AAB      ABAA`  
`AAA      AAAA`  
`BAA      BAAA`  
`AAA      AAAA`  
`AAAAAABAAAAAA`  
`AAAAAAAAAAAAA`  
`BBAAAAAAAAAAA`  
`AAAAAAAAAAAAA`  
  
6×6の空白の正方形が生じる。  


---------------------


出力方法

コマンドラインにて
`make`  

これで実行ファイルであるbsqが生成される。
続いて
`./bsq 実行ファイル`  

のように実行する。具体的には
`./bsq test_correct/bsq1.txt`  

と打つ。


複数ファイルでも実行が可能なので、
`./bsq test_correct/bsq1.txt test_correct/bsq24`  

とやっても結果が複数生じる。

なお、test_incorrectフォルダにはマップの書式に欠陥があるためにmaperrorと出力するテスト群である。

例
`bsq1_maperror.txt`  
`6.oo` 障害物と置き換え文字が同じ。

`bsq9abc.txt`  

`8ab `  
`aaaaaaaaaaaaa`  
`aaaaaaabaaaba`  
`aaabaaaaaaaaa`  
`aaaaaaaaaaaaa`  
`aaaaaaaaaaaaa`  
`aaaaaabaaaaaa`  
`aaaaaaaaaaaaa`  
`aaaaaaaaaaaaba`  

マップは長方形(もしくは正方形)でないため、maperrorとなる。







