## start qpid service
qpidd -p 5672 --no-data-dir

## send messages
qpid-send -b 127.0.0.1:5672 -a "topic;{create:always}" --content-stdin

## receive messages
qpid-receive -b 127.0.0.1:5672 -a "topic;{create:always}" -f
