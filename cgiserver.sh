#!/bin/bash
fcgi=/usr/bin/spawn-fcgi
ip=127.0.0.1
port=9001
user=www
group=www
cgi=/data0/www/cgi/cgi
child_num=2
pid=/var/run/cgiserver.pid
case "$1" in 
    start)
        echo "Starting cgiserver"
        $fcgi -a $ip -p $port -u $user -g $group -f $cgi -F $child_num -P $pid 
        if [ $? != 0 ];then
            echo "faild"
        fi
        echo "done"
    ;;
    stop)
        echo "Shutting down cgiserver"
        if [ ! -r $pid ];then
            cat $pid | xargs kill
        elif [ `ps -ef | grep $cgi | grep -v grep | awk '{print $1}' | wc -l` -gt 0 ];then 
            ps -ef | grep $cgi | grep -v grep | awk '{print $2}' | xargs kill
        fi
        if [ $? != 0 ];then
            echo "faild"
        fi
        echo "done"
    ;;
    restart)
        echo "Shutting down cgiserver"
        if [ ! -r $pid ];then
            cat $pid | xargs kill
        elif [ `ps -ef | grep $cgi | grep -v grep | awk '{print $1}' | wc -l` -gt 0 ];then 
            ps -ef | grep $cgi | grep -v grep | awk '{print $2}' | xargs kill
        fi
        if [ $? != 0 ];then
            echo "faild"
        fi
        echo "done"
        echo "Starting cgiserver"
        $fcgi -a $ip -p $port -u $user -g $group -f $cgi -F $child_num -P $pid
        if [ $? != 0 ];then
            echo "faild"
        fi
        echo "done"
    ;;
    *)
        echo "Usage: $0 {start|stop|restart}";
    ;;
esac
