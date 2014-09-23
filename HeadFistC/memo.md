<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title></title>
<link rel="stylesheet" href="github.css" type="text/css">
</head>
<body>
<h1><strong>ポインタの説明</strong></h1>
<hr>
<h1><strong>配列変数</strong></h1>
<div class="codehilite"><pre><span class="kt">char</span> <span class="n">s</span><span class="p">[]</span> <span class="o">=</span> <span class="s">&quot;Are you sore?&quot;</span><span class="p">;</span>
</pre></div>


<p>ポインタのようなものだが、sizeofの結果が異なる <br>
ポインタのsizeofの結果はポインタのサイズだが <br>
配列変数の場合は、配列のサイズ   </p>
<p>ポインタはメモリ上に空間を割り当てるが <br>
配列変数は設定割り当てない</p>
<h2><strong>scanf</strong></h2>
<p>scanfはオーバーフローを起こす可能性があるので必ず長さを指定すること <br>
一方、fgetsは必ず指定しなければいけない <br>
fgetsは文字列しか取得できない <br>
scanfは空白は取得できない。そこで終了とみなされる   </p>
<div class="codehilite"><pre><span class="kt">char</span> <span class="n">name</span><span class="p">[</span><span class="mi">6</span><span class="p">];</span>  
<span class="kt">char</span><span class="o">*</span> <span class="n">ptr</span><span class="p">;</span>   
<span class="kt">int</span> <span class="n">age</span><span class="p">;</span>   
<span class="n">scanf</span><span class="p">(</span><span class="s">&quot;%5s&quot;</span><span class="p">,</span> <span class="n">name</span><span class="p">);</span>   
<span class="n">fgets</span><span class="p">(</span><span class="n">name</span><span class="p">,</span> <span class="k">sizeof</span><span class="p">(</span><span class="n">name</span><span class="p">),</span> <span class="n">stdin</span><span class="p">);</span>
<span class="c1">//ポインタのsieofはポインタのサイズを返すので、自分で指定する</span>
<span class="n">fgets</span><span class="p">(</span><span class="n">ptr</span><span class="p">,</span> <span class="mi">5</span><span class="p">,</span> <span class="n">stdin</span><span class="p">);</span>
<span class="n">scanf</span><span class="p">(</span><span class="s">&quot;%i&quot;</span><span class="p">,</span> <span class="o">&amp;</span><span class="n">age</span><span class="p">);</span>
</pre></div>


<h2><strong>配列変数とポインタ</strong></h2>
<p>charは配列操作ができない</p>
<div class="codehilite"><pre><span class="kt">char</span><span class="o">*</span> <span class="n">str</span> <span class="o">=</span> <span class="s">&quot;abc&quot;</span><span class="p">;</span>
<span class="kt">char</span> <span class="n">val</span><span class="p">[]</span> <span class="o">=</span> <span class="s">&quot;abc&quot;</span><span class="p">;</span>
<span class="kt">char</span><span class="o">*</span> <span class="n">pptr</span><span class="p">;</span>

<span class="n">pptr</span> <span class="o">=</span> <span class="n">val</span><span class="p">;</span>
<span class="c1">//これはできない</span>
<span class="n">str</span><span class="p">[</span><span class="mi">1</span><span class="p">]</span> <span class="o">=</span> <span class="n">str</span><span class="p">[</span><span class="mi">0</span><span class="p">];</span>
<span class="c1">//これはできる</span>
<span class="n">val</span><span class="p">[</span><span class="mi">1</span><span class="p">]</span> <span class="o">=</span> <span class="n">val</span><span class="p">[</span><span class="mi">0</span><span class="p">];</span>
<span class="c1">//ポインタがさす配列変数が変更されるとポインタのほうも変更される</span>
<span class="n">printf</span><span class="p">(</span><span class="s">&quot;val = %s , str = %s</span><span class="se">\n</span><span class="s">&quot;</span><span class="p">,</span> <span class="n">val</span><span class="p">,</span> <span class="n">pptr</span><span class="p">);</span>
</pre></div>


<p>以下の2つは同じこと、配列変数を渡すと結局ポインタになる</p>
<div class="codehilite"><pre><span class="kt">void</span> <span class="nf">func_with_array</span><span class="p">(</span><span class="kt">char</span><span class="p">[]</span> <span class="n">str</span><span class="p">){}</span>
<span class="kt">void</span> <span class="nf">func_with_pointer</span><span class="p">(</span><span class="kt">char</span><span class="o">*</span> <span class="n">str</span><span class="p">){}</span>
</pre></div>


<h2><strong>変数の型</strong></h2>
<ul>
<li>unsigned <br>
  マイナスをとらない代わりに、1ビット分大きな値が設定できる</li>
<li>long <br>
  long intのように使う。大きな値が設定できる</li>
</ul>
<h2><strong>コンパイル</strong></h2>
<p>コンパイラは未知の関数呼び出しがあるとintを返すとみなす。 <br>
実際の関数定義を見つけた時intではないと不一致となりエラーとなる   </p>
<h2><strong>変数の共有</strong></h2>
<p>ヘッダファイルにexternをつけて宣言することで複数ファイルで変数を共有できる</p>
<div class="codehilite"><pre><span class="k">extern</span> <span class="kt">int</span> <span class="n">passcode</span><span class="p">;</span>
</pre></div></body>
</html>
