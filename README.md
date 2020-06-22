# mod-ijon-maze
对ijon的maze模块进行魔改，加了个tiny地图，用来测是不是安装成功，然后加了个路径完成之后跳转到路径自动跑一遍的程序  
## 地图源文件
big.c 大地图（13 * 17 大地图模式）  
small.c 小地图（7 * 11 符号执行的路径经常用这个地图来测试）  
tiny.c 新加的地图（4 * 6 超级小地图）  
## 地图结果展示源文件
maze_show.c 当fuzz跑完跑出结果的时候调用这个文件对应的程序，对路径结果进行展示  
## 脚本
1. build.sh 编译脚本，对三类地图进行编译，并对地图展示程序进行编译.  
2. run_afl.sh 运行 afl，第一个参数格式 maze.tiny.bt （tiny对应三种地图模式，bt是对应两类，还有一种是nobt，意味着是否可以回退，如果可以回退，对 fuzz 来说路径难度会加倍）
## 运行
提前安装好ijon，流程可以看这里[粗制滥造的教程23333](https://www.cnblogs.com/wayne-tao/p/13064634.html)，或者[官方说明](https://github.com/RUB-SysSec/ijon)
```bash
bash build.sh
bash run_afl.sh maze.tiny.bt
```
