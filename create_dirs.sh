#!/bin/bash
n=3
max=25
set -- #this sets the $@ [the argv array] to an empty list

while [ "$n" -le "$max" ]; do
  set -- "$@" "day_$n" #this adds day_n to the end of $@
  n=$(( $n + 1 ));
done

mkdir "$@"