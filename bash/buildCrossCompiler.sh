#!/bin/bash -x

## install build deps
yum install -y gcc-c++ make gawk

## get source
wget -cq http://ftpmirror.gnu.org/binutils/binutils-2.24.tar.gz
wget -cq http://ftpmirror.gnu.org/gcc/gcc-4.9.2/gcc-4.9.2.tar.gz
wget -cq https://www.kernel.org/pub/linux/kernel/v3.x/linux-3.17.2.tar.xz
wget -cq http://ftpmirror.gnu.org/glibc/glibc-2.20.tar.xz
wget -cq http://ftpmirror.gnu.org/mpfr/mpfr-3.1.2.tar.xz
wget -cq http://ftpmirror.gnu.org/gmp/gmp-6.0.0a.tar.xz
wget -cq http://ftpmirror.gnu.org/mpc/mpc-1.0.2.tar.gz

## extract source
for f in *.tar*; do tar xf $f; done

## create gcc symlinks
cd gcc-4.9.2
ln -s ../mpfr-3.1.2 mpfr
ln -s ../gmp-6.0.0 gmp
ln -s ../mpc-1.0.2 mpc
cd ..

mkdir -p /opt/cross
export PATH=/opt/cross/bin:$PATH

## make binutils
mkdir build-binutils
cd build-binutils
../binutils-2.24/configure --prefix=/opt/cross --target=aarch64-linux --disable-multilib
make -j4
make install
cd ..

## install Linux kernel headers
cd linux-3.17.2
make ARCH=arm64 INSTALL_HDR_PATH=/opt/cross/aarch64-linux headers_install
cd ..

## make gcc
mkdir -p build-gcc
cd build-gcc
../gcc-4.9.2/configure --prefix=/opt/cross --target=aarch64-linux --enable-languages=c,c++ --disable-multilib --without-headers --with-gnu-as --with-gnu-ld
make -j4 all-gcc
make install-gcc
cd ..

## make glibc
mkdir -p build-glibc
cd build-glibc
../glibc-2.20/configure --prefix=/opt/cross/aarch64-linux --build=$MACHTYPE --host=aarch64-linux --target=aarch64-linux --with-headers=/opt/cross/aarch64-linux/include --disable-multilib libc_cv_forced_unwind=yes
make install-bootstrap-headers=yes install-headers
make -j4 csu/subdir_lib
install csu/crt1.o csu/crti.o csu/crtn.o /opt/cross/aarch64-linux/lib
aarch64-linux-gcc -nostdlib -nostartfiles -shared -x c /dev/null -o /opt/cross/aarch64-linux/lib/libc.so
touch /opt/cross/aarch64-linux/include/gnu/stubs.h
cd ..

## build gcc again
cd build-gcc
make -j4 all-target-libgcc
make install-target-libgcc
cd ..

## build glibc again
cd build-glibc
make -j4
make install
cd ..

## build standard C++ library
cd build-gcc
make -j4
make install
cd ..

echo -en "Done.\n"

