#! /bin/sh

ls -la | cut  --bytes=46- > text1.txt
ls -la | cut --bytes=1-10 > text3.txt
paste -d ':' text1.txt text3.txt > text4.txt
