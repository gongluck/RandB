## 设置代理
```Command
#WIN
SET GO111MODULE=on
#LINUX
export GO111MODULE=on

go env -w GOPROXY=https://goproxy.cn
go env -w GOPROXY=https://github.com/goproxy
go env -w GOPROXY=https://mirrors.aliyun.com/goproxy
go env -w GOPROXY=https://goproxy.io
go env -w GOPROXY=https://goproxy.cn,direct
```