# 安装perl工具
# 使用对应版本的VC控制台环境
同一份源码不要同时编译32位和64位

# 32位
perl Configure debug-VC-WIN32 no-asm --prefix="output/win32/debug"
perl Configure VC-WIN32 no-asm --prefix="output/win32/release"

ms\do_ms

# 64位
perl Configure debug-VC-WIN64A no-asm --prefix="output/x64/debug"
perl Configure VC-WIN64A no-asm --prefix="output/x64/release"

ms\do_win64a

# 动态库
nmake -f ms\ntdll.mak
nmake -f ms\ntdll.mak test
nmake -f ms\ntdll.mak install