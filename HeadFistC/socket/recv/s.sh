#!/usr/bin/env bash
echo -n "input: "
read -s -n 1 c

echo $c

case $c in
  a )
     echo "input is a"
     ;;
  $'\x01' )
     echo "input is Ctrl-a"
     ;;
  * )
     echo "input is other"
     ;;
esac
