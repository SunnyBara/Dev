#! /bin/sh

echo "$1" | tr --squeeze-repeats ' '  | tr ' ' '_' | tr '*' '.'
