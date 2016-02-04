#!/bin/bash -x

mkdir -p /var/www/html/repo/CentOS/7/os/x86_64
mkdir -p /var/www/html/repo/CentOS/7/updates/x86_64

rsync="/usr/bin/rsync -avqHz --delete"
mirror=rsync://mirrors.kernel.org/centos

verlist="7"
archlist="x86_64"
baselist="os updates"
local=/var/www/html/repo/CentOS

for ver in $verlist
do
    for arch in $archlist
    do
        for base in $baselist
        do
            remote=$mirror/$ver/$base/$arch
            $rsync $remote $local/$ver/$base/$arch
        done
    done
done


