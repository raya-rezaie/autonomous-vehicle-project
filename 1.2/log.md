
### Different linux log paths

## /var/log/syslog or /var/log/message
 general system activity logs

## /var/log/auth.log or /var/log/secure
 logs for both successful and failed authentication

## /var/log/boot.log
 start-up messages and boot info
 
## /var/log/maillog or /var/log/mail.log
for mail server logs 

## /var/log/kern
for kernel logs and warning info

## /var/log/dmesg
logs of device driver messages

## /var/log/faillogs
Stores failed login attempts per user in a structured binary format

## /var/log/cron
logs of cron-related messages

## /var/log/daemon.log
keeps track running in background services (doesnt show them graphically)

## /var/logs/btmp
Logs all failed login attempts in a chronological list

## /var/log/utmp
current user info

## /var/log/wtmp
record of each login/logout

## /var/log/lastlog
holds every user's last login as a binary file

## /var/log/yum.log
 holds data on any package installations that used the yum command.

 ## /var/log/httpdl
  a directory containing error_log and access_log files of the Apache httpd daemon. error_log has
  all errors that httpd have faced and access_log logs all requests that come in via http.

  ## /var/log/mysqld.log or /var/log/mysql.log
   MySQL log file that records every  debug, failure and success message, including starting, stopping and restarting of MySQL daemon mysqld

## /var/log/pureftp.log 
monitors for FTP connections using the pureftp process. (data on every connection, FTP login, and authentication failure)

## /var/log/spooler 
some rare messages from USENET

## /var/log/xferlog
FTP file tranfer sessions. (info like file names and user-initiated FTP transfers)

