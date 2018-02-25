# alarm

### 手机被收的权宜之计。

当前版本: 0.0.1alpha

`alarm.wav` 为闹钟铃声，可替换，在 Windows 下必须是 .wav 波形音频，为什么只支持这个连压缩都没有的格式？因为我太弱了！

Windows 用户请打开 `alarm_gb2312_chinese.cpp` 来获取 GB2312 编码的程序，这样在终端中不会乱码 (shabi Windows 终端不支持 UTF-8)。

Windows 用户请自行编译，然后使用 run_windows.bat 运行。

在 Windows 上编译，需要添加 `-lwinmm` 参数。  
对于 Dev-C++，点选“工具[T]”->“编译选项[C]“，选中”编译时加入以下命令“，在文本框中加上 `-lwinmm`。  
为什么还要你们自己加编译参数呢？因为我不会写 Makefile 啊，我太弱了！

**本程序未在 Windows 下做非常充分的测试，可能存在 Bug。**

类 Unix 系统用户使用 run_unix.sh 来运行(如果未编译会自动编译)。

BSD、GNU/Linux 用户请自行安装依赖包 `mplayer`，并配置到 `PATH` 环境变量。

Code with ❤️ by **Victor Huang** < https://imvictor.tech/ >。