## Prerequisites
yum install cmake boost-devel libuuid-devel pkgconfig gcc-c++ make ruby help2man doxygen graphviz cyrus-sasl-devel cyrus-sasl-md5 cyrus-sasl-plain nss-devel nspr-devel xqilla-devel xerces-c-devel libibverbs-devel librdmacm-devel ruby ruby-devel swig libdb-cxx-devel libaio-devel
yum install python-devel python-qpid qpid-tests

## build
cd [src]
mkdir bld
cd bld
cmake -DCMAKE_CXX_FLAGS="-std=c++11 -Wno-error=deprecated-declarations" -DCMAKE_INSTALL_PREFIX=./install ..
make all
make install
