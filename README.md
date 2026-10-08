# cpp-sysCoding

Linux 系统编程（C 语言）学习与实践代码，涵盖文件 IO、进程、线程、信号、进程间通信及静态/动态库制作，配套《Linux系统编程笔记.pdf》。

## 环境

- Linux + GCC（线程相关示例需加 `-pthread`）
- 使用 GNU Make 构建

## 目录结构

| 目录 | 内容 |
| --- | --- |
| `fileSystem_test` | 文件 IO：`dup/dup2/fcntl`、`unlink`、目录遍历、自制 `myls` |
| `process_test` | 进程：`fork`、`exec`、`wait/waitpid`、管道 `pipe`、`mmap` 映射与通信 |
| `pthread_test` | 线程基础：创建、`join`、`detach`、`cancel`、退出与属性 |
| `pthread_sync_test` | 线程同步：互斥锁、读写锁、条件变量、信号量、生产者-消费者 |
| `signal_test` | 信号：`signal/sigaction`、`alarm`、`setitimer`、`kill`、`SIGCHLD` 回收 |
| `session_daemon` | 会话、进程组与守护进程创建流程 |
| `staticLib` / `dynamicLib` | 静态库 `.a` 与动态库 `.so` 的制作和调用 |
| `maketest` / `gdbtest` | Makefile 分层编译、GDB 调试示例 |

根目录 `Makefile` 提供通配编译规则；`makeCleanAll.c` 递归在各子目录执行 `make clean`；`gitPush.sh` 为带重试的推送脚本。

## 构建

进入任意示例目录执行：

```bash
make        # 编译当前目录全部 .c
make clean  # 清理生成的可执行文件
```

运行动态库示例前需设置库路径：`export LD_LIBRARY_PATH=./lib`（见 `dynamicLib/run.sh`）。
