## 获取redis资源
wget http://download.redis.io/redis-stable.tar.gz 
tar -xzvf redis-stable.tar.gz

## 安装
cd redis-stable
make
cd src
make install PREFIX=/usr/local/redis

## 移动配置文件到安装目录下
cd ../
mkdir /usr/local/redis/etc
mv redis.conf /usr/local/redis/etc

## 配置redis为后台启动
*将daemonize no 改成daemonize yes*
vi /usr/local/redis/etc/redis.conf 

## 将redis加入到开机启动
*在里面添加内容：/usr/local/redis/bin/redis-server /usr/local/redis/etc/redis.conf*
vi /etc/rc.local

## 开启redis
/usr/local/redis/bin/redis-server /usr/local/redis/etc/redis.conf 

## 常用命令
redis-server */usr/local/redis/etc/redis.conf //启动redis*
pkill redis  *停止redis*

## 卸载redis：
rm -rf /usr/local/redis *删除安装目录*
rm -rf /usr/bin/redis-* *删除所有redis相关命令脚本*
m -rf /root/download/redis-4.0.4 *删除redis解压文件夹*
