#!/bin/bash
n=21087
while :

do
         sleep 10
         python main.py $n
         mv  result.html index.html
         sleep 20
         let n++
done
