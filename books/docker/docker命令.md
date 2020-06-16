# docker命令

## 安装docker

```shell
yum update
yum install docker
windows安装Docker Desktop Installer.exe
```

## ~~WSL安装dockr~~

```shell
sudo apt-get install apt-transport-https ca-certificates curl software-properties-common
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
sudo add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable"
sudo apt-get update
sudo apt-get install docker-ce
docker --version
```

## 查看docker状态

```shell
docker info
```

## 查看容器状态

```shell
docker ps -a -l
docker inspect [容器名/容器ID]
```

## 创建容器

```shell
docker run --name [自定义容器名] --restart=always -i -t [镜像] /bin/bash
```

## 启动容器

```shell
docker start [容器名/容器ID]
```

## 附着到容器

```shell
docker attach [容器名/容器ID]
```

## 查看容器日志

```shell
docker logs [-ft] [容器名/容器ID]
```

## 查看容器进程

```shell
docker top [容器名/容器ID]
```

## 在容器内部运行进程

```shell
docker exec -d [容器名/容器ID] [需后台运行的命令]
docker exec -t -i [容器名/容器ID] [需交互运行的命令]
```

## 停止容器

```shell
docker stop [容器名/容器ID]
docker kill [容器名/容器ID]
```

## 删除容器

```shell
docker rm [容器名/容器ID]
docker rm $(docker ps -a -q)
```

## 列出镜像

```shell
docker images
```

## 拉取镜像

```shell
docker pull [镜像名]
```

## 构建镜像

```shell
docker build -t [镜像名] [包含Dockerfile的目录]
```

## 推送镜像

```shell
docker push [镜像名]
```

## 删除本地镜像

```shell
docker rmi [镜像名]
docker rmi $(docker images --filter “dangling=true” -q --no-trunc)
```

