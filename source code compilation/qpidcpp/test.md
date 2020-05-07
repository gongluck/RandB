## 启动qpid服务
qpidd.exe -p 5672 --no-data-dir

## 发送消息
qpid-send.exe -b 127.0.0.1:5672 -a "topic;{create:always}" --content-stdin

## 消费消息
qpid-receive.exe -b 127.0.0.1:5672 -a "topic;{create:always}" -f
