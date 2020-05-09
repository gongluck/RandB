#!/bin/bash   
shared=$(find ./ -maxdepth 1 -name '*.so.*')
for f in `echo $shared | xargs`
do
    if [ -f $f ]; then
		ldd $f | awk '{print $3}' | xargs -i cp -L {} ./
    fi
done 
