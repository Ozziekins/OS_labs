#!/bin/bash
now="$(date +'%T')"
printf "The date and time now is %s\n" "$now"

echo "Wait three seconds"
sleep 3

now="$(date +'%X')"
printf "The current time in locale's time representation is %s\n" "$now"

