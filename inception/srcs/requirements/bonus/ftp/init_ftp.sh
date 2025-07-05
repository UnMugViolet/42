#!/bin/bash

if [ -z "$FTP_USER" ] || [ -z "$FTP_PASSWORD" ]; then
	echo "FTP_USER and FTP_PASSWORD must be set in the environment."
	exit 1
fi

service vsftpd start

# Check if the FTP server is running
if pgrep -x "vsftpd" > /dev/null; then
	echo "FTP server is running."
else
	echo "FTP server failed to start."
	exit 1
fi

if ! id "$FTP_USER" &>/dev/null; then
    adduser $FTP_USER --disabled-password --gecos ""
fi

echo "$FTP_USER:$FTP_PASSWORD" | chpasswd
echo "$FTP_USER" | tee -a /etc/vsftpd.userlist

mkdir -p /home/$FTP_USER/ftp
chown nobody:nogroup /home/$FTP_USER/ftp
chmod a-w /home/$FTP_USER/ftp

mkdir -p /home/$FTP_USER/ftp/files
chown $FTP_USER:$FTP_USER /home/$FTP_USER/ftp/files

sed -i "s/#write_enable=YES/write_enable=YES/" /etc/vsftpd.conf
sed -i "s/#chroot_local_user=YES/chroot_local_user=YES/" /etc/vsftpd.conf

echo "
local_enable=YES
allow_writeable_chroot=YES
pasv_enable=YES
local_root=/home/$FTP_USER/ftp
pasv_min_port=40000
pasv_max_port=40010
userlist_file=/etc/vsftpd.userlist
" >> /etc/vsftpd.conf

