## 发送消息
qpid-send.exe -b 192.168.39.43:5673 -a "topic;{create:always}" --content-stdin

## 消费消息
qpid-receive.exe -b 192.168.39.43:5673 -a "topic;{create:always}" -f
