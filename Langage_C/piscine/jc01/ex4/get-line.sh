#! /bin/sh

head --lines=$2 $1 | tail --lines=1
