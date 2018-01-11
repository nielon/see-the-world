#!/bin/sh

pnum=$(ps -ef | grep $0$ | grep -v grep | wc -l)
if [ $pnum -gt 2  ];then
	        exit
	fi

ping localhost > log
