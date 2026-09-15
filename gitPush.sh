#!/bin/bash

while true;do
	if git push;then 
		break
	fi
	sleep 20
done
