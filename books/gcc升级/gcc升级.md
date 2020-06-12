## 环境准备
yum -y install wget bzip2 gcc gcc-c++ glibc-headers
wget -c -P /opt/tmp/ https://mirrors.tuna.tsinghua.edu.cn/gnu/gcc/gcc-8.2.0/gcc-8.2.0.tar.gz
cd /opt/tmp/
tar zxvf gcc-8.2.0.tar.gz
cd gcc-8.2.0

## 下载gmp mpfr mpc
./contrib/download_prerequisites		                    
cd ../   
 
## 不能在source目录下configure，必须在上一层的目录下
mkdir build-gcc-8.2 					                    
cd build-gcc-8.2
../gcc-8.2.0/configure --prefix=/usr/local/gcc --enable-bootstrap --enable-checking=release --enable-languages=c,c++ --disable-multilib
make -j 4
make install

## 配置环境变量
*查看当前gcc版本*
gcc -v                                                                           
echo -e '\nexport PATH=/usr/local/gcc/bin:$PATH\n' >> /etc/profile.d/gcc.sh && source /etc/profile.d/gcc.sh

## 导出头文件
ln -sv /usr/local/gcc/include/ /usr/include/gcc

## 导出库文件
vim /etc/ld.so.conf.d/gcc.conf
/usr/local/gcc/lib64		#64位系统
ldconfig -v					#配置生效
ldconfig -p |grep gcc		#导出验证

## 另外一种方法
*升级到gcc 9.3：*
yum -y install centos-release-scl
yum -y install devtoolset-9-gcc devtoolset-9-gcc-c++ devtoolset-9-binutils
scl enable devtoolset-9 bash
*需要注意的是scl命令启用只是临时的，退出shell或重启就会恢复原系统gcc版本。*
*如果要长期使用gcc 9.3的话：*
echo "source /opt/rh/devtoolset-9/enable" >>/etc/profile
*这样退出shell重新打开就是新版的gcc了*
*以下其他版本同理，修改devtoolset版本号即可。*