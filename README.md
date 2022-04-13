# CLayer7
HTTP DDoS Attack implementation in C++ with Curl Libraries


· 1 Clone the repository in a folder

· 2 Open a terminal in location of that folder

· 3 Compile <code>cl7.cpp</code> file

· 4 Run it with <code>./cl7 \<url\> \<threads\> \<time\></code>
  
## Linux
$ Execute in terminal

Clone and move to clayer7 directory
  
```
git clone https://github.com/xFr33z3/clayer7.git
cd clayer7
```
  
Compile it with

```
chmod +x compile.sh
./compile.sh
```
  
Or
  
```
g++ cl7.cpp -lcurl -pthread -o cl7
  
```

Run it
  
```
./cl7 <url> <threads> <time>
```
