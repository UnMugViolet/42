#!/bin/bash

if [ -z "$FTP_USER" ] || [ -z "$FTP_PASSWORD" ]; then
	echo "FTP_USER and FTP_PASSWORD must be set in the environment."
	exit 1
fi

service vsftpd start

if ! id "$FTP_USER" &>/dev/null; then
    adduser $FTP_USER --disabled-password --gecos ""
fi

echo "$FTP_USER:$FTP_PASSWORD" | chpasswd
echo "$FTP_USER" | tee -a /etc/vsftpd.userlist

mkdir -p /home/$FTP_USER/ftp
chown nobody:nogroup /home/$FTP_USER/ftp
chmod a-w /home/$FTP_USER/ftp

mkdir -p /home/$FTP_USER/ftp/wordpress
chown $FTP_USER:$FTP_USER /home/$FTP_USER/ftp/wordpress

sed -i "s/#write_enable=YES/write_enable=YES/" /etc/vsftpd.conf
sed -i "s/#chroot_local_user=YES/chroot_local_user=YES/" /etc/vsftpd.conf

echo "
local_enable=YES
allow_writeable_chroot=YES
anonymous_enable=YES
anon_upload_enable=YES
anon_mkdir_write_enable=YES
anon_world_readable_only=NO
anon_other_write_enable=YES
pasv_enable=YES
local_root=/home/$FTP_USER/ftp
pasv_min_port=$FTP_PORT_MIN
pasv_max_port=$FTP_PORT_MAX
userlist_file=/etc/vsftpd.userlist
userlist_enable=YES
userlist_deny=NO
local_umask=022
" >> /etc/vsftpd.conf

# Restart vsftpd to apply configuration changes
service vsftpd restart
echo "FTP server is set up and running."

# Monitor logs
touch /var/log/vsftpd.log
chmod 644 /var/log/vsftpd.log
tail -f /var/log/vsftpd.log
